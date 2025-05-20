/****************************************************************************
 Name        : Student_Functions.c
 Author      : Salma Hamdy
 Description : Student Functions
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*Structure that represents a student*/
struct student{
	int id;            /*Student ID*/
	char name[50];     /*Student Name*/
	int age;           /*Student Age*/
	float gpa;         /*Student GPA*/
};

/*Structure that represents a node in the linked list*/
struct node{
	struct student data;
	struct node *next;
};

struct node *head = NULL;    /*Pointer to point to the first node in the linked list*/
struct node *current = NULL; /*Pointer to loop on linked list*/

/*This function collects new student details from the user and adds them to the student linked list.*/
void addStudent(const struct student *const ptr)
{
	int id;  /*student ID*/

	printf("-------------------------------------------------------------\n");
	printf("Enter Student ID: ");   scanf("%d", &id);

	/*check if student ID already exists*/
	current = head;
	while(current != NULL) /*loop to the last node in the list*/
	{
		if(current -> data.id == id)
		{
			printf("-------------------------------------------------------------\n");
			printf("ERROR ID ALREADY EXISTS!\n");
			return;
		}
		current = current -> next;
	}

	/*if student ID does NOT exist attempt to allocate memory for new student nod*/
	struct node *newStudent = (struct node*)malloc(sizeof(struct node));

	/*if memory allocation fails*/
	if(newStudent == NULL)
	{
		printf("-------------------------------------------------------------\n");
		printf("ERROR MEMORY ALLOCATION FAILED!\n");
		return;
	}

	/*if memory allocation is successful copy student data to new node*/
	newStudent -> data.id = id;
	printf("Enter Student Name: "); scanf("%s",newStudent -> data.name);
	printf("Enter Student Age: ");  scanf("%d", &newStudent -> data.age);
	printf("Enter Student GPA: ");  scanf("%f", &newStudent -> data.gpa);

	newStudent -> next = NULL;

	/*if linked list is empty, head points to the first node*/
	if(head == NULL)
	{
		head = newStudent;
		return;
	}

	/*to add more nodes in the list*/
	current = head;
	while(current -> next != NULL) 	/*loop to reach the last node in the old list*/
	{
		current = current -> next;
	}
	current -> next = newStudent; /*make the last node in the old list point to the new node*/
}

/*This function displays the details of all students currently in the system.*/
void displayStudents(void)
{
	struct node *ptr = head;

	if(head == NULL) /*if student list is empty return*/
	{
		printf("-------------------------------------------------------------\n");
		printf("STUDENT LIST IS EMPTY!\n");
		return;
	}
	else /*if student list is not empty print list*/
	{

	printf("-------------------------------------------------------------\n");
		while(ptr != NULL)
		{
			printf("Student =>  ID: %d",ptr -> data.id);
			printf("  Name: %s",ptr -> data.name);
			printf("  Age: %d",ptr -> data.age);
			printf("  GPA: %.2f",ptr -> data.gpa);
			printf("\n");
			ptr = ptr -> next;
		}
	}
}
/*This function searches for a student by their ID and displays their details if found.*/
void searchStudentByID(int id)
{
	current = head;
	if(head == NULL) /*if student list is empty return*/
	{
		printf("-------------------------------------------------------------\n");
		printf("STUDENT LIST IS EMPTY!\n");
		return;
	}

	while(current != NULL) /*loops to the the last node in the linked list*/
	{
		if(current -> data.id == id)  /*if id was found display student details*/
		{
			printf("-------------------------------------------------------------\n");
			printf("Student found\n");
			printf("Student =>  ID: %d",current -> data.id);
			printf("  Name: %s",current -> data.name);
			printf("  Age: %d",current -> data.age);
			printf("  GPA: %.2f",current -> data.gpa);
			printf("\n");

			return;
		}
		current = current -> next;
	}
	/*if id was NOT found in the list*/
	printf("-------------------------------------------------------------\n");
	printf("STUDENT NOT FOUND!\n");

}

/*This function updates the details of a student with the given ID.*/
void updateStudent(int id)
{
	current = head;

	if(head == NULL) /*if student list is empty return*/
	{
		printf("-------------------------------------------------------------\n");
		printf("STUDENT LIST IS EMPTY!\n");
		return;
	}

	while(current != NULL) /*loops to the the last node in the linked list*/
	{
		if(current -> data.id == id)  /*if id was found update student information*/
		{
			printf("-------------------------------------------------------------\n");
			printf("Enter new details for student with ID %d\n",id);
			printf("New Name: ");
			scanf("%s",current -> data.name);
			printf("New Age: ");
			scanf("%d",&current -> data.age);
			printf("New GPA: ");
			scanf("%f",&current -> data.gpa);
			printf("Student details updated successfully\n");

			return;
		}
		current = current -> next;
	}
	/*if id was NOT found in the list*/
	printf("-------------------------------------------------------------\n");
	printf("STUDENT NOT FOUND!\n");

}

/*This function calculates and returns the average GPA of all students.*/
float calculateAverageGPA(void)
{
	int Student_count = 0;     /*number of students*/
	float GPA_sum = 0;         /*sum of students' GPA*/
	float GPA_average = 0.0;   /*average of students' GPA*/

	current = head;

	if(head == NULL) /*if student list is empty return*/
	{
		printf("-------------------------------------------------------------\n");
		printf("STUDENT LIST IS EMPTY!\n");
		return 0.0;
	}

	while(current != NULL) /*loops to the the last node in the linked list*/
	{
		GPA_sum += current -> data.gpa;
		Student_count++;

		current = current -> next;
	}

	GPA_average = (float)GPA_sum/Student_count;

	printf("-------------------------------------------------------------\n");
	printf("Average GPA Of Students = %.2f\n",GPA_average);

	return GPA_average;
}

/*This function finds and displays the student with the highest GPA.*/
void searchHighestGPA(void)
{
	struct node *highest_GPA = NULL; /*pointer that saves the node with the highest GPA*/

	highest_GPA = head;       /*assume head node has the highest GPA*/
	current = head -> next;   /*current points to the second node*/


	if(head == NULL) /*if student list is empty return*/
	{
		printf("-------------------------------------------------------------\n");
		printf("STUDENT LIST IS EMPTY!\n");
		return;
	}

	while(current != NULL) /*loops to the the last node in the linked list*/
	{
		if(current -> data.gpa > highest_GPA -> data.gpa) /*if current node has GPA higher than the highest_gpa node, update it*/
		{
			highest_GPA  = current;
		}

		current = current -> next;
	}

	/*display the student with the highest GPA*/
	printf("-------------------------------------------------------------\n");
	printf("Student with highest GPA is:\n");
	printf("Student =>  ID: %d",highest_GPA -> data.id);
	printf("  Name: %s",highest_GPA -> data.name);
	printf("  Age: %d",highest_GPA -> data.age);
	printf("  GPA: %.2f",highest_GPA -> data.gpa);
	printf("\n");

}

/*This function deletes a student from the linked list by their ID.*/
void deleteStudent(int id)
{
	struct node *previous = NULL;    /*pointer that points to the node before current*/
	struct node *deleteNode = NULL;  /*pointer that points to the node that will be deleted*/

	previous = head;
	current = head -> next;

	if(head == NULL) /*if student list is empty return*/
	{
		printf("-------------------------------------------------------------\n");
		printf("STUDENT LIST IS EMPTY!\n");
		return;
	}

	while(current != NULL) /*loops to the the last node in the linked list*/
	{
		if(head -> data.id == id) /*if the head node is the required node to be deleted*/
		{
			deleteNode = head;
			head = head -> next;
			free(deleteNode);
			/*if the data was deleted*/
			printf("-------------------------------------------------------------\n");
			printf("Student with ID %d deleted successfully\n",id);
			return;
		}

		if(current -> data.id == id) /*if another node from the list is required to be deleted*/
		{
			deleteNode = current;
			previous -> next = current -> next;
			free(deleteNode);
			return;
		}
		previous = current;
		current = current -> next;
	}

	/*if the data was not found in the linked list*/
	if(deleteNode == NULL)
	{
		printf("-------------------------------------------------------------\n");
		printf("Student with ID %d was not found\n",id);
	}
}
