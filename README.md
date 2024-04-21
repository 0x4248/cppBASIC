# cppBASIC

A simple BASIC like interpreter in C++

## Features

- Variables
- Arithmetic operations
- Print

## Usage

To open cppBASIC, run the following command:

```cpp
./cppBASIC
```

This will open a terminal with the cppBASIC interpreter. You can now type in your BASIC code.

## Example

```BASIC
10 LET A = 5
20 LET B = 10
30 PRINT ADD A B
```

Then run this

```
RUN
```

The output will be:

```
15
```

## CLI Commands

- `RUN`: Run the program
- `LIST`: List the program
- `CLEAR`: Clear the screen
- `NEW`: Clear the program
- `QUIT`: Quit the interpreter

## Program commands

- `LET`: Assign a value to a variable `LET A = 5`
- `PRINT`: Print a value `PRINT A`

### Arithmetic operations

These can be used in the `PRINT` and `LET` command.

- `ADD`: Add two variables `ADD A B`
- `SUB`: Subtract two variables `SUB A B`
- `MUL`: Multiply two variables `MUL A B`
- `DIV`: Divide two variables `DIV A B`

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENCE](LICENCE) file for details
