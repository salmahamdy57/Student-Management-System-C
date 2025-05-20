/****************************************************************************
 Name        : Student_Functions_Prototype.c
 Author      : Salma Hamdy
 Description : Function Prototypes
 ****************************************************************************/

struct student;
void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);
