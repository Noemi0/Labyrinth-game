#include <stdio.h>
#include <stdlib.h>
#include "labyrinth.h"



int main()
{
    int input;
    int o;
    int eredmeny;

    do
    {
        menu();
        input=getchar();
        getchar();
        switch(input)
        {
        case'1':
                eredmeny=ujJatek();
            break;
        case'2':
                system("@cls||clear");
                o=leiras();
                if(o=='2'){
                     return EXIT_SUCCESS;
                }
                else{
                    menu();
                }
            break;
        case'3':
                system("@cls||clear");
                o=szabalyok();
                if(o=='2'){
                     return EXIT_SUCCESS;
                }
                else{
                    menu();
                }
            break;
            case'4':
               return EXIT_SUCCESS;
        default:

            break;
        }

    }
    while(input != '4');

    return EXIT_SUCCESS;
}



