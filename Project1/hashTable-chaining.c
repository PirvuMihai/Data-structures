#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	int ID;
	char* nume;
	int nota;
}student;

typedef struct {
	student stud;
	struct nodLS* next;
}nodLS;

typedef struct {
	struct nodLS** vect;
	int nrElem;
}hashT;

int functieHash(int cheie, hashT tabela) {
	return cheie % tabela.nrElem;
}

void inserareLS(nodLS** cap, student s) {
	nodLS* nou = (nodLS*)malloc(sizeof(nodLS));
	nou->stud.ID = s.ID;
	nou->stud.nume = (char*)malloc(strlen(s.nume)+1);
	strcpy(nou->stud.nume, s.nume);
	nou->stud.nota = s.nota;
	nou->next = NULL;
	if (*cap == NULL) {
		*cap = nou;
	}
	else {
		nodLS* temp = *cap;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = nou;
	}
}

void inserareHash(hashT tabela, student s) {
	int poz = functieHash(s.ID, tabela);
	inserareLS(&tabela.vect[poz], s);
}

void traversareLS(nodLS* cap) {
	nodLS* temp = cap;
	while (temp != NULL) {
		printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", temp->stud.ID, temp->stud.nume, temp->stud.nota);
		temp = temp->next;
	}
}

void traversareHash(hashT tabela) {
	for (int i = 0; i < tabela.nrElem; i++) {
		if (tabela.vect[i] != NULL) {
			printf("Pozitia = %d", i);
			traversareLS(tabela.vect[i]);
		}
	}
}

void dezalocareLS(nodLS* nod) {
	nodLS* temp = nod;
	while (temp != NULL) {
		nodLS* temp2 = temp->next;
		free(temp->stud.nume);
		free(temp);
		temp = temp2;
	}
}
void dezalocareHash(hashT tabela) {
	for (int i = 0; i < tabela.nrElem; i++) {
		if (tabela.vect[i] != NULL) {
			dezalocareLS(tabela.vect[i]);
		}
	}
	free(tabela.vect);
}

void main() {
	hashT tabela;
	tabela.nrElem = 25;
	tabela.vect = (nodLS**)malloc(sizeof(nodLS*) * tabela.nrElem);
	for (int i = 0; i < 25; i++)
		tabela.vect[i] = NULL;
	nodLS* cap = NULL;
	int nrStud;
	student s;
	char buffer[20];
	FILE* f = fopen("Text.txt", "r");
	fscanf(f, "%d", &nrStud);
	for (int i = 0; i < nrStud; i++) {
		fscanf(f, "%d", &s.ID);
		fscanf(f, "%s", buffer);
		s.nume = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(s.nume, buffer);
		fscanf(f, "%d", &s.nota);
		inserareHash(tabela, s);
		free(s.nume);
	}
	fclose(f);

	traversareHash(tabela);
	dezalocareHash(tabela);
}