#include "header.h"

void update_id(BT *, int);
void update_title(BT *, char *);

void update_book(BT **hptr)
{
    int id;
    char title[50];
    char op;

    if(*hptr == 0)
    {
        printf("No records available\n");
        return;
    }

    printf("\n    Update Book Details    \n");
    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. Back to Main Menu\n");

    printf("Enter choice: ");
    scanf(" %c",&op);

    if(op=='A' || op=='a')
    {
        printf("Enter Book ID: ");
        scanf("%d",&id);

        update_id(*hptr,id);
    }
    else if(op=='B' || op=='b')
    {
        printf("Enter Book Name: ");
        scanf(" %[^\n]",title);

        update_title(*hptr,title);
    }
    else
        return;
}


void update_id(BT *ptr, int id)
{
    while(ptr)
    {
        if(ptr->bookid == id)
        {
            printf("New Title: ");
            scanf(" %[^\n]",ptr->title);

            printf("New Author: ");
            scanf(" %[^\n]",ptr->author);

            printf("New Quantity: ");
            scanf("%d",&ptr->quantity);

            printf("\nBook Updated Successfully\n");

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

    printf("Book ID not found\n");
}


void update_title(BT *ptr, char *title)
{
    while(ptr)
    {
        if(strcmp(ptr->title,title)==0)
        {
            printf("New Title: ");
            scanf(" %[^\n]",ptr->title);

            printf("New Author: ");
            scanf(" %[^\n]",ptr->author);

            printf("New Quantity: ");
            scanf("%d",&ptr->quantity);

            printf("\nBook Updated Successfully\n");

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

    printf("Book Name not found\n");
}
