#include <stdio.h>

struct account_details
{
	int id;
	char name[40];
	char address[20];
	char phone[20];
	char username[10];
	char password[10];
}person;

struct food_details
{
	int id;
	char name[20];
	int stock;
	int price;
}food;

void customer_screen (int id)
{
    FILE *fp,*fp1;
    char c;
    int i;
    fp = fopen ("DataBase\\account_details.txt","r");

    while (fread(&person,sizeof(person),1,fp)==1)
    {
        if (person.id == id)
        {
            break;
        }
    }
    fclose(fp);

    printf("Logged in as customer: \n");
    printf("Name: %s\t\tPhone:%s\n\n\n",person.name,person.phone);

    fp = fopen("DataBase\\food_details.txt","r");
    fp1 = fopen("View\\3. Login\\3.1. Customer\\customer_screen.txt","r");

    while ( (c=fgetc(fp1)) != EOF)
    {
        if (c == '9')
        {
            while (fread(&food,sizeof(food),1,fp)==1)
            {
                printf("*  %-5d %-12s", food.id,food.name);

                for (i=0;i<food.stock;i++)
                {
                    printf("* ");
                }

                for (i = i ;i <35;i++)
                {
                    printf("  ");
                }

                printf("%-9d*\n*%100c\n",food.price,'*');
            }
        }
        else if (c == '1')
        {

        }
        else
        {
            printf("%c",c);
        }
    }

    fclose(fp);
    fclose(fp1);

}
