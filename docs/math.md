# Math
This is a WIP document describing some of the mathematical concepts used in the game's code.

## Trigonometric math
In Super Metroid, trigonometry is used often to calculate angles and distances. Since the original game is in binary,
a different system is used from what is normally used in trig. In trig, the two common angular units are degrees and radians,
where a full turn is 360&deg; or 2&pi; rads, and the conversion between the two is  degrees = radians \* (180&deg; / &pi;) 
and radians = degrees \* (&pi; / 180&deg;).

However, since we have a different counting system, we instead use binary degrees (bdegrees).
In this system, a full turn is now 0x100 binary degrees, so now we have that radians = bdegrees \* (&pi; / 0x80).
So as an example, if we had a variable `bangle` in bdegrees and a variable `distance`, the formula
`y_distance = distance * sin(bangle * pi / 80h)` would be equivalent to `y_distance = distance * sin(angle)`, where angle is
now in standard radians.

## Color interpolation
WARNING: BAD EXPLANATION, REDO THIS LATER
Given two points $(x_0, y_0)$ and $(x_1, y_1)$, we want to an equation that can find any point $(x, y)$ along a straight line between the two points.
Such an equation can be found using the linear interpolation formula, which is as follows:
$y = y_0 + \frac{(x-x_0) * (y_1-y_0)}  {(x_1 - x_0)}$, where $(x - x_0)$ is the x distance from the origin, $(y_1 - y_0)$ is the vertical component, and $(x_1 - x_0)$ is the horizontal component.
In the case we are using, the origin $(x_0, y_0)$ is always at $x_0 = 0$, which simplifies the equation to:
$y = y_0 + \frac{x * (y_1-y_0)}  {x_1} = y_0 + (y_1-y_0)*\frac{x}  {x_1}$.
The purpose of all this is that we want to get the color(s) between two colors in a color space (this is used for gradients), which can be achieved using linear interpolation.
Let's set $x$ = pal_change_numer, $y$ = color_trans_component, $y_0$ = src_pal_color, $x_1$ = palette_change_denom, and $y_1$ = dst_pal_color.
Now using the linear interpolation on the color space, we get:
$color\_trans\_component = src\_pal\_color + (dst\_pal\_color - src\_pal\_color)*\frac{pal\_change\_numer} {palette\_change\_denom}$.
In other words, given:
- source color
- target color
- palette change denominator, which represents the amount of color steps between the source and target
- palette change numerator, which represents the color step between the source and target

then plugging into the equation will give us the numerator[th] color between the source and target colors.