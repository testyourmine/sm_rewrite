# sm

For build instructions see [BUILDING](./BUILDING.md). For more information about the original port, see: https://github.com/snesrev/sm.

This is a fork of the Super Metroid PC Port meant to continue the work and add more features. There are various goals intended for this project, including:
1. Giving all functions and variables proper names. (work has been made on functions, but not on variables as of yet)
2. Removing all the calls to read code directly from rom. (some progress has been made removing RomPtrs, but much more work is to be done)
3. Adding MSU-1 support. (early support has been added, but is not perfect and currently disables mismatch checking)
4. Adding widescreen and overscan support. (no work yet)

The fork is still very early in development and there is much to be done. Outside of early MSU-1 support, there is not much improvement on the player side.
Any contributions, even as simple as giving a function or a variable a proper name, is welcome. The bank logs are a great resource for this: https://patrickjohnston.org/bank/.

Note about Port_Extraction folder:
Port_Extraction is currently a scratchpad to manually extract assets from the rom and insert them into the port.
In the long run, this will be used to automatically extract all necessary assets from the game.

