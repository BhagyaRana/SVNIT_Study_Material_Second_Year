#include <stdio.h>
#include "mystring.h"

#define MAX 100000

int main()
{
    //Function 1 : Write a program to find the length of a given string.

    printf("\n1 - MYSTRLEN FUNCTION : \n\n");

    char string[MAX];

    printf("Enter String :\n");
    scanf("%s", string);

    printf("Length of String : %d\n", mystrlen(string));

    //Function 2 : Write a program to concate two given string.

    printf("\n2 - MYSTRCONCAT FUNCTION : \n\n");

    char string1[MAX];
    char string2[MAX];

    printf("Enter String 1 :\n");
    scanf("%s", string1);

    printf("Enter String 2 :\n");
    scanf("%s", string2);

    // char string3[MAX];
    char *str3 = mystrconcat(string1, string2);

    printf("Concatanated String : %s\n", str3);

    //Function 3 : Write a program to copy one string to another string.

    printf("\n3 - MYSTRCOPY FUNCTION : \n\n");

    char string3[MAX];
    char string4[MAX];

    printf("Enter String to be Copied :\n");
    scanf("%s", string3);

    mystrcopy(string3, string4);

    printf("Copied String : %s\n", string4);

    //Function 4 : Write a program to compare two given string.

    printf("\n4 - MYSTRCOMP FUNCTION : \n\n");

    char string5[MAX];
    char string6[MAX];

    printf("Enter String 5 :\n");
    scanf("%s", string5);

    printf("Enter String 6 :\n");
    scanf("%s", string6);

    int cmp = mystrcomp(string5, string6);

    if (cmp == 0)
    {
        printf("Result : Both Strings are Equal\n");
    }
    else
    {
        if (cmp > 0)
        {
            printf("Result : %s is greater than %s\n", string5, string6);
        }
        else
        {
            printf("Result : %s is less than %s\n", string5, string6);
        }
    }

    //Function 5 : Write a program to search for the first
    //occurrence of the character ‘c’ (any char) in the given string.

    printf("\n5 - MYSTROCCUR FUNCTION : \n\n");

    char string7[MAX], ch;

    printf("Enter String 7 :\n");
    scanf("%s", string7);

    fflush(stdin); // So that it does not count "Enter" as Character

    printf("Enter Character to Search :\n");
    ch = getchar();

    int srch = mystroccur(string7, ch);

    if (srch == -1)
    {
        printf("Result : %c not found in %s\n", ch, string7);
    }
    else
    {
        printf("Result : %c found in %s at index %d\n", ch, string7, srch);
    }

    //Function 6 : Write a program to find sub string is there in given string or not?

    printf("\n6 - MYSTRSUB FUNCTION : \n\n");

    char parent[MAX];
    char substring[MAX];

    printf("Enter Parent String :\n");
    scanf("%s", parent);
    printf("Enter Sub-String to be Found :\n");
    scanf("%s", substring);

    if (mystrsub(parent, substring))
    {
        printf("Result : %s found as substring in %s\n", substring, parent);
    }
    else
    {
        printf("Result : %s not found as substring in %s\n", substring, parent);
    }

    //Function 7 : Write a program to generate reverse of a string.

    printf("\n7 - MYSTRREV FUNCTION : \n\n");

    char string8[MAX];
    char string9[MAX];

    printf("Enter String 8 :\n");
    scanf("%s", string8);

    mystrrev(string8, string9);

    printf("Reversed String : %s\n", string9);

    return 0;
}
