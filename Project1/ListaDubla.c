//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//
//typedef struct {
//	int ID;
//	char* nume;
//	int nota;
//}student;
//
//typedef struct {
//	student stud;
//	struct nodLS* next;
//	struct nodLS* prev;
//}nodLS;
//
//nodLS* inserare(nodLS* cap, nodLS** coada, student s) {
//	nodLS* nou = (nodLS*)malloc(sizeof(nodLS));
//	nou->stud.ID = s.ID;
//	nou->stud.nume = (char*)malloc(strlen(s.nume)+1);
//	strcpy(nou->stud.nume, s.nume);
//	nou->stud.nota = s.nota;
//	nou->next = nou;
//	nou->prev = nou;
//	if (cap == NULL) {
//		cap = nou;
//		*coada = nou;
//	}
//	else {
//		nodLS* temp = cap;
//		while (temp->next != cap) {
//			temp = temp->next;
//		}
//		temp->next = nou;
//		nou->prev = temp;
//		*coada = nou;
//		(*coada)->next = cap;
//		cap->prev = *coada;
//	}
//	return cap;
//}
//
//void afisare(nodLS* cap) {
//	nodLS* temp = cap;
//	while (temp->next != cap) {
//		printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", temp->stud.ID, temp->stud.nume, temp->stud.nota);
//		temp = temp->next;
//	}
//	printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", temp->stud.ID, temp->stud.nume, temp->stud.nota);
//}
//
//void afisareInvers(nodLS* coada) {
//	nodLS* temp = coada;
//	while (temp->prev != coada) {
//		printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", temp->stud.ID, temp->stud.nume, temp->stud.nota);
//		temp = temp->prev;
//	}
//	printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", temp->stud.ID, temp->stud.nume, temp->stud.nota);
//}
//
//void dezalocare(nodLS* cap) {
//	nodLS* temp = cap;
//	while (temp->next != cap) {
//		nodLS* aux = temp->next;
//		free(temp->stud.nume);
//		free(temp);
//		temp = aux;
//	}
//	free(temp->stud.nume);
//	free(temp);
//}
//
//void main() {
//	char buffer[20];
//	nodLS* cap = NULL;
//	nodLS* *coada = NULL;
//	student s;
//	FILE* f = fopen("Text.txt", "r");
//	int nrElem;
//	fscanf(f, "%d", &nrElem);
//	for (int i = 0; i < nrElem; i++) {
//		fscanf(f, "%d", &s.ID);
//		fscanf(f, "%s", buffer);
//		s.nume = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//		strcpy(s.nume, buffer);
//		fscanf(f, "%d", &s.nota);
//		cap = inserare(cap, &coada, s);
//	}
//	fclose(f);
//	afisare(cap);
//	printf("\n-----------------------------------------------\n");
//	afisareInvers(coada);
//	dezalocare(cap);
//}