#include <stdio.h>
#include <stdlib.h> // exit func
#include <ctype.h>  // for isdigit
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

//Function Declarations

void push(char ele);
char pop();

int is_operator(char symbol);
int precedence(char symbol);

void Infix_To_PostFix(char infix_exp[], char postfix_exp[]);

void Infix_to_Prefix(char infix_exp[], char prefix_exp[]);
void Bracket(char *exp);

int main()
{
    char infix[SIZE], postfix[SIZE], prefix[SIZE];

    int cnt = 0;
    printf("Enter the Number of Infix Expression to Convert to PostFix & Prefix Expression :\n");
    scanf("%d", &cnt);
    fflush(stdin);

    while (cnt--)
    {
        printf("Enter Valid Infix Expression : ");
        gets(infix);

        Infix_To_PostFix(infix, postfix);

        printf("Postfix Expression : ");
        puts(postfix);

        Infix_to_Prefix(infix, prefix);

        printf("Prefix Expression  : ");
        puts(prefix);
        printf("\n");

        top = -1; //Empty the Stack
    }

    return 0;
    // LIMITATION : SINGLE LETTER DIGITS AND VARIABLES
}

// Function Definations

void push(char ele)
{
    if (top >= SIZE - 1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        top = top + 1;
        stack[top] = ele;
    }
}

char pop()
{
    char ele;

    if (top < 0)
    {
        // underflow -> invalid expression
        // OR '(' and ')' are not matched
        printf("Stack Under Flow! : Invalid Infix Expression Entered!");
        getchar();
        exit(1);
    }
    else
    {
        ele = stack[top];
        top = top - 1;
        return (ele);
    }
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-' || symbol == '%')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    // Exponent > (* OR /) > (+ OR -)
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-') /* lowest precedence */
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void Infix_To_PostFix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char ele;
    char x;

    //push '(' onto stack
    push('(');

    // add ')' to infix expression
    strcat(infix_exp, ")");

    i = 0;
    j = 0;

    // Initialize with First Char
    ele = infix_exp[i];

    // run loop till end of infix expression
    while (ele != '\0')
    {
        if (ele == '(')
        {
            push(ele);
        }
        else if (isdigit(ele) || isalpha(ele))
        {
            // add operand symbol to postfix expr
            postfix_exp[j] = ele;
            j++;
        }
        else if (is_operator(ele) == 1)
        {
            x = pop();

            while (is_operator(x) == 1 && precedence(x) >= precedence(ele))
            {
                //add them to postfix expresion
                postfix_exp[j] = x;
                j++;
                x = pop();
                // pop all higher precendence operator
            }

            // For -> While Loop popped element
            push(x);

            //push current oprerator symbol onto stack
            push(ele);
        }
        else if (ele == ')')
        {
            x = pop();

            //keep popping until '(' encounterd
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            // Neither of Above Symbols
            printf("\nInvalid Infix Expression!\n");
            getchar();
            exit(1);
        }
        i++;

        // Next Symbol
        ele = infix_exp[i];
    }

    if (top > 0)
    {
        printf("\nInvalid Infix Expression.\n");
        getchar();
        exit(1);
    }

    //add sentinel "\0" else puts() fucntion will print entire postfix[] array upto SIZE
    postfix_exp[j] = '\0';
}

void Bracket(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
        i++;
    }
}

void Infix_to_Prefix(char infix_exp[], char prefix_exp[])
{
    char tmp[SIZE];
    strcpy(tmp, infix_exp);

    // Reverse Given Infix Expression
    strrev(tmp);

    //change Bracket
    Bracket(tmp);

    //get postfix of tmp
    Infix_To_PostFix(tmp, prefix_exp);

    // reverse string again
    strrev(prefix_exp);
}
