#include <stdlib.h>
#include <stdio.h>
#include "funzioni.h"

int main() {
    
    //Crea una griglia 5x6 e la riempie con bolle random
    char griglia[5][6];
    int counter_rig, counter_col;
    int riga, colonna;

    for (counter_rig=0; counter_rig<5; counter_rig++){
        for (counter_col=0; counter_col<6; counter_col++){
            griglia[counter_rig][counter_col]=bollaRandom();
            printf("\t%c", griglia[counter_rig][counter_col]);
        }
        printf("\n");
    }
    //Fine riempimento griglia

    selezionaBolla(griglia, &riga, &colonna);

    if (griglia[riga][colonna]==79) {
        propaga(griglia, riga, colonna);
    } else {
        cambioStatoBolla(griglia, riga, colonna);
    }
    
    mostraGriglia(griglia);
    
   

   getchar();getchar();

}