
#include <stdio.h>
#include <string.h>

int main()
{
    char string[50];
    int flag = 0, count, valid = 1;

    printf("The grammar is: S->aS, S->Sb, S->ab\n");
    printf("Enter the string to be checked:\n");

    scanf("%49s", string);

    if(string[0] != 'a')
        valid = 0;

    for(count = 0; string[count] != '\0'; count++)
    {
        if(string[count] == 'b')
            flag = 1;
        else if(string[count] == 'a' && flag == 1)
            valid = 0;
        else if(string[count] != 'a' && string[count] != 'b')
            valid = 0;
    }

    if(flag == 0)
        valid = 0;

    if(valid)
        printf("String accepted");
    else
        printf("The string does not belong to the specified grammar");

    return 0;
}
