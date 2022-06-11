#ifndef _ADDRESS_BOOK_H_
#define _ADDRESS_BOOK_H_

/* returns the length of the null terminated string up to a maximum of max_length */
size_t strnlen(char *string, size_t max_length);

/* compares two strings to the end of the string or up to max_length returns 
   < 0 if string 1 comes before string 2 alphabetically
   0 if they are the same
   > 0 if string 1 comes after string 2 alphabetically
   The match is case sensitive, upparcase letters come before lowercase
   letters, so strncmp("A", "a") returns <0
*/
int strncmp(char *string1, char* string2, size_t max_length);

/* copys a string from source to the destination, the destination
   up to max_length characters.
   the destination must already be allocated
 */
viod strncpy(char *src, char *dst, size_t max_length);

/* creates a new node with the specified name and phone # */
BSTNode *new_node(char *name, char* phone);

/* frees memory used by a node */
BSTNode *free_node(BSTNode *node);

/* finds a node in the tree starting at root with the given name
   if the name doesn't exist returns an appropriate value signalling 
   that such a node doesn't exist
*/
BSTNode *find_name(BSTNode *root, char *name);

/* Inserts a node into a binary search tree pointed to by root */
void insert(BSTNode *root, BSTNode *new_node);

/* Deletes a node with the given name from the tree pointed to by 
   root, if the name doesn't exist the tree remains unchanged */
void delete(BSTNode *root, char *name);

/* clears the binary search tree pointed to by root and frees its memory */
void clear(BSTNode *root);

#endinf // _ADDRESS_BOOK_H_
