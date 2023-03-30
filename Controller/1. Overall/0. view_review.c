#include <stdio.h>
#include <conio.h>

struct review_details
{
    int id;
    char name[30];
    char reviews[500];
}review;

void view_review()
{
    FILE *fp;

    fp = fopen("DataBase\\review.txt","r");

    while (fread(&review,sizeof(review),1,fp)==1)
    {
        printf("Name: %s          \nReview:%s \n\n",review.name,review.reviews);
    }
    fclose(fp);

}

