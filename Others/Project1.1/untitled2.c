#include <stdio.h>

// 定义学生结构体
typedef struct {
	char name[100];
	int id;
	float score[3];
} Student;

// 定义顺序表结构体
typedef struct {
	Student students[100];
	int size;
} SeqList;

// 初始化顺序表
void InitList(SeqList* list) {
	list->size = 0;
}

// 添加学生
void AddStudent(SeqList* list, Student student) {
	if (list->size < 100) {
		list->students[list->size] = student;
		list->size++;
	}
}

// 删除学生
void DeleteStudent(SeqList* list, int id) {
	for (int i = 0; i < list->size; i++) {
		if (list->students[i].id == id) {
			for (int j = i; j < list->size - 1; j++) {
				list->students[j] = list->students[j + 1];
			}
			list->size--;
			break;
		}
	}
}

// 查找学生
Student* FindStudent(SeqList* list, int id) {
	for (int i = 0; i < list->size; i++) {
		if (list->students[i].id == id) {
			return &list->students[i];
		}
	}
	return NULL;
}

// 打印所有学生信息
void PrintAllStudents(SeqList* list) {
	for (int i = 0; i < list->size; i++) {
		printf("Name: %s, ID: %d, Scores: %.2f, %.2f, %.2f\n", list->students[i].name, list->students[i].id, list->students[i].score[0], list->students[i].score[1], list->students[i].score[2]);
	}
}
