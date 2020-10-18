/****************************************************/
/* sudoku.c                                         */
/* Andreea Muresan                                  */
/* SID: 1498868                                     */
/* Description: Takes user input sudoku board and   */
/* solves it using struct                           */
/****************************************************/

#include <stdio.h>
#include <stdbool.h>

#define N 9
int counter = 0;

bool in_row(int puzzle[N][N], int row, int num);
bool in_col(int puzzle[N][N], int col, int num);
bool in_sqr(int puzzle[9][9], int initial_row, int initial_col, int num);

struct cell {
  int num;
  int maybe[10];
};

int fill_maybes(int puzzle[N][N], int row, int col) {
  for (int n = 1; n <= 9; n++) {
    if (!in_row(puzzle, row, n) && !in_col(puzzle, col, n)
        && !in_sqr(puzzle, row - (row%3), col - (col%3), n)) {
          puzzle[row][col].maybe[n] = 1;
    } else {
      puzzle[row][col].maybe[n] = 0;
    }
  }
}

bool in_row(int puzzle[N][N], int row, int num) {
  for (int i = 0; i < 9; i++) {
    if (puzzle[row][i].num == num) {
      return true;
    }
  }
  return false;
}

bool in_col(int puzzle[N][N], int col, int num) {
  for (int i = 0; i < 9; i++) {
    if (puzzle[i][col].num == num) {
      return true;
    }
  }
  return false;
}

bool in_sqr(int puzzle[9][9], int initial_row, int initial_col, int num) {
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (puzzle[i + initial_row][j + initial_col].num == num)
        return true;
    }
  }
  return false;
}

// int found_number(puzzle, row, col){
//   for (int n = 1; n <= 9; n++){
//     if (!in_row(...) && !in_col(...) && !in_box(...)){
//       puzzle[row][col].maybe[n] = n;
//
//     }
//   }
// }

int main(void) {
  struct cell puzzle[N][N];

  // READ IN PUZZLE
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++){
      scanf(" %d", &puzzle[i][j].num);
      if (puzzle[i][j].num != 0) counter++;
    }
  }

  // FILL IN MAYBE NUMBERS
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (puzzle[row][col].num == 0) {
        fill_maybes(puzzle, row, col);
      }
    }
  }
  
  printf("puzzle[0][0].maybe[0] = %d\n", puzzle[0][0].maybe[0]);
  // puzzle[0][0].num = 0;
  // printf("%d\n", puzzle[0][0].num);
  return 0;
}
