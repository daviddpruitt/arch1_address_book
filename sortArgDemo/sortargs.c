#include "list.h"  

/* prints arguments in order */
int main(int argc, char **argv)
{
  ListNode *list_head = NULL;
  /* argv is an array of strings that
     contains all the arguments passed to the program
  */
  for (char **p = &argv[1]; *p; p++) {
    list_insert(&list_head, *p);
  }

  list_print(list_head);
  list_clear(&list_head);
  return 0;
}
