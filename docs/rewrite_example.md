# Example of rewriting a function
In this document, I'll show an example of how to rewrite and document a function.
For this, the [bank logs](https://patrickjohnston.org/bank/index.html) will be a valuable resource
for understanding what the function does and what some of the variables mean, and to keep some names
interoperable so things are easier to compare.
This is not a specific step by step or an order to do things in, this is just an example of a process.
So to start off, here is the function we will be rewriting from the original code (some functions may already be partially
cleaned up from enumerations and renaming, so we will assume a completely untouched function):

```C
void OptionsMenuControllerFunc_0(void) {  // 0x82F6B9
  uint16 v0 = 12;
  while ((word_82F575[v0 >> 1] & joypad1_newkeys) == 0) {
    v0 -= 2;
    if ((v0 & 0x8000) != 0)
      return;
  }
  uint16 r18 = v0 >> 1;
  uint16 v1 = 2 * menu_option_index + 2;
  if (!sign16(2 * menu_option_index - 12))
    v1 = 0;
  uint16 v2 = v1;
  for (int i = 5; i >= 0; --i) {
    if (eproj_F[(v2 >> 1) + 13] == r18)
      break;
    v2 += 2;
    if ((int16)(v2 - 14) >= 0)
      v2 = 0;
  }
  int v4 = menu_option_index;
  uint16 r20 = eproj_F[v4 + 13];
  eproj_F[v4 + 13] = r18;
  eproj_F[(v2 >> 1) + 13] = r20;
  OptionsMenuFunc6();
}
```
One of the first things that should be done is renaming the function. From the bank logs, we can see that the function sets
controller bindings, so we would rename the function to `OptionsMenuControllerFunc_SetBinding`, which keeps the original
port naming scheme. The next thing would be to rename the array, which from the bank logs we would name something like
`kControllerInputMasks`. Names should be similar to the bank logs to keep things consistent, but can be made shorter
or named to keep it consistent with what the port uses. I'm not sure why the array is the type `Buttons`, but it should
be made a `uint16` in order to keep the size consistent with the original code, which is 2 bytes.
For reference, here is what the array looks like now:
```C
static const uint16 kControllerInputMasks[9] = {  // 0x82F558
  kButton_X,
  kButton_A,
  kButton_B,
  kButton_Select,
  kButton_Y,
  kButton_L,
  kButton_R,
  kButton_Left,
  kButton_Right,
};
```

At this point, we can start making our way down from the top. The bank logs doesn't explicitly say what v0 is,
but it can be inferred that it represents the index into the array, so we could call it something like `binding_idx`,
where "idx" is shorthand for "index". Next, we can see that `if ((binding_idx & 0x8000) != 0)` looks kind of funky.
Here, the purpose of `& 0x8000` is to check the signedness, since in binary the most significant bit
represents the signedness of a number, where 0 is positive and 1 is negative. Since it's checking for nonzero, it means
that the statement is true if `binding_idx` is negative. Thus, this can be rewritten to `if (binding_idx < 0)`.
However, with our current code this would not work, since `binding_idx` is a `uint16`, which is unsigned. So, we can
either make `binding_idx` an `int16`, or cast it in the if statement, which would look like `if ((int16)binding_idx < 0)`.
In this case, it would be better to change the type to `int16`. Next, we can rename `r18` to `new_binding`, which can be both
seen from the bank logs, and inferred as when the while loop breaks, it means we found a nonzero bitmask for the binding.

You might have noticed that the array is 9 entries long (or 18 bytes), yet we only go up to entry 7 (zero indexed).
Here, we should note that we exclude the left and right dpad entries. While we're at it, we should also note that the
purpose of this block of code is to find the new button that was pressed, which we would explain in a comment.
Now, our rewritten snippet should look like this:
```C
// Get the new button pressed, excluding the left and right dpad
int16 binding_idx = 12;
while ((kControllerInputMasks[binding_idx >> 1] & joypad1_newkeys) == 0) {
  binding_idx -= 2;
  if (binding_idx < 0)
    return;
}
uint16 new_binding = binding_idx >> 1;
```

Now, the next few lines may seem a bit confusing, and the bank logs doesn't exactly explain what is going on.
Let's start with `if (!sign16(2 * menu_option_index - 12))`. Here, `sign16` is macro that's a shorthand for `& 0x8000`,
and the `!` is a logical not, so it's true if it's 0, since !0 is 1, which is true.
So the if statement is checking if `(value & 0x8000) == 0`, which from before we know means that `value >= 0`.
However, we can also not that the value in the if statement is similar to `uint16 v1 = 2 * menu_option_index + 2`,
so we can replace the value inside the paranthesis with `v1 - 14`, where we have to subtract 2 to account for the added 2
in v1. Now we have `if ((v1 - 14) >= 0)`, which using arithmetic, is `if (v1 >= 14)`. Now that the code is cleaned up a bit,
we can see that it appears that `v1` is the next menu option index, and is reset back to 0 if the index reaches 14.
So, we can rename `v1` to something like `next_option_down`. We can also see that `v2 = v1` is useless since
`v1` isn't referenced again, so we can replace all instances of `v2` with `v1`.
It should be noted that the value 14 indicates that we have gone past the last binding option, which we can comment about.
With everything cleaned up, we have that:
```C
// Go back to first binding if gone past the last binding
uint16 next_option_down = 2 * menu_option_index + 2;
if (next_option_down >= 14)
  next_option_down = 0;
```

Now, the for loop. This is an instance where the port uses an odd variable here that doesn't seem to make much sense.
We can either verify ourselves, or reference with the bank logs, that `eproj_F[(next_option_down >> 1) + 13]` should really be
`something[next_option_down >> 1]`, where something is at 0x1B3D, which we can see in the bank logs, and can verify
since `eproj_F` is at 0x1B23, and it is a `uint16` pointer, so `0x1B23 + 2 * 13 = 0x1B3D`. Here, we could make a variable
in `variables.h`, but there is actually already a variable located in `variables_extra.h` called `optionsmenu_input_bindings`
which defines this for us. So now we have `optionsmenu_input_bindings[next_option_down >> 1]`. The line
`if ((int16)(next_option_down - 14) >= 0)` can be simplified to `if (next_option_down >= 14)` using arithmetic,
and the `int16` can be removed since here signedness doesn't matter. As well, the for statement can be rewritten
to be more standard since the `i` variable is not used for anything else except the for statement.
Putting it all together, we have:
```C
for (int i = 0; i < 6; --i) {
  if (optionsmenu_input_bindings[next_option_down >> 1] == new_binding)
    break;
  next_option_down += 2;
  if (next_option_down >= 14)
    next_option_down = 0;
}
```

We're nearly done. We can see here that there's some odd temporary variable stuff happening here, which was probably necessary
in the original code, but we can simplify here. First, we can replace all instances of `eproj_F[x + 13]` with
`optionsmenu_input_bindings[x]`. Next, we can simplify this a bit by moving `optionsmenu_input_bindings[v2 >> 1] = r20`
up so that we don't have to back anything up, and then replacing `r20` in the assignment and removing the variable.
Since `v4` is just a reassignment, we can go ahead and replace `v4` in the array index and get rid of the assignment.
The naming of `OptionsMenuFunc6()` may already have been fixed, but if it hasn't then you don't need to worry about it.
For reference though, in the rewrite the code was renamed to `OptionsMenuFunc6_DrawControllerBindings()` (this name is subject
to change).
Now, the code is simplified to:
```C
optionsmenu_input_bindings[next_option_down >> 1] = optionsmenu_input_bindings[menu_option_index];
optionsmenu_input_bindings[menu_option_index] = new_binding;
OptionsMenuFunc6_DrawControllerBindings();
```

The next step would be to provide documentation above the function. There is no return type or parameters, so the
comment will only consist of a brief, which would state something like `Sets the current option to the new binding
and sets the option that has the same binding as the new one with what was originally in the current option`.
Finally, the rewritten code and documented code should look like this:
```
/**
* @brief Sets the current option to the new binding and sets the option that has the same binding as the new one
* with what was originally in the current option
*/
void OptionsMenuControllerFunc_SetBinding(void) {  // 0x82F6B9
  // Get the new button pressed, excluding the left and right dpad
  int16 binding_idx = 12;
  while ((kControllerInputMasks[binding_idx >> 1] & joypad1_newkeys) == 0) {
    binding_idx -= 2;
    if (binding_idx < 0)
      return;
  }
  uint16 new_binding = binding_idx >> 1;

  // Go back to first binding if gone past the last binding
  uint16 next_option_down = 2 * menu_option_index + 2;
  if (next_option_down >= 14)
    next_option_down = 0;
  }

  for (int i = 0; i < 6; --i) {
    if (optionsmenu_input_bindings[next_option_down >> 1] == new_binding)
      break;
    next_option_down += 2;
    if (next_option_down >= 14)
      next_option_down = 0;
  }
  optionsmenu_input_bindings[next_option_down >> 1] = optionsmenu_input_bindings[menu_option_index];
  optionsmenu_input_bindings[menu_option_index] = new_binding;
  OptionsMenuFunc6_DrawControllerBindings();
}
```

With that, the function is now fully rewritten and documented. At this point, it is recommended to test the function works,
in this case by going into the controller options menu and messing around to make sure nothing breaks.
There's some optional things you can do, such as representing indexes as `x*2` (so 14 would be `7*2`),
or representing `binding_idx = 12` as `binding_idx = sizeof(kControllerInputMasks) - 6` or something similar,
but these may or may not end up making the code more confusing.

These functions can sometimes be very long and confusing, so good luck!