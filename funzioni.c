#include <stdio.h>
#include <unistd.h>
#include "funzioni.h"

//corpo delle funzioni che useró nell'altro programma

//Questa funzione crea una bolla con uno stato randomico
 /* Definisco le 3 bolle:
    IN PROCINTO DI ESPLODERE > @
    GONFIE A METÁ > a
    SGONFIE > -
    */
char bollaRandom() {
   char esplo=64; //@ in ASCII
   char met=97; //a in ASCII
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