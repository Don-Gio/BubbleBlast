#include <stdlib.h>
#include <stdio.h>
#include "funzioni.h"

int main() {
    
    //Crea una griglia 5x6 e la riempie
    char griglia[5][6];
    int counter_rig, counter_col;

    for (counter_rig=0; counter_rig<5; counter_rig++){
        for (counter_col=0; counter_col<6; counter_col++){
            printf("\t%c", bollaRandom());
        }
        printf("\n");
    }
   

   getchar();

}