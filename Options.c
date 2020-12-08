#include<stdio.h>

void options(char rollno[])
{
    int choice;
    system("cls");
    printf("What do you want to do?\n\n");
    printf("1. Compose\n");
    printf("2. Read\n");
    printf("3. Logout\n");

    printf("\nEnter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            compose(rollno);
            break;
        case 2:
            read(rollno);
            break;
        case 3:
            homepage();
            break;
        default:
            printf("\n-------------------------\nINVALID CHOICE\n-------------------------");
            break;
    }
}
