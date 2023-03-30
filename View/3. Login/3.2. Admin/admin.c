#include <stdio.h>
#include <conio.h>

void admin()
{
    int status,choice;
    FILE *fp,*fp1;

    status = 1;

    while (status == 1)
    {
        screen();
        admin_front();
        label1:
        fflush(stdin);
        choice = getch();
        switch (choice)
        {
            case 'h':
                help();
                goto label1;
                break;

            case 'c':
                customer_details_screen();
                break;

            case 'f':
                food_details_screen();
                break;

            case 'v':
                screen();
                printf("Administrator --> Reviews\n\n");
                view_review();
                getch();
                break;

            case 'p':
                //purchase_history_screen();
                break;

            case 'e':
                status = 0;
          }
    }

}
