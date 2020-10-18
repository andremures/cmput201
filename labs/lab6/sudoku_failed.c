/****************************************************/
/* sudoku.c                                         */
/* Andreea Muresan                                  */
/* SID: 1498868                                     */
/* Description: Takes user input sudoku board and   */
/* solves it using backtracking.                    */
/****************************************************/

#include <stdio.h>
#include <stdbool.h>

bool in_row(int puzzle[9][9], int row, int num);
bool in_col(int puzzle[9][9], int col, int num);
bool in_sqr(int puzzle[9][9], int initial_row, int initial_col, int num);
bool check_ok(int puzzle[9][9], int row, int col, int num);

int main(void) {
  int puzzle[9][9];
  printf("Enter the sudoku puzzle:\n");

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++){
      scanf(" %d", &puzzle[i][j]);
    }
  }

  int row = 0;
  int col = 0;
  int num = 1;

  while (true){
    num = fill(row, col, num);
    if (num == 0){
      // print solved puzzle
    }else if (num == 10){
      printf("Not Solvable");
    };
  }

  // prints puzzle:
  // printf("\n");
  // for (int i = 0; i < 9; i++) {
  //   for (int j = 0; j < 9; j++){
  //     printf("%d ", puzzle[i][j][0]);
  //   }
  //   printf("\n");
  // }

  return 0;
}

/****************************************/

int fill(int puzzle[9][9], int row, int col, int num){
  if (puzzle[row][col] == 0) {
    again:
    if (check_ok(puzzle, col, row, num){
      puzzle[row][col] = num;
      fill(puzzle, row, col+1, 1);
    } else {
      num++;
      goto again;
    }
  } else {
    fill(puzzle, row, col+1, 1);
    return 0;
  }
  // if at the beginning, return num - it will be the one you put in the first time


    } else if (row < 9 && col < 9) {
      (++col) % 8;
      fill(puzzle, row, col);
    }


    }
      if (col <= 8 && row <= 8) {
        fill(puzzle, row, col+1, num);
      }
      col = 0;
    } else {
      return false;
    }
  num++;
  }

}

/****************************************/

bool in_row(int puzzle[9][9], int row, int num) {
  for (int i = 0; i < 9; i++){
    if (puzzle[row][i] == 0)
      return true;
  }
  return false;
}

/****************************************/

bool in_col(int puzzle[9][9], int col, int num) {
  for (int i = 0; i < 9; i++){
    if (puzzle[i][col] == 0)
      return true;
  }
  return false;
}

/****************************************/

bool in_sqr(int puzzle[9][9], int initial_row, int initial_col, int num) {
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (puzzle[i + initial_row][j + initial_col] == num)
        return true;
    }
  }
  return false;
}

/****************************************/

bool check_ok(int puzzle[9][9], int row, int col, int num) {
  if (!in_row(puzzle, row, num) && !in_col(puzzle, col, num)
      && !in_sqr(puzzle, row - (row%3), col - (col%3), num)){
    return false;
  }
  return true;
}
