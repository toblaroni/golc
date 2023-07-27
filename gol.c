
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
#include <string.h>
#include <unistd.h>

#define WIDTH  100
#define HEIGHT WIDTH 

const char ALIVE = '0';
const char DEAD  = '.';

char pState[HEIGHT][WIDTH];
char cState[HEIGHT][WIDTH];
/*
char cState[HEIGHT][WIDTH] = { {DEAD,ALIVE,DEAD},
                               {DEAD,ALIVE,DEAD},
                               {DEAD,ALIVE,DEAD} };
                               */

int checkAbove(int, int);
int checkBelow(int, int);
int checkLeft(int, int);
int checkRight(int, int);

int checkTopLeft(int, int);
int checkTopRight(int, int);
int checkBottomLeft(int, int);
int checkBottomRight(int, int);

void showGame();
void updateGame();
int numNeighbours(int i, int j);
void makeRandomGame();

int main(void) {
   makeRandomGame();
   showGame();
   while (1) {
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

         if (pState[i][j] == ALIVE) {
            if (neighbours == 2 || neighbours == 3) {
               continue;
            }
            cState[i][j] = DEAD;

         } else {
            if (neighbours == 3) {
               cState[i][j] = ALIVE;
            }
         }
      }
   }
}

void showGame() {
   system("clear");
   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         printf("%c", cState[i][j]);
      }
      printf("\n");
   }
   system("sleep 0.5");
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
      count += checkBelow(i, j);
      count += checkRight(i, j);
      count += checkBottomRight(i, j);

      return count;

   } else if (i == HEIGHT - 1 && j == WIDTH - 1) { // Bottom right
      count += checkAbove(i, j);
      count += checkLeft(i, j);
      count += checkTopLeft(i, j);
      return count;

   } else if (i == 0 && j == WIDTH - 1) { // top right
      count += checkBelow(i, j);
      count += checkLeft(i, j);
      count += checkBottomLeft(i, j);
      return count;

   } else if (i == HEIGHT - 1 && j == 0) { // Bottom left
      count += checkAbove(i, j);
      count += checkRight(i, j);
      count += checkTopRight(i, j);
      return count;

   } else if (i == 0) { // Top edge
      count += checkBelow(i, j);
      count += checkLeft(i, j);
      count += checkRight(i, j);
      count += checkBottomRight(i, j);
      count += checkBottomLeft(i, j);
      return count;

   } else if (i == HEIGHT -1) {  // Bottom edge
      count += checkAbove(i, j);
      count += checkLeft(i, j);
      count += checkRight(i, j);
      count += checkTopRight(i, j);
      count += checkTopLeft(i, j);
      return count;

   } else if (j == 0) { // Left edge
      count += checkAbove(i, j);
      count += checkBelow(i, j);
      count += checkRight(i, j);
      count += checkTopRight(i, j);
      count += checkBottomRight(i, j);
      return count;

   } else if (j == WIDTH - 1) { // Right edge
      count += checkAbove(i, j);
      count += checkBelow(i, j);
      count += checkLeft(i, j);
      count += checkTopLeft(i, j);
      count += checkBottomLeft(i, j);
      return count;
   }

   count += checkAbove(i, j);
   count += checkBelow(i, j);

   count += checkLeft(i, j);
   count += checkRight(i, j);

   count += checkBottomRight(i, j);
   count += checkBottomLeft(i, j);

   count += checkTopLeft(i, j);
   count += checkTopRight(i, j);

   return count;
}

int checkAbove(int i, int j) {
   if (pState[i-1][j] == ALIVE) return 1;
   return 0;
}
int checkTopRight(int i, int j) {
   if (pState[i-1][j+1] == ALIVE) return 1;
   return 0;
}
int checkTopLeft(int i, int j) {
   if (pState[i-1][j-1] == ALIVE) return 1;
   return 0;
}
int checkBottomRight(int i, int j) {
   if (pState[i+1][j+1] == ALIVE) return 1;
   return 0;
}
int checkBottomLeft(int i, int j) {
   if (pState[i+1][j-1] == ALIVE) return 1;
   return 0;
}
int checkBelow(int i, int j) {
   if (pState[i+1][j] == ALIVE) return 1;
   return 0;
}
int checkLeft(int i, int j) {
   if (pState[i][j-1] == ALIVE) return 1;
   return 0;
}
int checkRight(int i, int j) {
   if (pState[i][j+1] == ALIVE) return 1;
   return 0;
}
