//Project 11
//Simple Billing System
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define FILENAME "Bill.txt"
struct bill{
    int price;
    int quantity;
    char name[50];
    float tax;
    int total;
    int aftertax;
}b;
void info();
void input();
void exit1();
void calculate();
void tax();
void display();
void file();
int main(){
    int a;
    printf("\n==================Simple Billing System================\n");
    start:
    info();
    scanf("%d",&a);
    switch(a){
        case 1:
        input(); break;

        case 2:
        calculate(); break;

        case 3:
        tax(); break;

        case 4:
        display(); break;
        
        case 5:
        file(); break;

        case 6:
        exit1(); break;

        default:
        printf("\nInvalid Input"); break;
    }
    goto start;
    getch();
    return 0;
}
void info(){
    printf("\nPress 1 For Input Price And Quantity");
    printf("\nPress 2 For Calculate Total");
    printf("\nPress 3 For Add Tax");
    printf("\nPress 4 For Display Bill");
    printf("\nPress 5 For Store Bills To File");
    printf("\nPress 6 For Exit");
    printf("\nPress(1-6): ");
}
void exit1(){
    exit(0);
}
void input(){
    printf("\nEnter Item Name: ");
    scanf("%s",b.name);
    printf("\nEnter Item Price: ");
    scanf("%d",&b.price);
    printf("\nEnter Item Quantity: ");
    scanf("%d",&b.quantity);
    printf("\nItem Added\n");
}
void calculate(){
    b.total=b.price*b.quantity;
    printf("\nCalculation Comlpeted\n");
}
void tax(){
    b.tax=1.18;
    b.aftertax=b.total*b.tax;
    printf("\nTax Added\n");
}
void display(){
    printf("\n======BILL=======\n");
    printf("\nItem Name:%s",b.name);
    printf("\nItem Price:%d",b.price);
    printf("\nItem Quantity:%d",b.quantity);
    printf("\nItem Total Price:%d",b.total);
    printf("\nTax:%f",b.tax);
    printf("\nItem Total Price After Tax:%d\n",b.aftertax);
}
void file(){
    FILE *fp;
    fp=fopen(FILENAME,"a");
    if(fp==NULL){
        printf("\nError File Opening\n");
        return;
    }
    fprintf(fp,"\n%s %d %d %d %f %d",b.name,b.price,b.quantity,b.total,b.tax,b.aftertax);
    fclose(fp);
    printf("\nReport Generated\n");
}