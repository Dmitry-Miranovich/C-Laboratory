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
void write(char*, Person*);
void writeF3(char*);
void read(char*, char*, int, int);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person ArrayOfPerson[] = { 21, 186, 2975803, 19, 190, 1998003, 15, 175, 1998001, 21, 180, 1998002 };
	write("D:\\laboratory5\\F1.dat", &ArrayOfPerson[0]);
	write("D:\\laboratory5\\F1.dat", &ArrayOfPerson[1]);
	//write("D:\\laboratory5\\F2.dat", &ArrayOfPerson[2]);
	//write("D:\\laboratory5\\F2.dat", &ArrayOfPerson[3]);
	//writeF3("D:\\laboratory5\\F3.dat");
	read("D:\\laboratory5\\F1.dat", "D:\\laboratory5\\F2.dat",2,2);
	
	return 0;
}
void read(char* fileName1, char* fileName2, int FileSize1, int FileSize2) {
	FILE* file1;
	char* c1;
	int size = sizeof(Person);
	Person* person = (Person*)malloc(size);
	if ((file1 = fopen(fileName1, "rb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	c1 = (char*)person;
	int i = 0;
	int byte;
	while (i<size) {
		byte = fgetc(file1);
		*c1 = byte;
		c1++;
		i++;
	}
	
	fclose(file1);
	printf("%d", person->mobileTelephone);
}

void write(char* filename, Person* person) {
	FILE* file;
	printf("%d", sizeof(file));
	char* array;
	int size = sizeof(Person);
	if ((file = fopen(filename, "wb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	array = (char*)person;
	for (int i = 0; i < size; i++) {
		fputc(*array++, file);
	}
	fclose(file);
}void writeF3(char*filename) {
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) {
		perror("Error occured while opening this file");
		exit(0);
	}
	fclose(file);
}


