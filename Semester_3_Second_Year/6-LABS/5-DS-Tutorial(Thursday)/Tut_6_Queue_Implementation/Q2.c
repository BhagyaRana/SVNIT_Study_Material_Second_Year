#include <stdio.h>
#include <conio.h>
#define SIZE 100

// Function Defination
void enQueue();
// For INPUT Restricted Queue
int deQueueFront();
int deQueueRear();
// For OUTPUT Restricted Queue
void enQueueRear();
void enQueueFront();

void display();

int queue[SIZE];
int rear = 0, front = 0;

int main()
{
    char ch;
    int ch1, ch2, value = 0;
    printf("\n~~~~~~~ Type of Double Ended Queue ~~~~~~~\n");
    do
    {
        printf("\n1 -> Input-restricted deque \n");
        printf("2 -> Output-restricted deque \n");
        printf("\nEnter your choice of Queue Type : ");
        scanf("%d", &ch1);

        switch (ch1)
        {
        case 1:
            printf("\n~~~ Operations For Input Restricted Deque ~~~\n");

            printf("1 -> Insert\n2 -> Delete from Rear\n3 -> Delete from Front\n4 ->  Display");

            do
            {
                printf("\nEnter Choice for DeQueue Operation : ");
                scanf("%d", &ch2);
                switch (ch2)
                {
                case 1:
                    enQueueRear();
                    // display();
                    break;
                case 2:
                    value = deQueueRear();
                    if (value)
                        printf("\nThe value deleted is %d", value);
                    // display();
                    break;
                case 3:
                    value = deQueueFront();
                    if (value)
                        printf("\nThe value deleted is %d", value);
                    // display();
                    break;
                case 4:
                    display();
                    break;
                default:
                    printf("Wrong choice");
                }
                printf("\nDo you want to perform another operation (Y/N): ");
                ch = getch();

            } while (ch == 'y' || ch == 'Y');

            getch();
            break;

        case 2:
            printf("\n~~~ Operations For Output Restricted Deque ~~~\n");
            printf("1 -> Insert at Rear\n2 -> Insert at Front\n3 -> Delete\n4 -> Display");
            do
            {
                printf("\nEnter your choice for the operation: ");
                scanf("%d", &ch2);
                switch (ch2)
                {
                case 1:
                    enQueueRear();
                    // display();
                    break;
                case 2:
                    enQueueFront();
                    // display();
                    break;
                case 3:
                    value = deQueueFront();
                    if (value)
                        printf("\nThe value deleted is %d", value);
                    // display();
                    break;
                case 4:
                    display();
                    break;
                default:
                    printf("Wrong choice");
                }
                printf("\nDo you want to perform another operation (Y/N): ");
                ch = getch();

            } while (ch == 'y' || ch == 'Y');
            getch();
            break;
        }
        printf("\nDo you want to continue with Another Deque(y/n):");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
}

void enQueueRear()
{
    char ch;
    if (front == SIZE / 2)
    {
        printf("\nQueue is full!!! Insertion is not possible!!! ");
        return;
    }
    do
    {
        int value;
        printf("\nEnter Value to be Inserted:");
        scanf("%d", &value);
        queue[front] = value;
        front++;
        printf("Continue Insertion(Y/N)?");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
}

void enQueueFront()
{
    char ch;
    if (front == SIZE / 2)
    {
        printf("\nQueue is full! Insertion Not Possible!");
        return;
    }
    do
    {
        int value;
        printf("\nEnter Value to be Inserted:");
        scanf("%d", &value);
        rear--;
        queue[rear] = value;
        printf("Continue Insertion(Y/N)?");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
}

int deQueueRear()
{
    int deleted;
    if (front == rear)
    {
        printf("\nQueue is Empty! Deletion Not Possible!");
        return 0;
    }
    front--;
    deleted = queue[front + 1];
    return deleted;
}

int deQueueFront()
{
    int deleted;
    if (front == rear)
    {
        printf("\nQueue is Empty! Deletion Not Possible!");
        return 0;
    }
    rear++;
    deleted = queue[rear - 1];
    return deleted;
}

void display()
{
    int i;
    if (front == rear)
        printf("\nQueue is Empty!");
    else
    {
        printf("\nThe Queue Elements are : ");
        for (i = rear; i < front - 1; i++)
        {
            printf("%d -> ", queue[i]);
        }
        printf("%d", queue[i]);
    }
}