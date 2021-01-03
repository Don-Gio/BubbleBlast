#include <stdio.h>
#include <stdbool.h>
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
    IN PROCINTO DI ESPLODERE > O
    GONFIE A METÁ > c
    SGONFIE > -
    */
char bollaRandom() {
   char esplo=79; //O in ASCII
   char met=99; //c in ASCII
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
   } else if (casuale>=10 && casuale<25){
       bolla=met;
   } else if (casuale>=25 && casuale<=30){
       bolla=esplo;
   }
   return bolla;
}
//Fine funzione creazione randomica bolla

//Funzione per selezionare una bolla
void selezionaBolla (char griglia[5][6], int *riga, int *colonna) {
    int new_riga, new_colonna;
    printf("\n");
    printf("Seleziona la bolla da cambiare\n");
    printf("Inserisci numero riga: ");
    scanf("%d", &new_riga);
    printf("Inserisci numero colonna: ");
    scanf("%d", &new_colonna);
    printf("\n");
    printf("Hai selezionato la bolla a riga %d e colonna %d\n", new_riga, new_colonna);
    printf("Il suo valore e' %c\n", griglia[new_riga][new_colonna]);
    printf("\n");
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
    int tempRig, tempCol;
    char tempGri;

    cambioStatoBolla(griglia, riga, colonna);

    tempRig=riga;
    tempCol=colonna;
    tempGri=griglia[riga][colonna];
    
    for (j=0; j<6; j++){
           cambioStatoBolla(griglia, riga, j);
           if (griglia[riga][j]==45){
               propagaVert(griglia, riga, j);
           }
        }
    for (k=0; k<5; k++){
            cambioStatoBolla(griglia, k, colonna);
            if (griglia[k][colonna]==45){
               propagaOriz(griglia, k, colonna);
           }
        }
    griglia[tempRig][tempCol]=tempGri;
    }

//Fine funzione che propaga l'esplosione

//Funzione che propaga Verticalmente l'esplosione
void propagaVert (char griglia[5][6], int riga, int colonna) {
    int j, k;
    int tempRig, tempCol;
    char tempGri;

    tempRig=riga;
    tempCol=colonna;
    tempGri=griglia[riga][colonna];
    
    for (k=0; k<5; k++){
         cambioStatoBolla(griglia, k, colonna);
    }
    griglia[tempRig][tempCol]=tempGri;
}
//Fine funzione che propaga Verticalmente l'esplosione


//Funzione che propaga Orizzontalmente l'esplosione
void propagaOriz (char griglia[5][6], int riga, int colonna) {
    int j, k;
    int tempRig, tempCol;
    char tempGri;

    tempRig=riga;
    tempCol=colonna;
    tempGri=griglia[riga][colonna];
    
    for (j=0; j<6; j++){
         cambioStatoBolla(griglia, riga, j);
    }
    griglia[tempRig][tempCol]=tempGri;
}
//Fine funzione che propaga Orizzontalmente l'esplosione


//Verifica che se la griglia sia vuota o meno
//Se vuota ritorna 1 altrimenti ritorna 0
bool verificaGriglia (char griglia[5][6]){
    int temp, counter_rig, counter_col=0;
    for (counter_rig=0; counter_rig<5; counter_rig++){
        for (counter_col=0; counter_col<6; counter_col++){
            if (griglia[counter_rig][counter_col]==45) {
                temp++;
            }
        }
    }
    //Altrimenti tiene conto degli spazi di tabulazione
    temp=temp-5;
    if (temp==30){
        return true;
    } else {
       return false; 
    }
    
}
//Fine verifica riempimento griglia.

//Prova a risolverla
//Descritto un algoritmo di risoluzione per schema
int passiNecessari (char griglia[5][6]) {

    int temp, counter_rig, counter_col=0;

        //Inizia cambiando tutte le bolle a bolle in procinto di esplodere
        for (counter_rig=0; counter_rig<5; counter_rig++){
            for (counter_col=0; counter_col<6; counter_col++){
                if (griglia[counter_rig][counter_col]==45) {
                    cambioStatoBolla(griglia, counter_rig, counter_col);
                    temp=temp+1;
                    cambioStatoBolla(griglia, counter_rig, counter_col);
                    temp=temp+1;
                } else if (griglia[counter_rig][counter_col]==99) {
                    cambioStatoBolla(griglia, counter_rig, counter_col);
                    temp=temp+1;
                }
            }
        }

        //Fa esplodere la prima bolla propagando l'esplosione (posizione 0-0)
        propaga(griglia, 0, 0);
        temp=temp+1;

        //Porta tutte le bolle sulla prima colonna allo stato in procinto di esplodere
        for (counter_rig=0; counter_rig<5; counter_rig++){
            if (griglia[counter_rig][0] == 45){
                cambioStatoBolla(griglia, counter_rig, 0);
                temp = temp + 1;
                cambioStatoBolla(griglia, counter_rig, 0);
                temp = temp + 1;
            } else if (griglia[counter_rig][0] == 99){
                cambioStatoBolla(griglia, counter_rig, 0);
                temp = temp + 1;
            }
        }

        //Porta tutte le bolle sulla prima riga in procinto di esplodere
        for (counter_col=0; counter_col<6; counter_col++){
            if (griglia[0][counter_col]==45) {
                cambioStatoBolla(griglia, 0, counter_col);
                temp=temp+1;
                cambioStatoBolla(griglia, 0, counter_col);
                temp=temp+1;
            } else if (griglia[0][counter_col]==99) {
                cambioStatoBolla(griglia, 0, counter_col);
                temp=temp+1;
            }
        }

    //Fa esplodere nuovamente la prima bolla (posizione 0-0)
    propaga(griglia, 0, 0);
    temp=temp+1;
    //A questo punto la griglia sará tutta costituita di -

    return temp;
}
//Fine test di risoluzione