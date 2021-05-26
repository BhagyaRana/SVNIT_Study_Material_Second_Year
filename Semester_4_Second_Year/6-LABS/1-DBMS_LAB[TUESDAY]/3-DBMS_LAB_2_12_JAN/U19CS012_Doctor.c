// DOCTORS INFORMATION [U19CS012] [BHAGYA VINOD RANA]
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// -----------------GENERAL_STRUCTURES_TO_STORE_INFORMATION[START]------------------

// 1-Structure of Date
typedef struct _date
{
    int dd;
    int mm;
    int yy;
} date;

// 2-Structure of Patient [COVID]
typedef struct _covid
{
    int number;
    char first[20];
    char last[20];
    char gender;
    int age;
    char area[20];
    date admission;
    date discharge;
} covid, mypat;

// 3-Structure of Doctor
typedef struct _doctor
{
    int number;
    char name[20];
    char gender;
    int age;
    char area[20];
} doctor;

// 4-Structure to Store the Relation Between Doc & Patient
typedef struct _relation
{
    int doc_num;
    int patients[100];
    int pat_num;
    char name[20];
} relation;

// -----------------GENERAL_STRUCTURES_TO_STORE_INFORMATION[END]------------------

// -------------MODULAR_PROGRAMMING_STRUCTURE_HELPER_FUNCTION[START]--------------

// 1- Add Doctor to DataBase
void write();
// 2- Display List of Doctors with Corresponding Number of Patients [Summary 4A]
void print_num_patients();
// 3 - Assign a Patient to the Doctor with the Least Number of Patients
void assign_patient();
// 3A - Patient to be Assigned
int add_pat_util();
// 4 - Display Various Reports Doctor-Wise
void summary_reports();
// 4B - Gender-Wise Patient Summary
void gender_count();
// 4C - Age-Wise Patient Summary
void age_count();
// 4D - Area-Wise Patient Summary
void area_count();
// 5 - Sort Patients in Ascending Order
void sort_ascending();
// 5A1 - Helper Function to Compare Dates
int compare_dates(date d1, date d2);
void sort_adate();
void sort_ddate();
void sort_doc();
void sort_mdoc();
void sort_fdoc();
// 6B - Add Patients in DataBase [Incase of No Patients]
void new_pat_entry();
// 6A - Function Caller for Each Patient
void add_new_patients();

// -------------MODULAR_PROGRAMMING_STRUCTURE_HELPER_FUNCTION[END]--------------

int main()
{
    int cont = 1, choice;
    while (1)
    {
        printf("\nChoose What you want to do?\n");
        printf("\nNote: Add Patient's Data from Option 6 [If Not Done Earlier!]\n\n");
        printf("1 -> Add Doctor Info\n");
        printf("2 -> Display List of Doctors with Corresponding Number of Patients\n");
        printf("3 -> Assign a Patient to the Doctor with the Least Number of Patients\n");
        printf("4 -> Display Various Reports Doctor-Wise\n");
        printf("5 -> Sort Patients in Ascending Order\n");
        printf("6 -> Add Patients in DataBase [Incase of No Patients]\n");
        printf("7 -> Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            write();
            break;
        case 2:
            print_num_patients();
            break;
        case 3:
            assign_patient();
            break;
        case 4:
            printf("Select Parameter on which You Want Doctor-Wise Report :\n");
            printf("1 -> Display Count of Patient(s)\n");
            printf("2 -> Display Count of Patient based on Gender\n");
            printf("3 -> Display Age-Wise Count of Patient(s)\n");
            printf("4 -> Display Area-Wise Count of Patient(s)\n");
            fflush(stdin);
            summary_reports();
            break;
        case 5:
            printf("Select what you wish to do\n");
            printf("1 -> Admitted on Same date\n");
            printf("2 -> Discharged on Same date\n");
            printf("3 -> Patients under Doctor\n");
            printf("4 -> Patients under Male Doctor\n");
            printf("5 -> Patients under Female Doctor\n");
            sort_ascending();
            break;
        case 6:
            add_new_patients();
            break;
        case 7: //Quit
            cont = 0;
            break;
        default:
            printf("Enter a Valid choice!!!\n");
        }
        if (!cont)
            break;
    }
    return 0;
}

//-----------------------------------ADD_DOCTORS_SECTION[START]------------------------------------------

// 1- Add Doctor to DataBase
void write()
{
    int i;
    doctor d;
    relation r;
    FILE *fp;
    FILE *fp1;

    fp = fopen("doctors.txt", "a+");

    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    fp1 = fopen("doctor_patient_relation.txt", "a+");

    if (fp1 == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    printf("~~ENTER DOCTOR DETAILS~~\n");
    // DOCTORS INFORMATION SECTION
    printf("Enter Doctor's Number :\n");
    scanf("%d", &d.number);
    printf("Enter Doctor's Name :\n");
    fflush(stdin);
    gets(d.name);
    printf("Enter Doctor's Gender [(M/F)Only] :\n");
    fflush(stdin);
    scanf("%c", &d.gender);
    printf("Enter Doctor's Age :\n");
    fflush(stdin);
    scanf("%d", &d.age);
    printf("Enter Doctor's Area of Residence :\n");
    fflush(stdin);
    gets(d.area);

    // Also Insert the Relation
    r.doc_num = d.number;
    strcpy(r.name, d.name);

    printf("Enter Number of Patient(s) Currently Under Doctor [Count]:\n");
    fflush(stdin);
    scanf("%d", &r.pat_num);

    // Initialise
    for (i = 0; i < 100; ++i)
    {
        r.patients[i] = 0;
    }

    printf("Enter Patient ID's :\n");
    fflush(stdin);

    int x;
    for (i = 0; i < r.pat_num; ++i)
    {
        scanf("%d", &x);
        r.patients[x] = 1; // Mark the Patient
    }

    fwrite(&d, sizeof(doctor), 1, fp);
    fwrite(&r, sizeof(relation), 1, fp1);

    fclose(fp);
    fclose(fp1);
}

//-----------------------------------ADD_DOCTORS_SECTION[END]------------------------------------------

//-------------------------------DISPLAY_DOC_PATIENT_NO_SECTION[START]---------------------------------

// 2- Display List of Doctors with Corresponding Number of Patients
void print_num_patients()
{
    relation r;

    FILE *fp;
    fp = fopen("doctor_patient_relation.txt", "r");

    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    while (fread(&r, sizeof(relation), 1, fp))
    {
        printf("Doctor ID : %d\n", r.doc_num);
        printf("Number of Patient(s) : %d\n", r.pat_num);
        printf("\n");
    }

    fclose(fp);
}

//-------------------------------DISPLAY_DOC_PATIENT_NO_SECTION[END]---------------------------------

//-------------------------------ASSIGN_PATIENT_TO_LEAST_DOC[START]----------------------------------

// 3 - Assign a Patient to the Doctor with the Least Number of Patients
void assign_patient()
{
    FILE *fp;
    fp = fopen("doctor_patient_relation.txt", "r+");

    if (fp == NULL)
    {
        printf("Failed to Load File!!!!\n");
        fclose(fp);
        return;
    }

    int p_id = add_pat_util();

    relation arr[100];
    relation r;

    int count = 0;

    while (fread((&r), sizeof(relation), 1, fp))
    {
        arr[count++] = r;
    }

    fclose(fp);

    char min_name[] = "zzzzzzzzzzzzzz";
    int min_count = 100000000;
    int pos = -1, i;

    for (i = 0; i < count; ++i)
    {
        if (arr[i].pat_num < min_count)
        {
            min_count = arr[i].pat_num;
            strcpy(min_name, arr[i].name);
            pos = i;
        }
        else if (arr[i].pat_num == min_count)
        {
            if (strcmp(min_name, arr[i].name) < 0)
            {
                strcpy(min_name, arr[i].name);
                pos = i;
            }
        }
    }

    ++arr[pos].pat_num;
    arr[pos].patients[p_id] = 1;

    FILE *temp;
    temp = fopen("temp.txt", "w");
    for (i = 0; i < count; ++i)
    {
        fwrite(&arr[i], sizeof(relation), 1, temp);
    }
    fclose(temp);

    remove("doctor_patient_relation.txt");
    rename("temp.txt", "doctor_patient_relation.txt");

    printf("Summary : \n");
    printf("Patient Number %d referred to Dr. %s", p_id, arr[pos].name);
}

int add_pat_util()
{
    FILE *fp;
    fp = fopen("patients.txt", "a+");

    printf("~~ENTER PATIENT DETAILS~~\n");
    struct _covid p;
    printf("Patients Number : \n");
    scanf("%d", &p.number);
    printf("Patients First Name : \n");
    fflush(stdin);
    gets(p.first);
    printf("Patients Last Name : \n");
    fflush(stdin);
    gets(p.last);
    printf("Patients Age : \n");
    scanf("%d", &p.age);
    printf("Patients Gender : \n");
    fflush(stdin);
    scanf("%c", &p.gender);
    printf("Patients Admission Date [DD/MM/YYYY] : \n");
    scanf("%d %d %d", &p.admission.dd, &p.admission.mm, &p.admission.yy);
    printf("Patients Discharge Date [DD/MM/YYYY] :  \n");
    scanf("%d %d %d", &p.discharge.dd, &p.discharge.mm, &p.discharge.yy);
    printf("Patient Area of Residence : \n");
    fflush(stdin);
    gets(p.area);

    fwrite(&p, sizeof(struct _covid), 1, fp);
    fclose(fp);

    // Only Difference is that it Returns Patient(s) Number
    return p.number;
}

//-------------------------------ASSIGN_PATIENT_TO_LEAST_DOC[START]----------------------------------

//-----------------------------DISPLAY_VARIOUS_SUMMARY_REPORTS[START]---------------------------

// 4 - Display Various Reports Doctor-Wise
void summary_reports()
{
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        print_num_patients();
        break;
    case 2:
        gender_count();
        break;
    case 3:
        age_count();
        break;
    case 4:
        area_count();
        break;
    default:
        printf("Invalid choice\n");
    }
}

// 4B - Gender-Wise Patient Summary
void gender_count()
{
    FILE *fp;

    fp = fopen("doctor_patient_relation.txt", "r");

    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    relation r;

    while (fread(&r, sizeof(relation), 1, fp))
    {
        printf("Doctor ID : %d\n", r.doc_num);

        int male = 0, female = 0;

        covid p1;
        FILE *fp1;
        fp1 = fopen("patients.txt", "r");

        while (fread(&p1, sizeof(covid), 1, fp1))
        {
            if (r.patients[p1.number])
            {
                if (p1.gender == 'm' || p1.gender == 'M')
                    ++male;
                else
                    ++female;
            }
        }

        fclose(fp1);

        printf("No. Of Male Patient(s)   : %d\n", male);
        printf("No. Of Female Patient(s) : %d\n", female);
    }

    fclose(fp);
}

// 4C - Age-Wise Patient Summary
void age_count()
{
    FILE *fp;

    fp = fopen("doctor_patient_relation.txt", "r");

    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    relation r;

    while (fread(&r, sizeof(relation), 1, fp))
    {
        printf("Doctor ID : %d\n", r.doc_num);

        covid p1;
        int i;
        FILE *fp1;

        fp1 = fopen("patients.txt", "r");
        // Max Age = 150 [Frequency Array]
        int age[150] = {0};
        while (fread(&p1, sizeof(covid), 1, fp1))
        {
            if (r.patients[p1.number])
                ++age[p1.age];
        }
        fclose(fp1);

        for (i = 0; i < 150; ++i)
        {
            if (age[i])
                printf("Number of Patient(s) of Age %d : %d\n", i, age[i]);
        }
    }
    fclose(fp);
}

// 4D - Area-Wise Patient Summary
void area_count()
{
    FILE *fp;
    fp = fopen("doctor_patient_relation.txt", "r");

    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    relation r;
    while (fread(&r, sizeof(relation), 1, fp))
    {
        printf("Doctor ID : %d\n", r.doc_num);
        covid p1;
        int i;
        FILE *fp1;

        fp1 = fopen("patients.txt", "r");

        while (fread(&p1, sizeof(covid), 1, fp1))
        {
            char area[20];
            char arr[100][20];
            int temp = 0;
            if (r.patients[p1.number])
            {
                int count = 0, flag = 0, i;
                strcpy(area, p1.area);

                for (i = 0; i < temp; ++i)
                {
                    if (strcmp(area, arr[i]) == 0)
                    {
                        flag = 1;
                        break;
                    }
                }

                if (!flag)
                {
                    strcpy(arr[temp], area);
                    ++temp;
                    FILE *fp2;
                    covid p2;

                    fp2 = fopen("patients.txt", "r");
                    while (fread(&p2, sizeof(covid), 1, fp2))
                    {
                        if (strcmp(area, p2.area) == 0)
                        {
                            if (r.patients[p2.number])
                                ++count;
                        }
                    }
                    printf("Number of Patient(s) from Area %s : %d\n", area, count);
                    fclose(fp2);
                }
            }
        }
        fclose(fp1);
    }
    fclose(fp);
}

//-----------------------------DISPLAY_VARIOUS_SUMMARY_REPORTS[START]---------------------------

//-----------------------------SORT_PATIENTS_ASCENDING_ORDER[START]-----------------------------

void sort_ascending()
{
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        sort_adate();
        break;
    case 2:
        sort_ddate();
        break;
    case 3:
        sort_doc();
        break;
    case 4:
        sort_mdoc();
        break;
    case 5:
        sort_fdoc();
        break;
    default:
        printf("Invalid Input\n");
    }
}

int compare_dates(date d1, date d2)
{
    if (d1.yy > d2.yy)
        return 1;

    if (d1.yy < d2.yy)
        return -1;

    if (d1.mm > d2.mm)
        return 1;

    if (d1.mm < d2.mm)
        return -1;

    if (d1.dd > d2.dd)
        return 1;

    if (d1.dd < d2.dd)
        return -1;

    return 0;
}

void sort_adate()
{
    FILE *fp;
    fp = fopen("patients.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    covid p1, arr[100];
    date d;
    printf("Enter Date for which you want to Sort\n");
    scanf("%d %d %d", &d.dd, &d.mm, &d.yy);

    int count = 0;
    while (fread(&p1, sizeof(covid), 1, fp))
    {
        if (compare_dates(d, p1.admission) == 0)
        {
            arr[count++] = p1;
        }
    }
    fclose(fp);

    if (!count)
    {
        printf("No Patient admitted on the Given Date\n");
        return;
    }

    // Bubble Sort the Data Based on First Name
    int i, j;
    for (i = 0; i < count; ++i)
    {
        for (j = 0; j < count - i - 1; ++j)
        {
            if (strcmp(arr[j].first, arr[j + 1].first) > 0)
            {
                p1 = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = p1;
            }
        }
    }

    printf("Sorted Data :\n");
    for (i = 0; i < count; ++i)
    {
        printf("\nPatient Number is : %d", arr[i].number);
        printf("\nFirst Name is : %s", arr[i].first);
        printf("\nLast Name is : %s", arr[i].last);
        printf("\nAge is : %d", arr[i].age);
        printf("\nGender is : %c", arr[i].gender);
        printf("\nArea is : %s", arr[i].area);
        printf("\nAdmission date is : %d/%d/%d", arr[i].admission.dd, arr[i].admission.mm, arr[i].admission.yy);
        printf("\nDischarge date is : %d/%d/%d\n", arr[i].discharge.dd, arr[i].discharge.mm, arr[i].discharge.yy);
    }
}

void sort_ddate()
{
    FILE *fp;
    fp = fopen("patients.txt", "r");

    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    covid p1, arr[100];
    date d;

    printf("Enter Date for which you want to Sort\n");
    scanf("%d %d %d", &d.dd, &d.mm, &d.yy);

    int count = 0;
    while (fread(&p1, sizeof(covid), 1, fp))
    {
        if (compare_dates(d, p1.discharge) == 0)
        {
            arr[count++] = p1;
        }
    }
    fclose(fp);

    if (!count)
    {
        printf("No patient discharged on the given date\n");
        return;
    }
    // Bubble Sort Based on First Name
    int i, j;
    for (i = 0; i < count; ++i)
    {
        for (j = 0; j < count - i - 1; ++j)
        {
            if (strcmp(arr[j].first, arr[j + 1].first) > 0)
            {
                p1 = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = p1;
            }
        }
    }

    printf("Sorted Data :\n");
    for (i = 0; i < count; ++i)
    {
        printf("\nPatient Number is : %d", arr[i].number);
        printf("\nFirst Name is : %s", arr[i].first);
        printf("\nLast Name is : %s", arr[i].last);
        printf("\nAge is : %d", arr[i].age);
        printf("\nGender is : %c", arr[i].gender);
        printf("\nArea is : %s", arr[i].area);
        printf("\nAdmission date is : %d/%d/%d", arr[i].admission.dd, arr[i].admission.mm, arr[i].admission.yy);
        printf("\nDischarge date is : %d/%d/%d\n", arr[i].discharge.dd, arr[i].discharge.mm, arr[i].discharge.yy);
    }
}

void sort_doc()
{
    FILE *fp;
    fp = fopen("doctor_patient_relation.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    relation r, arr[100];
    int d_id, count = 0;
    printf("Enter the Doctor's ID whose patients have to be sorted\n");
    scanf("%d", &d_id);

    while (fread(&r, sizeof(relation), 1, fp))
    {
        arr[count++] = r;
    }
    fclose(fp);

    int count2 = 0;
    covid arr2[100], p;

    int i;
    bool flag = false;
    for (i = 0; i < count; i++)
    {
        if (arr[i].doc_num == d_id)
        {
            FILE *fp1;
            fp1 = fopen("patients.txt", "a+");
            while (fread(&p, sizeof(covid), 1, fp1))
            {
                if (arr[i].patients[p.number])
                {
                    arr2[count2++] = p;
                }
            }
            flag = true;
            fclose(fp1);
            break;
        }
    }

    if (!flag)
    {
        printf("Doctor with the given ID does not exist!\n");
        return;
    }

    if (count2 == 0)
    {
        printf("The doctor has No Patients Assigned!\n");
        return;
    }
    // Bubble Sort the Data Based on First Name
    int j;
    for (i = 0; i < count2; ++i)
    {
        for (j = 0; j < count2 - i - 1; ++j)
        {
            if (strcmp(arr2[j].first, arr2[j + 1].first) > 0)
            {
                p = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = p;
            }
        }
    }

    printf("Sorted Data :\n");
    for (i = 0; i < count2; ++i)
    {
        printf("\nPatient Number is : %d", arr2[i].number);
        printf("\nFirst Name is : %s", arr2[i].first);
        printf("\nLast Name is : %s", arr2[i].last);
        printf("\nAge is : %d", arr2[i].age);
        printf("\nGender is : %c", arr2[i].gender);
        printf("\nArea is : %s", arr2[i].area);
        printf("\nAdmission date is : %d/%d/%d", arr2[i].admission.dd, arr2[i].admission.mm, arr2[i].admission.yy);
        printf("\nDischarge date is : %d/%d/%d\n", arr2[i].discharge.dd, arr2[i].discharge.mm, arr2[i].discharge.yy);
    }
    fclose(fp);
}

void sort_mdoc()
{
    FILE *fp;
    fp = fopen("doctors.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    doctor d, arr[100];
    int count = 0;
    while (fread(&d, sizeof(doctor), 1, fp))
    {
        if (d.gender == 'm' || d.gender == 'M')
        {
            arr[count] = d;
            count++;
        }
    }
    fclose(fp);

    FILE *fp1;
    fp1 = fopen("doctor_patient_relation.txt", "r+");
    relation r, arr1[100];
    int rcount = 0, i, j;
    while (fread(&r, sizeof(relation), 1, fp1))
    {
        arr1[rcount] = r;
        rcount++;
    }
    fclose(fp1);

    for (i = 0; i < count; ++i)
    {
        int d_id = arr[i].number;
        covid p1, arr2[100];
        int pcount = 0;
        for (j = 0; j < rcount; ++j)
        {
            if (arr1[j].doc_num == d_id)
            {
                FILE *fp2;
                fp2 = fopen("patients.txt", "r");
                while (fread(&p1, sizeof(covid), 1, fp2))
                {
                    if (arr1[j].patients[p1.number])
                    {
                        arr2[pcount] = p1;
                        pcount++;
                    }
                }
                fclose(fp2);
                break;
            }
        }

        if (pcount == 0)
        {
            printf("The Male Doctor Don't have any Assigned Patient\n");
            continue;
        }

        int k;
        for (k = 0; k < pcount; ++k)
        {
            for (j = 0; j < pcount - k - 1; ++j)
            {
                if (strcmp(arr2[j].first, arr2[j + 1].first) > 0)
                {
                    p1 = arr2[j];
                    arr2[j] = arr2[j + 1];
                    arr2[j + 1] = p1;
                }
            }
        }
        printf("Male Doctor ID : %d\n", d_id);
        printf("Sorted Patient(s)\n");
        for (i = 0; i < pcount; ++i)
        {
            printf("\nPatient Number is : %d", arr2[i].number);
            printf("\nFirst Name is : %s", arr2[i].first);
            printf("\nLast Name is : %s", arr2[i].last);
            printf("\nAge is : %d", arr2[i].age);
            printf("\nGender is : %c", arr2[i].gender);
            printf("\nArea is : %s", arr2[i].area);
            printf("\nAdmission date is : %d/%d/%d", arr2[i].admission.dd, arr2[i].admission.mm, arr2[i].admission.yy);
            printf("\nDischarge date is : %d/%d/%d\n", arr2[i].discharge.dd, arr2[i].discharge.mm, arr2[i].discharge.yy);
        }
    }
}

void sort_fdoc()
{
    FILE *fp;
    fp = fopen("doctors.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to Load File!\n");
        fclose(fp);
        return;
    }

    doctor d, arr[100];
    int count = 0;
    while (fread(&d, sizeof(doctor), 1, fp))
    {
        if (d.gender == 'f' || d.gender == 'F')
        {
            arr[count++] = d;
        }
    }
    fclose(fp);
    FILE *fp1;
    fp1 = fopen("doctor_patient_relation.txt", "r+");
    relation r, arr1[100];
    int rcount = 0, i, j;
    while (fread(&r, sizeof(relation), 1, fp1))
    {
        arr1[rcount++] = r;
    }
    fclose(fp1);
    for (i = 0; i < count; ++i)
    {
        int d_id = arr[i].number;
        covid p1, arr2[100];
        int pcount = 0;
        for (j = 0; j < rcount; ++j)
        {
            if (arr1[j].doc_num == d_id)
            {
                FILE *fp2;
                fp2 = fopen("patients.txt", "r");
                while (fread(&p1, sizeof(covid), 1, fp2))
                {
                    if (arr1[j].patients[p1.number])
                    {
                        arr2[pcount++] = p1;
                    }
                }
                fclose(fp2);
                break;
            }
        }
        if (pcount == 0)
        {
            printf("The Female Doctor Don't have any Assigned Patient\n");
            continue;
        }
        int k;
        for (k = 0; k < pcount; ++k)
        {
            for (j = 0; j < pcount - k - 1; ++j)
            {
                if (strcmp(arr2[j].first, arr2[j + 1].first) > 0)
                {
                    p1 = arr2[j];
                    arr2[j] = arr2[j + 1];
                    arr2[j + 1] = p1;
                }
            }
        }
        printf("Female Doctor ID : %d\n", d_id);
        printf("Sorted Patients\n");
        for (i = 0; i < pcount; ++i)
        {
            printf("\nPatient Number is : %d", arr2[i].number);
            printf("\nFirst Name is : %s", arr2[i].first);
            printf("\nLast Name is : %s", arr2[i].last);
            printf("\nAge is : %d", arr2[i].age);
            printf("\nGender is : %c", arr2[i].gender);
            printf("\nArea is : %s", arr2[i].area);
            printf("\nAdmission date is : %d/%d/%d", arr2[i].admission.dd, arr2[i].admission.mm, arr2[i].admission.yy);
            printf("\nDischarge date is : %d/%d/%d\n", arr2[i].discharge.dd, arr2[i].discharge.mm, arr2[i].discharge.yy);
        }
    }
}

//-----------------------------SORT_PATIENTS_ASCENDING_ORDER[END]-----------------------------

//-----------------------------------ADD_PATIENTS_SECTION[START]--------------------------------

// 6 - Add Patients in DataBase [Incase of No Patients]
void new_pat_entry()
{
    FILE *fp;
    fp = fopen("patients.txt", "a+");
    printf("~~ENTER PATIENT DETAILS~~\n");

    struct _covid p;

    printf("Patients Number : \n");
    scanf("%d", &p.number);
    printf("Patients First Name : \n");
    fflush(stdin);
    gets(p.first);
    printf("Patients Last Name : \n");
    fflush(stdin);
    gets(p.last);
    printf("Patients Age : \n");
    scanf("%d", &p.age);
    printf("Patients Gender : \n");
    fflush(stdin);
    scanf("%c", &p.gender);
    printf("Patients Admission Date [DD/MM/YYYY] : \n");
    scanf("%d %d %d", &p.admission.dd, &p.admission.mm, &p.admission.yy);
    printf("Patients Discharge Date [DD/MM/YYYY] :  \n");
    scanf("%d %d %d", &p.discharge.dd, &p.discharge.mm, &p.discharge.yy);
    printf("Patient Area of Residence : \n");
    fflush(stdin);
    gets(p.area);

    fwrite(&p, sizeof(struct _covid), 1, fp);
    fclose(fp);

    return;
}

void add_new_patients()
{
    int pcnt;
    printf("Enter the Number of Patient's You Want to Add : ");
    scanf("%d", &pcnt);
    for (int i = 0; i < pcnt; i++)
    {
        new_pat_entry();
    }
    printf("\nSuccessfully Added %d Patients Data in DataBase!!\n", pcnt);
}

//-----------------------------------ADD_PATIENTS_SECTION[END]---------------------------------
