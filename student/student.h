#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Student
{
    int registration;
    char name[50];
    char subject[20];
    float grades[3];
} Student;

typedef struct StudentList
{
    int size;
    struct StudentNode *start;
    struct StudentNode *end;
} StudentList;

typedef struct StudentNode
{
    Student student;
    struct StudentNode *next;
    struct StudentNode *prev;
} StudentNode;

Student registerStudent(char name[], char subject[], float grades[]);
StudentList *createStudentList();
void insertStudentToList(StudentList *list, Student student);
void removeStudentFromList(StudentList *list, int registration);
void displayStudentList(StudentList *list);
Student *searchStudentInList(StudentList *list, int registration);
void updateStudentGrades(Student *student, float grades[]);
void calculateStudentAverages(StudentList *list);
void freeStudentList(StudentList *list);

#endif
