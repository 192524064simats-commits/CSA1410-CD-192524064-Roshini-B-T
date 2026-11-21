
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char buffer[])
{
    char keywords[32][10] = {
        "main","auto","break","case","char","const",
        "continue","default","do","double","else","enum",
        "extern","float","for","goto","if","int","long",
        "register","return","short","signed","sizeof",
        "static","struct","switch","typedef","unsigned",
        "void","printf","while"
    };

    int i;
    for(i=0; i<32; i++)
    {
        if(strcmp(keywords[i],buffer)==0)
            return 1;
    }
    return 0;
}

int main()
{
    char ch, buffer[100];
    char operators[] = "+-*/%=";
    FILE *fp;
    int i,j=0;

    fp=fopen("C:\\Users\\vinsa\\Desktop\\dev c++\\flex_input.txt.txt","r");

    if(fp==NULL)
    {
        printf("Error while opening the file");
        return 1;
    }

    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='/')
        {
            char next=fgetc(fp);

            if(next=='/')
            {
                while((ch=fgetc(fp))!=EOF && ch!='\n');
                continue;
            }
            else if(next=='*')
            {
                char prev=0;
                while((ch=fgetc(fp))!=EOF)
                {
                    if(prev=='*' && ch=='/')
                        break;
                    prev=ch;
                }
                continue;
            }
            else
            {
                ungetc(next,fp);
            }
        }

        if(isalnum((unsigned char)ch))
        {
            buffer[j++]=ch;
        }
        else
        {
            if(j>0)
            {
                buffer[j]='\0';

                if(isKeyword(buffer))
                    printf("%s is keyword\n",buffer);
                else
                    printf("%s is identifier\n",buffer);

                j=0;
            }

            if(strchr(operators,ch)!=NULL)
                printf("%c is operator\n",ch);
        }
    }

    if(j>0)
    {
        buffer[j]='\0';

        if(isKeyword(buffer))
            printf("%s is keyword\n",buffer);
        else
            printf("%s is identifier\n",buffer);
    }

    fclose(fp);
    return 0;
}
