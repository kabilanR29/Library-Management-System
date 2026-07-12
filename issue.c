#include "issue.h"
#include "bookslib.h"
#include "date.h"
#include "fine.h"

ISSUE issue[MAX_USERS];
int issue_count = 0;

void issue_book(void)
{
    int id;
    int i;

    printf("\nEnter Book ID : ");
    scanf("%d",&id);

    for(i=0;i<book_count;i++)
    {
        if(books[i].book_id==id)
        {
            if(books[i].quantity<=0)
            {
                printf("\nBook Not Available\n");
                return;
            }

            issue[issue_count].issue_id=issue_count+1;
            issue[issue_count].book_id=id;

            printf("Enter User ID : ");
            scanf("%d",&issue[issue_count].user_id);

            printf("Enter User Name : ");
            scanf(" %[^\n]",issue[issue_count].user_name);

            get_current_date(issue[issue_count].issue_date);
            get_due_date(issue[issue_count].due_date,7);

            strcpy(issue[issue_count].return_date,"Not Returned");

            issue[issue_count].fine=0;

            books[i].quantity--;

            issue_count++;

            printf("\nBook Issued Successfully.\n");

            return;
        }
    }

    printf("\nBook Not Found\n");
}

void return_book(void)
{
    int id;
    int i,j;

    printf("\nEnter Book ID : ");
    scanf("%d",&id);

    for(i=0;i<issue_count;i++)
    {
        if(issue[i].book_id==id &&
           strcmp(issue[i].return_date,"Not Returned")==0)
        {
            get_current_date(issue[i].return_date);

            printf("Enter Late Days : ");
            int late_days;
            scanf("%d",&late_days);

            issue[i].fine=calculate_fine(late_days);

            for(j=0;j<book_count;j++)
            {
                if(books[j].book_id==id)
                {
                    books[j].quantity++;
                    break;
                }
            }

            printf("\nBook Returned Successfully.\n");
            printf("Fine = %d\n",issue[i].fine);

            return;
        }
    }

    printf("\nIssue Record Not Found\n");
}

void display_issued_books(void)
{
    int i;

    if(issue_count==0)
    {
        printf("\nNo Issued Books\n");
        return;
    }

    printf("\n=============================================================\n");

    for(i=0;i<issue_count;i++)
    {
        printf("\nIssue ID     : %d",issue[i].issue_id);
        printf("\nBook ID      : %d",issue[i].book_id);
        printf("\nUser ID      : %d",issue[i].user_id);
        printf("\nUser Name    : %s",issue[i].user_name);
        printf("\nIssue Date   : %s",issue[i].issue_date);
        printf("\nDue Date     : %s",issue[i].due_date);
        printf("\nReturn Date  : %s",issue[i].return_date);
        printf("\nFine         : %d",issue[i].fine);
        printf("\n-------------------------------------------------------------");
    }
}

void save_issue(void)
{
    FILE *fp;

    fp=fopen("data/issue.dat","wb");

    if(fp==NULL)
    {
        printf("\nCannot Open File\n");
        return;
    }

    fwrite(&issue_count,sizeof(int),1,fp);
    fwrite(issue,sizeof(ISSUE),issue_count,fp);

    fclose(fp);
}

void load_issue(void)
{
    FILE *fp;

    fp=fopen("data/issue.dat","rb");

    if(fp==NULL)
        return;

    fread(&issue_count,sizeof(int),1,fp);
    fread(issue,sizeof(ISSUE),issue_count,fp);

    fclose(fp);
}
