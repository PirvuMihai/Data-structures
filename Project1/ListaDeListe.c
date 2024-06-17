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
//}nodLS;
//
//typedef struct {
//	struct nodLS* stud;
//	struct nodLP* next;
//}nodLP;
//
//void inserareLS(nodLS** cap, student s) {
//	nodLS* nou = (nodLS*)malloc(sizeof(nodLS));
//	nou->stud.ID = s.ID;
//	nou->stud.nume = (char*)malloc(strlen(s.nume)+1);
//	strcpy(nou->stud.nume, s.nume);
//	nou->stud.nota = s.nota;
//	nou->next = NULL;
//	if (*cap == NULL) {
//		*cap = nou;
//	}
//	else {
//		nodLS* temp = *cap;
//		while (temp->next != NULL) {
//			temp = temp->next;
//		}
//		temp->next = nou; 
//	}
//}
//
//void inserareLP(nodLS* capLS, nodLP** capLP) {
//	nodLP* nou = (nodLP*)malloc(sizeof(nodLP));
//	nou->stud= capLS;
//	nou->next = NULL;
//	if (*capLP == NULL) {
//		*capLP = nou;
//	}
//	else {
//		nodLP* temp = *capLP;
//		while (temp->next != NULL)
//			temp = temp->next;
//		temp->next = nou;
//	}
//}
//
//void traversareLS(nodLS* cap) {
//	nodLS* temp = cap;
//	while (temp != NULL) {
//		printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", temp->stud.ID, temp->stud.nume, temp->stud.nota);
//		temp = temp->next;
//	}
//}
//
//void traversareLP(nodLP* cap) {
//	int i = 0;
//	nodLP* temp = cap;
//	while (temp != NULL) {
//		printf("Sublista cu numarul %d contine:", i);
//		traversareLS(temp->stud);
//		temp = temp->next;
//	}
//}
//
//void dezalocareLS(nodLS* cap) {
//	nodLS* temp = cap;
//	while (temp != NULL) {
//		nodLS* aux = temp->next;
//		free(temp->stud.nume);
//		free(temp);
//		temp = aux;
//	}
//}
//
//void dezalocareLP(nodLP* cap) {
//	nodLP* temp = cap;
//	while (temp != NULL) {
//		nodLP* aux = temp->next;
//		dezalocareLS(temp);
//		temp = aux;
//	}
//}
//
//void main() {
//	student s;
//	char buffer[20];
//	nodLS* capLS1 = NULL;
//	nodLS* capLS2 = NULL;
//	nodLS* capLP = NULL;
//	FILE* f = fopen("Text.txt", "r");
//	int nrStud;
//	fscanf(f, "%d", &nrStud);
//	for (int i = 0; i < nrStud; i++) {
//		fscanf(f, "%d", &s.ID);
//		fscanf(f, "%s", buffer);
//		s.nume = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//		strcpy(s.nume, buffer);
//		fscanf(f, "%d", &s.nota);
//		if (s.nota > 5)
//			inserareLS(&capLS1, s);
//		else
//			inserareLS(&capLS2, s);
//		free(s.nume);
//	}
//	inserareLP(capLS1, &capLP);
//	inserareLP(capLS2, &capLP);
//	traversareLS(capLS1);
//	fclose(f);
//}