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

struct food_details
{
	int id;
	char name[20];
	int stock;
	int price;
}food;

void order (int id)
{
    int idf, quantity, valid;
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
            break;
        }
        else
        {
            printf("%c",c);
        }
    }

    fclose(fp);
    fclose(fp1);

    printf("\n\nOrder Foood: \n\n");

    valid = 0;
    while (valid == 0)
    {
        printf("Enter the food ID: ");
        scanf("%d",&idf);

        fp = fopen("DataBase\\food_details.txt","r");
        while (fread(&food,sizeof(food),1,fp)==1)
        {
            if (food.id == idf)
            {
                break;
            }
        }
        fclose(fp);
        if (food.id != idf)
        {
            printf("The id did not matched, ");
        }
        else
        {
            valid = 1;
        }

    }

    valid = 0;
    while (valid == 0)
    {
        printf("Enter the quantity: ");
        scanf("%d",&quantity);

        if (food.stock >= quantity)
        {
            if (quantity < 1)
            {
                printf("Invalid Quantity, ");
            }
            else
            {
                valid = 1;
                break;
            }

        }
        else
        {
            printf("Sorry , we don't have the required stock, ");
        }
    }

    printf("\n\nDo you want to make this order (y/n)? ");
    c = getch();

    if (c == 'y')
    {
        system("cls");
        bill(idf,quantity,person.name);

        fp = fopen("DataBase\\food_details.txt","r");
        fp1 = fopen ("DataBase\\temp.txt","w");

        while (fread(&food,sizeof(food),1,fp)==1)
        {
            if (food.id == idf)
            {
                food.stock = food.stock - quantity;
            }

            fwrite(&food,sizeof(food),1,fp1);
        }

        fclose(fp);
        fclose(fp1);

        fp = fopen("DataBase\\food_details.txt","w");
        fp1 = fopen ("DataBase\\temp.txt","r");

        while (fread(&food,sizeof(food),1,fp1)==1)
        {
            fwrite(&food,sizeof(food),1,fp);
        }

        fclose(fp);
        fclose(fp1);
    }
}
