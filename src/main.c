/*
 * File: main.c
 * Flusso di esecuzione:
 *
 *  - lettura del file di input:
 *        - prima riga: dettagli strutturali (righe, colonne, num veicoli, num
 *                      corse, bonus partenza in orario, tempo totale
 *                      simulazione)
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

// Defining structure for Position object
typedef struct Position {
  int x;
  int y;
} position_t;

// Defining structure for Car object
typedef struct Car {
   position_t position; // current position of the car
   int totalTime;            // total time of the rides run by the car
} car_t;

// Defining structure for GameData object
typedef struct GameData {
    int rows;
    int columns;
    int vehicleNum;
    int rideNum;
    int bonusForOnTimeLeave;
    int maxSimulationTime;
} gamedata_t;

// Defining structure for Ride object
typedef struct Ride {
  position_t start;
  position_t end;
  int startTime;
  int finalTime;
} ride_t;

// Defining list of Rides
typedef struct RideListNode {
    // The ride to store
    ride_t ride;
    // The next object in the list
    struct RideListNode *next;
} ridelistnode_t;


void init() {
    // Global variables
    //struct gamedata_t* GAME_DATA = malloc( sizeof( gamedata_t ) ); //
    //struct ridelistnode_t* head  = malloc( sizeof ( ridelistnode_t ) );  // first element of the list
}

void defineRideFromInputLine(char* rideData) {

}

void readInputFile(gamedata_t* GAME_DATA, ridelistnode_t* head, char* iFile) {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(iFile, "r");

    int count = -1;
    ridelistnode_t* node = head;
    if (fp == NULL) {
        printf(" ***** ERROR: failure on opening file!\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        count++;
        //printf("line: %s\n", line);
        if ( count == 0 ) {
            //int r = 0, c = 0, v = 0, d = 0, b = 0, t = 0;
            //sscanf(line, "%i %i %i %i %i %i", &r, &c, &v, &d, &b, &t);
            //printf( "Registered game data: rows: %i, columns: %i, number of vehicles: %i, number of rides: %i, bonus: %i, total time: %i\n", r, c, v, d, b, t);
            sscanf(line, "%i %i %i %i %i %i", &(GAME_DATA->rows), &(GAME_DATA->columns), &(GAME_DATA->vehicleNum), &(GAME_DATA->rideNum), &(GAME_DATA->bonusForOnTimeLeave), &(GAME_DATA->maxSimulationTime)) ;
            printf( "Registered game data: rows: %i, columns: %i, number of vehicles: %i, number of rides: %i, bonus: %i, total time: %i\n", GAME_DATA->rows, GAME_DATA->columns, GAME_DATA->vehicleNum, GAME_DATA->rideNum, GAME_DATA->bonusForOnTimeLeave, GAME_DATA->maxSimulationTime);
        }
        else {
            //printf("Reading ride . . .\n");
            int sx = 0, sy = 0, ex = 0, ey = 0, ts = 0, te = 0;
            // Defining a new ride with the data . . .
            ride_t* ride = malloc( sizeof ( ride_t ) ) ;
            position_t* start = malloc( sizeof( position_t) );
            position_t* end   = malloc( sizeof( position_t) );
            ride->start = *start;
            ride->end   = *end;
            sscanf(line, "%i %i %i %i %i %i", &(ride->start.x), &(ride->start.y), &(ride->end.x), &(ride->end.y), &(ride->startTime), &(ride->finalTime));
            //printf(" --> Ride %i: [ %i, %i] to [ %i, %i] leave max on %i and arrive on %i\n", count, ride->start.x, ride->start.y, ride->end.x, ride->end.y, ride->startTime, ride->finalTime);
            // "node" is the previous element: defining the next element and setting the next->ride to the actual ride
            node->ride = *ride;
            node->next = malloc( sizeof( ridelistnode_t ) ) ;
            node->next->next = NULL;
            node = node->next;
        }
    }
    fclose(fp);
    if (line)
      free(line);
    //exit(EXIT_SUCCESS);
}



int main(int argc, char* argv[]) {
    printf("Initializing . . . \n");
    //init();
    // Global variables
    gamedata_t* GAME_DATA = malloc( sizeof( gamedata_t ) );
    ridelistnode_t* head  = malloc( sizeof ( ridelistnode_t ) );  // first element of the list
    printf( "Reading input file . . .\n" );
    readInputFile(GAME_DATA, head, "./input/a_example.in");
    printf( "Testing ride list . . .\n");
    ridelistnode_t* node = head;
    int count = 0;
    while ( node->next != NULL ) {
        ride_t ride = node->ride;
        printf(" --> Ride %i: [ %i, %i ] to [ %i, %i ] leave max on %i and arrive on %i\n", count, ride.start.x, ride.start.y, ride.end.x, ride.end.y, ride.startTime, ride.finalTime);
        node = node->next;
        count++;
    }
    printf( "Planning rides . . .\n");


}
