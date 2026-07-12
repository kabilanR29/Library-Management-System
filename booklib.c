#include "bookslib.h"

bookslib books[MAX_BOOKS];
int book_count = 0;

void add_book(void)
{
printf("\n----- Add New Book -----\n");


printf("Enter Book ID : ");
scanf("%d", &books[book_count].book_id);

printf("Enter Book Title : ");
scanf(" %[^\n]", books[book_count].title);

printf("Enter Author Name : ");
scanf(" %[^\n]", books[book_count].author);

printf("Enter Quantity : ");
scanf("%d", &books[book_count].quantity);

book_count++;

printf("\nBook Added Successfully.\n");


}

void display_books(void)
{
int i;

if(book_count == 0)
{
    printf("\nNo Books Available.\n");
    return;
}

printf("\n---------------------------------------------------------------\n");
printf("%-10s %-25s %-20s %-10s\n",
       "Book ID","Title","Author","Quantity");
printf("---------------------------------------------------------------\n");

for(i = 0; i < book_count; i++)
{
    printf("%-10d %-25s %-20s %-10d\n",
           books[i].book_id,
           books[i].title,
           books[i].author,
           books[i].quantity);
}

printf("---------------------------------------------------------------\n");


}

void save_books(void)
{
FILE *fp;

fp = fopen("data/books.dat", "wb");

if(fp == NULL)
{
    printf("\nUnable to Open File.\n");
    return;
}

fwrite(&book_count, sizeof(int), 1, fp);
fwrite(books, sizeof(bookslib), book_count, fp);

fclose(fp);

printf("\nBooks Saved Successfully.\n");


}

void load_books(void)
{
FILE *fp;


fp = fopen("data/books.dat", "rb");

if(fp == NULL)
    return;

fread(&book_count, sizeof(int), 1, fp);
fread(books, sizeof(bookslib), book_count, fp);

fclose(fp);


}

void search_book(void)
{
int id, i;


printf("\nEnter Book ID : ");
scanf("%d",&id);

for(i=0;i<book_count;i++)
{
    if(books[i].book_id==id)
    {
        printf("\nBook Found\n");

        printf("Book ID   : %d\n",books[i].book_id);
        printf("Title     : %s\n",books[i].title);
        printf("Author    : %s\n",books[i].author);
        printf("Quantity  : %d\n",books[i].quantity);

        return;
    }
}

printf("\nBook Not Found\n");


}

void update_book(void)
{
int id,i;


printf("\nEnter Book ID : ");
scanf("%d",&id);

for(i=0;i<book_count;i++)
{
    if(books[i].book_id==id)
    {
        printf("\nEnter New Title : ");
        scanf(" %[^\n]",books[i].title);

        printf("Enter New Author : ");
        scanf(" %[^\n]",books[i].author);

        printf("Enter New Quantity : ");
        scanf("%d",&books[i].quantity);

        printf("\nBook Updated Successfully\n");

        return;
    }
}

printf("\nBook Not Found\n");


}

void delete_book(void)
{
int id;
int i,j;


printf("\nEnter Book ID : ");
scanf("%d",&id);

for(i=0;i<book_count;i++)
{
    if(books[i].book_id==id)
    {
        for(j=i;j<book_count-1;j++)
        {
            books[j]=books[j+1];
        }

        book_count--;

        printf("\nBook Deleted Successfully\n");

        return;
    }
}

printf("\nBook Not Found\n");


}

