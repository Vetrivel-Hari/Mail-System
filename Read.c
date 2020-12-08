#include<stdio.h>

void newm(char roll[])
{
    system("cls");

    int i = 1,n,ind;
    char line[999999];
    char path[45]="E:\\C Programs\\Files\\";

    FILE *f;
    sprintf(path,"E:\\C Programs\\Files\\%s.txt",roll);
    f = fopen(path,"r");

    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,"From : "))
        {
            printf("%d. %s",i,line);
            i++;
        }
        if(strstr(line,"Subject : "))
            printf("   %s\n",line);

    }
    fclose(f);
    if(i==1)
    {
        getchar();
        printf("--------------------------------\nYOU HAVE READ ALL THE MESSAGES\n--------------------------------");
        printf("\nPress Any Key to Go Back");
        getchar();
        read(roll);
    }
    printf("\n\nEnter the mail number that you want to open : ");
    scanf("%d",&n);

    f = fopen(path,"r+");

    system("cls");
    i = 1;
    while(fgets(line,sizeof(line),f))
    {

        if(strstr(line,"From : "))
        {
            if(i == n)
            {
                ind = (strlen(line)) * -1;
                fseek(f,ind,SEEK_CUR);
                fprintf(f,"X");
                fseek(f,(ind*-1)-1,SEEK_CUR);
                printf("%s\n",line);
            }

        }
        if(strstr(line,"Subject : "))
        {
             if(i == n)
             {
                ind = (strlen(line)+1) * -1;
                fseek(f,ind,SEEK_CUR);
                fprintf(f,"R");
                fseek(f,(ind*-1)-1,SEEK_CUR);
                printf("%s\n",line);
             }
        }
        if(strstr(line,"Description : "))
        {
            if(i == n)
             {
                ind = (strlen(line)+1) * -1;
                fseek(f,ind,SEEK_CUR);
                fprintf(f,"R");
                fseek(f,(ind*-1)-1,SEEK_CUR);
                printf("%s\n",line);
             }

            i++;
        }
    }
    fclose(f);

}

void oldm(char roll[])
{
    system("cls");

    int i = 1,n;
    char line[999999];
    char path[45]="E:\\C Programs\\Files\\";

    FILE *f;
    sprintf(path,"E:\\C Programs\\Files\\%s.txt",roll);
    f = fopen(path,"r");

    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,"FXom : "))
        {
            line[1] = 'r';
            printf("%d. %s",i,line);
            i++;
        }
        if(strstr(line,"Rubject : "))
        {
            line[0] = 'S';
            printf("   %s\n",line);
        }


    }
    fclose(f);
    if(i==1)
    {
        getchar();
        printf("--------------------------------\nYOU HAVE NO READ\n--------------------------------");
        printf("\nPress Any Key to Go Back");
        getchar();
        read(roll);
    }
    printf("\n\nEnter the mail number that you want to open : ");
    scanf("%d",&n);

    f = fopen(path,"r");

    system("cls");
    i = 1;
    while(fgets(line,sizeof(line),f))
    {

        if(strstr(line,"FXom : "))
        {
            if(i == n)
            {
                line[1] = 'r';
                printf("%s\n",line);
            }

        }
        if(strstr(line,"Rubject : "))
        {
            if(i == n)
            {
                line[0] = 'S';
                printf("%s\n",line);
            }
        }
        if(strstr(line,"Rescription : "))
        {
            if(i == n)
            {
                line[0] = 'D';
                printf("%s\n",line);
            }

            i++;
        }
    }
    fclose(f);

}
void read(char roll[])
{
    int choice;
    system("cls");
    printf("What do you want to read?\n\n");
    printf("1. New  Messages\n");
    printf("2. Read Messages\n");
    printf("3. Go Back\n");

    printf("\nEnter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            newm(roll);
            break;
        case 2:
            oldm(roll);
            break;
        case 3:
            options(roll);
            break;
        default:
            printf("\n-------------------------\nINVALID CHOICE\n-------------------------");
            break;
    }

}
