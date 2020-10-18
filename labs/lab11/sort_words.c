/**********************************************************/
/* sort_words.c                                           */
/* Andreea Muresan                                        */
/* SID: 1498868                                           */
/* Description: This program asks the user to input       */
/* words, when they do not enter a word the program       */
/* prints out the given words in lexicographic order.     */
/**********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // use qsort from here
#define WORD_MAX 20

char read_word(char **line, int w);
int compare_words(const void *p, const void *q);

int main() {

  char** word_list = malloc(sizeof(char*));

  char* word; // word is NULL
  int iter = 0; // number of words

  while (1) {

    if((word = malloc(WORD_MAX + 1)) == NULL)
      exit(EXIT_FAILURE);

    printf("Enter a word: ");
    fgets(word, WORD_MAX + 1, stdin);
    if (word[strlen(word) - 1] == '\n')
      word[strlen(word) - 1] = '\0';

    // check if no word was entered
    if (word[0] == '\0')
      break;

    // move pointer to next position and put new word in
    *(word_list + iter) = word;
    iter++;

    // get one more space as needed
    word_list = realloc(word_list, sizeof(char *) * (iter + 1));
  }

  qsort(word_list, iter, sizeof(char *), compare_words);
  printf("\nIn sorted order: \n");
  for (int i = 0; i < iter; i++) {
      printf("%s\n", *(word_list + i));
  }
  printf("\n");

  free(word_list);
  return 0;
}

// taken directly from page 453 of textbook
int compare_words(const void *p, const void *q) {
  // p and q are two words
  return strcmp( *(char **)p, *(char **)q );
}
