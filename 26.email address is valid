%{
#include<stdio.h>
%}
%%
[a-z A-Z 0-9]+(@[a-z]+)(.[a-z]+) {printf("%s is valid email", yytext); }
.* {printf("it is not a valid email");}
%%
int main()
{
printf("\n enter the email:");
yylex();
return 0;
}
int yywrap()
{
}
