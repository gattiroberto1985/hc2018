/*
 * File: main.c
 * Flusso di esecuzione:
 *
 *  - lettura del file di input:
 *        - prima riga: dettagli strutturali (righe, colonne, num veicoli, bonus
 *                      partenza in orario, tempo totale simulazione)
 *        - righe successive: singole corse, con:
 *                 p_start  [ x_start, y_start ], p_end [ x_end, y_end ], t_start, t_end
 *
 *        - creazione matrice con lista dei percorsi
 *
 *  - pianificazione corse:
 *
 *      per ogni macchina cerco la corsa con minimizzazione tra:
 *        - distanza macchina - p_start_corsa (abs( p_in_corsa - p_in_macchina)) < parametro_interno_o_specificato
 *        - t_start_corsa e valore di cui sopra ( deve essere > 0 )
 *
 *      se la corsa esiste, la assegno e procedo ad una nuova ricerca per la
 *      stessa macchina, con nuove posizioni e tutto.
 */

 #include <stdio.h>
 #include <stdlib.h>

struct Position {
  int x;
  int y;
};

struct Car {
   struct Position position; // current position of the car
   int totalTime;     // total time of the rides run by the car
};

struct Ride {
  struct Position start;
  struct Position end;
  int startTime;
  int finalTime;
};

void readInputFile(char* iFile) {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(iFile, "r");
    if (fp == NULL)
      exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
      printf("%s", line);
    }
    fclose(fp);
    if (line)
      free(line);
    exit(EXIT_SUCCESS);
}



int main( ) {
  printf( "Reading input file . . ." );
  readInputFile("../input/a_example.in");
  printf( "Planning rides . . .");


}
