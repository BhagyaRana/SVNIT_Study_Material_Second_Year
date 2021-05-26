#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BLANK ' '
#define TAB '\t'

void PostFix_To_InFix(char postfix_exp[], char infix_exp[]);

#define MAX 100
char stack2[MAX];
int top2;

int is_operator(char symbol);
void push2(char c);
char pop2();

void PostFix_To_PreFix(char postfix[], char prefix[]);

#define SIZE 100
int top;

char stack[SIZE][SIZE];
void push(char *str);
char *pop();

int isempty();
int white_space(char symbol);

int main()
{
    char infix[SIZE], postfix[SIZE], prefix[SIZE];

    int cnt = 0;
    printf("Enter the Number of PostFix Expression to Convert to PreFix & Infix Expression :\n");
    scanf("%d", &cnt);
    fflush(stdin);

    while (cnt--)
    {
        top = -1;
        printf("Enter Valid PostFix Expression : ");
        gets(postfix);

        PostFix_To_PreFix(postfix, prefix);
        printf("Prefix Expression : ");
        puts(prefix);

        top2 = -1;
        PostFix_To_InFix(postfix, infix);
        printf("Infix Expression  : ");
        puts(infix);
        printf("\n");
    }

    // LIMITATION : SINGLE LETTER DIGITS AND VARIABLES
    return 0;
}

void PostFix_To_PreFix(char postfix[], char prefix[])
{
    int i;

    char operand1[SIZE], operand2[SIZE];

    char symbol;

    char temp[2];

    char strin[SIZE];

    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        temp[0] = symbol;
        temp[1] = '\0';

        if (!white_space(symbol))
        {
            switch (symbol)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                // string = operator + operand2 + operand1
                strcpy(operand1, pop());
                strcpy(operand2, pop());
                strcpy(strin, temp);
                strcat(strin, operand2);
                strcat(strin, operand1);
                //push the string in Stack
                push(strin);
                break;

            // Operand should be pushed in Stack
            default:
                push(temp);
            }
        }
    }

    strcpy(prefix, stack[0]);
}

void push(char *str)
{
    if (top > SIZE)
    {
        printf("\nStack Overflow!\n");
        exit(1);
    }
    else
    {
        top = top + 1;
        strcpy(stack[top], str);
    }
}

char *pop()
{
    if (top == -1)
    {
        printf("\nStack underflow || Enter Valid PostFix Expression\n");
        exit(2);
    }
    else
        return (stack[top--]);
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int white_space(char symbol)
{
    if (symbol == BLANK || symbol == TAB || symbol == '\0')
        return 1;
    else
        return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~POSTFIX TO INFIX~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void PostFix_To_InFix(char postfix_exp[], char infix_exp[])
{
    char str[MAX];

    int i, j = 0;

    strcpy(str, postfix_exp);

    strrev(str);

    for (i = 0; i < MAX; i++)
        stack2[i] = '\0';

    int n = strlen(str);

    for (i = 0; i < n; i++)
    {
        if (is_operator(str[i]))
        {
            push2(str[i]);
        }
        else
        {
            infix_exp[j] = str[i];
            j++;
            infix_exp[j] = pop2();
            j++;
        }
    }

    infix_exp[j] = str[top--];
    strrev(infix_exp);
}

void push2(char c)
{
    stack2[++top2] = c;
}

char pop2()
{
    return stack2[top2--];
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
