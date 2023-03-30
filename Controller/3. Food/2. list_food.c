#include <stdio.h>
#include <conio.h>

struct food_details
{
	int id;
	char name[20];
	int stock;
	int price;
}food;

void list_food ()
{
    FILE *fp;

    fp = fopen ("DataBase\\food_details.txt","r");

    printf("List of Foods: \n\n");
    printf("ID    Name            Stock        Price\n");
    while (fread(&food,sizeof(food),1,fp)==1)
    {
        printf("%-5d %-16s %-12d %-12d\n",food.id,food.name,food.stock,food.price);
    }

    fclose(fp);
}
