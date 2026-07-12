#include "date.h"

void get_current_date(char date[])
{
time_t t;
struct tm *tm_info;


time(&t);
tm_info = localtime(&t);

sprintf(date,"%02d/%02d/%04d",
        tm_info->tm_mday,
        tm_info->tm_mon+1,
        tm_info->tm_year+1900);

}

void get_due_date(char date[], int days)
{
time_t t;
struct tm *tm_info;


time(&t);

t += days * 24 * 60 * 60;

tm_info = localtime(&t);

sprintf(date,"%02d/%02d/%04d",
        tm_info->tm_mday,
        tm_info->tm_mon+1,
        tm_info->tm_year+1900);

}

