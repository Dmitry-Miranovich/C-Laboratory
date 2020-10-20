#include <Windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char phrase[20] = "Какой чудесный день";
	char NewPhrase[20];
	for (int i = 0; i < 20; i++) {
		NewPhrase[i] = ' ';
	}
	int IndexBeforeUpper = 0;
	int j = 0;
	for (int i = 19; i >= 0; i--) {
		if (phrase[i] == ' ' || i == 0) {
			if (i == 0) {
				for (j = i; j < 19 && phrase[j] != ' '; j++) {
					NewPhrase[IndexBeforeUpper++] = phrase[j];
				}
				break;
			}
			for (j = i + 1; j < 19 && phrase[j] != ' '; j++) {
				NewPhrase[IndexBeforeUpper++] = phrase[j];
			}
			NewPhrase[++IndexBeforeUpper] = ' ';
			printf("Текущий пробел : %d\n", i);
		}

	}
	for (int i = 0; i < 20; i++) {
		printf("%c", NewPhrase[i]);
	}

}
