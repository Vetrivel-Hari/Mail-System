#include<stdio.h>
#include<string.h>

typedef struct UserDef{
        char name[50];
        char rollno[7];
        char dob[11];
        char dep[3];
        char passwd[20];
        char rpasswd[20];
    }user;

void addnewuser(user A)
{
    FILE *f;
    f = fopen("E:\\C Programs\\Files\\users.txt","a");
    fputs(A.name,f);
    fputs("(",f);
    fputs(A.dep,f);
    fputs(")",f);
    fputs(" - ",f);
    fputs(A.rollno,f);
    fprintf(f,"\n");
    fclose(f);

    char path[45];
    sprintf(path,"E:\\C Programs\\Files\\%s.txt",A.rollno);
    f = fopen(path,"a");
    fputs(A.passwd,f);
    fprintf(f,"\n");
    fputs("Name : ",f);
    fputs(A.name,f);
    fprintf(f,"\n");
    fputs("Rollno : ",f);
    fputs(A.rollno,f);
    fprintf(f,"\n");
    fputs("DOB : ",f);
    fputs(A.dob,f);
    fprintf(f,"\n");
    fputs("Department : ",f);
    fputs(A.dep,f);
    fprintf(f,"\n");
    fclose(f);

    printf("\n-------------------------\nACCOUNT CREATED\n-------------------------");
    getchar();
    homepage();

}

int isExistingUser(user A)
{
    FILE *f;
    f = fopen("E:\\C Programs\\Files\\users.txt","r");
    while(fgets(A.name, sizeof(A.name),f))
    {
        if(strstr(A.name,A.rollno))
        {
            fclose(f);
            return 1;

        }
    }
    fclose(f);
    return 0;
}
void signup()
{
    system("cls");

    user newuser;

    fflush(stdin);

    printf("Enter your Name : \n");
    gets(newuser.name);
    printf("Enter your Roll Number : \n");
    gets(newuser.rollno);
    printf("Enter your Date Of Birth(xx-xx-xxxx) : \n");
    gets(newuser.dob);
    printf("Enter your Department Name(SS/TCS/DS/CS) : \n");
    gets(newuser.dep);
    printf("Enter your Password : \n");
    gets(newuser.passwd);
    printf("Re-Enter your Password : \n");
    gets(newuser.rpasswd);

    if(!(strcmp(newuser.passwd,newuser.rpasswd)))
    {
        if(isExistingUser(newuser))
            printf("\n-------------------------\nACCOUNT ALREADY EXISTS\n-------------------------");
        else
            addnewuser(newuser);

    }
    else
        printf("Password Mismatch");
}
