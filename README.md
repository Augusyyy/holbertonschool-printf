# <p align="center">holbertonschool_printf</p>

## Outline
In c, rebuild the standard 'printf' function. We call the _printf function and our task requires a function that prints the '%d, %c, %s, %i, %o, %u, %x, %X, %%, %p, %b, %r, %R, %S specifiers to standard output.

### Supported Format Types

| Type  | Output |
|:-----:|:------:|
| c | char type |
| s | string type |
| d | integer decimal base10|
| i | integer decimal base10|
| o | integer base8 |
| u | unsigned integer bas10|
| x | integer base16 lowercase|
| X | integer base16 uppercase |
| % | percent sign |
| p | pointer |
| b | integer base2 |
| r | flashback output string |
| R | rot13 output string |
| S | escape character output in base16 |



### Test Case
It's an exemple 

```
 int len,len2;
    unsigned int ui;
    void *addr;
    void *addr1;

    ui =(unsigned int)INT_MAX + 1024;
    addr =(void *)0x7ffe637541f0;
    addr1 = (void *)0x7ffe63333333;

    /**
     * char type %c
     * char flags：support - 0 space
     * char with：support
     * char precision ：nonsupport
     * char l h nonsupport
     */

    len = _printf("%c\n",'a');
    len2 = printf("%c\n",'a');
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    len = _printf("%c,%c,%c\n",'a','b','c');
    len2 = printf("%c,%c,%c\n",'a','b','c');
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    len = _printf("%010c,%-10c,%-010c\n",'a','b','c');
    len2 = printf("%010c,%-10c,%-010c\n",'a','b','c');
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);


    /**
     * string type %s
     * string flags：support - 0 space -0无法配套使用
     * string with：support
     * string precision ：support
     * string l h nonsupport
     */
    len = _printf("%s and %s %s\n","Lucy","Jack","are friend");
    len2 = printf("%s and %s %s\n","Lucy","Jack","are friend");;
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    len = _printf("%010s and %-010s %- 10.2s\n","Lucy","Jack","are friend");
    len2 = printf("%010s and %-010s %- 10.2s\n","Lucy","Jack","are friend");
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    /**
     * digit  type %d %i
     * digit flags：support + - 0 space #
     * digit with：support
     * digit precision ：support
     * digit l h support
     */
    len = _printf("%d, %d, %d\n",-11111,-22222,-33333);
    len2 = printf("%d, %d, %d\n",-11111,-22222,-33333);
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    len = _printf("%-010d, %010d, %hd\n",-11111111,-2222222,-33333);
    len2 = printf("%-010d, %010d, %hd\n",-11111111,-2222222,-33333);
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    len = _printf("%d, %d, %d\n",11111,22222,33333);
    len2 = printf("%d, %d, %d\n",11111,22222,33333);
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    len = _printf("%+-20d, %+20ld, %hd\n",ui,ui+1,ui+2);
    len2 = printf("%+-20d, %+20ld, %hd\n",ui,ui+1,ui+2);
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    len = _printf("%+-20hd, %020ld, %05hd\n",ui,ui+1,ui+2);
    len2 = printf("%+-20hd, %020ld, %05hd\n",ui,ui+1,ui+2);
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    /**
     * o u x X  type %o %u %x %X
     * base flags：support - 0 space
     * base with：support
     * base precision ：support
     * base l h nonsupport
     */
    len = _printf("Unsigned: [%-20.10lu][%-20.10lu][%-20.10lu]\n", ui,ui+1,ui+2);
    len2 = printf("Unsigned: [%-20.10lu][%-20.10lu][%-20.10lu]\n", ui,ui+1,ui+2);
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    _printf("Unsigned octal: [%o][%o][%o]\n", ui,ui+1,ui+2);
    printf("Unsigned octal: [%o][%o][%o]\n", ui,ui+1,ui+2);
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    _printf("Unsigned octal: [%-20.11o][%-20.11o][%-20.11o]\n", ui,ui+1,ui+2);
    printf("Unsigned octal: [%-20.11o][%-20.11o][%-20.11o]\n", ui,ui+1,ui+2);
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    _printf("Unsigned hexadecimal: [%-020.10x,%015hX]\n",ui, ui+1);
    printf("Unsigned hexadecimal: [%-020.10x,%015hX]\n",ui, ui+1);
    printf("Length: [%d,%i]\n", len, len);
    printf("Length: [%d,%i]\n", len2, len2);

    /**
     * p  type %p
     * base flags：support - 0 space
     * base with：support
     * base precision ：nonsupport
     * base l h nonsupport
     */
    len = _printf("Address: [%-20.10p][%020p]\n", addr,addr1);
    len2 = printf("Address: [%-20.10p][%020p]\n", addr,addr1);
    _printf("Len: [%d]\n", len);
    printf("Len: [%d]\n", len2);

    /**
     * b  type %b
     * base flags：support - 0 space
     * base with：support
     * base precision ：nonsupport
     * base l h nonsupport
     */
    _printf("Bin: [%-10b]\n",98);
    _printf("Bin: [%10b]\n",98);
    _printf("Bin: [%010b]\n",98);
    printf("Bin: [%b]\n",98);


    /**
     * %  type %
     * base flags：support - 0 space
     * base with：support
     * base precision ：nonsupport
     * base l h nonsupport
     */
    len = _printf("Percent:[%010%]\n");
    len2 = printf("Percent:[%010%]\n");
    _printf("Len: [%d]\n", len);
    printf("Len: [%d]\n", len2);

    /**
     * r   type %r
     * base flags：support - 0 space
     * base with：support
     * base precision ：nonsupport
     * base l h nonsupport
     */
    _printf("Unknown: [%r]\n","Let's try to printf a simple sentence.");

    /**
     * r   type %R
     * base flags：support - 0 space
     * base with：support
     * base precision ：nonsupport
     * base l h nonsupport
     */
    _printf("Unknown: [%R]\n","Let's try to printf a simple sentence.");


    /**
     * S   type %S
     * base flags：support - 0 space
     * base with：support
     * base precision ：nonsupport
     * base l h nonsupport
     */
    _printf("Unknown: [%S]\n","Best\nSchool");
    _printf("Unknown: [%S]\n","Best\n\tSchool");
```

In this case the output is:

```
a
a
Length: [2,2]
Length: [2,2]
a,b,c
a,b,c
Length: [6,6]
Length: [6,6]
         a,b         ,c         
000000000a,b         ,c         
Length: [33,33]
Length: [33,33]
Lucy and Jack are friend
Lucy and Jack are friend
Length: [25,25]
Length: [25,25]
000000Lucy and Jack       ar        
000000Lucy and Jack       ar        
Length: [37,37]
Length: [37,37]
-11111, -22222, -33333
-11111, -22222, -33333
Length: [23,23]
Length: [23,23]
-11111111 , -002222222, 32203
-11111111 , -002222222, 32203
Length: [30,30]
Length: [30,30]
11111, 22222, 33333
11111, 22222, 33333
Length: [20,20]
Length: [20,20]
-2147482625         ,          +2147484672, 1025
-2147482625         ,          +2147484672, 1025
Length: [49,49]
Length: [49,49]
+1023               , 00000000002147484672, 01025
+1023               , 00000000002147484672, 01025
Length: [50,50]
Length: [50,50]
Unsigned: [2147484671          ][2147484672          ][2147484673          ]
Unsigned: [2147484671          ][2147484672          ][2147484673          ]
Length: [77,77]
Length: [77,77]
Unsigned octal: [20000001777][20000002000][20000002001]
Unsigned octal: [20000001777][20000002000][20000002001]
Length: [77,77]
Length: [77,77]
Unsigned octal: [20000001777         ][20000002000         ][20000002001         ]
Unsigned octal: [20000001777         ][20000002000         ][20000002001         ]
Length: [77,77]
Length: [77,77]
Unsigned hexadecimal: [00800003ff          ,000000000000400]
Unsigned hexadecimal: [00800003ff          ,000000000000400]
Length: [77,77]
Length: [77,77]
Address: [0x7ffe637541f0      ][0x0000007ffe63333333]
Address: [0x7ffe637541f0      ][0x0000007ffe63333333]
Len: [54]
Len: [54]
Bin: [1100010   ]
Bin: [   1100010]
Bin: [0001100010]
Bin: [b]
Percent:[000000000%]
Percent:[000000000%]
Len: [21]
Len: [21]
Unknown: [.ecnetnes elpmis a ftnirp ot yrt s'teL]
Unknown: [Yrg'f gel gb cevags n fvzcyr fragrapr.]
Unknown: [Best\x0ASchool]
Unknown: [Best\x0A\x09School]
```



# Notice
-   Allowed editors: vi, vim, emacs
-   All your files will be compiled on Ubuntu 20.04 LTS
-   Your programs and functions will be compiled with `gcc` using the optios `-Wall -Werror -Wextra -pedantic -std=gnu89`
-   All your files should end with a new line
-   A `README.md` file, at the root of the folder of the project is mandatory
-   Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
-   You are not allowed to use global variables
-   No more than 5 functions per file
-   In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
-   The prototypes of all your functions should be included in your header file called `holberton.h`
-   Don’t forget to push your header file
-   All your header files should be include guarded
-   Note that we will not provide the `_putchar` function for this project

## Enviorment

* [Ubuntu](https://ubuntu.com/)
* [GitHub](https://github.com/)
* [StackEdit](https://stackedit.io/)
* [RTFM](https://google.com/)

### Prototype

#include "main.h"
```bash
int _printf(const char *format, ...);
```

