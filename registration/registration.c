#include "enrollment.h"

EnrollmentQueue *createEnrollmentQueue()
{
    EnrollmentQueue *queue = (EnrollmentQueue *)malloc(sizeof(EnrollmentQueue));
    queue->size = 0;
    queue->start = NULL;
    queue->end = NULL;
    return queue;
}

void insertStudentIntoQueue(EnrollmentQueue *queue, Student student)
{
    SubjectNode *newNode = (SubjectNode *)malloc(sizeof(SubjectNode));
    newNode->student = student;
    newNode->next = NULL;
    newNode->prev = queue->end;
    if (queue->end != NULL)
    {
        queue->end->next = newNode;
    }
    queue->end = newNode;
    if (queue->start == NULL)
    {
        queue->start = newNode;
    }
    queue->size++;
}

void removeStudentFromQueue(EnrollmentQueue *queue, StudentList *list)
{
    if (queue->size == 0)
    {
        printf("Fila vazia!\n");
        return;
    }
    SubjectNode *removed = queue->start;
    queue->start = removed->next;
    if (queue->start != NULL)
    {
        queue->start->prev = NULL;
    }
    if (removed == queue->end)
    {
        queue->end = NULL;
    }
    insertStudentToList(list, removed->student);
    free(removed);
    queue->size--;
}

void displayEnrollmentQueue(EnrollmentQueue *queue)
{
    if (queue->size == 0)
    {
        printf("\n");
        printf("Fila de matrícula vazia!\n");
        return;
    }
    int i = 0;
    SubjectNode *current = queue->start;
    while (current != NULL)
    {
        printf("\n");
        printf("------ Estudante %d ------\n", ++i);
        printf("Matrícula: %d\n", current->student.registration);
        printf("Nome: %s\n", current->student.name);
        printf("Disciplina: %s\n", current->student.subject);
        printf("Notas: %.2f, %.2f, %.2f\n", current->student.grades[0], current->student.grades[1], current->student.grades[2]);
        printf("--------------------------\n");
        current = current->next;
    }
}
