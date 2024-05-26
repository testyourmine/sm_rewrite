#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "rtk2_sav_test.h"
#include "rtk2_globals.h"
#include "src/sm_rtl.h"

static Rtk2SaveTest SavTests[] = {
  {001, "SAV_TESTS/001-controller-inputs"},
  {002, "SAV_TESTS/002-intro"},
  {101, "SAV_TESTS/101-shine-spark"},
  {102, "SAV_TESTS/102-moon-fall"},
  {103, "SAV_TESTS/103-mock-ball"},
  {104, "SAV_TESTS/104-crystal-flash"},
  {201, "SAV_TESTS/201-alcatraz-escape"},
  {202, "SAV_TESTS/202-green-gate-glitch"},
  {999, NULL}
};

Rtk2SaveTestRunner g_sav_test_runner = {
  .state = kSavTestState_NONE,
  .now_test_idx = 0,
  .tests = SavTests
};


#define now_test(x) x->tests[x->now_test_idx]

void Rtk2SavTestRunner_ResolveSnapshotFail(Rtk2SaveTestRunner* x, bool has_failed)
{
  if (x->state == kSavTestState_NONE) return;
  if (!has_failed) return;
  now_test(x).has_failed = has_failed;
}

void Rtk2SavTestRunner_Start(Rtk2SaveTestRunner* x)
{
  x->state = kSavTestState_STARTING;
}

void Rtk2SavTestRunner_StateMachine_Run(Rtk2SaveTestRunner* x, bool is_replay)
{
  switch (x->state)
  {
    case kSavTestState_STARTING:
      x->state = kSavTestState_RUNNING;
      x->now_test_idx = -1;
      log("[SAV_TESTS] - tests stated");
      break;
    case kSavTestState_RUNNING:
      if (is_replay) return;
      x->now_test_idx++;
      if (now_test(x).name != NULL)
      {
        Rtk2_RtlSaveLoad_ByName(kSaveLoad_Replay, now_test(x).name);
      }
      else
      {
        Rtk2_RtlSaveLoad_ByName(kSaveLoad_Replay, "SAV_TESTS/999-black-out");
        x->state = kSavTestState_FINISHING;
        log("[SAV_TESTS] - tests ended");
      }
      break;
    case kSavTestState_FINISHING:
      log("\n*** SAV TESTS RESULTS ******************");
      for (struct Rtk2SavTest* test = x->tests; test && test->name != NULL; test++)
      {
        log("TEST #%03d | %s | %s", test->id, test->has_failed ? "FAIL" : "PASS", test->name);
      }
      log("****************************************");
      x->state = kSavTestState_NONE;
      break;
    default:
      break;
  }
}
