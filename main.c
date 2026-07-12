#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include "figure.h"

    IT issue[100];
    int issue_count = 0;
int main()
{
    BT *hptr = NULL;

    int choice;
    load_books(&hptr);

    while(1)
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
        printf("\n|=====================================|");

        printf("\n\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add_book(&hptr);
                break;

            case 2:
                update_book(&hptr);
                break;

            case 3:
                remove_book(&hptr);
                break;

            case 4:
                search_book(hptr);
                break;

            case 5:
                show_books(hptr);
                break;

            case 6:
                issue_book(hptr);
                break;

            case 7:
                return_book(hptr);
                break;

            case 8:
                list_issued_books();
                break;

            case 9:
                save_books(hptr);
		save_issue_list(hptr);
                //printf("\nBooks Saved Successfully!\n");
                break;

            case 10:
                save_books(hptr);
		save_issue_list(hptr);
                printf("\nThank You For Using Library Management System\n");
                printf("Program Exited Successfully\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }

    return 0;
}
