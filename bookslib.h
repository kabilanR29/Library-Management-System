#ifndef BOOKSlib_H
#define BOOKSlib_H

#include "general.h"

typedef struct
{
    int book_id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int quantity;

} bookslib;



extern bookslib books[MAX_BOOKS];
extern int book_count;

void add_book(void);

void display_books(void);

void search_book(void);

void update_book(void);

void delete_book(void);

void save_books(void);

void load_books(void);

#endif
