#include <stdlib.h>

typedef struct int_cell {
  int value;
  struct int_cell* next;
} * int_list;

int_list new_int_list() { return NULL; }

void delete_int_list(int_list ilist) {
  if (ilist == NULL) return;

  delete_int_list(ilist->next);
  free(ilist);
}

int_list add_at_head_of_int_list(int_list ilist, int value) {
  int_list new_list = (int_list)malloc(sizeof(struct int_cell));
  if (new_list == NULL) {
    exit(EXIT_FAILURE);
  }

  new_list->value = value;
  new_list->next = ilist;

  return new_list;
}

#ifdef TEST
#include <assert.h>

#define LIST_LENGTH 5
void test_int_list() {
  int_list list = new_int_list();
  for (size_t i = 0; i < LIST_LENGTH; i++) {
    list = add_at_head_of_int_list(list, i);
  }

  int_list current_head = list;
  for (size_t i = 0; i < LIST_LENGTH; i++) {
    assert(current_head->value == 4 - i);
    current_head = current_head->next;
  }

  assert(current_head == NULL);
}

int main(void) { test_int_list(); }

#endif
