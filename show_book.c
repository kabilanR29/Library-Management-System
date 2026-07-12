#include<stdio.h>
#include "header.h"

void show_books(BT *ptr)
{
    if(ptr == NULL)
    {
        printf("No Records Available\n");
        return;
    }

    printf(" ---------- ---------------------- ---------------------- ----------\n");
    printf("| BOOK ID  | TITLE                | AUTHOR               | QUANTITY |\n");
    printf(" ---------- ---------------------- ---------------------- ----------\n");

    while(ptr)
    {
        printf("| %-8d | %-20s | %-20s | %-8d |\n",ptr->bookid,ptr->title,ptr->author,ptr->quantity);

        ptr = ptr->next;
    }

    printf(" ---------- ---------------------- ---------------------- ----------\n");
}
