#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int msec = 0;
    const int trigger = 500; /* ms */
    const int printWidth = 4;
    int counter = 0;
    clock_t before = clock();    
	printf("\n\n\n\n\n\n\n\n\n\n\n");	
    while (1)
    {
        clock_t difference = clock() - before;
        msec = difference * 2000 / CLOCKS_PER_SEC;
                
        if (msec >= trigger) 
        {
        	
            /* contabilidad del temporizador */ 
            counter = (counter+1) % printWidth;
            msec = 0;
            before = clock();            
            /* desarrollo
            \e[1;101;41mCargando:\e[0m <<< para tener color rojo  */
            fputs("				CARGANDO", stdout);
            for (int dotPosition = 0; dotPosition < printWidth; ++dotPosition)
            {            
                fputc(dotPosition < counter ? '.' : ' ', stdout);               
            }             
            /* se repite */
            fflush(stdout);
            fputc('\r', stdout);                                             
        } 
    }
    return 0;
}