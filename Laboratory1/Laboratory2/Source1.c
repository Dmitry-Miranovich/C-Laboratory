#include <Windows.h>
#include <math.h>
#include <stdio.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//������� �����
	int matrix[4][4] = { {1,-2,-5,-1},{4,7,2,1},{-1,-6,-12,-5}, {-3,-4,0,9} };
	puts("��������� �������:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			printf("%3d ", matrix[i][j]);
		printf("\n");
	}
	//������ ���������� ������������� �����
	int masOfOnes[4];
	//����������� �� ������ ����� ������������� �����
	for (int i = 0; i < 4; i++) {
		int ones = 0;
		for (int j = 0; j < 4; j++) 
			//���� ������� ������� ������ ����
			if (matrix[i][j] < 0) 
				ones++;
		masOfOnes[i] = ones;
	}
	int temp = masOfOnes[0], temp2 = masOfOnes[0];
	//������ � �������� ����� �� ������� �����
	int tempMas[2];
	//����� ����� � �������� ������������� � ������������� ���������
	for (int i = 0; i < 4; i++) {
		if (temp2 >= masOfOnes[i]) {
			temp2 = masOfOnes[i];
			tempMas[0] = i;
		}
		if (temp <= masOfOnes[i]) {
			temp = masOfOnes[i];
			tempMas[1] = i;
		}
		
	}
	int newMatrix[2][4];
	int k = 0;
	puts("���������� �������: \n");
	for (int i = 0; i < 4; i++) {
		if ((i != tempMas[0]) || (i != tempMas[1])) {
			for (int j = 0; j < 4; j++) {
				newMatrix[k][j] = matrix[i][j];
				printf("%3d ", newMatrix[k][j]);
			}
			k++;
			puts("\n");
		}
	}
	return 0;
}