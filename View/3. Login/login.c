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
}person;

int login ()
{
    int i;
    char username[10],password[10];
    char c;
    int found;

    int status =1;
    while (status == 1)
    {
        screen();
        FILE *fp;
        fp = fopen ("View\\3. Login\\login.txt","r");
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

        // Taking User name and Password
        printf("\n\n\t\t\t\t\t\t\t\t\t\tUser name: ");
        scanf("%s",username);
        printf("\n\t\t\t\t\t\t\t\t\t\t");
        printf("Password: ");
        i=0;
        while (i<4)
        {
            c=getch();
            printf("*");
            password[i]=c;
            i++;
        }
        password[i]='\0';

        fp = fopen("DataBase\\account_details.txt","r");
        found = 0;
        while (fread(&person,sizeof(person),1,fp))
        {
            if (strcmp(person.username,username)==0 && strcmp(person.password,password) == 0)
            {
                found = 1;
                break;
            }
            found = 0;
        }
        fclose(fp);

        if (found)
        {
            return person.id;
            label1:
                return 0;
        }
        else
        {
                printf("\n\n\t\t\t\t\t\t\t\t\t !!!The User name or Password did not match!!!\n");
                printf("\n\t\t\t\t\t\t\t\t\t    Press enter to try again and h for help");
                c = getch();
                switch(c)
                {
                case 'h':
                    printf("\n\n\t\t\t\t\t\t\t\t1. Create a account at first before login");
                    printf("\n\t\t\t\t\t\t\t\t2. Press enter to retry");
                    printf("\n\t\t\t\t\t\t\t\t3. Press e to exit");
                    c = getch();
                    switch (c)
                    {
                    case 'e':
                        goto label1;
                    }
                    break;

                case 'e':
                    goto label1;
                }
        }
    }

}
