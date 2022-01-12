# ft_printf

:books: [Introduction](#introduction)

:eyes: [Specifiers and flags](#specifiers-and-flags)

:collision: [New concept](#new-concept): Variadic functions



## Introduction
The aim of the ft_printf proyect is to recode the libc`s printf function 
("print formated") for what we need to get familiar with variadic functions. 

The prototype of this function is:

```C
int printf(const char *format, ...);
```
where format contains format tags (specifiers and flags) that are replaced by the values 
specified in subsequent additional argument and formatted as needed. The format tags prototype is:
<img height=40 align=center src="https://user-images.githubusercontent.com/71781441/149183604-a15b6f20-62c0-4e2d-ad3c-1be8d157d494.jpg" >

On success, the total number of characters written is returned.

## Specifiers and flags
The string argument that contains the text to be written to stdout contain
This implementation manage the following specifiers:
|Conversions|Description|Type|
|:---------:|:---------:|:--:|
|``%c`` | single character |int|
|``%s`` | string of characters|char*|
|``%p`` | pointer address|void*|
|``%d`` | signed decimal (base 10) integer |int|
|``%i`` | signed decimal integer |int|
|``%u`` | unsigned decimal integer|int|
|``%x`` | unsigned hexadecimal (base 16) integer|unsigned int|
|``%X`` | unsigned hexadecimal integer (uppercase)|unsigned int|
|``%%`` | percent sign|

And the following flags:
|Flags|Description|
|:---------:|:---------:|
|``width`` | Specifies the minimum number of characters to be printed. The result is padded with blank spaces if necessary. The value is not truncated even if the result is longer.|
| ``*``| The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|
|``.precision`` | For integer specifiers (d,i,u,x,X), precision specifies the minimum number of digits to be written. The result is padded with leading zeros if necessary The value is not truncated even if the result is longer.For s specifier, this is the maximum number of characters to be printed.|
|``.*``| The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|
|``-`` | Left-justify within the given field width.|
|``0`` | Left-pads the number with zeroes instead of spaces when padding is specified.|
|``#`` | The value is preceeded with 0x or 0X (used with x or X specifiers) for values different than zero.|
|`` `` | If there's no sign, a blank space is inserted before the value.|
|``+`` | Forces to preceed the result with a plus or minus sign.|
|``l``| Modifies the length of the data type. For d and i specifiers, takes an int but converts it into a long int. For u,x and X specifiers, convert it into an unsigned long int. And for s specifier, converts it into wchar_t*.|
|``h``| Modifies the length of the data type. For d and i specifiers, takes an int but converts it into a short int. For u,x and X specifiers, convert it into an unsigned short int.|

To format the output, the const char* is iterated and printed until a percent sign (``%``) is found. Then, all the flags found are parsed and the related information is kept in a struct until the end of the string is reached or a specifier is found.


## New concept
A variadic function is a special type of function that takes a variable number of arguments.
In order to handle a variable number of arguments the following functions are used:
|Function|Description|
|:------:|:---------:|
|``void va_start(va_list ap, last_arg);``| Initializes ap variable that hold the information needed to retrieve the additional arguments. For that, the last known fixed argument being passed to the function (last_arg) is needed.|
|``type va_arg(va_list ap, type);``| Retrieves the next argument in the parameter list of the function with the given type.|
|`` void va_end(va_list ap)`` |  Modify ap so that it is no longer usable.|
