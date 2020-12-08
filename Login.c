#include<stdio.h>

void login()
{
    system("cls");
    int i,l;

    char rollno[7];
    char pass[20];
    char chk[20];

    fflush(stdin);
    printf("Enter your Roll Number : ");
    gets(rollno);
    printf("Enter your Password : ");
    gets(pass);

    options(rollno);
    //Password checking need to be done
    /*
    char path[45];
    sprintf(path,"E:\\C Programs\\Files\\%s.txt",rollno);

    FILE *f;
    int c = 0;

    l = strlen(pass)>strlen(chk)?strlen(chk):strlen(pass);
    printf("l = %d\n",l);
    if((f = fopen(path,"rw")))
    {
        fgets(chk,sizeof(chk),f);
        printf("%d",strcmp(chk,pass));
        if(!(strcmp(chk,pass)))
        {
            getchar();
            options();
        }

        else
            printf("\n-------------------------\nINCORRECT PASSWORD\n-------------------------");
    }
    else
        printf("\n-------------------------\nACCOUNT DOESNOT EXIST\n-------------------------");*/
}
