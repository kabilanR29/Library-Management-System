#include "general.h"
#include "menu.h"
#include "bookslib.h"
#include "issue.h"

void menu(void)
{
int choice;


while(1)
{
    printf("\n========================================");
    printf("\n      LIBRARY MANAGEMENT SYSTEM");
    printf("\n========================================");

    printf("\n1. Add Book");
    printf("\n2. Display Books");
    printf("\n3. Search Book");
    printf("\n4. Update Book");
    printf("\n5. Delete Book");
    printf("\n6. Issue Book");
    printf("\n7. Return Book");
    printf("\n8. Display Issued Books");
    printf("\n9. Save Books");
    printf("\n10. Save Issue Records");
    printf("\n11. Exit");

    printf("\n\nEnter Choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            add_book();
            break;

        case 2:
            display_books();
            break;

        case 3:
            search_book();
            break;

        case 4:
            update_book();
            break;

        case 5:
            delete_book();
            break;

        case 6:
            issue_book();
            break;

        case 7:
            return_book();
            break;

        case 8:
            display_issued_books();
            break;

        case 9:
            save_books();
            break;

        case 10:
            save_issue();
            break;

        case 11:

            save_books();
            save_issue();

            printf("\nData Saved Successfully");
            printf("\nThank You...\n");

            exit(0);

        default:

            printf("\nInvalid Choice\n");
    }
}


}

