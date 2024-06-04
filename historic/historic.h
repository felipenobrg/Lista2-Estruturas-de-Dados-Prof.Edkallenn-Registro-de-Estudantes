#include "../student/student.h"

typedef struct history
{
    int size;
    struct HistoryNode *end;
} History;

typedef struct HistoryNode
{
    Student student;
    struct HistoryNode *prev;
} HistoryNode;

History *createHistory();
void addStudentToHistory(History *history, Student *student);
void displayHistory(History *history, char subject[]);
