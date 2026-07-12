#ifndef FIGURE_H
#define FIGURE_H

void main_menu(void)
{
    printf("\n|=====================================|");
    printf("\n|     LIBRARY MANAGEMENT SYSTEM       |");
    printf("\n|=====================================|");
    printf("\n| 1. Add New Book                     |");
    printf("\n| 2. Update Book Details              |");
    printf("\n| 3. Remove Book                      |");
    printf("\n| 4. Search Book                      |");
    printf("\n| 5. View All Books                   |");
    printf("\n| 6. Issue Book                       |");
    printf("\n| 7. Return Book                      |");
    printf("\n| 8. List Issued Books                |");
    printf("\n| 9. Save                             |");
    printf("\n| 10. Exit                            |");
    printf("\n|=====================================|\n");
}


void update_menu(void)
{
    printf("\n----- Update Book Details -----\n");
    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. Back to Main Menu\n");
}


void remove_menu(void)
{
    printf("\n----- Remove Book -----\n");
    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. Back to Main Menu\n");
}


void search_menu(void)
{
    printf("\n----- Search Book -----\n");
    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. By Author Name\n");
    printf("D. Back to Main Menu\n");
}

#endif
