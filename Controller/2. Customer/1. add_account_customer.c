#include <stdio.h>
#include <conio.h>
#include <string.h>

struct account_details
{
	int id;
	char name[40];
	char address[20];
	char phone[20];
	char username[10];
	char password[10];
}person,temp;

void add_account_customer (int *id)
{
    FILE *fp;
    char c;
    fflush(stdin);
    printf("Add Account: \n\n");
    printf("Enter full Name: ");
    gets(person.name);
    printf ("Enter Address: ");
    gets(person.address);
    printf("Enter Phone: ");
    gets(person.phone);

    person.id = *id;

    label1:
    printf("Enter Username: ");
    gets(person.username);
    fp = fopen("DataBase\\account_details.txt","r");
    while (fread(&temp,sizeof(temp),1,fp) == 1)
    {
        if (strcmp(person.username,temp.username)==0)
        {
            printf("User name Already Taken\n");
            goto label1;
        }
    }
    fclose(fp);

    label2:
    printf("Enter Password: ");
    gets(person.password);

    if (strlen(person.password)!=4)
    {
        printf("The password must be 4 characters only\n");
        goto label2;
    }

    printf("Do you want to add this account (y/n)");
    c=getch();

    if (c=='y')
    {
        fp = fopen ("DataBase\\account_details.txt","a");
        fwrite(&person,sizeof(person),1,fp);
        fclose(fp);
    }
    else
    {
        *id = *id -1;
    }
}
