
%{
#include<stdio.h>
%}

%%
((http)|(ftp))s?:\/\/[A-Za-z0-9][A-Za-z0-9.-]*\.[A-Za-z]{2,}([/?#][^ \t\n]*)? {
    printf("\nURL Valid\n");
}

[^\n]+ {
    printf("\nURL Invalid\n");
}

\n ;
%%

int main()
{
    printf("Enter URL: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
