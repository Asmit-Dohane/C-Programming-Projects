//Project 12
//To Do List
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "Task.txt"
#define MAX 10
struct t{
    char task[100];
}tk;
struct display1{
    char task[100];
}ds[MAX];
void info();
void add();
void display();
void mark();
void del();
void exit1();
int main(){
    int a;
    printf("================TO DO LIST==================");
    start:
    info();
    scanf("%d",&a);
    switch(a){
        case 1:
        add(); break;

        case 2:
        display(); break;

        case 3:
        mark(); break;

        case 4:
        del(); break;

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
    printf("\nPress 1 For Add Task");
    printf("\nPress 2 For Display Task");
    printf("\nPress 3 For Mark As Completed");
    printf("\nPress 4 For Delete Task");
    printf("\nPress 5 For Exit");
    printf("\nPress(1-5): ");
}
void add(){
    FILE *fp;
    printf("\nUse UnderScore(_) For Space( )");
    printf("\n Add Task: ");
    scanf("%s",tk.task);
    fp=fopen(FILE_NAME,"a");
    if(fp==NULL){
        printf("\nError File Opening");
        return;
    }
    fprintf(fp,"%s ",tk.task);
    fclose(fp);
    printf("\nTask Added");
}
void display(){
    FILE *fp;
    int i,a=0;
    fp=fopen(FILE_NAME,"r");
    if(fp==NULL){
        printf("\nError File Opening");
        return;
    }
    for(i=1;i<=MAX;i++){
        fscanf(fp,"%s",ds[i].task);
    }
    fclose(fp);
    printf("\n============TASKS============\n");
    for(i=1;i<=MAX;i++){
        a++;
        printf("\n%d) Task:%s",a,ds[i].task);
    }
}
void mark(){
   FILE *fp;
    int i,a=0;
    char name[20]="_(TASK_COMPLETED)";
    fp=fopen(FILE_NAME,"r");
    if(fp==NULL){
        printf("\nError File Opening");
        return;
    }
    for(i=1;i<=MAX;i++){
        fscanf(fp,"%s",ds[i].task);
    }
    fclose(fp);
    printf("\n============TASKS============\n");
    for(i=1;i<=MAX;i++){
        a++;
        printf("\n%d) Task:%s",a,ds[i].task);
    }
    printf("\nEnter Task Number: ");
    scanf("%d",&a);
    for(i=a;i<=a;i++){
        strncat(ds[i].task,name,100);
    }
    printf("Marked As Completed");
    fp=fopen(FILE_NAME,"w");
    if(fp==NULL){
        printf("\nError File Opening");
        printf("\nMark Completed But Not Saved");
        return;
    }
    for(i=1;i<=MAX;i++){
        fprintf(fp,"%s ",ds[i].task);
    }
    fclose(fp);
}
void exit1(){
    exit(0);
}
void del(){
    FILE *fp;
    int i,a=0;
    char name[20]="_(TASK_COMPLETED)";
    fp=fopen(FILE_NAME,"r");
    if(fp==NULL){
        printf("\nError File Opening");
        return;
    }
    for(i=1;i<=MAX;i++){
        fscanf(fp,"%s",ds[i].task);
    }
    fclose(fp);
    printf("\n============TASKS============\n");
    for(i=1;i<=MAX;i++){
        a++;
        printf("\n%d) Task:%s",a,ds[i].task);
    }
    printf("\nEnter Task Number For Delete: ");
    scanf("%d",&a);
    for(i=a;i<=a;i++){
        strcpy(ds[i].task," ");
    }
    printf("\nTask Deleted\n");
    fp=fopen(FILE_NAME,"w");
    if(fp==NULL){
        printf("\nError File Opening");
        printf("\nTask Deleted But Not Saved");
        return;
    }
    for(i=1;i<=MAX;i++){
        fprintf(fp,"%s ",ds[i].task);
    }
    fclose(fp);
}