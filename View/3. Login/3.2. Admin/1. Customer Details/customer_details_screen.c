#include <stdio.h>
#include <conio.h>

void customer_details_screen()
{
    int id = get_ida();
    int id1;
    int status=1;
    char choice;
    while(status == 1)
    {
        screen();
        printf("Administrator --> Customer Details\n\n");
        printf("Tools: \n");
        printf("Add Account\n");
        printf("List Account\n");
        printf("Delete Account\n");
        printf("Update Account\n");
        printf("Report in Detail\n");
        printf("Exit\n");

        choice = getch();
        switch (choice)
        {
            case 'a':
                screen();
                add_account_customer (&id);
                id++;
                break;

            case 'l':
                screen();
                list_record_customer();
                getch();
                break;

            case 'd':
                screen();
                printf("Delete Account: \n");
                printf("Enter the Account ID: ");
                scanf("%d",&id1);
                delete_account_customer(id1);
                break;

            case 'u':
                screen();
                printf("Edit Account: \n");
                printf("Enter the Account ID: ");
                scanf("%d",&id1);
                update_customer_account(id1);
                break;

            case 'r':
                screen();
                printf("Detailed Report Account: \n");
                printf("Enter the Account ID: ");
                scanf("%d",&id1);
                printf("\n");
                detailed_customer_account(id1);
                break;

            case 'e':
                status = 0;
                save_ida(id);
                break;
        }
    }


}
