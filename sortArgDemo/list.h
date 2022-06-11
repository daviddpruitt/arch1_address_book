#include <stdio.h>

extern const size_t MAX_STRING_LENGTH;

// struct for list node
typedef struct LNode_s {
  struct LNode_s *next;
  struct LNode_s *prev;
  char *str;
} ListNode;

// Basic list functions

/* Insert a string into the list */
void list_insert(ListNode **root, char *str);

/* Print the list in order */
void list_print(ListNode *root);

/* Remove all items in the list and free their memory */
void list_clear(ListNode **root); 
