#include "../student/student.h"

#define SUBJECT1 "Mathematics"
#define SUBJECT2 "Portuguese"

typedef struct EnrollmentQueue
{
    int size;
    struct SubjectNode *start;
    struct SubjectNode *end;
} EnrollmentQueue;

typedef struct SubjectNode
{
    Student student;
    struct SubjectNode *next;
    struct SubjectNode *prev;
} SubjectNode;

EnrollmentQueue *createEnrollmentQueue();
void insertStudentIntoQueue(EnrollmentQueue *queue, Student student);
void removeStudentFromQueue(EnrollmentQueue *queue, StudentList *list);
void displayEnrollmentQueue(EnrollmentQueue *queue);
