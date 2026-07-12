#include<stdio.h>
#include "header.h"

void list_issued_books(void)
{
    int i;

    if(issue_count==0)
    {
        printf("\nNo Issued Books Available\n");
        return;
    }

    printf(" ---------- ---------- ---------- ---------------------- ------------ ------------ --------------- ---------\n");
    printf("| ISSUE ID | BOOK ID  | USER ID  | USER NAME            | ISSUE DATE | DUE DATE   | RETURN DATE   | FINE    |\n");
    printf(" ---------- ---------- ---------- ---------------------- ------------ ------------ --------------- ---------\n");

    for(i=0;i<issue_count;i++)
    {
        printf("| %-8d | %-8d | %-8d | %-20s | %-10s | %-10s | %-13s | %-7.2f |\n",issue[i].issue_id,issue[i].bookid,issue[i].userid,issue[i].username,
		issue[i].issue_date,issue[i].due_date,issue[i].return_date,issue[i].fine_amount);
    }

    printf(" ---------- ---------- ---------- ---------------------- ------------- ------------ --------------- ---------\n");
}
