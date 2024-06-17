//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//
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
//}nodLS;
//
//nodLS* inserare(nodLS* cap, student s) {
//	nodLS* nou = (nodLS*)malloc(sizeof(nodLS));
//	nou->stud.ID = s.ID;
//	nou->stud.nume = (char*)malloc(strlen(s.nume)+1);
//	strcpy(nou->stud.nume, s.nume);
//	nou->stud.nota = s.nota;
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		cap = nou;
//	}
//	else {
//		nodLS* temp = cap;
//		while (temp->next != NULL) {
//			temp = temp->next;
//		}
//		temp->next = nou;
//	}
//	return cap;
//}
//
//nodLS* afisare(nodLS* cap) {
//	nodLS* temp = cap;
//	while (temp != NULL) {
//		printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", temp->stud.ID, temp->stud.nume, temp->stud.nota);
//		temp = temp->next;
//	}
//}
//
//void dezalocare(nodLS* cap) {
//	nodLS* temp = cap;
//	while (temp!=NULL && temp->next != NULL) {
//		nodLS* copie = temp->next;
//		free(temp->stud.nume);
//		free(temp);
//		temp = copie;
//	}
//}
//
//student* stocareInVector(nodLS* cap, student* s) {
//	int nrElem = 0;
//	nodLS* temp = cap;
//	while (temp != NULL) {
//		s[nrElem].ID = temp->stud.ID;
//		s[nrElem].nume = (char*)malloc(strlen(temp->stud.nume) + 1);
//		strcpy(s[nrElem].nume, temp->stud.nume);
//		s[nrElem].nota = temp->stud.nota;
//		nrElem++;
//		temp = temp->next;
//	}
//	return s;
//}
//
//void main() {
//	nodLS* cap = NULL;
//	int nrStud;
//	student s;
//	char buffer[20];
//	FILE* f = fopen("Text.txt", "r");
//	fscanf(f, "%d", &nrStud);
//	for (int i = 0; i < nrStud; i++) {
//		fscanf(f, "%d", &s.ID);
//		fscanf(f, "%s", buffer);
//		s.nume = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//		strcpy(s.nume, buffer);
//		fscanf(f, "%d", &s.nota);
//		cap = inserare(cap, s);
//	}
//	afisare(cap);
//	fclose(f);
//
//	student* stud = (student*)malloc(sizeof(student) * nrStud);
//	stud = stocareInVector(cap, stud);
//	for (int i = 0; i < nrStud; i++) {
//		printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", stud[i].ID, stud[i].nume, stud[i].nota);
//	}
//
//
//	dezalocare(cap);
//}