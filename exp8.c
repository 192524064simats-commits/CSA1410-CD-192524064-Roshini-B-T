
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][20];
char first[26][30], follow[26][30];
int n;

int add(char set[], char ch)
{
    int i;
    for(i = 0; set[i] != '\0'; i++)
        if(set[i] == ch)
            return 0;

    set[i] = ch;
    set[i + 1] = '\0';
    return 1;
}

int findFirst(char *s, char result[])
{
    int i, j, nullable = 1, changed = 0;
    result[0] = '\0';

    for(i = 0; s[i] != '\0' && nullable; i++)
    {
        nullable = 0;

        if(islower((unsigned char)s[i]))
            changed |= add(result, s[i]);
        else if(isupper((unsigned char)s[i]))
        {
            for(j = 0; first[s[i]-'A'][j] != '\0'; j++)
            {
                if(first[s[i]-'A'][j] == '$')
                    nullable = 1;
                else
                    changed |= add(result, first[s[i]-'A'][j]);
            }
        }
        else if(s[i] == '$')
            nullable = 1;
    }

    if(nullable)
        changed |= add(result, '$');

    return changed;
}

int main()
{
    int i, j, k, changed;
    char temp[30];

    printf("Enter Total Number of Productions: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Production %d: ", i + 1);
        scanf("%19s", production[i]);
    }

    do
    {
        changed = 0;

        for(i = 0; i < n; i++)
        {
            char lhs = production[i][0];
            char *rhs = production[i] + 2;
            changed |= findFirst(rhs, first[lhs-'A']);
        }

        for(i = 0; i < n; i++)
            if(i == 0)
                changed |= add(follow[production[i][0]-'A'], '$');

        for(i = 0; i < n; i++)
        {
            char lhs = production[i][0];
            char *rhs = production[i] + 2;

            for(j = 0; rhs[j] != '\0'; j++)
            {
                if(isupper((unsigned char)rhs[j]))
                {
                    findFirst(rhs + j + 1, temp);

                    for(k = 0; temp[k] != '\0'; k++)
                        if(temp[k] != '$')
                            changed |= add(follow[rhs[j]-'A'], temp[k]);

                    if(temp[0] == '\0' || strchr(temp, '$') != NULL)
                    {
                        for(k = 0; follow[lhs-'A'][k] != '\0'; k++)
                            changed |= add(follow[rhs[j]-'A'], follow[lhs-'A'][k]);
                    }
                }
            }
        }
    } while(changed);

    for(i = 0; i < n; i++)
    {
        char ch = production[i][0];

        printf("\nFOLLOW(%c) = { ", ch);
        for(j = 0; follow[ch-'A'][j] != '\0'; j++)
            printf("%c ", follow[ch-'A'][j]);
        printf("}\n");
    }

    return 0;
}
