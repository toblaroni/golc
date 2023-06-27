
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

const int width  = 10;
const int height = 10;
const char ALIVE = '0';
const char DEAD  = '.';

char pState[10][10] = {};
char cState[10][10] = { {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '0', '0', '.', '.', '0', '.', '.', '.', '.'},
                        {'.', '0', '0', '.', '.', '0', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '0', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '0', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'0', '.', '0', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '0', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'} };


void showGame();
void updateGame();
int numNeighbours(int i, int j);

int main(void) {
   updateGame();
   showGame();
}


void updateGame() {
   // Set the previous state to be the current state.
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         pState[i][j] = cState[i][j];
      }
   }

   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {

      }
   }


}

void showGame() {
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         printf("%c ", pState[i][j]);
      }
      printf("\n");
   }
}

int numNeighbours(int i, int j) {
   int count = 0;

   // Edge cases
   if (i == 0 && j == 0) {

   } else if (i == height - 1 && j == width - 1) {

   } else if (i == 0 && j == width - 1) {

   } else if (i == height - 1 && j == 0) {

   }

   return count;
}
