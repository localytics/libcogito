#ifndef COGITO_LIST
#define COGITO_LIST

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A struct representing a node in the list. Contains a pointer to a string
 * representing the AWS identifier and a pointer to the next node.
 */
typedef struct cg_node {
  char *value;
  struct cg_node *next;
} cg_node_t;

/**
 * A struct representing the list. Contains a pointer to the head node of the
 * list and an integer flag representing whether or not this list is negated.
 */
typedef struct {
  struct cg_node *head;
  int negated;
} cg_list_t;

/**
 * A macro for looping through the nodes in the list.
 */
#define cg_ll_foreach(list, ptr) \
  for ((ptr) = list->head; (ptr) != NULL; (ptr) = (ptr)->next)

/**
 * Append a node to the end of the list.
 * @param list The list on which to append the new value
 * @param value The new value that should be appended to the list
 */
void cg_list_append(cg_list_t *list, char *value);

/**
 * Build the first node or append a node to the list.
 * @param list The list that should be updated (or created if NULL)
 * @param value The new value that should be appended to the list
 * @return The newly created or updated list
 */
cg_list_t* cg_list_update(cg_list_t *list, char *value);

/**
 * Build the first list node and return the list.
 * @param value The value to be used to create the first node
 * @return The newly created list
 */
cg_list_t* cg_list_build(char *value);

/**
 * The sum of the size of all of the values in the list.
 * @param list The list to with which to compute the sum
 * @return The size_t representing the sum
 */
size_t cg_list_value_size_sum(cg_list_t *list);

/**
 * Negate the given list.
 * @param list The list on which to flip the negated flag
 */
void cg_list_negate(cg_list_t *list);

/**
 * Free the memory for the entire list.
 * @param list The list to free
 */
void cg_list_free(cg_list_t *list);

#endif
