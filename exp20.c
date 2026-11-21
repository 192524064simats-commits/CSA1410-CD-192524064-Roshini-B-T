
#include <stdio.h>

char arr[18][3] = {
    {'E','+','F'}, {'E','*','F'}, {'E','(','F'},
    {'E',')','F'}, {'E','i','F'}, {'E','$','F'},
    {'F','+','F'}, {'F','*','F'}, {'F','(','F'},
    {'F',')','F'}, {'F','i','F'}, {'F','$','F'},
    {'T','+','F'}, {'T','*','F'}, {'T','(','F'},
    {'T',')','F'}, {'T','i','F'}, {'T','$','F'}
};

char prod[6] = "EETTFF";

char res[6][3] = {
    {'E','+','T'}, {'T','\0','\0'},
    {'T','*','F'}, {'F','\0','\0'},
    {'(','E',')'}, {'i','\0','\0'}
};

char stack[30][2];
int top = -1;

void install(char pro, char re)
{
    int i;

    for(i = 0; i < 18; i++)
    {
        if(arr[i][0] == pro && arr[i][1] == re)
        {
            if(arr[i][2] == 'T')
                return;
            arr[i][2] = 'T';
            top++;
            stack[top][0] = pro;
            stack[top][1] = re;
            return;
        }
    }
}

int main()
{
    int i, j;
    char pro, re, pri = ' ';

    for(i = 0; i < 6; i++)
    {
        for(j = 2; j >= 0; j--)
        {
            if(res[i][j] == '+' || res[i][j] == '*' ||
               res[i][j] == '(' || res[i][j] == ')' ||
               res[i][j] == 'i' || res[i][j] == '$')
            {
                install(prod[i], res[i][j]);
                break;
            }
            else if(res[i][j] == 'E' || res[i][j] == 'F' ||
                    res[i][j] == 'T')
            {
                if(j > 0 && (res[i][j-1] == '+' ||
                   res[i][j-1] == '*' || res[i][j-1] == '(' ||
                   res[i][j-1] == ')' || res[i][j-1] == 'i' ||
                   res[i][j-1] == '$'))
                {
                    install(prod[i], res[i][j-1]);
                    break;
                }
            }
        }
    }

    while(top >= 0)
    {
        pro = stack[top][0];
        re = stack[top][1];
        top--;

        for(i = 0; i < 6; i++)
        {
            if(res[i][0] == pro && res[i][0] != prod[i])
                install(prod[i], re);
        }
    }

    printf("\nTRAILING TABLE\n");

    for(i = 0; i < 18; i++)
        printf("\n\t%c\t%c\t%c", arr[i][0], arr[i][1], arr[i][2]);

    printf("\n\nTRAILING SETS\n");

    for(i = 0; i < 18; i++)
    {
        if(pri != arr[i][0])
        {
            pri = arr[i][0];
            printf("\n%c -> ", pri);
        }

        if(arr[i][2] == 'T')
            printf("%c ", arr[i][1]);
    }

    return 0;
}
