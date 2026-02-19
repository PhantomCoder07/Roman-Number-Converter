#include <stdio.h>
#include <string.h>
#include <ctype.h>
int value (char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return -1;
    }
}
int valid_string (char a, char b)
{
    return (a=='I' && (b=='V' || b=='X')) || (a=='X' && (b=='L' || b=='C')) || (a=='C' && (b=='D' || b=='M'));
}
int roman_conv (const char *s)
{
    int sum=0;
    int n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int v1=value(s[i]);
        if (v1==-1)
            return -1;
        if (i+1<n)
        {
            int v2=value(s[i+1]);
            if (v2==-1)
                return -1;
            if (v1<v2)
            {
                if (!valid_string(s[i],s[i+1]))
                    return -1;
                sum-=v1;
                continue;
            }
        }
        sum+=v1;
    }
    return sum;
}
void int_conv (int num, char *res)
{
    struct map
    {
        int val;
        char *sym;
    };
    struct map mp[]= {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
    res[0]='\0';
    for (int i=0; i<13; i++)
    {
        while (num>=mp[i].val)
        {
            strcat(res,mp[i].sym);
            num-=mp[i].val;
        }
    }
}
int is_valid (const char *s)
{
    int val=roman_conv(s);
    if (val<=0 || val>3999)
        return 0;
    char canonical[50];
    int_conv(val,canonical);
    return strcmp(s,canonical)==0;
}
void converter ()
{
    char s[100];
    printf("Enter the Roman number: ");
    scanf("%s",s);
    for (int i=0; s[i]!='\0'; i++)
        s[i]=toupper(s[i]);
    if (is_valid(s))
        printf("The integer of your input is: %d\n",roman_conv(s));
    else
        printf("Your input is not valid.\n");
}
int main()
{
    int n;
    printf("---------------//Welcome to Roman Number Converter\\\\---------------\n");
    printf("1 - For convert into integer\n");
    printf("0 - If you want to exit\n");
    printf("-------------------------------------------------------------------\n");
    printf("Enter number according to your choice: ");
    scanf("%d",&n);
    printf("-------------------------------------------------------------------\n");
    while (1)
    {
        switch (n)
        {
        case 0:
            printf("Thank you.\n");
            break;
        case 1:
            converter();
            break;
        default:
            printf("Wrong entry\n");
            printf("-------------------------------------------------------------------\n");
            printf("Choice carefully\n");
        }
        printf("-------------------------------------------------------------------\n");
        if (n==0)
            break;
        printf("Do you want to continue?\n");
        printf("1 - Yes\n");
        printf("0 - No\n");
        printf("-------------------------------------------------------------------\n");
        printf("Make your choice: ");
        scanf("%d",&n);
        if (n==0)
        {
            printf("-------------------------------------------------------------------\n");
            printf("Thank you.\n");
            break;
        }
        else
        {
            printf("-------------------------------------------------------------------\n");
            continue;
        }
    }
    return 0;
}
