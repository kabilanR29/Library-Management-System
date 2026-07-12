#include<stdio.h>
#include<string.h>
#include<time.h>
#include "header.h"

void return_book(BT *ptr)
{
    int id, i;
    time_t t;
    struct tm *tm_info;

    if(ptr == NULL)
    {
        printf("\nNo Books Available\n");
        return;
    }

    printf("\nEnter Book ID to Return: ");
    scanf("%d",&id);

    while(ptr)
    {
        if(ptr->bookid == id)
        {
            ptr->quantity++;

           
            for(i=0; i<issue_count; i++)
            {
                if(issue[i].bookid == id &&
                   strcmp(issue[i].return_date,"Not_Returned")==0)
                {
                    t = time(NULL);
                    tm_info = localtime(&t);

                    strftime(issue[i].return_date,
                             sizeof(issue[i].return_date),
                             "%d/%m/%Y",
                             tm_info);

                    issue[i].fine_amount = 0;

                    break;
                }
            }

            printf("\nBook Returned Successfully...\n");

            printf(" ---------- ---------------------- ---------------------- ----------\n");
            printf("| BOOK ID  | TITLE                | AUTHOR               | QUANTITY |\n");
            printf(" ---------- ---------------------- ---------------------- ----------\n");

            printf("| %-8d | %-20s | %-20s | %-8d |\n",
                   ptr->bookid,
                   ptr->title,
                   ptr->author,
                   ptr->quantity);

            printf(" ---------- ---------------------- ---------------------- ----------\n");

            return;
        }

        ptr = ptr->next;
    }

    printf("\nBook ID Not Found\n");
}
