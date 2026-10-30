
%{
#include<stdio.h>
#include<stdlib.h>

int com=0;
%}

%s COMMENT

%%
"/*" {
    BEGIN COMMENT;
}

<COMMENT>"*/" {
    BEGIN 0;
    com++;
}

<COMMENT>\n {
    com++;
}

<COMMENT>. ;

\/\/.* {
    com++;
}

.|\n {
    fprintf(yyout,"%s",yytext);
}
%%

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("Usage: comment.exe input.c output.c\n");
        return 1;
    }

    yyin=fopen(argv[1],"r");
    yyout=fopen(argv[2],"w");

    if(yyin==NULL || yyout==NULL)
    {
        printf("File opening error\n");
        return 1;
    }

    yylex();

    printf("\nNumber of comments are = %d\n",com);

    fclose(yyin);
    fclose(yyout);

    return 0;
}

int yywrap()
{
    return 1;
}
