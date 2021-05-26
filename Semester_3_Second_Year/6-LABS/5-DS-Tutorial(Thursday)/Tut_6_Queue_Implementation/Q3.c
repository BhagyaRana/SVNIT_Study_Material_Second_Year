#include <stdio.h>

#define SIZE 100
// To Store Data Element
int Priority_Queue[SIZE];
// To Store Priority of Data Element
int Priority[SIZE];

// rear -> r & front -> f
int r = -1, f = -1;

//enqueuePQ function -> Insert Data and its Priority in queue
void enqueuePQ(int data, int p);

//Display Priority Queue
void displayPQ();

//Delete Element from Front of Priority Queue
int dequeuePQ();

int main()
{
    int choice, n, i, data, p;

    do
    {
        printf("\n1 -> Insert the Data in Priority Queue");
        printf("\n2 -> Display Priority Queue");
        printf("\n3 -> Delete the data from the Priority Queue");
        printf("\n0 -> Exit\n");

        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the Number of Data to be Inserted : ");
            scanf("%d", &n);
            printf("\nEnter your Data and Priority of Data :\n");
            i = 0;
            while (i < n)
            {
                scanf("%d %d", &data, &p);
                enqueuePQ(data, p);
                i++;
            }
            break;
        case 2:
            displayPQ();
            break;
        case 3:
            dequeuePQ();
            break;
        case 0:
            break;
        default:
            printf("\nIncorrect Choice Entered!");
        }
    } while (choice != 0);
    return 0;
}

//enqueuePQ function to insert data and its priority in queue
void enqueuePQ(int data, int p)
{
    int i;
    //Check if Queue is full
    if ((f == 0) && (r == SIZE - 1))
        printf("Queue is Full!");
    else
    {
        //if Queue is empty
        if (f == -1)
        {
            f = r = 0;
            Priority_Queue[r] = data;
            Priority[r] = p;
        }
        else if (r == SIZE - 1)
        {
            //if there there is some elemets in Queue
            // Insert Element at Right Priority Position
            for (i = f; i <= r; i++)
            {
                Priority_Queue[i - f] = Priority_Queue[i];
                Priority[i - f] = Priority[i];
                r = r - f;
                f = 0;
                for (i = r; i > f; i--)
                {
                    if (p > Priority[i])
                    {
                        Priority_Queue[i + 1] = Priority_Queue[i];
                        Priority[i + 1] = Priority[i];
                    }
                    else
                        break;
                    Priority_Queue[i + 1] = data;
                    Priority[i + 1] = p;
                    r++;
                }
            }
        }
        else
        {
            for (i = r; i >= f; i--)
            {
                if (p > Priority[i])
                {
                    Priority_Queue[i + 1] = Priority_Queue[i];
                    Priority[i + 1] = Priority[i];
                }
                else
                    break;
            }
            Priority_Queue[i + 1] = data;
            Priority[i + 1] = p;
            r++;
        }
    }
}

//Display Priority Queue
void displayPQ()
{
    int i;
    if (f == -1)
    {
        printf("Queue is Empty!");
        return;
    }

    printf("Priority Queue [Element,Priority] : \n\n");
    for (i = f; i <= r; i++)
    {
        printf("[ %d , %d ]\n", Priority_Queue[i], Priority[i]);
    }
}

//Delete Element from Front of Priority Queue
int dequeuePQ()
{
    if (f == -1)
    {
        printf("Queue is Empty!");
    }

    else
    {
        printf("Deleted Data [Element,Priority] = [ %d , %d ]\n", Priority_Queue[f], Priority[f]);
        if (f == r)
            f = r = -1;
        else
            f++;
    }
}