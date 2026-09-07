//project 3
//Calculator
#include <stdio.h>
#include <conio.h>
int main()
{
    int a,b,c;
    char operator;
    printf("============================CALCULATOR==============================");
    printf("\n Enter Operator (+,-,*,/,):");
    scanf("%c",&operator);
    printf("\n Enter First Value: ");
    scanf("%d",&a);
    printf("\n Enter Second Value: ");
    scanf("%d",&b);
    switch(operator)
    {
        case '+':
        c=a+b;
        printf("\n Answer Is:%d",c); break;

        case '-':
        c=a-b;
        printf("\n Answer Is:%d",c); break;

        case '*':
        c=a*b;
        printf("\n Answer Is:%d",c); break;

        case '/':
        c=a/b;
        printf("\n Answer Is:%d",c); break;

        default:
        printf("\n Invalid Operator");
        break;
    }
    getch();
}