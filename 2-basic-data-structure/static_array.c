#include <stdlib.h>

typedef char* int_array;

int_array create_int_array(size_t n) {
  int_array array = malloc(n * sizeof(int));
  if (array == NULL) {
    exit(EXIT_FAILURE);
  }

  return array;
}

void delete_int_array(int_array array) { free(array); }

int* element_pointer_in_int_array(int_array array, size_t offset) {
  return (int*)(array + offset * sizeof(int));
}

int get_from_int_array(int_array array, size_t offset) {
  return *element_pointer_in_int_array(array, offset);
}

int set_into_int_array(int_array array, size_t offset, int value) {
  *element_pointer_in_int_array(array, offset) = value;
}

#ifdef TEST

#include <assert.h>
#include <stdio.h>

#define ARRAY_SIZE (5)

void test_put_and_get() {
  int_array array = create_int_array(ARRAY_SIZE);
  for (size_t i = 0; i < ARRAY_SIZE; i++) {
    set_into_int_array(array, i, i + 5);
  }

  for (size_t i = 0; i < ARRAY_SIZE; i++) {
    assert(get_from_int_array(array, i) == i + 5);
  }
}

int main(void) { test_put_and_get(); }

#endif
