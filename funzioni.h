#ifndef FUNZIONI_H
#define FUNZIONI_H

//Prototipi delle funzioni usate nel programma

void mostraGriglia(char griglia[5][6]);

char bollaRandom();

void selezionaBolla (char griglia[5][6], int *riga, int *colonna);

void cambioStatoBolla (char griglia[5][6], int riga, int colonna);

void propaga (char griglia[5][6], int riga, int colonna);

void propaga2 (char griglia[5][6], int riga, int colonna);

#endif