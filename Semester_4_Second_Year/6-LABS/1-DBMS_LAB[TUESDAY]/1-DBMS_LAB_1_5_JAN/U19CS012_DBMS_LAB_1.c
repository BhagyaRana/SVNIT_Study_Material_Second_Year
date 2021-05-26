#include <stdio.h> // FILE

#include <stdlib.h>
// covid patient data of Surat city

// BASIC STRUCTURE OF PATIENT

struct Date
{
    int date;
    int month;
    int year;
};

struct Patient
{
    int pno;
    char first_name[100];
    char last_name[100];
    int age;
    char gender[10];
    struct Date admission_date;
    struct Date discharge_date;
    char area[100];
};

// Global File Pointer
FILE *fp;

// Add Record in File
void add()
{
    // Append Mode [If Doesnt Exist, it will Create it]
    fp = fopen("Patient_Data.txt", "a+");

    printf("~~ENTER PATIENT DETAILS~~\n");

    struct Patient p;

    printf("Patients Number : \n");
    scanf("%d", &p.pno);
    printf("Patients First Name : \n");
    fflush(stdin);
    gets(p.first_name);
    printf("Patients Last Name : \n");
    fflush(stdin);
    gets(p.last_name);
    printf("Patients Age : \n");
    scanf("%d", &p.age);
    printf("Patients Gender : \n");
    fflush(stdin);
    gets(p.gender);
    printf("Patients Admission Date [DD/MM/YYYY] : \n");
    scanf("%d %d %d", &p.admission_date.date, &p.admission_date.month, &p.admission_date.year);
    printf("Patients Discharge Date [DD/MM/YYYY] :  \n");
    scanf("%d %d %d", &p.discharge_date.date, &p.discharge_date.month, &p.discharge_date.year);
    printf("Patient Area of Residence : \n");
    fflush(stdin);
    gets(p.area);

    fwrite(&p, sizeof(struct Patient), 1, fp);
    fclose(fp);

    return;
}

// Deletion of Record in File
void del()
{
    FILE *fp2;
    fp = fopen("Patient_Data.txt", "r+");
    fp2 = fopen("temp.txt", "a+");
    if (fp == NULL)
    {
        printf("Unable to Open File!\n");
        fclose(fp);
        return;
    }
    else
    {
        int id;
        printf("\nEnter the Patient Number to be deleted : ");
        scanf("%d", &id);
        struct Patient p;
        // Write all records to the tempfile, except the one(s) you want to delete.
        while (fread(&p, sizeof(struct Patient), 1, fp))
        {
            if (p.pno != id)
            {
                fwrite(&p, sizeof(struct Patient), 1, fp2);
            }
        }
        fclose(fp);
        fclose(fp2);
        // Remove the old file.
        remove("Patient_Data.txt");
        // Rename New File With Old File Name
        rename("temp.txt", "Patient_Data.txt");
        printf("\nDeleted Succesfully!\n");
    }

    return;
}

// Modify a Record in File
void modify()
{
    FILE *fp2;

    fp = fopen("Patient_Data.txt", "r+");
    fp2 = fopen("temp.txt", "a+");

    if (fp == NULL)
    {
        printf("Unable to Open File!\n");
        fclose(fp);
        return;
    }
    else
    {
        // New Record
        struct Patient p1;
        printf("Patients Number to be Updated : \n");
        scanf("%d", &p1.pno);
        printf("New Patients First Name : \n");
        fflush(stdin);
        gets(p1.first_name);
        printf("New Patients Last Name : \n");
        fflush(stdin);
        gets(p1.last_name);
        printf("New Patients Age : \n");
        scanf("%d", &p1.age);
        printf("New Patients Gender : \n");
        fflush(stdin);
        gets(p1.gender);
        printf("New Patients Admission Date [DD/MM/YYYY] : \n");
        scanf("%d %d %d", &p1.admission_date.date, &p1.admission_date.month, &p1.admission_date.year);
        printf("New Patients Discharge Date [DD/MM/YYYY] :  \n");
        scanf("%d %d %d", &p1.discharge_date.date, &p1.discharge_date.month, &p1.discharge_date.year);
        printf("New Patient Area of Residence : \n");
        fflush(stdin);
        gets(p1.area);

        // Temporary Structure to Hold Data
        struct Patient p2;

        while (fread(&p2, sizeof(struct Patient), 1, fp))
        {
            if (p2.pno != p1.pno)
            {
                fwrite(&p2, sizeof(struct Patient), 1, fp2);
            }
            else
            {
                fwrite(&p1, sizeof(struct Patient), 1, fp2);
            }
        }

        fclose(fp);
        fclose(fp2);

        // Remove the old file.
        remove("Patient_Data.txt");
        // Rename New File With Old File Name
        rename("temp.txt", "Patient_Data.txt");
        printf("\nModified Succesfully!\n");
    }

    return;
}

void display()
{
    fp = fopen("Patient_Data.txt", "r+");

    if (fp == NULL)
    {
        printf("Unable to Open File\n");
        fclose(fp);
        return;
    }
    else
    {
        struct Patient p2;

        while (fread(&p2, sizeof(struct Patient), 1, fp))
        {
            printf("\n~~ PATIENT DETAILS ~~\n");

            printf("Patients Number : %d\n", p2.pno);
            printf("Patients First Name : %s\n", p2.first_name);
            printf("Patients Last Name : %s\n", p2.last_name);
            printf("Patients Age : %d\n", p2.age);
            printf("Patients Gender : %s\n", p2.gender);
            printf("Patients Admission Date [DD/MM/YYYY] : %d %d %d\n", p2.admission_date.date, p2.admission_date.month, p2.admission_date.year);
            printf("Patients Discharge Date [DD/MM/YYYY] : %d %d %d\n", p2.discharge_date.date, p2.discharge_date.month, p2.discharge_date.year);
            printf("Patient Area of Residence : %s\n", p2.area);
        }

        fclose(fp);

        return;
    }
}

int main()
{
    printf("~~ COVID PATIENT DATA [SURAT] ~~\n");

    while (1)
    {
        int ch;
        printf("1 -> Add a Record of Patient\n");
        printf("2 -> Delete a Record of Patient\n");
        printf("3 -> Modify a Record of Patient\n");
        printf("4 -> Display a Record of Patients\n");
        printf("5 -> Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        case 3:
            modify();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("Enter a Valid Choice!\n");
            break;
        }
    }

    return 0;
}