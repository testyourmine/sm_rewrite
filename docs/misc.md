This is for information that I have not yet categorized.

# Indexing arrays
A common thing that appears when indexing arrays is right shifting the indexer.
This occurs because the way arrays are indexed in the original assembly code is different than how it is in C.
In the original assembly code, arrays are indexed by bytes, thus the index is twice as large as it should be.
As an example, the assembly array `.org $89ABCD dw 1234, 5678, 9ABC` would be indexed by `LDA $ABCD, x` in the original code.
Since the assembly is byte addressable, the index in x must be 2 times the index. So x = 0 gets the first word (bytes 0 and 1),
x = 2 gets the second word (bytes 2 and 3), and x = 3 gets the third word (bytes 4 and 5).
In C, arrays are indexed based on the size of the type.
So, this same array would appear as `uint16 array[] = { 0x1234, 0x5678, 0x9ABC }`.
Here, array[0] gets the first word (0x1234), array[1] gets the second word (0x5678), and array[2] gets the third word (0x9ABC).
So, to convert the original assembly code to C, the index must be right shifted by 1.
To get the first word using the same index values as the assembly,
it would be accessed as `array[0 >> 1]`, the second word as `array[2 >> 1]`, and the third word as `array[4 >> 1]`.
Thus, the original `LDA $ABCD, x` would be `array[x >> 1]` in C.

When converting assembly code to C, it is preferable to keep the original index values to better match the assembly code.
When the same index is used multiple times, it is better to store the shifted index in a variable to avoid multiple shifts.
So, `array[x >> 1]` would be `int index = x >> 1; array[index]`.
As well, when the index in the original assembly code is already shifted, it should not be shifted again in C.
So, since area_index, which represents what area you are in, is stored as 0 through 7, arrays which are indexed
by area_index should not be shifted in the C code, even though it may be shifted (to the left) in the original assembly code.

# Constants and Macros
Values which represent constants, such as the number of PLMs, should be defined as constants using macros.
As well, constants which represent bit flags should be defined as macros. They can either be defined using hex values or bit shifting.
For example, `#define BLK_X_FLIP 0x4000` could also be defined as `#define BLK_X_FLIP (1 << 14)`.
Operations which follow a pattern and are performed multiple times should be defined as macros.
For example, the operation `level_data[index] = level_data[index] & 0xFFF | 0xX000;` is performed multiple times.
Thus, this operation could be defined as a macro,

`#define SET_BLK_TYPE(blk, blk_type) ((blk) & ~(0xF000) | ((blk_type) << 12))`,

where `~(0xF000)` shows that its clearing the top 4 bits, and `((blk_type) << 12)` shows that its setting the top 4 bits.
So the original operation would be replaced with `level_data[index] = SET_BLK_TYPE(level_data[index], X);`, where
`X` would be the block type (likely described using an enumeration).
Macro names should be descriptive and in all caps. The current convention is to keep them in header files, but this may change.

# Code cleanup tips
Here are some tips and conventions for cleaning up code:
- In instances where a variable is checked against 0x8000 (sometimes represented as sign16(var)),
  this usually indicates its checking if the negative bit is set. This can be replaced with a check against 0.
  For example, `if ((index & 0x8000) != 0)` can be replaced with `if (index < 0)`. Note that in this case, if `index` was
  originally an unsigned integer, it should either be changed to a signed integer or sign casted. However, checks against 0x8000 sometimes
  indicates that it's checking for a flag, in which case the `0x8000` should be replaced with a macro that describes the flag.

- Most of the time, when the code does something like `if ((x & 0xFF00) == 0)`, it usually means it is checking the high byte.
  However, there are a few instances where it is a shorthand for `if (0 <= x && x < 0x100)`. This is because by masking out
  the low byte, it can check if any bit above 0x00FF is set. This means that any value from 0x100 onward will make the
  condition false, and any negative value will also cause the condition to be false since negative values sets 0x8000.
  This check is most often used when checking location of an object on screen, however it may be used for other purposes.
  If it's not entirely clear whether this is the case, consulting the bank logs is a good choice.

- Some while and do while loops can be replaced with for loops. For example, `int index = 0; while (index < 10) { ...; index++; }`
  can be replaced with `for (int index = 0; index < 10; index++) { ... }`. However, this is not always the case, especially
  when the order of iterating and checking is not the same.

- When comparing values, it is important to note what the sign of the values should be. Often, the port code does something like
  `if ((int16)(x - y) >= 0)`, which could be reduced to `if (x >= y)`, casting to `int16` if they are not already of that type.
  Currently, I do not know if all instances of these need to be signed or unsigned. So, when simplifying these,
  check with the original code the type of comparison it does. If it uses `BCC/BCS`, then the comparison is unsigned.
  If it uses `BPL/BMI`, then the comparison is signed.

- Whether a number is expressed in decimal or hex is up to interpretation. Generally, numbers that are used as bit flags
  are expressed in hex. Sequences of numbers which seem random in decimal but line up nicely in hex should be expressed in hex,
  and vice versa. 

- Some operations can be reduced or simplified to make it clearer what the operation is doing. It is generally fine to do so,
  but for the time being, the original operation should be kept in a comment, and additional comments should be added to show
  how the reduction was arrived at.

- This is not the same case for other reductions that rely on functions such as IntMin(). Those can replace the original code,
  as long as the function is well documented and tested.

- The general layout for doxygen comments at the top of functions should be as follows:
```
/**
* @brief A brief description of the function
* @param1 A description of the first parameter
* @param2 A description of the second parameter
* @return *type* description of the return value
*/
```
- Commenting in the middle of functions is fine, especially if its clarifying what a block of code or a condition is doing.