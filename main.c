#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int id;

int main()
{
    getch();
    welcome_screen();

	char choice;

	int status=1;
    while(status == 1)
	{
		open_screen();

		choice = getch();

		switch(choice)
		{
			case 'l':
            {
                id = login();

                if (id == 0)
                {
                    break;
                }
                else if (id == 1)
                {
                    admin();
                }
                else
                {
                    customer(id);
                }
				break;

            }

			case 's':
            {
                sign_up();
				break;

            }

			case 'e':
            {
                status = 0;
				break;
            }

		}
	}
}

