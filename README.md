# CS330_Project7_StudentDBTree

## Project Overview

**StudentDBTree** is a C++ project that implements a **Binary Search Tree (BST)** to manage a student database. Each student is assigned a unique ID upon joining, and the BST provides efficient operations for storing, retrieving, and deleting student records. This project highlights the use of Object-Oriented Programming (OOP) concepts like inheritance, composition, and memory management.

## Features

- **Binary Search Tree (BST)**:
  - Efficient insertion, search, and deletion of student records.
  - Implements the core operations of a Binary Search Tree (BST).
  
- **Student Database**:
  - Each student is assigned a unique, auto-incrementing ID upon joining the school.
  - Even if a student leaves (is deleted from the BST), the ID is not reassigned to another student, maintaining a unique record of total students.

- **Object-Oriented Design**:
  - **Composition**: BST uses C++ classes to represent nodes and their relationships.
  - **Inheritance**: The student database is built using inheritance to extend the BST functionalities.
  
- **Error Handling and Memory Management**:
  - The project ensures that there are no memory leaks using destructors.
  - Proper validation of input data and operations.

## Project Structure

```bash
.
├── bst.h                   # Binary Search Tree class declaration
├── bst.cc                  # Binary Search Tree class implementation
├── db.h                    # Student Database class declaration
├── db.cc                   # Student Database class implementation
├── main.cc                 # Main file to run tests and examples
├── Makefile                # Makefile to compile the project
└── test_files/             # Directory containing input/output test files
```

## How to Build and Run

### Prerequisites

- A C++ compiler that supports C++11 or later.
- Make sure you have `make` installed to use the provided `Makefile`.

### Build

To compile the project, run the following command in the terminal:

```bash
make
```

This will compile the project and generate the executable file.

### Run

After building, you can run the program using the generated executable. Here’s an example:

```bash
./student_db_tree
```

### Testing

The project includes test files that can be used to test the functionality of the Binary Search Tree and the Student Database. Unit tests are provided to validate that the tree works correctly for different input sizes and operations.

You can run the unit tests using the following commands:

- **BST Unit Test**:
  ```bash
  ./student_db_tree -bst -t 100 -s 100
  ```
  This tests the BST with 100 elements and seed 100.

- **Student Database Test**:
  ```bash
  ./student_db_tree -db -i test_files/students_1.txt -o test_files/students_1_ans.txt
  ```
  This runs the student database functionality using the provided input file and checks the results.

## Features to Enhance

Here are some future enhancements that can be added to improve **StudentDBTree**:

1. **Self-Balancing Tree (e.g., AVL or Red-Black Tree)**: Extend the project to include self-balancing features to improve performance for larger datasets.
  
2. **Persistent Database**: Add functionality to store student records in a file for persistent storage, allowing the database to be loaded even after the program ends.

3. **Search and Filtering Options**: Implement advanced search features to filter students by name, enrollment date, or other criteria.

## Memory Management

This project ensures that there are no memory leaks, and all dynamically allocated memory is properly released using destructors. Valgrind can be used to verify that the implementation is memory-safe.

To run Valgrind (if installed):

```bash
valgrind ./student_db_tree
```

