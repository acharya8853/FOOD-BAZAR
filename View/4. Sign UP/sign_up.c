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

int sign_up ()
{
	screen();
	FILE *fp,*fp1;
    int id;
	char c;


	id =  get_ida();

	fp = fopen ("View\\4. Sign UP\\signup.txt","r");
	printf("\n\n");
	while ( (c=fgetc(fp)) != EOF)
	{
		if (c == '\n')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t");
		}
		else
		{
			printf ("%c",c);
		}
	}
	fclose(fp);

    fflush(stdin);
	printf("\n\n\n\t\t\t\t\t\t\t\t\tEnter Full Name: ");
	gets(person.name);
	printf("\n\t\t\t\t\t\t\t\t\tEnter Address: ");
	gets(person.address);
	printf("\n\t\t\t\t\t\t\t\t\tEnter Phone: ");
	gets(person.phone);

	person.id = id;
	id++;

	label1:
	printf("\n\t\t\t\t\t\t\t\t\tEnter Username: ");
	gets(person.username);
	fp = fopen("DataBase\\account_details.txt","r");
	while (fread(&temp,sizeof(temp),1,fp) == 1)
	{
		if (strcmp(person.username,temp.username)==0)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\tUser name Already Taken\n");
			goto label1;
		}
	}
	fclose(fp);

	label2:
	printf("\n\t\t\t\t\t\t\t\t\tEnter Password: ");
	gets(person.password);

	if (strlen(person.password)!=4)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\tThe password must be 4 characters only\n");
		goto label2;
	}

    printf("\n\n\t\t\t\t\t\t\t\t\tDo you want to add this account (y/n)");
    c=getch();

    if (c=='y')
    {
        fp = fopen ("DataBase\\account_details.txt","a");
        fwrite(&person,sizeof(person),1,fp);
        fclose(fp);

        save_ida(id);
    }
}
