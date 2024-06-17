#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	int ID;
	char* nume;
	int nota;
}student;

typedef struct {
	student** stud;
	int nrElem;
}hashT;

int functieHash(hashT tabela, int cheie) {
	return cheie % tabela.nrElem;
}

void inserareHash(hashT tabela, student* s) {
	int poz = functieHash(tabela, s->ID);
	if (tabela.stud[poz] == NULL)
		tabela.stud[poz] = s;
	else {
		int index = 1;
		while (poz + index < tabela.nrElem) {
			if (tabela.stud[poz + index] == NULL) {
				tabela.stud[poz + index] = s;
				poz = poz + index;
				break;
			}
			else {
				index++;
			}
		}
	}
}

void traversareHash(hashT tabela) {
	for (int i = 0; i < tabela.nrElem; i++) {
		if (tabela.stud[i] != NULL) {
			printf("Pozitia %d\n", i);
			printf("Studentul %s are ID-ul %d si nota %d\n", tabela.stud[i]->nume, tabela.stud[i]->ID, tabela.stud[i]->nota);
		}
	}
}

void dezalocareHash(hashT tabela) {
	for (int i = 0; i < tabela.nrElem; i++) {
		if (tabela.stud[i] != NULL) {
			free(tabela.stud[i]->nume);
			free(tabela.stud[i]);
		}
	}
	free(tabela.stud);
}

void main() {
	hashT tabela;
	tabela.nrElem = 35;
	tabela.stud = (student**)malloc(sizeof(student*) * tabela.nrElem);
	for (int i = 0; i < tabela.nrElem; i++) {
		tabela.stud[i] = NULL;
	}
	int nrStud;
	student* s;
	char buffer[20];
	FILE* f = fopen("Text.txt", "r");
	fscanf(f, "%d", &nrStud);
	for (int i = 0; i < nrStud; i++) {
		s = (student*)malloc(sizeof(student));
		fscanf(f, "%d", &s->ID);
		fscanf(f, "%s", buffer);
		s->nume = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(s->nume, buffer);
		fscanf(f, "%d", &s->nota);
		inserareHash(tabela, s);
		}
	traversareHash(tabela);
	dezalocareHash(tabela);
}