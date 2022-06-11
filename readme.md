Lab Project 1: Building an address book
===================================
A related demo program is in directory "sortArgDemo". You are
encouraged to thoroughly understand it before attempting this project.

All work should be your own work. If you work with others or use information
from other source you must give proper attribution (note: you may not use code
snippets without explicit permission). For example
* Worked with Juan Smith on algorithm
* Used algorithm from https://stackoverflow.com/questions/11227809/why-is-processing-a-sorted-array-faster-than-processing-an-unsorted-array

Please see the course website and syllabus for full details on the course's policy on academic honesty.

Prototype source code for this project is in a directory named `src`.
You should add and modify source code within that directory, and those
changes should be pushed to your private Github repository prior to
the deadline. Your project should contain:  
- All .c and .h source files
- A Makefile whose default production builds the project, and whose
`clean` production eliminates any files created when the project is
built.
- A brief README documenting any non-obvious aspects of your program.
  For example, you may want to describe how it works, how to run it,
  and any bugs or idiosyncracies the user ought to know about.

## Learning outcomes
Students who complete this lab will demonstrate ability to
- Use command-line tools (cp, mv, rm, mkdir, cd, emacs, cc, make, git)
for program development under bash
- Develop and debug C programs that include
  - Pointer arithmetic
  - Dynamic memory allocation & free (malloc/calloc/free)
  - Multiple source files (and headers with declarations)
  - A pointer-based data structure (linked list of structs)
- Design a comprehensible small program in the C language.
- You may refer to the syllabus, course info, lectures, and assignment
for an in depth explanation of the grading criteria and expectations.

# Grading
At a technical interview where your project will be examined
and discussed, your mastery of the following will be assessed

- Proper use of development tools (e.g. bash, emacs, make, compiler,
  and git)
- Clear and concise written communication
- Code Hygiene: consistent, expressive, and efficient
    - variable, function, and struct names
    - comments
    - modularization (into functions and files) including header files
    - storage management (variable scope & lifetime, allocation and
      freeing of dynamically allocated memory)
    - consistent and language-appropriate coding style
       - indentation
       - use of capitalization and whitespace (e.g. `char *word_end(char *p)`
         rather than `char* wordEnd (char* p)`)
    - algorithms and data structures
    - repository content (all necessary files are included, no
      unnecessary files such as `#ui.h#` and `address_book.o`)
    - repository log messages (we encourage you to examine ours)
- Correctness
- Timely completion

## Overview
Your task for this lab project is to build a simple sorted address book. Users
will be able to enter names and phone numbers. After these are entered they
can go back and retrieve them. Users should be able to recall an entry by name
or print out the entire address book.

When the program starts up it should give the option of adding an entry,
recalling an entry, printing all entries, or clearing the address book.

You should have code to test the functionality of the code. Its recommended
that you come up with a few test cases first so that you can better understand
what you need to do and to make sure individual pieces work properly.

## Requirements
Except for the functions listed below you must write all the code
yourself. You may also use scanf although this is highly discouraged.
* printf
* puts
* gets
* getchar
* putchar

The address book entries must be stored in a binary search tree. Each entry
must contain a name and a phone number.

The UI must allow the user to enter more than one address book entry, retrieve
them, delete them, and to clear the address book. The code for the UI must be
in a seperate file from the address book implementation. 

## Building a Simple UI
The first milestone for your project is to complete a simple functioning
user interface (which means it does not have to be anything fancy). It
should have an indicator on the left to notify the user that the program
is ready to receive input. For example:

`$ this would work`

`> or even this`

At this point of the project, your program should just echo the input
back to the user.

```
$ my fancy interface thing
my fancy interface thing
```

## Working with Strings
Inside this repository there is one header file, **address_book.h**,
which declare functions your project will define. You should explore the
contents of the file so that you are familiar with the instructions to
follow.

The second milestone of your project is to define several of the
functions declared and described (but not defined) in address_book.h:


1. `size_t strnlen(char *string, size_t max_length); // returns the length of a string`
2. `int strncmp(char *string1, char* string2, size_t max_length); // compares two strings`
3. `void strncpy(char *src, char *dst, max_length); // copys the string source into the destination

## Dealing with memory allocation
The third milestone of your project will require you to allocate and free
memory. You must define and test the following functions declared in `list.h`

4. `BSTNode *new_node(char *name, char* phone); // create a new node `
5. `BSTNode *free_node(BSTNode *node); // frees the given node`
6. `BSTNode *find_name(BSTNode *root, char *name); // find a node with the given name`

## Putting it together
Now that you have all the pieces for the tokenizer defined, the last part is
to put them together and define the functions you need to create and traverse
the tree.

7. `void insert(BSTNode *root, BSTNode *new_node); // insert a node into the tree`
8. `void delete(BSTNode *root, char *name); // deletes a node with the given name`
9. `void clear(BSTNode *root); // clears the tree and frees its memory`
