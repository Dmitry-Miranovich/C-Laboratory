#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <stdio.h>

typedef struct Person_ {
	int age;
	int height;
	int mobileTelephone;
}Person;
void write(char*, Person[], int);
void writeF3(char*);
void WriteObjectsToTheThirdFile(char*, char*, char*, int, int);
void WriteObjectIntoAFile(FILE*, Person*);
Person* WriteObjectFromAFile(FILE*, char*, long);
void ReadFile3(int, int);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person FirstArrayOfPersons[] = { 21, 186, 2975803, 19, 190, 1998003};
	Person SecondArrayOfPersons[] = { 15, 175, 1998001, 21, 180, 1998002 };
	write("D:\\laboratory5\\F1.dat", &FirstArrayOfPersons, 2);
	write("D:\\laboratory5\\F2.dat", &SecondArrayOfPersons, 2);
	writeF3("D:\\laboratory5\\F3.dat");
	WriteObjectsToTheThirdFile("D:\\laboratory5\\F1.dat", "D:\\laboratory5\\F2.dat","D:\\laboratory5\\F3.dat" ,2,2);
	ReadFile3(2, 2);
	return 0;
}
void WriteObjectsToTheThirdFile(char* fileName1, char* fileName2,char* fileName3, int SizeOfArray1, int SizeOfArray2) {
	FILE* file1;
	FILE* file2;
	FILE* file3;
	char* c1;
	int size = sizeof(Person);
	Person* person = (Person*)malloc(size);
	if ((file1 = fopen(fileName1, "rb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	if ((file2 = fopen(fileName2, "rb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	if ((file3 = fopen(fileName3, "wb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	int iteratorForFile1 = 0,iteratorForFile2 = 0;
	int i = 0;
	while (i < SizeOfArray1 + SizeOfArray2) {
		if (iteratorForFile1 < SizeOfArray1) {
			Person* person = WriteObjectFromAFile(file1, fileName1, iteratorForFile1 * sizeof(Person));
			WriteObjectIntoAFile(file3,person);
			iteratorForFile1++;
			i++;
			free(person);
		}
		if (iteratorForFile2 < SizeOfArray2) {
			Person* person = WriteObjectFromAFile(file1, fileName2, iteratorForFile2 * sizeof(Person));
			WriteObjectIntoAFile(file3,person);
			iteratorForFile2++;
			i++;
			free(person);
		}
	}
	fclose(file3);
	fclose(file2);
	fclose(file1);
}

void write(char* filename, Person person[], int ArraySize) {
	FILE* file;
	char* array;
	int size = sizeof(Person);
	if ((file = fopen(filename, "wb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	for (int i = 0; i < ArraySize; i++) {
		array = (char*)&person[i];
		for (int i = 0; i < size; i++) {
			fputc(*array++, file);
		}
	}
	fclose(file);
}
void WriteObjectIntoAFile(FILE* file, Person* person) {
	char* array;
	array = (char*)person;
	for (int i = 0; i < sizeof(Person); i++) {
		fputc(*array++, file);
	}
}
Person* WriteObjectFromAFile(FILE* file, char* filename, long offset) {
	if ((file = fopen(filename, "rb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	fseek(file, offset, SEEK_SET);
	Person* person = malloc(sizeof(Person));
	char* array = (char*)person;
	int byte;
	for (int i = 0; i < sizeof(Person); i++) {
		byte = fgetc(file);
		*array = byte;
		array++;
	}
	fclose(file);
	return person;
}
void writeF3(char*filename) {
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	fclose(file);
}
void ReadFile3(int SizeOfArray1, int SizeOfArray2) {
	FILE* file;
	char* name = "D:\\laboratory5\\F3.dat";
	if ((file = fopen(name, "rb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	printf("Человек %-7c Возраст %-7c Рост %-7c Телефон\n", ' ', ' ', ' ');
	for (int i = 0; i < SizeOfArray1 + SizeOfArray2; i++) {
		Person* person = malloc(sizeof(Person));
		person = WriteObjectFromAFile(file, name, i * sizeof(Person));
		printf("%4d %15d %14d %16d\n", i+1, person->age, person->height, person->mobileTelephone);
		free(person);
	}
	fclose(file);
}


