# Coroutines

Coroutines are used to represent non-maskable interrupts in C.
Like other implementations, the purpose of a coroutine is to allow a function to be paused and resumed at a later time.
They are defined as macros in types.h, and the following commands are available:
- `COROUTINE_BEGIN(state_var, start_pos)`
  - This begins the coroutine. state_var keeps track of the current position in the coroutine, and start_pos is the position to start at.
- `COROUTINE_MANUAL_POS(position)`
  - This manually sets the position to resume the coroutine 
- `COROUTINE_AWAIT(position, function)`
  - This waits for a coroutine to finish. The position is the position to resume at if the function is not finished, and function is the function to return.
- `COROUTINE_AWAIT_ONLY(function)`
  - This waits for a coroutine to finish, but does not store the position to resume at.
- `COROUTINE_END(position)`
  - This ends the coroutine. The position is the position the coroutine finished at. It returns 0, indicating the coroutine is finished.

Coroutine states are stored in the `coroutine_state_x` variables, where x is the coroutine number, ranging from 0 to 4.
The boolean variable `coroutine_completion_flags` is used in `WaitForNMI_Async()` and `WaitForNMI_NoUpdate_Async()`
to determine if a coroutine has finished.

More research is needed to have a better understanding of coroutines and the various positions possible.