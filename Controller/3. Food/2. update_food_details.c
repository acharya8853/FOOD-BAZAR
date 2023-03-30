#include <stdio.h>
#include <string.h>
#include <conio.h>

struct food_details
{
	int id;
	char name[20];
	int stock;
	int price;
}food;

void update_food_details(int id)
{
    FILE *fp,*fp1;
    char c;
    int flag=0;

    fp = fopen("DataBase\\food_details.txt","r");
    fp1 = fopen("DataBase\\temp.txt","w");

    while(fread(&food,sizeof(food),1,fp)==1)
    {
      if (food.id == id)
      {
        printf("ID    Name            Stock        Price\n");
        printf("%-5d %-16s %-12d %-12d\n",food.id,food.name,food.stock,food.price);

        printf("\nDO you want to update this food details (y/n): ");

        c = getche();
        if (c == 'y')
        {
            fflush(stdin);
            printf("\nEnter Food Name: ");
            gets(food.name);
            printf ("Enter Stock: ");
            scanf("%d",&food.stock);
            printf("Enter Price: ");
            scanf("%d",&food.price);

            flag = 1;
            fwrite(&food,sizeof(food),1,fp1);
        }
        else
        {
            goto label1;
        }
      }
      else
      {
        fwrite(&food,sizeof(food),1,fp1);
      }
    }

    fclose(fp);
    fclose(fp1);

    if (flag == 1)
    {
    fp = fopen("DataBase\\food_details.txt","w");
    fp1 = fopen("DataBase\\temp.txt","r");
      while(fread(&food,sizeof(food),1,fp1)==1)
      {
        fwrite(&food,sizeof(food),1,fp);
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
