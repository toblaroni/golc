
/*
 * IMPLEMENTATION OF GAME OF LIFE IN C
 *
 * RULES
 * - Alive cell with 2 or 3 neighbours = Alive
 * - Dead cell with 3 neighbours = lives
 * - All others cells = dead
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH  10
#define HEIGHT 10

const char ALIVE = '0';
const char DEAD  = '.';



char pState[HEIGHT][WIDTH] = {};
/* char cState[HEIGHT][WIDTH] = { {'0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'} };

                               */

char cState[HEIGHT][WIDTH] = { {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '0', '0', '.', '.', '0', '.', '.', '.', '.'},
                              {'.', '0', '0', '.', '.', '0', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '0', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'0', '.', '0', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '0', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '0', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'} };

void showGame();
void updateGame();
int numNeighbours(int i, int j);
void makeRandomGame();

int main(void) {
   char in; 
   makeRandomGame();
   showGame();
   while (1) {
      scanf("%c", &in);
      if (in == '\n') {
         updateGame();
         showGame();
      }
   }
}


void updateGame() {
   // Set the previous state to be the current state.
   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         pState[i][j] = cState[i][j];
      }
   }

   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         int neighbours = numNeighbours(i, j);
         // printf("Cell at %i, %i has %i neighbours\n", i, j, neighbours);
         if (pState[i][j] == ALIVE && (neighbours == 2 || neighbours == 3)) 
            cState[i][j] = ALIVE;
         else if (pState[i][j] == DEAD && neighbours == 3)
            cState[i][j] = ALIVE;
         else
            cState[i][j] = DEAD;

      }
   }
}

void showGame() {
   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         fputc(cState[i][j], stdout);
      }
      fputc('\n', stdout);
   }
}


void makeRandomGame() {
   srand(time(NULL));
   float r;
   
   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         r = (float) rand() / RAND_MAX;
         if (r > 0.5) cState[i][j] = ALIVE;
         else  cState[i][j] = DEAD;
      }
   }
}


int numNeighbours(int i, int j) {
   int count = 0;

   // Edge cases
   if (i == 0 && j == 0) { // top left
      if (pState[i+1][j] == ALIVE) count++;
      if (pState[i][j+1] == ALIVE) count++;
      return count;

   } else if (i == HEIGHT - 1 && j == WIDTH - 1) { // Bottom right
      if (pState[i-1][j] == ALIVE) count++;
      if (pState[i][j-1] == ALIVE) count++;
      return count;

   } else if (i == 0 && j == WIDTH - 1) { // bottom left
      if (pState[i+1][j] == ALIVE) count++;
      if (pState[i][j-1] == ALIVE) count++;
      return count;

   } else if (i == HEIGHT - 1 && j == 0) { // top right
      if (pState[i-1][j] == ALIVE) count++;
      if (pState[i][j+1] == ALIVE) count++;
      return count;

   } else if (i == 0) { // Top row
      if (pState[i+1][j] == ALIVE) count++;
      if (pState[i][j+1] == ALIVE) count++;
      if (pState[i][j-1] == ALIVE) count++;
      return count;

   } else if (i == HEIGHT -1) { 
      if (pState[i-1][j] == ALIVE) count++;
      if (pState[i][j+1] == ALIVE) count++;
      if (pState[i][j-1] == ALIVE) count++;
      return count;

   } else if (j == 0) {
      if (pState[i-1][j] == ALIVE) count++;
      if (pState[i+1][j] == ALIVE) count++;
      if (pState[i][j+1] == ALIVE) count++;
      return count;

   } else if (j == WIDTH - 1) {
      if (pState[i-1][j] == ALIVE) count++;
      if (pState[i+1][j] == ALIVE) count++;
      if (pState[i][j-1] == ALIVE) count++;
      return count;
   }

   if (pState[i+1][j] == ALIVE) count ++;
   if (pState[i-1][j] == ALIVE) count ++;
   if (pState[i][j+1] == ALIVE) count ++;
   if (pState[i][j-1] == ALIVE) count ++;

   return count;
}
