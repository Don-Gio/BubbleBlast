#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "funzioni.h"

int main() {
    
    //Crea una griglia 5x6 e la riempie con bolle random
    char griglia[5][6];
    char testGriglia[5][6];
    int counter_rig, counter_col;
    int riga, colonna;
    int passiMinimi, passiMassimi;
    int passiAttuali;

    printf("Benvenuto in Bubble Blaster!\n");
    printf("Lo scopo del gioco e' selezionare le bolle per cambiarne lo stato;\n");
    printf("ci sono 3 tipi di bolle:\n");
    printf(" - e' la bolla sgonfia,\n");
    printf(" c e' la bolla gnfia a meta' e\n");
    printf(" O e' la bolla in procinto di esplodere,\n");
    printf("Selezionando una bolla questa cambia di stato. Se si seleziona la bolla O, questa esplode\n");
    printf("e propaga l'esplosiona in verticale e orizzontale. Se l'esplosione incontra un'altra bolla O\n");
    printf("questa propaga a sua volta l'esplosione\n");
    printf("Si vince se si riesce a far scoppiare tutte le bolle in un numero di passi minore a quello dato dal gioco\n");
    printf("\n");
    printf("!!!ATTENZIONE!!!\n");
    printf("La numerazione di righe e colonne inizia da Zero\n");
    printf("\n");
    printf("Buona fortuna!\n");
    printf("\n");



    for (counter_rig=0; counter_rig<5; counter_rig++){
        for (counter_col=0; counter_col<6; counter_col++){
            griglia[counter_rig][counter_col]=bollaRandom();
            printf("\t%c", griglia[counter_rig][counter_col]);
        }
        printf("\n");
    }
    //Fine riempimento griglia

    //Copia griglia in griglia test per prova risoluzione
    for (counter_rig=0; counter_rig<5; counter_rig++){
        for (counter_col=0; counter_col<6; counter_col++){
            testGriglia[counter_rig][counter_col]=griglia[counter_rig][counter_col];
        }
    }
    //Fine copia griglia test

    //Stampa il numero minimo di mosse necessarie per risolvere il gioco
    passiMinimi=passiNecessari(testGriglia);
    printf("\n");
    printf("Sono necessari minimo %d passi per vincere\n", passiMinimi);

    //Stampa il numero di passi massimi affinché sia considerata una vittoria
    passiMassimi=passiMinimi+10;
    printf("Sara' una vittoria se si riuscira' a far scoppiare tutte le bolle entro %d passi\n", passiMassimi);

    //Inizia il giorco vero e proprio, finché tutte le bolle non saranno scoppiate si continua la scelta
    while (verificaGriglia(griglia)==0){
    selezionaBolla(griglia, &riga, &colonna);

    if (griglia[riga][colonna]==79) {
        propaga(griglia, riga, colonna);
        passiAttuali=passiAttuali+1;
    } else {
        cambioStatoBolla(griglia, riga, colonna);
        passiAttuali=passiAttuali+1;
    }
    
    //Ogni bolla che viene cambiata viene riproposta la griglia modificata
    mostraGriglia(griglia);
   }
   
   //Decreta a vittoria o meno
   if (passiAttuali<=passiMassimi){
       printf("CONGRATULAZIONI HAI VINTO!!!\n");
       printf("Hai eseguito %d passi contro i %d passi massimi necessari\n", passiAttuali, passiMassimi);
   } else {
       printf("SPIACENTE! ): \n");
       printf("Hai eseguito %d passi contro i %d passi massimi necessari\n", passiAttuali, passiMassimi);
   }
   getchar();getchar();getchar();

}