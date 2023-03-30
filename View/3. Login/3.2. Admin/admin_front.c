#include <stdio.h>
#include <windows.h>

struct food_details
{
	int id;
	char name[20];
	int stock;
	int price;
}food;

void admin_front()
{
    int i;
    char c;
    FILE *fp,*fp1;

    fp = fopen("View\\3. Login\\3.2. Admin\\admin_screen.txt","r");
    fp1 = fopen("DataBase\\food_details.txt","r");

    while ( (c=fgetc(fp)) != EOF)
    {
        if (c == '9')
        {
            i=1;
            while (fread(&food,sizeof(food),1,fp1)==1)
            {
                printf("*    %-3d %-19s %-12d %-12d*\n",i,food.name,food.stock,food.price);
                i++;
            }
        }
        else
        {
            printf("%c",c);
        }
    }

    fclose(fp1);
    fclose(fp);
}
