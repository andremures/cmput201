#include "insertionsort.h"

void insertionsort(int a[], int left, int right) {
  if (left <= right) return;

  struct node head;
  head = malloc(sizeof(struct node));
  if (head == NULL) exit(-3);

  //(*head).value = a[left];
  head -> value = a[left];
  (*head).next = NULL;

  for (int i = left + 1; i <= right; i++) {
    head = add_to_list(head, a[i]);
  }

  int i = left;
  while(head != NULL) {
    a[i++] = head -> value;
    struct node *tmp = head;
    head = head -> next;
    free(tmp);
  }

  return;
}

struct node *add_to_head(struct node *head, int key) {
  return;
}
