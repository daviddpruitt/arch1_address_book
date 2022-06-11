#include <malloc.h>
#include <string.h>
#include "list.h"

// creates a new node with str
ListNode* create_node(char *str);
  
const size_t MAX_STRING_LENGTH = 256;

/* inserts a string in order into the list pointed to by root
   if root is 0 (an empty list) a new node is created and root
   is set to that node
*/
void list_insert(ListNode **root, char *str)
{
  // why is root a ** and why are we use *root?
  // root is empty, insert here
  if (*root == NULL) {
    *root = create_node(str);
  } else {
    ListNode *insertion_point = *root;
    // advance to where we need to insert node
    while (strncmp(str, insertion_point->str, MAX_STRING_LENGTH) > 0) {
      if (insertion_point->next == NULL) {
	// insert at end of list
	// create a new node at that point
	ListNode *new_node = create_node(str);
	insertion_point->next = new_node;
	new_node->prev = insertion_point;
	return;
      }
      insertion_point = insertion_point->next;
    }

    // We're somewhere in the middle so we have to
    // create a node and insert it between two others
    ListNode *new_node = create_node(str);

    new_node->next = insertion_point;
    new_node->prev = insertion_point->prev;

    // if we're not the head
    if (insertion_point->prev != NULL) {
      insertion_point->prev->next = new_node;
    } else {
      // if we are head
      *root = new_node;
    }

    insertion_point->prev = new_node;
  }
  return;
}

/* prints the contents of the list */
void list_print(ListNode *root)
{
  if (root != NULL) {
    puts(root->str);
    list_print(root->next);
  }
  return;
}

/* clears the list */
void list_clear(ListNode **root)
{
  if (*root != NULL) {
    list_clear( &((*root)->next) );

    free((*root)->str);
    free(*root);
  }
  return;
}

ListNode* create_node(char *str)
{
  ListNode *new_node = (ListNode*)malloc( sizeof(ListNode) );

  new_node->next = NULL;
  (*new_node).prev = NULL;

  size_t str_len = strnlen(str, MAX_STRING_LENGTH);
  
  // why does this malloc have a * and the last one didnt't?
  char* new_str = (char*) malloc(sizeof(char) * str_len);
  
  size_t index = 0;
  while ( str[index] != '\0' ) {
    // wonder what's different between the two?
    new_str[index] = *(str + index);
    index++; // never forget the ++
  }
  *(new_str + index) = '\0';
  
  new_node->str = new_str;

  return new_node;
}
