#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int id;
    float score;
} Student;

typedef struct {
    Student students[MAX_SIZE];
    int size;
} StudentList;

void addStudent(StudentList* list, Student student) {
    if (list->size >= MAX_SIZE) {
        printf("The list is full.\n");
        return;
    }
    list->students[list->size++] = student;
}

void deleteStudent(StudentList* list, int id) {
    for (int i = 0; i < list->size; i++) {
        if (list->students[i].id == id) {
            for (int j = i; j < list->size - 1; j++) {
                list->students[j] = list->students[j + 1];
            }
            list->size--;
            return;
        }
    }
    printf("Student not found.\n");
}

Student* findStudent(StudentList* list, int id) {
    for (int i = 0; i < list->size; i++) {
        if (list->students[i].id == id) {
            return &list->students[i];
        }
    }
    return NULL;
}

void printStudents(StudentList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("Name: %s, ID: %d, Score: %.2f\n", list->students[i].name, list->students[i].id, list->students[i].score);
    }
}

int main() {
    StudentList list;
    list.size = 0;

    Student student1;
    strcpy(student1.name, "Alice");
    student1.id = 1;
    student1.score = 90.5;

    addStudent(&list, student1);

    Student* student = findStudent(&list, 1);
    if (student != NULL) {
        printf("Found student: %s\n", student->name);
    }

    printStudents(&list);

    deleteStudent(&list, 1);

    printStudents(&list);

    return 0;
}