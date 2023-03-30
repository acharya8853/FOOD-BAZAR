#include <stdio.h>
#include <conio.h>
#include <string.h>

struct review_details
{
    int id;
    char name[30];
    char reviews[500];
}review;

struct account_details
{
	int id;
	char name[40];
	char address[20];
	char phone[20];
	char username[10];
	char password[10];
}person;

void write_review(int id)
{
    FILE *fp,*fp1;
    fp = fopen("DataBase\\account_details.txt","r");
    review.id = id;
    while (fread(&person,sizeof(person),1,fp)==1)
    {
        if (person.id == id)
        {
            break;
        }
    }
    fclose(fp);

    review.id = person.id;
    strcpy(review.name,person.name);
    fflush(stdin);
    printf("Enter your comment: ");
    gets(review.reviews);

    fp = fopen("DataBase\\review.txt","a");
    fwrite(&review,sizeof(review),1,fp);
    fclose(fp);

}
