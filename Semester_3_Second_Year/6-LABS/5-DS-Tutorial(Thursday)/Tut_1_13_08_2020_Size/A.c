// Question 1 : Find the Size of the below listed C data types
// using Size () function.

#include <stdio.h>

int main()
{
    // typespecifier is %ld since it can have at max 12 bytes (long double)

    //int or signed int = 4 bytes
    int typeint;
    printf("Size of int or signed int             : %ld bytes\n", sizeof(typeint));

    //unsigned int = 4 bytes
    unsigned int typeunsignedint;
    printf("Size of unsigned int                  : %ld bytes\n", sizeof(typeunsignedint));

    //short int or signed short int = 2 bytes
    short int typeshortint;
    printf("Size of short int or signed short int : %ld bytes\n", sizeof(typeshortint));

    //unsigned short int = 2 bytes
    unsigned short int typeunsignedshortint;
    printf("Size of unsigned short int            : %ld bytes\n", sizeof(typeunsignedshortint));

    //long int or signed long int = 4 bytes
    long int typelongint;
    printf("Size of long int or signed long int   : %ld bytes\n", sizeof(typelongint));

    //unsigned long int = 4 bytes
    unsigned long int typeunsignedlongint;
    printf("Size of unsigned long int             : %ld bytes\n", sizeof(typeunsignedlongint));

    //Float = 4 bytes
    float typefloat;
    printf("Size of Float                         : %ld bytes\n", sizeof(typefloat));

    //double = 8 bytes
    double typedouble;
    printf("Size of double                        : %ld bytes\n", sizeof(typedouble));

    //long double = 12 bytes
    long double typelongdouble;
    printf("Size of long double                   : %ld bytes\n", sizeof(typelongdouble));

    //char or signed char = 1 byte
    char typechar;
    printf("Size of char or signed char           : %ld byte\n", sizeof(typechar));

    //unsigned char = 1 bytes
    unsigned char typeunsignedchar;
    printf("Size of unsigned char                 : %ld byte\n", sizeof(typeunsignedchar));

    return 0;
}