library: main.o booklib.o date.o fine.o issue.o menu.o
        cc main.c booklib.c date.c fine.c issue.c menu.c -o library

main.o: main.c
        cc -c main.c

booklib.o: booklib.c
        cc -c booklib.c

date.o: date.c
        cc -c date.c

fine.o: fine.c
        cc -c fine.c

issue.o: issue.c
        cc -c issue.c

menu.o: menu.c
        cc -c menu.c
~                        
