// In a classroom of 100 students you have to divide students
//  in 10 sub list of equal students.

#include <stdio.h>

int student[101], i, j; // global student array

// 1. Insertation of marks.
void fx1()
{
    int cnt = 0;
    printf("Enter the Number of Students whose Data is to be Inserted :\n");
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        int rno;
        printf("Enter the Roll Number of Student :\n");
        scanf("%d", &rno);
        if (rno <= 0 && rno >= 101)
        {
            printf("Enter Valid Roll Number!\n");
        }
        else
        {
            int mark = 0;
            printf("Enter the Marks of Student :\n");
            scanf("%d", &mark);
            student[rno] = mark;
        }
    }

    return;
}

// 2. Deletion of marks.
void fx2()
{
    int cnt = 0;
    printf("Enter the Number of Students whose Data is to be Deleted :\n");
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        int rno;
        printf("Enter the Roll Number of Student :\n");
        scanf("%d", &rno);
        if (rno <= 0 && rno >= 101)
        {
            printf("Enter Valid Roll Number!\n");
        }
        else
        {
            student[rno] = -1;
        }
    }

    return;
}

// 3. Updation of marks.
void fx3()
{
    int cnt = 0;
    printf("Enter the Number of Students whose Data is to be Updated :\n");
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        int rno;
        printf("Enter the Roll Number of Student :\n");
        scanf("%d", &rno);
        if (rno <= 0 && rno >= 101)
        {
            printf("Enter Valid Roll Number!\n");
        }
        else
        {
            int mark = 0;
            printf("Enter the Updated Marks of Student :\n");
            scanf("%d", &mark);
            student[rno] = mark;
        }
    }

    return;
}

// 4. Display marks
void fx4()
{
    int cnt = 0;
    printf("Enter the Number of Students whose Data is to be Displayed :\n");
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        int rno;
        printf("Enter the Roll Number of Student :\n");
        scanf("%d", &rno);
        if (rno <= 0 && rno >= 101)
        {
            printf("Enter Valid Roll Number!\n");
        }
        else
        {
            if (student[rno] != -1)
                printf("The Marks of Student with Roll No %d is : %d\n", rno, student[rno]);
            else
            {
                printf("The Marks of Student Not Entered by Admin!!\n");
            }
        }
    }
    return;
}

// 5. Replace one sub list with other
void fx5()
{
    int r1;
    printf("Enter Sublist to be Replaced :\n");
    scanf("%d", &r1);
    printf("Enter 10 Students Marks for this SubList\n");
    for (int i = (r1 - 1) * 10 + 1; i <= r1 * 10; i++)
    {
        scanf("%d", &student[i]);
    }
    return;
}

// 6. Compare two sub list
void fx6()
{
    int r1, r2;
    printf("Enter Two Sublist to be Compared :\n");
    scanf("%d %d", &r1, &r2);
    int id1 = (r1 - 1) * 10 + 1;
    int ed1 = r1 * 10;
    int id2 = (r2 - 1) * 10 + 1;
    int ed2 = r2 * 10;
    while (id1 <= ed1 && id2 <= ed2)
    {
        if (student[id1] != student[id2])
        {
            printf("Both Sublist are Not Equal\n");
            return;
        }
        id1++;
        id2++;
    }
    printf("Both Sublist are Equal\n");
    return;
}

// 7. Enter nth element in jth list
void fx7()
{
    int n, j, mark;
    printf("Enter the jth List Number :\n");
    scanf("%d", &j);
    printf("Enter the nth Element Number :\n");
    scanf("%d", &n);
    printf("Enter the Mark of Student :\n");
    scanf("%d", &mark);

    int idx = (j - 1) * 10 + n;
    if (idx >= 0 && idx <= 100)
    {
        student[idx] = mark;
        printf("Marks Entered Successfully!\n");
    }
    else
    {
        printf("Enter Valid jth List or nth Element!\n");
    }
    return;
}

int main()
{
    // Marks of Student Not Initialized = -1
    for (int i = 0; i <= 100; i++)
    {
        student[i] = -1;
    }

    printf("Perform the following operation.\n");

    printf("1 -> Insertation of marks.\n");
    printf("2 -> Deletion of marks.\n");
    printf("3 -> Updation of marks.\n");
    printf("4 -> Display marks\n");
    printf("5 -> Replace one sub list with other\n");
    printf("6 -> Compare two sub list\n");
    printf("7 -> Enter nth element in jth list\n");

    char ch = 'Y';
    while (ch == 'Y' || ch == 'y')
    {
        int choice = 0;

        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            fx1();
            break;
        case 2:
            fx2();
            break;
        case 3:
            fx3();
            break;
        case 4:
            fx4();
            break;
        case 5:
            fx5();
            break;
        case 6:
            fx6();
            break;
        case 7:
            fx7();
            break;

        default:
            printf("Enter Valid Choice [1-7] Only!");
            break;
        }
        fflush(stdin); // for character input

        printf("Want to Do Another Operation?(Y/N)\n");
        scanf("%c", &ch);
    }

    return 0;
}
