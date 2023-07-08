
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



char pState[][] = {};
char cState[][];

void showGame();
void updateGame();
int numNeighbours(int i, int j);
void makeRandomGame(int w, int h);

int main(void) {
   while(1) {
      updateGame();
      showGame();
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
            pState[i][j] = ALIVE;
         else if (pState[i][j] == DEAD && neighbours == 3)
            pState[i][j] = ALIVE;
         else
            pState[i][j] = DEAD;

      }
   }
}

void showGame() {
   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         putchar(pState[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}


void makeRandomGame(int w, int h) {
   srand(time(NULL));
   
   for (int i = 0; i < 
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
