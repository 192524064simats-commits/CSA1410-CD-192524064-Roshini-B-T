
#include <stdio.h>
#include <string.h>

char input[50], stack[50];
int i = 0, top = 0, l;

char handles[][5] = {")E(", "E*E", "E+E", "i", "E^E"};

char prec[9][9] = {
    {'>', '>', '<', '<', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '>', 'e', 'e', '>', '>'},
    {'<', '<', '<', '<', '<', '<', '<', '>', 'e'},
    {'>', '>', '>', '>', '>', 'e', 'e', '>', '>'},
    {'<', '<', '<', '<', '<', '<', '<', '<', '>'}
};

int getindex(char c)
{
    switch(c)
    {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '^': return 4;
        case 'i': return 5;
        case '(': return 6;
        case ')': return 7;
        case '$': return 8;
    }
    return 8;
}

void shift()
{
    stack[++top] = input[i++];
    stack[top + 1] = '\0';
}

int reduce()
{
    int k, len, found, t;

    for(k = 0; k < 5; k++)
    {
        len = strlen(handles[k]);

        if(top + 1 >= len)
        {
            found = 1;

            for(t = 0; t < len; t++)
            {
                if(stack[top - t] != handles[k][t])
                {
                    found = 0;
                    break;
                }
            }

            if(found)
            {
                stack[top - t + 1] = 'E';
                top = top - t + 1;
                stack[top + 1] = '\0';
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    printf("Enter the string:\n");
    scanf("%49s", input);

    strcat(input, "$");
    l = strlen(input);

    strcpy(stack, "$");

    printf("\nSTACK\tINPUT\tACTION\n");

    while(i < l - 1)
    {
        shift();

        printf("\n%s\t%s\tShift", stack, input + i);

        while(reduce())
            printf("\n%s\t%s\tReduce");
    }

    if(strcmp(stack, "$E") == 0)
        printf("\nAccepted");
    else
        printf("\nNot Accepted");

    return 0;
}
