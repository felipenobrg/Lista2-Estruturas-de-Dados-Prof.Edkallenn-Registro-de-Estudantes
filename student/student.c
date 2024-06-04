#include "student.h"

Student registerStudent(char name[], char subject[], float grades[])
{
    Student student;
    srand(time(NULL));
    student.registration = (rand() % 1000) + 1000;
    strcpy(student.name, name);
    strcpy(student.subject, subject);
    for (int i = 0; i < 3; i++)
    {
        student.grades[i] = grades[i];
    }
    return student;
}

StudentList *createStudentList()
{
    StudentList *list = (StudentList *)malloc(sizeof(StudentList));
    list->size = 0;
    list->start = NULL;
    list->end = NULL;
    return list;
}

void insertStudentToList(StudentList *list, Student student)
{
    StudentNode *newNode = (StudentNode *)malloc(sizeof(StudentNode));
    newNode->student = student;
    newNode->next = NULL;
    newNode->prev = list->end;
    if (list->end != NULL)
    {
        list->end->next = newNode;
    }
    list->end = newNode;
    if (list->start == NULL)
    {
        list->start = newNode;
    }
    list->size++;
}

void removeStudentFromList(StudentList *list, int registration)
{
    StudentNode *current = list->start;
    while (current != NULL)
    {
        if (current->student.registration == registration)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                list->start = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            else
            {
                list->end = current->prev;
            }
            free(current);
            list->size--;
            return;
        }
        current = current->next;
    }
    printf("Student not found!\n");
}

void displayStudentList(StudentList *list)
{
    if (list->size == 0)
    {
        printf("\n");
        printf("Student list is empty!\n");
        return;
    }

    int i = 0;
    StudentNode *current = list->start;
    while (current != NULL)
    {
        printf("\n");
        printf("------ Student %d ------\n", ++i);
        printf("Registration: %d\n", current->student.registration);
        printf("Name: %s\n", current->student.name);
        printf("Subject: %s\n", current->student.subject);
        printf("Grades: %.2f, %.2f, %.2f\n", current->student.grades[0], current->student.grades[1], current->student.grades[2]);
        printf("-------------------------\n");
        current = current->next;
    }
}

Student *searchStudentInList(StudentList *list, int registration)
{
    StudentNode *current = list->start;
    while (current != NULL)
    {
        if (current->student.registration == registration)
        {
            return &current->student;
        }
        current = current->next;
    }
    printf("Student not found!\n");
    return NULL;
}

void updateStudentGrades(Student *student, float grades[])
{
    for (int i = 0; i < 3; i++)
    {
        student->grades[i] = grades[i];
    }
}

void calculateStudentAverages(StudentList *list)
{
    StudentNode *current = list->start;
    while (current != NULL)
    {
        float average = 0;
        for (int i = 0; i < 3; i++)
        {
            average += current->student.grades[i];
        }
        average /= 3;
        printf("Average for student %d: %.2f\n", current->student.registration, average);
        current = current->next;
    }
}

void freeStudentList(StudentList *list)
{
    StudentNode *current = list->start;
    while (current != NULL)
    {
        StudentNode *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
