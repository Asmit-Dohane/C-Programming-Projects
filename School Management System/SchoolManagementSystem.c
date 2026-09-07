//Project 4
//School Management System
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENTS 50
#define FILE_NAME "Students.txt"
struct students
{
    int roll;
    char name[50];
    int marks1;
    int marks2;
}student;
struct all
{
    int roll;
    char name[50];
    int marks1;
    int marks2;
}data[MAX_STUDENTS];
struct find
{
    int roll;
    char name[50];
    int mark;
    int marks;
}fi;
void information();
void find();
void add();
void all();
void save();
void close();
void delet();
int main()
{
    int a;
    printf("==WELL-COME TO SCHOOL MANAGEMENT SYSTEM==");
    start:
    information();
    scanf("%d",&a);
    switch(a){
        case 1:
        add(); break;

        case 2:
        find(); break;

        case 3:
        all(); break;

        case 4:
        save(); break;

        case 5:
        close(); break;

        default:
        printf("\nInvalid Input"); break;
    }
    goto start;
    getch();
}
void information()
{
    
    printf("\n\nPress 1 For add student data");
    printf("\nPress 2 for find student data");
    printf("\nPress 3 for All Students Data");
    printf("\nPress 4 For Save");
    printf("\nPress 5 For Close");
    printf("\nPress(1-5): ");
}
void add()
{
    int i,k;
    printf("\nEnter Student Roll No:");
    scanf("%d",&student.roll);
    printf("\nEnter Student Name:");
    scanf("%s",student.name);
    printf("\nEnter 10th Board Marks:");
    scanf("%d",&student.marks1);
    printf("\nEnter 12th Board Marks:");
    scanf("%d",&student.marks2);  
    printf("\nStudent Data Added\n"); 
}
void find()
{
    FILE *fp;
    int roll,found=0;
    fp=fopen(FILE_NAME,"r");
    if(fp==NULL){
        printf("\nError File Opening\n");
        return;
    }
    printf("\nEnter Student Roll No: ");
    scanf("%d",&roll);
    while(fscanf(fp,"%d %s %d %d",&fi.roll,fi.name,&fi.mark,&fi.marks)!=EOF){
        if(roll==fi.roll){
            printf("\n=======Data Found=======\n");
            printf("\n Student Roll No:%d",fi.roll);
            printf("\nStudent Name:%s",fi.name);
            printf("\nStudent 10th Board Marks:%d",fi.mark);
            printf("\nStudent 12th Board Marks:%d\n",fi.marks);
            found=1;
            break;
        }
    }
    if(!found){
        printf("\n No Student Data Found From %d Roll No\n",roll);
    }
    fclose(fp);
}
void all()
{
    FILE *fp;
    int i;
    fp=fopen(FILE_NAME,"r");
    if(fp==NULL){
        printf("\n Error File Opening\n");
        return;
    }
    for(i=1;i<=MAX_STUDENTS;i++)
    {
        fscanf(fp,"%d %s %d %d",&data[i].roll,data[i].name,&data[i].marks1,&data[i].marks2);
    }
    fclose(fp);
    for(i=1;i<=MAX_STUDENTS;i++)
    {
        printf("\n\n Student Roll no:%d",data[i].roll);
        printf("\n Student Name:%s",data[i].name);
        printf("\n Student 10th Board Marks:%d",data[i].marks1);
        printf("\n Student 12th Board Marks:%d\n",data[i].marks2);
    }
}
void save(){
    FILE *fp;
    fp=fopen(FILE_NAME,"a");
    if(fp == NULL){
        printf("\nError File Opening");
        return;
    }
    fprintf(fp,"\n%d %s %d %d",student.roll,student.name,student.marks1,student.marks2);
    fclose(fp);
    printf("\nStudent Data Saved\n");
}
void close()
{
    exit(0);
}