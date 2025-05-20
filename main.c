/****************************************************************************
 Name        : main.c
 Author      : Salma Hamdy
 Description :
 ****************************************************************************/

#include <stdio.h>
#include "Student_Functions_Prototype.h"

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	/*Variable Declaration*/
	int choice;   /*user choice of operation*/
	int id;       /*student ID*/

	/********************************************Student Management System Menu*********************************************/

	do{
		printf("-------------------------------------------------------------\n");
		printf(" 1. Add Student\n 2. Display Students\n 3. Search for a student by ID\n 4. Update Student Information\n"
				" 5. Delete a Student\n 6. Calculate Average GPA\n 7. Search For Student With Highest GPA\n 8. Exit\n");

		/*Enter user's choice*/
		printf("Enter choice: ");
		scanf("%d", &choice);

		if(choice == 8){
			printf("********************You Exited The Program*******************\n");
			break;
		}

		/*Switch over the user's choice and call the corresponding function accordingly*/
		switch(choice)
		{

		case 1:
			addStudent(NULL);
			break;
		case 2:
			displayStudents();
			break;
		case 3:
			printf("Enter student ID: ");
			scanf("%d", &id);
			searchStudentByID(id);
			break;
		case 4:
			printf("Enter student ID: ");
			scanf("%d", &id);
			updateStudent(id);
			break;
		case 5:
			printf("Enter student ID:");
			scanf("%d", &id);
			deleteStudent(id);
			break;
		case 6:
			calculateAverageGPA();
			break;
		case 7:
			searchHighestGPA();
			break;
		}

	}while(1);

	return 0;
}
