#include <stdio.h>
#include "header.h"

void save_issue_list(BT *hptr)
{
    FILE *fp;
    int i;

    fp = fopen("issue.dat", "w");

    if(fp == NULL)
    {
        printf("File open failed\n");
        return;
    }

    fprintf(fp," ---------- ---------- ---------- ---------------------- ------------ ------------ --------------- ----------\n");
    fprintf(fp,"| ISSUE ID | BOOK ID  | USER ID  | USER NAME            | ISSUE DATE | DUE DATE   | RETURN DATE   | FINE     |\n");
    fprintf(fp," ---------- ---------- ---------- ---------------------- ------------ ------------ --------------- ----------\n");

    for(i = 0; i < issue_count; i++)
    {
        fprintf(fp,
        "| %-8d | %-8d | %-8d | %-20s | %-10s | %-10s | %-13s | %-8.2f |\n",
        issue[i].issue_id,
        issue[i].bookid,
        issue[i].userid,
        issue[i].username,
        issue[i].issue_date,
        issue[i].due_date,
        issue[i].return_date,
        issue[i].fine_amount);
    }

    fprintf(fp," ---------- ---------- ---------- ---------------------- ------------ ---------- --------------- ----------\n");

    fclose(fp);

    printf("Issue records saved successfully...\n");

}

