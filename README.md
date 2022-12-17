# Monty - The monty program | Alx 0x19. C - Stacks, Queues 

Monty is an interpreter of Monty ByteCodes files, which is a scripting language just like Python.

## Description 

Monty is a language that contains specific instructions to manipulate data information (stacks or queues), where each instruction (called opcode) is read amd executed per line. Files which contains Monty byte codes usually have the .m extension.

#### Example
```
	$ cat file.m
	# Pushing element to the stack
	push 0
	push 1
	push 2
	# Printing all elements
	pall
	push 3
	push 4
	pop
	# Rotating the stack to the bottom
	rotr
	pall
	rotl
	# Setting FIFO
	queue
	push 5
	# Setting LIFO
	stack
	push 5
	$
```

## Technologies

* Interpreter was written with C language.
* Scripts written in Bash 5.0.17(1)
* C files are compiled using gcc 9.4.0
* C files are written according to the C90 standard
* Tested on Ubuntu 20.04 LTS

## Usage

To compile all files:
```
	$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
	$
```

The synopsis of the interpreter is the following:

```
	$ ./monty [filename.h]
	$
```

## Features - Opcodes
 
`Monty` executes the following opcodes:

Opcode | Description
--- | ---
`push` | Pushes an element to the stack
`pall` | Prints all the element value's on the stack
`pint` | Prints the element at the top of the stack
`pop` | Removes the top element of the stack
`swap` | Swaps the top two elements of the stack
`queue` | Sets the format of the data to a queue (FIFO)
`stack` | Sets the format of the data to a stack (LIFO)
`nop` | Doesn't do anything
`add` | Adds the top two elements of the stack
`sub` | Subtracts the top element of the stack from the second top element of the stack
`mul` | Multiplies the second top element of the stack with the top element of the stack
`div` | Divides the second top element of the stack by the top element of the stack
`mod` | Computes the rest of the division of the second top element of the stack by the top element of the stack
`pchar` | Prints the char at the top of the stack
`pstr` | Prints the string starting at the top of the stack
`rotl` | Rotates the stack to the top
`rotr` | Rotates the stack to the bottom

Comments, indicated with #, are not ignored by the interpreter.

When an **invalid opcode**  is passed, the interpreter prints an error message and stops:

```
$ cat errorfile.m
push 1
pint
pcx
$ ./monty errorfile.m
1
L3: unknown instruction pcx
```

### Return value
	
When there is no errors, monty returns 0. Otherwise, returns 1.

## Author
* Boluwatife E. Oyewumi -> [Twitter](https://twitter.com/Bolexzyy__)
