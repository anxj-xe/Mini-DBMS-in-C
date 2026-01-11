#include<stdio.h>

struct Student{
    char id[100];
    char name[50];
    int age;
    float CGPA;
};

void addstudent(){
    struct Student s;
    FILE *fp;

    fp = fopen("student.dat", "ab");

    if(fp == NULL){
        printf("File error\n");
        return;
    }

    printf("Enter id: ");
    scanf(" %s", s.id);

    getchar();

    printf("Enter name: ");
    fgets(s.name,sizeof(s.name),stdin);

    printf("Enter age: ");
    scanf("%d", &s.age);

    printf("Enter CGPA: ");
    scanf("%f", &s.CGPA);

    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);

    printf("Student added successfully!");
}

void viewstudents(){
    struct Student s;
    FILE *fp;

    fp = fopen("student.dat", "rb");

    if(fp == NULL){
        printf("File error!");
        return;
    }

    while(fread(&s,sizeof(s),1,fp)){
        printf("Enrollment number: %s\n",s.id);
        printf("Name: %s",s.name);
        printf("Age: %d\n",s.age);
        printf("CGPA: %.2f\n", s.CGPA);
    }
}


int main(){

    int choice;

    printf("******************************\n");
    printf("     Student Mini DBMS        \n");
    printf("******************************\n\n");

    printf("1. Add Student\n");
    printf("2. View all Students\n");
    printf("3. Search by student ID\n");
    printf("4. Update Student profile\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n\n");

    printf("Enter number to choose: ");
    scanf("%d",&choice);

    printf("You selected %d\n\n", choice);

    if(choice == 1){
        addstudent();
    }
    else if(choice == 2){
        viewstudents();
    }

    return 0;
}