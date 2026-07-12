#include "header.h"

void search_id(BT *, int);
void search_title(BT *, char *);
void search_author(BT *, char *);

void search_book(BT *hptr)
{
    int id;
    char ch[50], op;

    if(hptr == 0)
    {
        printf("No records available\n");
        return;
    }

    printf("\n      Search Book      \n");
    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. By Author Name\n");
    printf("D. Back\n");

    printf("Enter choice: ");
    scanf(" %c",&op);

    if(op=='A' || op=='a')
    {
        printf("Enter Book ID: ");
        scanf("%d",&id);

        search_id(hptr,id);
    }
    else if(op=='B' || op=='b')
    {
        printf("Enter Book Name: ");
        scanf(" %[^\n]",ch);

        search_title(hptr,ch);
    }
    else if(op=='C' || op=='c')
    {
        printf("Enter Author Name: ");
        scanf(" %[^\n]",ch);

        search_author(hptr,ch);
    }
}

void search_id(BT *ptr,int id)
{
    while(ptr)
    {
        if(ptr->bookid == id)
        {
            printf(" ---------- ---------------------- ---------------------- ----------\n");
            printf("| BOOK ID  | TITLE                | AUTHOR               | QUANTITY |\n");
            printf(" ---------- ---------------------- ---------------------- ----------\n");
            printf("| %-8d | %-20s | %-20s | %-8d |\n",ptr->bookid,ptr->title,ptr->author,ptr->quantity);
            printf(" ---------- ---------------------- ---------------------- ----------\n");
            return;
        }

        ptr = ptr->next;
    }

    printf("Book ID not found\n");
}

void search_title(BT *ptr,char *title)
{
    while(ptr)
    {
        if(strcmp(ptr->title,title)==0)
        {
            printf(" ---------- ---------------------- ---------------------- ----------\n");
            printf("| BOOK ID  | TITLE                | AUTHOR               | QUANTITY |\n");
            printf(" ---------- ---------------------- ---------------------- ----------\n");
            printf("| %-8d | %-20s | %-20s | %-8d |\n",ptr->bookid,ptr->title,ptr->author,ptr->quantity);
            printf(" ---------- ---------------------- ---------------------- ----------+\n");
            return;
        }

        ptr = ptr->next;
    }

    printf("Book Name not found\n");
}

void search_author(BT *ptr,char *author)
{
    int c=0;

    while(ptr)
    {
        if(strcmp(ptr->author,author)==0)
        {
            if(c==0)
            {
                printf(" ---------- ---------------------- ---------------------- ----------\n");
                printf("| BOOK ID  | TITLE                | AUTHOR               | QUANTITY |\n");
                printf(" ---------- ---------------------- ---------------------- ----------\n");
            }

                printf("| %-8d | %-20s | %-20s | %-8d |\n",ptr->bookid,ptr->title,ptr->author,ptr->quantity);

            c++;
        }

        ptr = ptr->next;
    }

    if(c)
        printf(" ---------- ---------------------- ---------------------- ----------+\n");
    else
        printf("Author not found\n");
}
