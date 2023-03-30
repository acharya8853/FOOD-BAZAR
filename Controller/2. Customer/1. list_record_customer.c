#include <stdio.h>
#include <windows.h>

struct account_details
{
	int id;
	char name[40];
	char address[20];
	char phone[20];
	char username[10];
	char password[10];
}person;

void list_record_customer ()
{
    int i,flag;
    char c;
    FILE *fp;

    printf("List of Customers: \n\n");
    printf("ID    Name              Phone\n");

    fp  = fopen("DataBase\\account_details.txt","r");
    flag =0;
    while(fread(&person,sizeof(person),1,fp)==1)
    {
        if (flag != 0)
        {
            printf ("%-5d %-17s %s\n",person.id,person.name,person.phone);
        }
        flag++;
    }

    fclose(fp);
}
