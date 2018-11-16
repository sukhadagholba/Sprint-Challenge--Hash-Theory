#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  Answer *a = malloc(sizeof(Answer));

  for (int i = 0; i < length; i++) {
    int index_value = hash_table_retrieve(ht, weights[i]);
    
    if (index_value != -1) {
      a -> index_1 = i;
      a -> index_2 = index_value;
      //printf("Answer is index_1: %d index_2: %d \n", i, index_value);
      return a;
    } 

    else {
      int diff = (limit - weights[i]);	    
      hash_table_insert(ht, diff, i);
    }
  } 


  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}
