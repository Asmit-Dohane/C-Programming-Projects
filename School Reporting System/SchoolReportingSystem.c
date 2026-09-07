/*Project 10
School Reporting System */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define FILE_NAME "report.txt"
#define MAX_STUDENTS 1
struct student
{
    char name[50];
    int roll;
    int eng;
    int mar;
    int math;
    int phy;
    int che;
    int bio;
    int all;
    float perc;
}st[MAX_STUDENTS];
void info();
void add();
void calculate();
void generate();
void display();
void exit1();
int main(){
    int a;
    printf("====================School Reporting System====================\n");
    start:
    info();
    scanf("%d",&a);
    switch(a){
        case 1:
        add(); break;

        case 2:
        calculate(); break;

        case 3:
        display(); break;

        case 4:
        generate(); break;

        case 5:
        exit1(); break;

        default:
        printf("Invalid Input"); break;
    }
    goto start;
    getch();
    return 0;
}
void info(){
    printf("\nPress 1 For Add Student Data");
    printf("\nPress 2 For Calculate Marks");
    printf("\nPress 3 For Display Student Ranking");
    printf("\nPress 4 For Generate Report");
    printf("\nPress 5 For Exit");
    printf("\nPress(1-5): ");
}
void add(){
    int i;
    for(i=1;i<=MAX_STUDENTS;i++){
        printf("\nEnter Student Name: ");
        scanf("%s",st[i].name);
        printf("\nEnter Student Roll No: ");
        scanf("%d",&st[i].roll);
        printf("\nEnter English Subject Marks: ");
        scanf("%d",&st[i].eng);
        printf("\nEnter Marathi Subject Marks: ");
        scanf("%d",&st[i].mar);
        printf("\nEnter Mathmatics Subject Marks: ");
        scanf("%d",&st[i].math);
        printf("\nEnter Physics Subject Marks: ");
        scanf("%d",&st[i].phy);
        printf("\nEnter Chemistry Subject Marks: ");
        scanf("%d",&st[i].che);
        printf("\nEnter Biology Subject Marks: ");
        scanf("%d",&st[i].bio);
    }
    printf("\nStudent Data Successfully Added\n");
}
void calculate(){
    int i;
    for(i=1;i<=MAX_STUDENTS;i++){
        st[i].all=st[i].eng+st[i].mar+st[i].math+st[i].phy+st[i].che+st[i].bio;
        st[i].perc=st[i].all/6;
    }
    printf("\nCalculation Complited You Can Display Data And Generate Report\n");
}
void generate(){
    int i;
    FILE *fp;
    for(i=1;i<=MAX_STUDENTS;i++){
        printf("%d",st[i].all);
        printf("%f",st[i].perc);
    }
    fp=fopen(FILE_NAME,"w");
    if(fp==NULL){
        printf("\nError File Opening");
        return;
    }
    for(i=1;i<=MAX_STUDENTS;i++){
        fprintf(fp,"\nStudent Name: %s \nStudent Roll no: %d \nStudent English Subject Marks: %d \nStudent Marathi Subject Marks: %d \nStudent Mathmatics Subject Marks: %d \nStudent Physics Subject Marks: %d \nStudent Chemistry Subject Marks: %d \nStudent Biology Subject Marks: %d \nStudent Total Subject Marks: %d \nStudent Percentage: %f",st[i].name,st[i].roll,st[i].eng,st[i].mar,st[i].math,st[i].phy,st[i].che,st[i].bio,st[i].all,st[i].perc);
    }
    fclose(fp);
    printf("\nReport Generated");
}
void exit1(){
    exit(0);
}
void display(){
    int i;
    printf("\n=================Student Ranking===============\n");
    for(i=1;i<=MAX_STUDENTS;i++){
        printf("\nStudent Name: %s",st[i].name);
        printf("\nStudent Roll No: %d",st[i].roll);
        printf("\nEnglish Subject Marks: %d",st[i].eng);
        printf("\nMarathi Subject Marks: %d",st[i].mar);
        printf("\nMathmatics Subject Marks: %d",st[i].math);
        printf("\nPhysics Subject Marks: %d",st[i].phy);
        printf("\nChemistry Subject Marks: %d",st[i].che);
        printf("\nBiology Subject Marks: %d",st[i].bio);
        printf("\nTotal Calculated Marks Of Student: %d",st[i].all);
        printf("\nPercentage Of Student: %f\n",st[i].perc);
    }
}