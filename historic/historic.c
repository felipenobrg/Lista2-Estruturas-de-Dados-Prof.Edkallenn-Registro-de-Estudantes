#include "history.h"

History *createHistory()
{
    History *history = (History *)malloc(sizeof(History));
    history->size = 0;
    history->end = NULL;
    return history;
}

void addStudentToHistory(History *history, Student *student)
{
    HistoryNode *newNode = (HistoryNode *)malloc(sizeof(HistoryNode));
    newNode->student = *student;
    newNode->prev = history->end;
    history->end = newNode;
    history->size++;
}

void displayHistory(History *history, char subject[])
{
    HistoryNode *current = history->end;
    printf("------ Disciplina: %s ------\n", subject);
    while (current != NULL)
    {
        printf("\n");
        printf("Nome: %s\n", current->student.name);
        printf("Matricula: %d\n", current->student.registration);
        printf("Nota - 1: %.2f\n", current->student.grades[0]);
        printf("Nota - 2: %.2f\n", current->student.grades[1]);
        printf("Nota - 3: %.2f\n", current->student.grades[2]);
        printf("\n");
        current = current->prev;
    }
    printf("-----------------------------\n");
}
