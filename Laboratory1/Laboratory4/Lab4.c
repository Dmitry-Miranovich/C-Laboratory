#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
void WriteAnIdentityOfEmployer(int, char*, int);
struct MyStruct
{
	char* Identity;
	int UniqueNumber;
	int AmountOfWorkedHours;
	int MoneyPerHour;
} Employers[5];
typedef struct MyStruct_
{
	char* Identity;
	int UniqueNumber;
	int AmountOfWorkedHours;
	int MoneyPerHour;
};
void TableOfSalaries(struct MyStruct[], int);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int MassiveOfSizes[5] = { 31, 26, 33, 22, 25 };
	//��������� ������� ������������ 31
	Employers[0].Identity = (char*)malloc(MassiveOfSizes[0]);
	//������� ������ ���������� 26
	Employers[1].Identity = (char*)malloc(MassiveOfSizes[1]);
	//����������� ����� �������������� 33
	Employers[2].Identity = (char*)malloc(MassiveOfSizes[2]);
	//�������� ��� �������� 22
	Employers[3].Identity = (char*)malloc(MassiveOfSizes[3]);
	//���������� ����� ������� 25
	Employers[4].Identity = (char*)malloc(MassiveOfSizes[4]);
	for (int i = 0; i < 5; i++) {
		WriteAnIdentityOfEmployer(i, Employers[i].Identity, MassiveOfSizes[i]);
	}
	for (int i = 0; i < 5; i++) 
		Employers[i].UniqueNumber = i+1;	
	for (int i = 0; i < 5; i++) 
		Employers[i].AmountOfWorkedHours = rand() % 100 + 1;
	for (int i = 0; i < 5; i++) 
		Employers[i].MoneyPerHour = rand() % 1000 + 1;;
	TableOfSalaries(Employers, 5);
	return 0;
}	
void WriteAnIdentityOfEmployer(int NumberOfName, char* Identity, int size) {
	char Name1[31] = "��������� ������� ������������";
	char Name2[26] = "A������ ������ ����������";
	char Name3[33] = "����������� ����� ��������������";
	char Name4[22] = "�������� ��� ��������";
	char Name5[25] = "���������� ����� �������";
	switch (NumberOfName) {
	case 0:
		for (int i = 0; i < size; i++)
			Identity[i] = Name1[i];
		break;

	case 1:
		for (int i = 0; i < size; i++)
			Identity[i] = Name2[i];
		break;

	case 2:
		for (int i = 0; i < size; i++)
			Identity[i] = Name3[i];
		break;

	case 3:
		for (int i = 0; i < size; i++)
			Identity[i] = Name4[i];
		break;
	
	case 4:
		for (int i = 0; i < size; i++)
			Identity[i] = Name5[i];
	}
}
void TableOfSalaries(struct MyStruct t[], int size) {
	int MassiveOfSizes[5] = { 31, 26, 33, 22, 25 };
	printf("������� ������� �� �����\n\n");
	printf("ID ����� %-8c ��� %-30c ��������\n", ' ', ' ');
	for (int i = 0; i < size; i++) {
		printf("%-16d", t[i].UniqueNumber);
		for (int j = 0; j < MassiveOfSizes[i]; j++) {
			printf("%c", t[i].Identity[j]);
		}
		for (int k = 0; k < 39 - MassiveOfSizes[i]; k++) {
			printf("%c", ' ');
		}
		printf("%d", t[i].AmountOfWorkedHours * t[i].MoneyPerHour);
		puts("\n");
	}
}