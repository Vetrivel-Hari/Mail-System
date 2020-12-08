#include<stdio.h>

void display(char code[],char roll[])
{
    system("cls");

    int i=1,n;
    char from_add[65];
    char sub[99999];
    char body[999999];
    char line[512];
    char path[45]="E:\\C Programs\\Files\\";

    FILE *f;
    sprintf(path,"E:\\C Programs\\Files\\users.txt");
    f = fopen(path,"r");

    printf("The available users are : \n\n");
    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,code))
        {
            printf("%d. %s",i,line);
            i++;
        }
        if(strstr(line,roll))
            strcpy(from_add,line);

    }
    fclose(f);
    printf("\n\n");

    printf("Enter the number of users you want to send the mail to : ");
    scanf("%d",&n);

    char nos[n+1][7];
    char user[7];

    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the Roll No. of User %d : ",(i+1));
        for(int j=0;j<6;j++)
        {
            scanf(" %c",&nos[i][j]);
        }
    }

    system("cls");
    fflush(stdin);

    printf("Enter the Subject : \n");
    gets(sub);
    printf("Enter the Description : \n");
    gets(body);

    for(i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)
            user[j] = nos[i][j];

        sprintf(path,"E:\\C Programs\\Files\\%s.txt",user);
        if(f = fopen(path,"a"))
        {
            fputs("From : ",f);
            fputs(from_add,f);
            fprintf(f,"\n");
            fputs("Subject : ",f);
            fputs(sub,f);
            fprintf(f,"\n");
            fputs("Description : ",f);
            fputs(body,f);
            fprintf(f,"\n");
            fclose(f);
        }
        else
            printf("\n-------------------------\nACCOUNT DOESNT EXIST\n-------------------------");

    }
    printf("\n--------------------------\nMESSAGE SENT SUCCESSFULLY\n--------------------------");
}
void compose(char rollno[])
{

    int choice;
    system("cls");

    printf("Which Department Student do you wish to send the Mail?\n\n");
    printf("1. Software Systems\n");
    printf("2. Theoretical Computer Science\n");
    printf("3. Data Science\n");
    printf("4. Cybersecurity\n");

    printf("\nEnter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            display("SS",rollno);
            break;
        case 2:
            display("TCS",rollno);
            break;
        case 3:
            display("DS",rollno);
            break;
        case 4:
            display("CS",rollno);
            break;
        default:
            printf("\n-------------------------\nINVALID CHOICE\n-------------------------");
            break;
    }

}
