# Code Flow
This document describes the top level flow of the port code.

## Main
The `main()` function is the entry point of the program. Here, many things are initialized and the game loop is started.
The sequence of events is roughly as follows:
1. Parse the configuration file and set up the options.
2. Initialize the window, audio, and inputs.
3. Load the rom and initalize the SNES. Here, all the bytes which need to be patched are patched, and `RtlRunFrameCompare()` is
   stored into `g_rtl_runframe` via `RtlSetupEmuCallbacks()` (this is not directly apparent via the main function).
4. Create the window and audio threads.
5. Read the save data.
6. Enter the program loop.
	1. Get the inputs from keyboard and controller.
	2. Pause or unpause the window and audio threads.
	3. Process the controller inputs.
	4. Run a frame of the game via `RtlRunFrame()`.
	5. Draw the frame.
	6. Display the bug counter, if needed.
	7. Adjust the frame rate (since the SNES does not run at exactly 60 FPS).
7. Clean up and exit.

## Run Frame
The `RtlRunFrame()` function is the main function that runs a frame of the game. It handles whether a replay is happening
or a bug has occured. More importantly, `RtlRunFrameCompare()` is called via `g_rtl_runframe`.
`RtlRunFrameCompare()` determines whether to run a frame of the port, a frame of the SNES emulator, or both.
If both are to run, then the SNES emulator is run first, followed by the port, then the results of RAM are compared.
If the RAM is different, then the SNES result is used, the results that are different is shown, and a bug save state is made.
In either case, a frame of the game is run, and then that frame is drawn to the PPU.
The entry point for the port game code is `RunOneFrameOfGame()` (which is at `0x828948`).