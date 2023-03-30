#include <stdio.h>

int get_idf ()
{
    int id;
    FILE *fp;
    fp = fopen("DataBase\\idf.txt","r");
    fscanf(fp,"%d",&id);
    fclose(fp);
    return id;
}

