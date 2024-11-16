
# Big Integer Calculator in C

This project implements a Big Integer Calculator using linked lists in C. It supports basic operations such as addition, subtraction, multiplication, division, power, square, cube, square root, and factorial on large integers that cannot be represented by traditional integer types.

## Features

- **Addition of Big Integers**
- **Subtraction of Big Integers**
- **Multiplication of Big Integers**
- **Division of Big Integers**
- **Exponentiation (Power) of Big Integers**
- **Square of Big Integers**
- **Cube of Big Integers**
- **Square Root of Big Integers**
- **Factorial of Big Integers**

The program uses linked lists to represent large integers, where each node contains a single digit.

## Functions

### Utility Functions:
- **reverse()**: Reverses a linked list of digits.
- **createnode()**: Creates a new node with a given integer value.
- **printlist()**: Prints the linked list (big integer).
- **inputbigint()**: Reads a large integer from the input and stores it in a linked list.
- **toint()**: Converts a linked list (big integer) to an integer.
- **copyBigInt()**: Creates a copy of a given big integer.
- **remove_initial_zeros()**: Removes any leading zeros from a linked list representing a big integer.
- **compare()**: Compares two big integers and returns:
  - `1` if the first integer is greater.
  - `-1` if the second integer is greater.
  - `0` if both integers are equal.
- **freeBigInt()**: Frees the memory allocated for a big integer linked list.
- **length()**: Returns the length of a linked list (big integer).
- **recieve_quotient()**: Compares two linked lists representing numbers and returns `1` if the first number is greater or equal, and `0` otherwise.
- **iszero()**: Checks if a big integer is zero.
- **appendnode()**: Appends a new node to the end of a linked list.
-  **quotient_genreator()**: Generates the quotient for division.

### Arithmetic Operations:
- **addint()**: Adds two big integers.
- **subint()**: Subtracts the second big integer from the first.
- **multiply_int()**: Multiplies two big integers.
- **divide()**: Divide two big integers.
- **square_int()**: Computes the square of a big integer.
- **cube_int()**: Computes the cube of a big integer.
- **power_int()**: Computes the exponentiation of one big integer raised to the power of another.
- **factorial()**: Computes the factorial of a big integer.
- **sqrt_int()**: Computes the square root of a big integer.

## Compilation

To compile the project, use the following command:

```bash
gcc library.c -o bigint_calculator
```

## Running the Program

To run the program, execute the following command:

```bash
./bigint_calculator
```

## Installation

### Prerequisites:
- Install a C compiler such as **GCC**.
  - On **Ubuntu/Debian**: You can install GCC using the following command:
    ```bash
    sudo apt-get install gcc
    ```

### Steps to run the program:

1. **Clone or Download the Source Code:**
   - You can download or clone the project from the repository (if applicable), or directly copy the provided `library.c` file.

2. **Compile the Program:**
   - Open your terminal or command prompt and navigate to the folder where the source code is stored.
   - Run the following command to compile the C program:
     ```bash
     gcc -o bigint_calculator library.c
     ```
   - This will generate an executable file named `bigint_calculator`.

3. **Run the Program:**
   - To run the program, use the following command:
     ```bash
     ./bigint_calculator
     ```
   - This will start the Big Integer Calculator.

## Usage

Once the program is running, you will be prompted to select one of the following operations:

- **Addition** - Add two big integers.
- **Subtraction** - Subtract one big integer from another.
- **Multiplication** - Multiply two big integers.
- **Division** - Divide two big integers (not implemented in this version).
- **Power** - Raise a big integer to the power of another.
- **Square** - Calculate the square of a big integer.
- **Cube** - Calculate the cube of a big integer.
- **Square Root** - Calculate the square root of a big integer.
- **Factorial** - Calculate the factorial of a big integer.
- **Exit** - Exit the program.

### How to Enter Big Integers:
When prompted for a big integer, enter the number as a sequence of digits (without any spaces). For example:
```bash
1234567890
```

### Example Usage:

#### Addition:
1. Choose **1. Addition**.
2. Enter the first big integer:
   ```bash
   123456789012345
   ```
3. Enter the second big integer:
   ```bash
   987654321098765
   ```
   - The program will display the result of the addition.

#### Subtraction:
1. Choose **2. Subtraction**.
2. Enter the first and second big integers as above, and the program will subtract the second from the first.

#### Multiplication:
1. Choose **3. Multiplication** and enter two big integers.

#### Division:
1. Choose **4. Division** and enter two big integers.

#### Power:
1. Choose **5. Power** and enter:
   ```bash
   2
   10
   ```
   - Result: `1024`

#### Factorial:
1. Choose **9. Factorial** to compute the factorial of a number. For example:
   ```bash
   5
   ```
   - Result: `120`

## Limitations

- **Division** algorithm is not efficient and have bugs.
- The program **does not handle negative numbers**.
- Some functions like **factorial are not optimized for very large integers** in terms of performance.

## Contributing
Contributions are welcome! Fork the repository and submit pull requests for new functions or bug fixes.

