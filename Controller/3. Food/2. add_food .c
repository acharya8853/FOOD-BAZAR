#include <stdio.h>
#include <conio.h>
#include <string.h>

struct food_details
{
	int id;
	char name[20];
	int stock;
	int price;
}food;


void add_food (int *id)
{
    FILE *fp;
    char c;
    fflush(stdin);
    printf("Add Food: \n\n");
    printf("Enter Food Name: ");
    gets(food.name);
    printf ("Enter Stock: ");
    scanf("%d",&food.stock);
    printf("Enter Price: ");
    scanf("%d",&food.price);

    food.id = *id;

    printf("Do you want to add this food (y/n)");
    c=getch();

    if (c=='y')
    {
        fp = fopen ("DataBase\\food_details.txt","a");
        fwrite(&food,sizeof(food),1,fp);
        fclose(fp);
    }
    else
    {
        *id = *id -1;
    }
}
