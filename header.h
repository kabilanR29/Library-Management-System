#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book
{
    int bookid;
    char title[50];
    char author[50];
    int quantity;

    struct book *next;

}BT;

typedef struct issue
{
    int issue_id;
    int bookid;
    int userid;
    char username[50];

    char issue_date[15];
    char due_date[15];
    char return_date[15];

    float fine_amount;

}IT;




extern IT issue[100];
extern int issue_count;



void add_book(BT **);
void update_book(BT **);
void remove_book(BT **);
void search_book(BT *);
void show_books(BT *);
void issue_book(BT *);
void return_book(BT *);
void list_issued_books(void);

void save_books(BT *);
void load_books(BT **);
void save_issue_list(BT *);
void load_issue_list(void);

#endif
