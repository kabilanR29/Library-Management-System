#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"
void add_book(BT **hptr)
{
    char choice;
    BT *new, *temp;
    int id;

    printf("\nDo you want to add a book (Y/N): ");
    scanf(" %c",&choice);

    while(choice=='Y' || choice=='y')
    {
        new = (BT *)malloc(sizeof(BT));

        if(new == NULL)
        {
            printf("Memory Allocation Failed\n");
            return;
        }

        id = 1;
        temp = *hptr;

        while(temp)
        {
            if(temp->bookid >= id)
                id = temp->bookid + 1;

            temp = temp->next;
        }

        new->bookid = id;

        printf("\nBook ID : %d\n",new->bookid);

        printf("Enter Book Name : ");
        scanf(" %[^\n]",new->title);

        printf("Enter Author Name : ");
        scanf(" %[^\n]",new->author);

        printf("Enter Quantity : ");
        scanf("%d",&new->quantity);

        new->next = NULL;

        if(*hptr == NULL)
            *hptr = new;
        else
        {
            temp = *hptr;

            while(temp->next)
                temp = temp->next;

            temp->next = new;
        }

        printf("\nBook Added Successfully\n");

        printf("\nDo you want to add another book (Y/N): ");
        scanf(" %c",&choice);
    }

   

    printf(" ---------- ---------------------- ---------------------- ----------\n");
    printf("| BOOK ID  | TITLE                | AUTHOR               | QUANTITY |\n");
    printf(" ---------- ---------------------- ---------------------- ----------\n");

    temp = *hptr;

    while(temp)
    {
        printf("| %-8d | %-20s | %-20s | %-8d |\n",
               temp->bookid,
               temp->title,
               temp->author,
               temp->quantity);

        temp = temp->next;
    }

    printf(" ---------- ---------------------- ---------------------- ----------\n");
}
