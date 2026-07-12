#include "general.h"
#include "menu.h"
#include "bookslib.h"
#include "issue.h"

int main()
{
load_books();
load_issue();

menu();

return 0;

}

