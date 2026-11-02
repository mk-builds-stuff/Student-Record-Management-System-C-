# Student-Record-Management-System-C-
# Student Record Management System (C)

A menu-driven student record management program written in C, using a Singly Linked List.

The project brings together pointers, structures, dynamic memory allocation, file handling, and a few different approaches to searching and sorting.

## Implementation

The program is divided into separate source files, with each operation handled independently.

- **`student.c`** – Handles the main menu, program flow, loading records at startup, and freeing the remaining nodes before exit. Menu options are case-insensitive.

- **`stud_add.c`** – Handles record creation and insertion. Roll numbers are assigned using the smallest available positive integer, and new nodes are inserted in ascending roll-number order.

- **`search.c`** – A common search function used by both modification and deletion. It supports searching by roll number, name, or percentage. When multiple records match, it lets you select the required record using its roll number.

- **`stud_mod.c`** – Uses the search function to locate a record before modifying its name or percentage.

- **`stud_del.c`** – Uses the same search function to locate a record, confirms the deletion, and unlinks and frees the selected node.

- **`stud_show.c`** – Traverses the linked list and displays the records in tabular form.

- **`stud_sort.c`** – Contains the sorting logic, node-counting function, and a custom case-insensitive string comparison function. Sorting is done using a dynamically allocated array of node pointers rather than rearranging the linked list itself. The array is sorted using Bubble Sort and freed afterwards.

- **`stud_save.c`** – Handles file operations. Existing records are loaded from `student.dat` at startup, and the current records can be saved back to the same file.

- **`header.h`** – Contains the student structure and function declarations shared across the source files.

## A Few Implementation Choices

- Used a custom `my_strcmp()` instead of relying on `strcmp()` for case-insensitive name matching and sorting.
- Reused a single search function across different operations by passing a mode to determine the available search criteria.
- Used an array of pointers for sorting so that the original linked list remains untouched.
- Kept the linked list ordered by roll number while allowing records to be displayed in a different order.
- Used the same search results to handle multiple matches rather than stopping at the first match.

## Build and Run

The project uses a Makefile for compilation.

make

./out


Student records are stored in `student.dat` in the project directory and loaded when the program starts.
