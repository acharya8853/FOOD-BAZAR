#include <stdio.h>
#include <windows.h>
#include <conio.h>

struct account_details
{
	int id;
	char name[40];
	char address[20];
	char phone[20];
	char username[10];
	char password[10];
}person;

void detailed_customer_account(int id)
{
    int flag;
    FILE *fp;

    if (id == 1)
    {
        printf("\nCan not Show\n");
        getch();
        goto label1;
    }

    flag=0;
    fp = fopen("DataBase\\account_details.txt","r");

    while(fread(&person,sizeof(person),1,fp)==1)
    {
      if (person.id == id)
      {
        printf("ID    Name              Address      Phone         Username     Password\n");
        printf ("%-5d %-17s %-12s %-13s %-12s %s\n",person.id,person.name,person.address,person.phone,person.username,person.password);
        flag=1;
        getch();
      }
    }

    fclose(fp);
    if (flag == 0)
    {
        printf("\nNo id matched\n\n");
        getch();
    }

    label1:
    return;
}

