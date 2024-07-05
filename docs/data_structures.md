# Data Structures
This is a high level overview of some of the data structures used.

## Objects
Objects are used to define various data structures in the game. They come in many different forms and define many different things.
They usually contain a pre-instruction function that initalizes the object, and a pointer to the instruction list that
processes the object.

## Instruction Lists
Instruction lists are used in many different capacites in the game. An instruction list is a list of instructions that
defines how an object is processed. Instructions usually come in two flavors: special instructions, which are usually used to
draw the object, and function instructions, which contains a function and parameters to be called.

In the original game, instruction lists are accessed via pointers, and those pointers are incremented and stored in RAM.
Since PC architecture is different from the SNES, pointers to instruction lists can't be stored the same way.
Instead, the instruction lists are represented as switch case statements, in order to keep the original SNES functionality the same.
Typically, the instruction list pointer is passed, and whatever the original address was is represented as a case. For instance,
if the original instruction list pointer was at 0x89AC, the case would be 0x89AC and would return the instruction at that address.

