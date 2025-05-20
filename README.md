# Student-Management-System-C


## 📖 Project Overview
The Student Management System is a console-based application written in C, designed to illustrate fundamental embedded and systems programming concepts. Utilizing a singly linked list data structure, this program provides a simple yet robust platform to store, manage, and analyze student records, including operations such as creation, retrieval, updating, deletion, and statistical computation. 


## 🎯 Objectives
- Demonstrate mastery of core C programming constructs: pointers, structures, dynamic memory allocation, and linked lists.
- Implement a state-machine driven menu interface for continuous user interaction.
- Apply modular programming principles to separate interface logic (main.c) from business logic (Student_Functions.c).
- Practice error checking and resource management in low-level code suitable for embedded environments.

## 💡 Key Features 

1. Add Student
   - Prompt user for ID, name, age, and GPA
   - Reject duplicate IDs and handle allocation failures gracefully

2. Display All Students
   - Traverse the linked list and print each student’s details
   - Notify if the list is empty

3. Search by ID
   - Locate and display a student record by unique ID
   - Print a "not found" message if absent

4. Update Student
   - Modify existing record fields (name, age, GPA)
   - Preserve list integrity if ID doesn’t exist

5. Delete Student
   - Remove a node by ID, with special handling for the head node
   - Free allocated memory to prevent leaks

6. GPA Statistics
   - Calculate and print the average GPA
   - Identify and display the student with the highest GPA
