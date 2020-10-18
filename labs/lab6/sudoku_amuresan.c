/****************************************************/
/* sudoku.c                                         */
/* Andreea Muresan                                  */
/* SID: 1498868                                     */
/* Description: Takes user input sudoku board and   */
/* solves it using recursive backtracking.          */
/****************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct cell {
  int num;
  bool maybe[10];
  bool is_set; // true -> cannot change the cell
};

// PROTOTYPES
bool in_row(struct cell **puzzle, int row, int num);
bool in_col(struct cell **puzzle, int col, int num);
bool in_sqr(struct cell **puzzle, int irow, int icol, int num);
void update_row(struct cell **puzzle, int row, int num);
void update_col(struct cell **puzzle, int col, int num);
void update_sqr(struct cell **puzzle, int irow, int icol, int num);
void fill_maybes(struct cell **puzzle, int row, int col);

bool solve(struct cell **puzzle, int row, int col);

int main() {
  struct cell **puzzle;

  // ALLOCATE SPACE FOR 9X9 PUZZLE
  puzzle = (struct cell**) malloc(9 * sizeof(struct cell*));
  for (int i = 0; i < 9; i++) {
    puzzle[i] = (struct cell*) malloc(9 * sizeof(struct cell));
  }

  // READ IN PUZZLE
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf(" %d", &puzzle[i][j].num);
      if (puzzle[i][j].num != 0)
        puzzle[i][j].is_set = true;
    }
  }
  printf("\n");

  // FILL IN MAYBE NUMBERS
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (puzzle[row][col].num == 0) {
        fill_maybes(puzzle, row, col);
      }
    }
  }

  bool solved = solve(puzzle, 0, 0);

  if (!solved) {
    printf("Not solvable\n");
  } else {
    for (int i = 0; i < 9; i++) {
      if (i != 0 && i%3 == 0) printf("-------+-------+-------\n");
      for (int j = 0; j < 9; j++) {
        if (j != 0 && j%3 == 0) printf(" |");
        printf(" %d", puzzle[i][j].num);
      }
      printf("\n");
    }
  }
  return 0;
}

/***********************************/

bool solve(struct cell **puzzle, int row, int col) {

  if (row == 9)
    return true;

  if (puzzle[row][col].is_set) {
    //solve next one
    return col == 8 ? solve(puzzle, row + 1, 0) : solve(puzzle, row, col + 1);
  }

  for (int n = 1; n <= 9; n++) {
    if (puzzle[row][col].maybe[n]) {
      puzzle[row][col].num = n;
      update_row(puzzle, row, n);
      update_col(puzzle, col, n);
      update_sqr(puzzle, row - (row%3), col - (col%3), n);

      if (col == 8 ? solve(puzzle, row + 1, 0) : solve(puzzle, row, col + 1)) {
        return true;
      }
      // if the puzzle is not solved, revert the changes
      puzzle[row][col].num = 0;
      update_row(puzzle, row, n);
      update_col(puzzle, col, n);
      update_sqr(puzzle, row - (row%3), col - (col%3), n);
    }
  }
  // no maybes found
  return false;
}

/***********************************/

void fill_maybes(struct cell **puzzle, int row, int col) {
  for (int n = 1; n <= 9; n++) {
    if (!in_row(puzzle, row, n) && !in_col(puzzle, col, n)
        && !in_sqr(puzzle, row - (row%3), col - (col%3), n)) {
          puzzle[row][col].maybe[n] = true;
    } else {
      puzzle[row][col].maybe[n] = false;
    }
  }
}

void update_row(struct cell **puzzle, int row, int num) {
  for (int j = 0; j < 9; j++) {
    if (puzzle[row][j].num == 0) {
      fill_maybes(puzzle, row, j);
    }
  }
}

void update_col(struct cell **puzzle, int col, int num) {
  for (int i = 0; i < 9; i++) {
    if (puzzle[i][col].num == 0) {
      fill_maybes(puzzle, i, col);
    }
  }
}

void update_sqr(struct cell **puzzle, int irow, int icol, int num) {
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (puzzle[i + irow][j + icol].num == 0) {
        fill_maybes(puzzle, i + irow, j + icol);
      }
    }
  }
}

bool in_row(struct cell **puzzle, int row, int num) {
  for (int i = 0; i < 9; i++) {
    if (puzzle[row][i].num == num) {
      return true;
    }
  }
  return false;
}

bool in_col(struct cell **puzzle, int col, int num) {
  for (int i = 0; i < 9; i++) {
    if (puzzle[i][col].num == num) {
      return true;
    }
  }
  return false;
}

bool in_sqr(struct cell **puzzle, int initial_row, int initial_col, int num) {
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (puzzle[i + initial_row][j + initial_col].num == num)
        return true;
    }
  }
  return false;
}
