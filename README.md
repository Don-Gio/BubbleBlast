# BubbleBlast
Progetto UNIMI Esame Programmazione

Giovanni De Ferrari
Matricola 896462

## Introduzione al progetto
Per il progetto richiesto per l'esame di programmazione in C svilupperó il gioco Bubble Blast.

La scelta viene dalla conoscienza pregresso del comportamento di giochi in stile Bubble Blast.

## Sviluppo
Lo sviluppo del progetto é stato effettuato in primo luogo con un approccio testuale su carta per definire
i requisiti funzionali del programma.
In seguito, sempre sull'onda del sopracitato metodo, il progetto é stato decomposto in funzionalitá basiche
che serviranno per definire i moduli di piú basso livello, essi interagiranno tra di loro durante
l'esecuzione del programma.
Sono stati inoltre definiti gli oggetti basici del programma.

Una volta preparato l'ambiente di sviluppo (Editor+Compilatore) é stato deciso di dividere il progetto in piú file:

* BubbleBlast.c [file contenente lo scheletro del gioco]
* funzioni.h	[libreria delle funzioni del gioco]
* funzioni.c	[file di definizione delle funzioni che saranno usate per il funzionamento del gioco]

Perché tale scelta? 
Tale approccio consente in primis una piú chiara lettura del codice del gioco e, di conseguenza, un possibile
riutilizzo del codice sia primario (BubbleBlast.c) sia delle funzioni (funzioni.c / funzioni.h).
Inoltre consente l'Information Hiding dei moduli di cui i progetto si avvale.

Ogni funzionalitá o blocco del codice é stato opportunamente commentato.

## Funzionamento
Al momento dell'avvio del gioco viene presentato un breve benvenuto con le istruzioni per affrontare
il gioco.
Una percentuale di caricamento viene poi presentata in attesa della generazione della tabella.
Vengono dunque presentati i passi minimi necessari e quelli massimi raggiungibili per poter vincere.
Dunque appare la tabella e il gioco comincia.

### Possibili sviluppi
Il programma potrebbe essere ulteriormente sviluppato integrando un modulo per la scelta del livello di
difficoltá.

### Codice piú significativo

Funzioni:
* char bollaRandom();
* int passiNecessari (char griglia[5][6]);

### Software utilizzato
* COMPILATORE: gcc
* EDITOR: Visual Studio Code
* GIT: GitBash

### How to run
Scaricare i 3 file sorgente e compilare nella stessa cartella di Download con il seguente comando:

gcc -o [nomeFile].exe BubbleBlast.c funzioni.c






