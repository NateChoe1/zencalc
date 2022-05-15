# How Zen calculator works

Zen calculator is operated by repeatedly typing the `make` command. The
calculator is controlled by the time that the command is run. Only the second
part of the time is read, everything else is ignored. Zen calculator uses a
stack based postfix notation to get inputs.

    XX:XX:00:            +
    XX:XX:01:            -
    XX:XX:02:            *
    XX:XX:03:            /
    XX:XX:04:            Push current number
    XX:XX:06 - XX:XX:09: Delete entire stack

For any other value, the final digit of the second hand is appended to the
current number. The calculator uses a stack based postfix notation.

Example timeline:

Code was compiled at:
    3:12:14
    3:12:22
    3:12:30
    3:13:04
    3:13:16
    3:13:19
    3:14:04
    3:15:02

Equivalent dc command:
    420 69 *

If at any point you need to restart your calculator, simply run `make restart`.

# How do I get the results of my calculation?

Just read the very human readable resulting source code in `scratch.c`

# Why did you make this

No clue.

# Should I use this calculator?

No.

# Did you learn anything from making this?

No.

# Was this worth your time

Probably not.

# What time are you writing this?

10:21 am but I've been awake all night writing this thing.
