# ft_printf

:books: [Introduction](#introduction)

:collision: [New concept](#new-concept): Variadic functions

:eyes: [Specifiers and flags](#specifiers-and-flags)

## Introduction
The aim of the ft_printf proyect is to recode the libc`s printf function 
("print formated") for what we need to get familiar with variadic functions. 

The prototype of this function is:

```C
int printf(const char *format, ...);
```
where format contains format tags (specifiers and flags) that are replaced by the values 
specified in subsequent additional argument and formatted as needed. The format tags prototype is



## New concept : Variadic functions
A variadic function is a special type of function that takes a variable number of arguments.
In order to handle a variable number of arguments the following functions are used:
|Function|Description|
|:------:|:---------:|
|``void va_start(va_list ap, last_arg);``| Initializes ap variable that hold the information needed to retrieve the additional arguments. For that, the last known fixed argument being passed to the function (last_arg) is needed.|
|``type va_arg(va_list ap, type);``| Retrieves the next argument in the parameter list of the function with the given type.|
|`` void va_end(va_list ap)`` |  Modify ap so that it is no longer usable.|


## Specifiers and flags
The string argument that contains the text to be written to stdout contain
This implementation manage the following specifiers:
|Conversions|Description|
|:---------:|:---------:|
|``%c`` | singel character |
|``%s`` | string of characters|
|``%p`` | pointer address|
|``%d`` | signed decimal (base 10) integer |
|``%i`` | signed decimal integer |
|``%u`` | unsigned decimal integer|
|``%x`` | unsigned hexadecimal (base 16) integer|
|``%X`` | unsigned hexadecimal integer (uppercase)|
|``%%`` | percent sign|

And the following flags:
|Flags|Description|
|:---------:|:---------:|
|``width`` | singel character |
|``precision`` | string of characters|
|``-`` | pointer address|
|``0`` | signed decimal (base 10) integer |
|``.`` | signed decimal integer |
|``#`` | unsigned decimal integer|
|`` `` | unsigned hexadecimal (base 16) integer|
|``+`` | unsigned hexadecimal integer (uppercase)|
