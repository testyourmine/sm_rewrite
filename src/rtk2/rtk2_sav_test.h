#pragma once

#include <stdbool.h>
#include "src/types.h"

typedef struct Rtk2SavTest {
	int id;
	const char* name;
	bool has_failed;
} Rtk2SaveTest;

typedef enum
{
	kSavTestState_NONE,
	kSavTestState_STARTING,
	kSavTestState_RUNNING,
	kSavTestState_FINISHING
} SavTestStates;

typedef struct Rtk2SaveTestRunner {
	SavTestStates state;
	int8 now_test_idx;
	struct Rtk2SavTest* tests;
} Rtk2SaveTestRunner;

extern Rtk2SaveTestRunner g_sav_test_runner;

void Rtk2SavTestRunner_Start(Rtk2SaveTestRunner* x);
void Rtk2SavTestRunner_StateMachine_Run(Rtk2SaveTestRunner* x, bool is_replay);
void Rtk2SavTestRunner_ResolveSnapshotFail(Rtk2SaveTestRunner* x, bool has_failed);