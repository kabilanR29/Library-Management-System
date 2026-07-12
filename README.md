LIBRARY MANAGEMENT SYSTEM-INTRODUCTION-The Library Management System(LMS) is a console based application developed in c language. it helps manage library operations like adding books,issuing books,returning books and tracking users.The system automatically handles important dates such as issue date,due date,return date and alo calculate fines for late returns.
Menu-driven detailed user interface with clear submenus for easy understanding of the user while using the function of updation,search and remove the books by book id,Author name and Book nme.
I will write separate function for Adding ,updating,deleting,searching the books using their book id,Author name,Book name.for this part I use structures,DMA(Dynamic memory Allocation),etc concepts.
While issuing books it will autogenerate the return date as the 7th day from which date the user take the book from library and if they miss to return within the stipulated timeframe the fine amount will be added as Rupees.5 per day.
I used file concept for store the list of books and issued books while persist program runs.

project structure:-
-------------------
main.c - program opening point and controls main menu.
menu.c/menu.h- menu display.
genral.h - it contains comman structure and varibles.
booklib.c/boolib.h -Contains operations like add,delete,update,vies search.
issue.c/issue.h - contains issued date and return date logics.
fine.c/fine.h -Contains fine calculation logics.

