//Write a program to check string is palindrome using stack.
#include <stdio.h>
#include <string.h>

#define MAX 1000 //Maximum number of elements that can be stored

int top = -1;
char stack[MAX];

int isfull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(char letter)
{
    if (isfull())
    {
        // printf("\nStack is Full!\n");
    }
    else
    {
        top = top + 1;
        stack[top] = letter;
    }
}

char pop()
{
    if (isempty())
    {
        // printf("\nStack is Empty!\n");
        return '0';
    }
    else
    {
        char tp = stack[top];
        top = top - 1;
        return tp;
    }
}
// ~~~~~~~~ ALGORITHM ~~~~~~~~~~~~~
// len(s1) = returns length of string s1

// 1.) stack.top = -1
// 2.) Read s1
// 3.) len1 = len(s1)

// 4.) i=0;
// 5.) Repeat Step 6 & 7 while i < (len1)/2
// 6.) push(s1[i], stack)
// 7.) i = i + 1

// 8.) if len is odd [len%2!=0]
// 9.)    i = i+1

// 10.) Repeat Step 11 & 12 while not isempty(stack)
// 11.)  if(stack.top != s[i]) return false;
// 12.)  i = i + 1; pop(stack.top);

// 13.) return true

int check_palindrome(char *str)
{
    int len = strlen(str);
    int i, mid = len / 2;
    for (i = 0; i < mid; i++)
    {
        push(str[i]);
    }

    if (len % 2 == 1) // Odd Length String
        i += 1;

    while (i < len)
    {
        char ele = pop();
        if (ele != (char)str[i])
        {
            return 0; // Cant Be Palindrome
        }
        i += 1;
    }

    top = -1; //Empty the Stack

    return 1; // Palindrome
}

int main()
{
    int t;
    printf("Enter the Number of Strings to Check for Palindrome:\n");

    scanf("%d", &t);

    while (t--)
    {

        char str[MAX];

        printf("Enter String :\n");
        fflush(stdin);

        gets(str);

        if (check_palindrome(str) != 0)
        {
            printf("%s : Palidromic String\n", str);
        }
        else
        {
            printf("%s : Not Palindromic String\n", str);
        }
    }

    return 0;
}
