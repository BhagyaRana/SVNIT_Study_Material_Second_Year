//Function 1 : Write a program to find the length of a given string.

int mystrlen(char str[1000000])
{
    int len = 0;
    for (; str[len] != '\0'; ++len)
    {
        ;
    }
    return len;
};

//Function 2 : Write a program to concate two given string.

static char *mystrconcat(char *str1, char *str2)
{
    int i = 0, j = 0;
    while (str1[i++] != '\0')
        ;
    i--;
    while (str2[j] != '\0')
    {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';

    return str1;
};

//Function 3 : Write a program to copy one string to another string.

void mystrcopy(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    return;
};

//Function 4 : Write a program to compare two given string.

int mystrcomp(char *str1, char *str2)
{
    int i = 0, j = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] == str2[i])
        {
            i++;
            continue;
        }
        else
        {
            return (int)(str1[i] - str2[i]);
        }
    }
    return 0;
};

//Function 5 : Write a program to search for the first occurrence
// of the character ‘c’(any char) in the given string.

int mystroccur(char *str1, char ch)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] == ch)
        {
            return i;
        }
        i++;
    }
    return -1;
};

//Function 6 : Write a program to find sub string is there in given string or not?

int mystrsub(char *str1, char *sub)
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] == sub[j])
        {
            int k = j;
            int oldi = i;
            int flag = 1;
            while (str1[i] != '\0' && sub[k] != '\0')
            {
                if (str1[i] == sub[k])
                {
                    k++;
                    i++;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                return 1; // found
            }
            i = oldi;
        }

        i++;
    }

    return 0; // substring not found
};

//Function 7 : Write a program to generate reverse of a string.

char *mystrrev(char *str1, char *str2)
{
    int len = 0;
    for (; str1[len] != '\0'; ++len)
    {
        ;
    }
    int i = 0;
    for (int j = len - 1; j >= 0; j--)
    {
        str2[i] = str1[j];
        i++;
    }
    str2[i] = '\0';
    return str2;
};
