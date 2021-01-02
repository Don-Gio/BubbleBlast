#ifndef FUNZIONI_H
#define FUNZIONI_H
//Prototipi delle funzioni usate nel programma

void mostraGriglia(char griglia[5][6]);

char bollaRandom();

void selezionaBolla (char griglia[5][6], int *riga, int *colonna);

void cambioStatoBolla (char griglia[5][6], int riga, int colonna);

void propaga (char griglia[5][6], int riga, int colonna);

void propagaVert(char griglia[5][6], int riga, int colonna);

void propagaOriz(char griglia[5][6], int riga, int colonna);

bool verificaGriglia (char griglia[5][6]);

int passiNecessari (char griglia[5][6]);

#endif