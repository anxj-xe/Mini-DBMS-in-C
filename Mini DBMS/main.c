#include<stdio.h>
#include<string.h>

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

    printf("Enter Enrollment Number: ");
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
        printf("CGPA: %.2f\n\n", s.CGPA);
    }
}

void searchstudents(){
    struct Student s;
    char key[100];
    int found = 0;

    FILE *fp;
    fp = fopen("student.dat", "rb");

    if(fp==NULL){
        printf("File error!");
        return;
    }

    printf("Enter student's Enrollment Number: ");
    scanf("%99s", key);

    while(fread(&s,sizeof(s),1,fp)){
        if(strcmp(s.id,key) == 0){

            printf("\n***STUDENT FOUND***\n\n");
            printf("Enrollment number: %s\n",s.id);
            printf("Name: %s",s.name);
            printf("Age: %d\n",s.age);
            printf("CGPA: %.2f\n\n", s.CGPA);

            found = 1;
            break;
        }

    }
    if(!found){
        printf("\n**Student not found or Invalid Enrollment number!**\n");
    }
}

void updatestudents(){
    struct Student s;
    int found = 0;
    char key[100];

    printf("Enter Enrollment Number to update: ");
    scanf(" %99s", key);

    FILE *fp, *temp;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");  

    if(fp == NULL || temp == NULL){
        printf("Invalid file!");
        return;
    }
    while(fread(&s,sizeof(s),1,fp)){
        if(strcmp(s.id,key)==0){
            found = 1;

            printf("\n***STUDENT FOUND***\n\n");
            printf("Enrollment number: %s\n",s.id);
            printf("Name: %s",s.name);
            printf("Age: %d\n",s.age);
            printf("CGPA: %.2f\n\n", s.CGPA);

            int updatenum;

            printf("Choose what to update:\n\n");

            printf("1. Enrollment Number\n");
            printf("2. Name\n");
            printf("3. Age\n");
            printf("4. Grade(CGPA)\n\n");

            printf("Enter a number to choose: ");
            scanf("%d", &updatenum);

            char newid[100];
            switch(updatenum){
                case 1:
                    printf("\nEnter updated Enrollment Number: ");
                    scanf("%99s",newid);
                    strcpy(s.id,newid);
                    break;
                case 2:
                    printf("\nEnter updated name: ");
                    getchar();
                    fgets(newid,sizeof(newid),stdin);
                    strcpy(s.name,newid);
                    break;
                case 3:
                    printf("Enter updated age: ");
                    scanf("%d", &s.age);
                    break;
                case 4:
                    printf("Enter updated Grade: ");
                    scanf("%f", &s.CGPA);
                    break;
                default:
                    printf("No update or Invalid update was done.\n");
            }
        }
        fwrite(&s,sizeof(s),1,temp);
    }
    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat","student.dat");

    if(found){
        printf("\nStudent data updated succesfully!\n");
    }
    else{
        printf("\nStudent updation error!!");
    }
}

// ALL THIS BULLSHIT WAS ME TRYING THE FUHH OUTTA ME (IT IS HERE FOR FUTURE REFFERENCE WHAT I DID WRONG!!)

// void updatestudents(){
//     struct Student s;
//     char key[100];
//     int found = 0;

//     FILE *fp;
//     fp = fopen("student.dat", "rb");

//     if(fp==NULL){
//         printf("File error!");
//         return;
//     }

//     printf("Enter student's Enrollment Number: ");
//     scanf("%99s", key);

//     while(fread(&s,sizeof(s),1,fp)){
//         if(strcmp(s.id,key) == 0){
//             int updatenum;

//             printf("Choose what to update:\n");

//             printf("1. Enrollment Number\n");
//             printf("2. Name\n");
//             printf("3. Age\n");
//             printf("4. Grade(CGPA)\n");

//             printf("Enter a number to choose: ");
//             scanf("%d", &updatenum);

//             char newid[100];
//             switch(updatenum){
//                 case 1:
//                     printf("Enter updated Enrollment Number: ");
//                     scanf("%99s",newid);
//                     strcpy(s.id,newid);
//                     printf("Enollment number updated!\n\n");
//                     break;
//                 default:
//                     printf("No update or Invalid update was done.");
//             }
//             FILE *fp;
//             fp = fopen("student.dat", "ab");
//             if(fp == NULL) printf("File error!");
//             fwrite(&s,sizeof(s),1,fp);
//             fclose(fp);
//                     printf("\n***UPDATED INFO***\n\n");
//                     printf("Enrollment number: %s\n",s.id);
//                     printf("Name: %s",s.name);
//                     printf("Age: %d\n",s.age);
//                     printf("CGPA: %.2f\n\n", s.CGPA);
//         }
//     }
// }


// void updatestudents(){
//     struct Student s;
//     int updatenum;

//     searchstudents()

//     printf("Choose what to update:\n");

//     printf("1. Enrollment Number\n");
//     printf("2. Name\n");
//     printf("3. Age\n");
//     printf("4. Grade(CGPA)\n");

//     printf("Enter a number to choose: ");
//     scanf("%d", &updatenum);

//     char newid[100];
//     switch(updatenum){
//         case 1:
//             printf("Enter updated Enrollment Number: ");
//             scanf("%s",&newid);
//             strcpy(s.id,newid);
//             break;
//         default:
//             printf("No update or Invalid update was done.");
//     }
//             printf("Enrollment number: %s\n",s.id);
//             printf("Name: %s",s.name);
//             printf("Age: %d\n",s.age);
//             printf("CGPA: %.2f\n\n", s.CGPA);
// }

void deletestudents(){
    struct Student s;
    int found = 0;
    char key[100];

    printf("Enter Enrollment Number to delete: ");
    scanf(" %99s", key);

    FILE *fp, *temp;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");  

    if(fp == NULL || temp == NULL){
        printf("Invalid file!");
        return;
    }
    while(fread(&s,sizeof(s),1,fp)){
        if(strcmp(s.id,key)==0){
            found = 1;

            printf("\n***STUDENT FOUND***\n\n");
            printf("Enrollment number: %s\n",s.id);
            printf("Name: %s",s.name);
            printf("Age: %d\n",s.age);
            printf("CGPA: %.2f\n\n", s.CGPA);

            continue;
        }
        fwrite(&s,sizeof(s),1,temp);
    }
    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat","student.dat");

    if(found){
        printf("\nStudent removed succesfully!\n");
    }
    else{
        printf("\nStudent not removed!");
    }
}

int main(){

    int choice;
    int exit = 0;

    while(!exit){
        printf("******************************\n");
        printf("     STUDENT MINI DBMS        \n");
        printf("******************************\n\n");

        printf("1. Add Student\n");
        printf("2. View all Students\n");
        printf("3. Search by student ID\n");
        printf("4. Update Student profile\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n\n");

        printf("Enter number to choose: ");
        scanf("%d",&choice);

        printf("\nYou selected option %d.\n\n", choice);

        switch(choice){
            case 1:
                addstudent();
                break;
            case 2:
                viewstudents();
                break;
            case 3:
                searchstudents();
                break;
            case 4:
                updatestudents();
                break;
            case 5:
                deletestudents();
                break;
            case 6:
                printf("Programe closed!");
                exit = 1;
                break;
            default:
                printf("\nInvalid Input!!\n");
        }
    }

    return 0;
}