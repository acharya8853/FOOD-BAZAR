#include <stdio.h>

struct food_details
{
    int id;
    char name[20];
    int stock;
    int price;
}food;

void food_details_screen ()
{
    int id = get_idf();
    int id1;
    int status=1;
    char choice;

    while (status ==1)
    {
        screen();
        printf("Administrator --> Food Details\n\n");
        printf("Tools: \n");
        printf("  Stock Food\n");
        printf("  Add Food\n");
        printf("  List Food Detials\n");
        printf("  Delete Food\n");
        printf("  Update Food Details\n");
        printf("  Exit\n");

        choice = getch();
        switch (choice)
        {
            case 'a':
                screen();
                add_food (&id);
                id++;
                break;

            case 'l':
                screen();
                list_food();
                getch();
                break;

            case 'd':
                screen();
                printf("Delete Food: \n");
                printf("Enter the Food ID: ");
                scanf("%d",&id1);
                delete_food(id1);
                break;

            case 'u':
                screen();
                printf("Edit Food Details: \n");
                printf("Enter the  Food ID: ");
                scanf("%d",&id1);
                update_food_details(id1);
                break;

            case 's':
                screen();
                printf("Stock Food: \n");
                printf("Enter the Food ID: ");
                scanf("%d",&id);
                stock(id);
                break;

            case 'e':
                status = 0;
                save_idf(id);
                break;

        }
    }
}

