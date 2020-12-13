#include <stdio.h>
#include <unistd.h>
#include "funzioni.h"

//corpo delle funzioni che useró nell'altro programma

//Funzione che mostra la griglia a comando
void mostraGriglia (char griglia[5][6]) {
    int counter_rig, counter_col;
    for (counter_rig=0; counter_rig<5; counter_rig++){
        for (counter_col=0; counter_col<6; counter_col++){
            printf("\t%c", griglia[counter_rig][counter_col]);
        }
        printf("\n");
    }
}
//Fine funzione per mostrare griglia



//Questa funzione crea una bolla con uno stato randomico
 /* Definisco le 3 bolle:
    IN PROCINTO DI ESPLODERE > @
    GONFIE A METÁ > a
    SGONFIE > -
    */
char bollaRandom() {
   char esplo=79; //@ in ASCII
   char met=99; //a in ASCII
   char sgon=45; //- in ASCII
   char bolla;
   int casuale=0;

   //Crea il seed di rand e crea un valore randomico da zero a trenta a seconda del tempo
   srand(time(NULL));
   casuale=rand() %30;
   casuale=casuale-rand() %5;
   sleep(1);
   
   if (casuale>-5 && casuale<10){
       bolla=sgon;
   } else if (casuale>=10 && casuale<20){
       bolla=met;
   } else if (casuale>=20 && casuale<=30){
       bolla=esplo;
   }
   return bolla;
}
//Fine funzione creazione randomica bolla

//Funzione per selezionare una bolla
void selezionaBolla (char griglia[5][6], int *riga, int *colonna) {
    int new_riga, new_colonna;
    printf("\n");
    printf("Seleziona la bolla\n");
    printf("Inserisci numero riga: ");
    scanf("%d", &new_riga);
    printf("Inserisci numero colonna: ");
    scanf("%d", &new_colonna);
    printf("Hai selezionato la bolla a riga %d e colonna %d\n", new_riga, new_colonna);
    printf("Il suo valore e' %c\n", griglia[new_riga][new_colonna]);
    *riga=new_riga;
    *colonna=new_colonna;
}
//Fine selezione bolla

//Funzione per cambiare lo stato di una bolla in una data posizione
void cambioStatoBolla (char griglia[5][6], int riga, int colonna) {
    char esplo=79; //@ in ASCII
    char met=99; //a in ASCII
    char sgon=45; //- in ASCII
    if (griglia[riga][colonna]==sgon) {
        griglia[riga][colonna]=met;
    } else if (griglia[riga][colonna]==met) {
        griglia[riga][colonna]=esplo;
    } else if (griglia[riga][colonna]==esplo) {
        griglia[riga][colonna]=sgon;
    }
}
//Fine funzione per cambiare lo stato della bolla

//Funzione che propaga l'esplosione
void propaga (char griglia[5][6], int riga, int colonna) {
    int j, k;
    for (j=0; j<6; j++){
        cambioStatoBolla(griglia, riga, j);
    }
    for (k=0; k<5; k++){
        cambioStatoBolla(griglia, k, colonna);
    }
}
//Fine funzione che propaga l'esplosione
