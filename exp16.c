
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char lhs[20], a[20], op[10], b[20];
    char temp[20];
    int j = 1;

    FILE *f1, *f2;

    f1 = fopen("C:\\Users\\vinsa\\Desktop\\dev c++\\sum.txt.txt", "r");

    if(f1 == NULL)
    {
        printf("Error: sum.txt not found!");
        return 1;
    }

    f2 = fopen("C:\\Users\\vinsa\\Desktop\\dev c++\\out.txt", "w");

    if(f2 == NULL)
    {
        printf("Error: Cannot create out.txt!");
        fclose(f1);
        return 1;
    }

    if(fscanf(f1, "%19s %*s %19s %9s %19s", lhs, a, op, b) != 4)
    {
        printf("Invalid input in sum.txt!");
        fclose(f1);
        fclose(f2);
        return 1;
    }

    sprintf(temp, "t%d", j);
    fprintf(f2, "%s=%s%s%s\n", temp, a, op, b);

    while(fscanf(f1, "%19s %9s %19s", op, a, b) == 3)
    {
        j++;

        char previous[20];
        strcpy(previous, temp);

        sprintf(temp, "t%d", j);
        fprintf(f2, "%s=%s%s%s\n", temp, previous, op, a);

        strcpy(a, b);
    }

    fclose(f1);
    fclose(f2);

    printf("Three Address Code generated successfully!");

    return 0;
}
