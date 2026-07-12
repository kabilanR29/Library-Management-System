#include<stdio.h>
#include<string.h>
#include<time.h>
#include "header.h"

void issue_book(BT *ptr)
{
    int id;
    char username[50];
    time_t t;
    struct tm *tm_info;

    if(ptr == NULL)
    {
        printf("\nNo Books Available\n");
        return;
    }

    printf("\nEnter Book ID to Issue: ");
    scanf("%d",&id);

    while(ptr)
    {
        if(ptr->bookid == id)
        {
            if(ptr->quantity == 0)
            {
                printf("\nBook Not Available\n");
                return;
            }

            printf("Enter User ID: ");
            scanf("%d",&issue[issue_count].userid);

            printf("Enter User Name: ");
            scanf(" %[^\n]",username);

            ptr->quantity--;

            
            issue[issue_count].issue_id = issue_count + 1;
            issue[issue_count].bookid = ptr->bookid;

            strcpy(issue[issue_count].username, username);

            
            t = time(NULL);
            tm_info = localtime(&t);

            strftime(issue[issue_count].issue_date,
                     sizeof(issue[issue_count].issue_date),
                     "%d/%m/%Y",
                     tm_info);

           
            t += 7 * 24 * 60 * 60;
            tm_info = localtime(&t);

            strftime(issue[issue_count].due_date,
                     sizeof(issue[issue_count].due_date),
                     "%d/%m/%Y",
                     tm_info);

            strcpy(issue[issue_count].return_date, "Not_Returned");

            issue[issue_count].fine_amount = 0;

            issue_count++;

            printf("\nBook Issued Successfully\n");

            printf(" ---------- ---------------------- ---------------------- ----------\n");
            printf("| BOOK ID  | TITLE                | AUTHOR               | QUANTITY |\n");
            printf(" ---------- ---------------------- ---------------------- ----------\n");

            printf("| %-8d | %-20s | %-20s | %-8d |\n",ptr->bookid,ptr->title,ptr->author,ptr->quantity);

            printf(" ---------- ---------------------- ---------------------- ----------\n");

            return;
        }

        ptr = ptr->next;
    }

    printf("\nBook ID Not Found\n");
}
