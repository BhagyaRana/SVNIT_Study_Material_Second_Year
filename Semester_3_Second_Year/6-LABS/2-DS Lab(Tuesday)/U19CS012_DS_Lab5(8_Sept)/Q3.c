// Write a program to sort the string using stack
#include <stdio.h>

#define MAX 1000 //Maximum number of elements that can be stored

//To Avoid the Conflicts of Top of "stack1" and "temp" stack
// I will be Using Struct
struct stack
{
    char stk[MAX];
    int top;

} stack1, temp;

char peek(struct stack *s)
{
    if (s->top == -1)
    {
        printf("stack is empty");
        return '$';
    }
    //Return the Character at the Top of Stack
    return s->stk[s->top];
}

void push(struct stack *s, char c)
{
    if (s->top == MAX - 1)
    {
        printf("stack overflow");
        return;
    }
    s->top += 1;
    s->stk[s->top] = c;
}

char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("stack underflow");
        return '$';
    }
    // return the Pop Character and then Decrements the Top
    return s->stk[s->top--];
    // Post Decrement
}

int main()
{
    char str[MAX];

    // Initialise Two Empty Stack
    stack1.top = -1;
    temp.top = -1;

    printf("Enter the String to Sort :\n");

    fgets(str, MAX, stdin);

    // Push the First Char of String in Stack "stack1"
    push(&stack1, str[0]);

    int i = 0;

    // Iterate till End of String
    for (i = 1; str[i] != '\0'; i++)
    {
        // If ASCII of Current Character is Less than Top
        // Push it in stack1
        if (peek(&stack1) >= str[i])
        {
            push(&stack1, str[i]);
        }
        else
        {
            // Otherwise Until the Stack1 is Not Empty
            while (stack1.top != -1)
            {
                // If top [ASCII] is less than ith char of str [ASCII]
                if (peek(&stack1) < str[i])
                {
                    //Push the Element from Stack to temp
                    temp.top += 1;
                    temp.stk[temp.top] = pop(&stack1);
                }
                else
                {
                    // Otherwise Break
                    break;
                }
            }

            push(&stack1, str[i]);

            while (temp.top != -1)
            {
                // Now Transfer all Character from "temp" to "stack1"
                push(&stack1, pop(&temp));
            }
        }
    }

    char str_sort[MAX];

    int j = 0;

    while (stack1.top != -1)
    {
        str_sort[j] = pop(&stack1);
        j += 1;
    }

    str_sort[j] = '\0'; // Append /0 at End

    printf("Sorted String : %s\n", str_sort);

    return 0;
}