
#include<stdio.h>
#include<ctype.h>

int main()
{
    char a[10];
    int flag=1, i=1;

    printf("\nEnter an identifier: ");
    scanf("%9s",a);

    if(isalpha((unsigned char)a[0]))
        flag=1;
    else
        flag=0;

    while(a[i]!='\0')
    {
        if(!isdigit((unsigned char)a[i]) &&
           !isalpha((unsigned char)a[i]))
        {
            flag=0;
            break;
        }
        i++;
    }

    if(flag==1)
        printf("\nValid identifier");
    else
        printf("\nNot a valid identifier");

    return 0;
}
