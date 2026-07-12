#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

void remove_id(BT **hptr, int id);
void remove_title(BT **hptr, char *title);

void remove_book(BT **hptr)
{
    int id;
    char title[50], op;

    if(*hptr == NULL)
    {
        printf("No Records Available\n");
        return;
    }

    printf("\n     Remove Book     \n");
    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. Back to Main Menu\n");

    printf("Enter Choice: ");
    scanf(" %c",&op);

    if(op=='A' || op=='a')
    {
        printf("Enter Book ID: ");
        scanf("%d",&id);
        remove_id(hptr,id);
    }
    else if(op=='B' || op=='b')
    {
        printf("Enter Book Name: ");
        scanf(" %[^\n]",title);
        remove_title(hptr,title);
    }
}

void remove_id(BT **hptr,int id)
{
    BT *ptr=*hptr,*temp;

    if(ptr!=NULL && ptr->bookid==id)
    {
        *hptr=ptr->next;

        printf("\nBook Removed Successfully...\n");

        free(ptr);
        return;
    }

    while(ptr->next!=NULL && ptr->next->bookid!=id)
        ptr=ptr->next;

    if(ptr->next==NULL)
    {
        printf("Book ID Not Found\n");
        return;
    }

    temp=ptr->next;
    ptr->next=temp->next;

    printf("\nBook Removed Successfully...\n");

    free(temp);
}

void remove_title(BT **hptr,char *title)
{
    BT *ptr=*hptr,*temp;

    if(ptr!=NULL && strcmp(ptr->title,title)==0)
    {
        *hptr=ptr->next;

        printf("\nBook Removed Successfully...\n");

        free(ptr);
        return;
    }

    while(ptr->next!=NULL && strcmp(ptr->next->title,title)!=0)
        ptr=ptr->next;

    if(ptr->next==NULL)
    {
        printf("Book Name Not Found\n");
        return;
    }

    temp=ptr->next;
    ptr->next=temp->next;

    printf("\nBook Removed Successfully...\n");

    free(temp);
}
