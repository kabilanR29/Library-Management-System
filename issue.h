#ifndef ISSUE_H
#define ISSUE_H

#include "general.h"
#include "bookslib.h"

typedef struct
{
int issue_id;
int book_id;
int user_id;

char user_name[MAX_NAME];

char issue_date[20];
char due_date[20];
char return_date[20];

int fine;


}ISSUE;

void issue_book(void);
void return_book(void);
void display_issued_books(void);

void save_issue(void);
void load_issue(void);

#endif

