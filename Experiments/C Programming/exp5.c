
#include <stdio.h>

int main()
{
    char str[100];

    int words=0, newline=0, characters=0;

    printf("Enter the text (use ~ to stop):\n");

    scanf("%99[^~]", str);

    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]==' ')
        {
            words++;
        }
        else if(str[i]=='\n')
        {
            newline++;
            words++;
        }
        else
        {
            characters++;
        }
    }

    if(characters>0)
    {
        words++;
        newline++;
    }

    printf("\nTotal number of words : %d\n",words);
    printf("Total number of lines : %d\n",newline);
    printf("Total number of characters : %d\n",characters);

    return 0;
}
