#include <stdio.h>
#include <string.h>
#include <conio.h>

struct account_details
{
	int id;
	char name[40];
	char address[20];
	char phone[20];
	char username[10];
	char password[10];
}person,temp;

int update_customer_account(int id)
{
    FILE *fp,*fp1,*fp2;
    char c;
    int flag=0;
    if (id == 1)
    {
        printf("\nCan not Edit\n");
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
        printf("\nDO you want to edit this account (y/n): ");

        c = getche();
        if (c == 'y')
        {
            fflush(stdin);
            printf("\nEnter full Name: ");
            gets(person.name);
            printf ("Enter Address: ");
            gets(person.address);
            printf("Enter Phone: ");
            gets(person.phone);

            label1a:
            printf("Enter Username: ");
            gets(person.username);
            fp2 = fopen("DataBase\\account_details.txt","r");
            while (fread(&temp,sizeof(temp),1,fp2) == 1)
            {
                if (strcmp(person.username,temp.username)==0)
                {
                    printf("User name Already Taken\n");
                    goto label1a;
                }
            }
            fclose(fp2);

            label2a:
            printf("Enter Password: ");
            gets(person.password);

            if (strlen(person.password)!=4)
            {
                printf("The password must be 4 characters only\n");
                goto label2a;
            }

            flag = 1;
            fwrite(&person,sizeof(person),1,fp1);
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
      return 1;
    }
    else
    {
        printf("\nNo id matched\n\n");
        getch();
    }
    label1:
    return 0;
}
