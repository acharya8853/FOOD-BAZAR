#include <stdio.h>
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

void delete_account_customer(int id)
{
    FILE *fp,*fp1;
    char c;
    int flag=0;
    if (id == 1)
    {
        printf("\nCan not delete\n");
        getch();
        goto label1;
    }

    fp = fopen("DataBase\\account_details.txt","r");
    fp1 = fopen("DataBase\\temp.txt","w");

    while(fread(&person,sizeof(person),1,fp)==1)
    {
      if (person.id == id)
      {
        printf("ID    Name              Phone\n");
        printf ("%-5d %-17s %s\n",person.id,person.name,person.phone);
        printf("\nDO you want to delete this account (y/n): ");

        c = getch();
        if (c == 'y')
        {
            flag = 1;
        }
        else
        {
            goto label1;
        }
      }
      else
      {
        fwrite(&person,sizeof(person),1,fp1);
      }
    }

    fclose(fp);
    fclose(fp1);

    if (flag == 1)
    {
    fp = fopen("DataBase\\account_details.txt","w");
    fp1 = fopen("DataBase\\temp.txt","r");
      while(fread(&person,sizeof(person),1,fp1)==1)
      {
        fwrite(&person,sizeof(person),1,fp);
      }
      fclose(fp);
      fclose(fp1);
    }
    else
    {
        printf("\nNo id matched\n\n");
        getch();
    }

    label1:
    return;
}
