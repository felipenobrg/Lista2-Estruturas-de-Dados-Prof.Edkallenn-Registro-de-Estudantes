/*
** Função: Sistema de Registro de Estudantes
** Autor: Felipe Nóbrega de Almeida
** Data: 04/06/2024
** Observações:
*/

#include <locale.h>
#include "history/history.h"
#include "enrollment/enrollment.h"
#include "student/student.h"

void menu();
void menuStudents();
void menuEnrollments();
void enrollStudent(EnrollmentQueue *enrollmentQueue);
void displayStudentAverages(StudentList *studentList);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    History *history = createHistory();
    EnrollmentQueue *enrollmentQueue = createEnrollmentQueue();
    StudentList *studentList = createStudentList();

    int option;
    do
    {
        menu();
        printf("Opção: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option)
        {
        case 1:
            do
            {
                int registration;
                menuStudents();
                printf("Opção: ");
                scanf("%d", &option);
                fflush(stdin);
                switch (option)
                {
                case 1:
                    displayStudentList(studentList);
                    break;
                case 2:
                    printf("Informe a matrícula do estudante:\n");
                    printf("Matrícula: ");
                    scanf("%d", &registration);
                    fflush(stdin);
                    removeStudentFromList(studentList, registration);
                    break;
                case 3:
                    printf("Informe a matrícula do estudante:\n");
                    printf("Matrícula: ");
                    scanf("%d", &registration);
                    fflush(stdin);
                    Student *student1 = searchStudentInList(studentList, registration);
                    if (student1 == NULL)
                    {
                        free(student1);
                        break;
                    }
                    printf("\n");
                    printf("Nome: %s\n", student1->name);
                    printf("Disciplina: %s\n", student1->subject);
                    printf("Nota 1: %.2f\n", student1->grades[0]);
                    printf("Nota 2: %.2f\n", student1->grades[1]);
                    printf("Nota 3: %.2f\n", student1->grades[2]);
                    printf("\n");

                    break;
                case 4:
                    printf("Informe a matrícula do estudante:\n");
                    printf("Matrícula: ");
                    scanf("%d", &registration);
                    fflush(stdin);
                    Student *student = searchStudentInList(studentList, registration);
                    if (student == NULL)
                    {
                        free(student);
                        break;
                    }

                    float grades[3];
                    printf("Informe as novas notas:\n");
                    for (int i = 0; i < 3; i++)
                    {
                        printf("Nota %d: ", i + 1);
                        scanf("%f", &grades[i]);
                        fflush(stdin);
                    }
                    addStudentToHistory(history, student);
                    updateStudentGrades(student, grades);
                    break;
                case 5:
                    displayStudentAverages(studentList);
                    break;
                case 6:
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
                }
                if (option == 6)
                {
                    break;
                }
            } while (1);
            break;
        case 2:
            do
            {
                menuEnrollments();
                printf("Opção: ");
                scanf("%d", &option);
                fflush(stdin);
                switch (option)
                {
                case 1:
                    displayEnrollmentQueue(enrollmentQueue);
                    break;
                case 2:
                    enrollStudent(enrollmentQueue);
                    break;
                case 3:
                    removeStudentFromQueue(enrollmentQueue, studentList);
                    break;
                case 4:
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
                }
                if (option == 4)
                {
                    break;
                }
            } while (1);
            break;
        case 3:;
            char subject[20];
            printf("Informe a disciplina: ");
            scanf("%s", subject);
            displayHistory(history, subject);
            break;
        case 4:
            return 0;
        case 5:
            return 0;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (1);

    return 0;
}

void menu()
{
    printf("\n");
    printf("1 - Estudantes\n");
    printf("2 - Matrículas\n");
    printf("3 - Histórico\n");
    printf("4 - Mais opções\n");
    printf("5 - Sair\n");
    printf("\n");
}

void menuStudents()
{
    printf("\n");
    printf("1 - Exibir estudantes\n");
    printf("2 - Remover estudante\n");
    printf("3 - Buscar estudante\n");
    printf("4 - Atualizar notas\n");
    printf("5 - Relatório de médias\n");
    printf("6 - Voltar\n");
    printf("\n");
}

void menuEnrollments()
{
    printf("\n");
    printf("1 - Exibir fila de matrícula\n");
    printf("2 - Matricular estudante\n");
    printf("3 - Andar fila de matrícula\n");
    printf("4 - Voltar\n");
    printf("\n");
}

void enrollStudent(EnrollmentQueue *enrollmentQueue)
{
    char name[50], subject[20];
    float grades[3];
    printf("Nome: ");
    scanf("%s", name);
    fflush(stdin);
    printf("Disciplina: ");
    scanf("%s", subject);
    fflush(stdin);
    printf("Nota 1: ");
    scanf("%f", &grades[0]);
    fflush(stdin);
    printf("Nota 2: ");
    scanf("%f", &grades[1]);
    fflush(stdin);
    printf("Nota 3: ");
    scanf("%f", &grades[2]);
    fflush(stdin);
    Student student = registerStudent(name, subject, grades);
    insertStudentIntoQueue(enrollmentQueue, student);
}

void displayStudentAverages(StudentList *studentList)
{
    printf("\n");
    printf("------ Médias dos estudantes ------\n");
    printf("\n");
    calculateStudentAverages(studentList);
    printf("\n");
}