
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[20], stack[20];
int ip = 0, top = -1, len;

void check()
{
    int i;

    if(top >= 0 && (stack[top] == 'a' || stack[top] == 'b'))
    {
        char ch = stack[top];
        stack[top] = 'E';
        printf("\n$%s\t\t%s$\t\tE->%c", stack, input + ip, ch);
    }

    if(top >= 2 &&
       stack[top-2] == 'E' &&
       (stack[top-1] == '+' || stack[top-1] == '*' || stack[top-1] == '/') &&
       stack[top] == 'E')
    {
        char op = stack[top-1];
        top -= 2;
        stack[top] = 'E';
        stack[top+1] = '\0';

        printf("\n$%s\t\t%s$\t\tE->E%cE", stack, input + ip, op);
    }
}

int main()
{
    printf("\n\tSHIFT REDUCE PARSER\n");
    printf("\nGRAMMAR\n");
    printf("E->E+E\nE->E/E\nE->E*E\nE->a/b\n");

    printf("\nEnter the input symbol: ");
    scanf("%19s", input);

    len = strlen(input);

    printf("\nStack\t\tInput Symbol\tAction\n");
    printf("$\t\t%s$\t\t--", input);

    while(ip < len)
    {
        stack[++top] = input[ip++];
        stack[top+1] = '\0';

        printf("\n$%s\t\t%s$\t\tShift", stack, input + ip);

        check();
    }

    if(top == 0 && stack[0] == 'E')
        printf("\n$E\t\t$\t\tACCEPT");
    else
        printf("\nString rejected");

    return 0;
}
