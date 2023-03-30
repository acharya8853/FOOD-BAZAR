#include <stdio.h>

struct food_details
{
	int id;
	char name[20];
	int stock;
	int price;
}food;

void bill(int idf,int quantity,char name[40])
{
    FILE *fp;
    char c;

    fp = fopen("DataBase\\food_details.txt","r");

    while (fread(&food,sizeof(food),1,fp)==1)
    {
        if (food.id == idf)
        {
            break;
        }
    }

    fclose(fp);

    fp = fopen ("View\\3. Login\\3.1. Customer\\bill.txt","r");

    while ( (c=fgetc(fp)) != EOF)
    {
        if (c == '^')
        {
            printf("%-55s*",name);
        }
        else if (c == ')')
        {
            printf("%-28s %-18d %-14d*",food.name,quantity,food.price);
        }
        else if (c == '&')
        {
            printf("%-18d*",quantity*food.price);
        }
        else
        {
            printf("%c",c);
        }
    }

    fclose(fp);

}
