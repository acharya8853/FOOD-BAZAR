#include <stdio.h>
#include <windows.h>
#include <conio.h>

void customer(int id)
{
    int work;
    char choice;
    int status;
    status = 1;
    while (status == 1)
    {
        screen();
        printf("\033[9;0H");
        customer_screen(id);
        choice = getch();

        switch (choice)
        {
            case 'o':
                screen();
                printf("\033[9;0H");
                order();
                getch();
                break;

            case 'c':
                screen();
                printf("\033[9;0H");
                printf("Edit you Details: \n\n");
                work = update_customer_account(id);
                if (work == 1)
                return;
                break;

            case 'r':
                screen();
                printf("\033[9;0H");
                printf("Home ---> Review\n");
                printf("View Review               Write Review\n\n");
                choice = getch ();
                switch(choice)
                {
                case 'v':
                    view_review();
                    getch();
                    break;

                case 'w':
                    write_review(id);
                    break;
                }
                break;

            case 'e':
                status = 0;
        }
    }
}

