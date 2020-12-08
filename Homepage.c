#include<stdio.h>
#include<windows.h>

void homepage()
{
    system("cls");
    int choice;
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    //SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 40|50|20|4);
    //system("COLOR 0");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t************************************\n");
    printf("\t\t\t\t\t*\tWELCOME TO AMCS MAIL\t   *\n");
    printf("\t\t\t\t\t************************************\n");
    printf("\t\t\t\t\t|\t\t\t\t   |\n");
    printf("\t\t\t\t\t|\t1.Login \t\t   |\n");
    printf("\t\t\t\t\t|\t\t\t\t   |\n");
    printf("\t\t\t\t\t|\t2.Signup\t\t   |\n");
    printf("\t\t\t\t\t|\t\t\t\t   |\n");
    printf("\t\t\t\t\t|\t3.Exit  \t\t   |\n");
    printf("\t\t\t\t\t|__________________________________|\n\n\n\n");

home :
    printf("\t\t\t\t\tEnter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
            case 1:
                login();
                break;
            case 2:
                signup();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("INVALID CHOICE");
                goto home;
    }
}
int main()
{
    homepage();
    return 0;
}
