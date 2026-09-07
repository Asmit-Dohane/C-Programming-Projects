//Contact Management System
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define FILE_NAME "contact.txt"
#define MAX_CONTACTS 10
struct contact{
    int num;
    char name[50];
    char email[60];
}store;
struct display{
    int num;
    char name[50];
    char email[60];
}dp[MAX_CONTACTS];
struct search{
    int num;
    char name[50];
    char email[60];
}sr;
void info();
void add();
void save();
void exit1();
void display();
void search();
int main(){
    int a;
    printf("\n=========================Contact Management System==============================");
    start:
    info();
    scanf("%d",&a);
    switch(a){
        case 1:
        add(); break;

        case 2:
        display(); break;

        case 3:
        search(); break;

        case 4:
        save(); break;

        case 5:
        exit1(); break;

        default:
        printf("\nInvalid Input"); break;
    }
    goto start;
    getch();
    return 0;
}
void info(){
    printf("\n\nPress 1 For Add Contact");
    printf("\nPress 2 For Display Contact"); 
    printf("\nPress 3 For Search Contact");
    printf("\nPress 4 For Save To File");
    printf("\nPress 5 For Exit");
    printf("\nPress(1-5): ");
}
void add(){
    printf("\nEnter Contact 9 Digit Phone Number: ");
    scanf("%d",&store.num);
    printf("\nEnter Contact Name: ");
    scanf("%s",store.name);
    printf("\nEnter Contact Email Address: ");
    scanf("%s",store.email);
    printf("\nContact Added");
}
void save(){
    FILE *fp;
    fp=fopen(FILE_NAME,"a+");
    fprintf(fp,"\n%d %s %s",store.num,store.name,store.email);
    fclose(fp);
    printf("\nContact Saved");
}
void exit1(){
    exit(0);
}
void display(){
    FILE *fp;
    int i;
    fp=fopen(FILE_NAME,"a+");
    for(i=1;i<=MAX_CONTACTS;i++){
        fscanf(fp,"%d %s %s",&dp[i].num,dp[i].name,dp[i].email);
    }
    fclose(fp);
    for(i=1;i<=MAX_CONTACTS;i++){
        printf("\nContact Phone Number:%d",dp[i].num);
        printf("\nContact Name:%s",dp[i].name);
        printf("\nContact Email Address:%s",dp[i].email);
    }
}
void search(){
    FILE *fp;
    int num,FOUND=0;
    fp=fopen(FILE_NAME,"r");
    if(fp==NULL){
        printf("\nError File Opening");
        return;
    }
    printf("\nEnter Contact Number: ");
    scanf("%d",&num);
    while(fscanf(fp,"%d %s %s",&sr.num,sr.name,sr.email)!=EOF){
        if(num==sr.num){
            printf("\n=======Contact Found=======\n");
            printf("\nContact Number: %d",sr.num);
            printf("\nContact Name:%s",sr.name);
            printf("\nContact Email:%s",sr.email);
            FOUND=1;
            break;
        }
    }
    if(!FOUND){
        printf("\nNo Contact Found");
    }
    fclose(fp);
}