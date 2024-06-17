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
//	struct nodCoada* next;
//}nodCoada;
//
//typedef struct {
//	student stud;
//	struct nodStiva* next;
//}nodStiva;
//
//
//void push(nodStiva** cap, student s) {
//	nodStiva* nou = (nodStiva*)malloc(sizeof(nodStiva));
//	nou->stud.ID = s.ID;
//	nou->stud.nume = (char*)malloc(strlen(s.nume)+1);
//	strcpy(nou->stud.nume, s.nume);
//	nou->stud.nota = s.nota;
//	nou->next = NULL;
//	if (*cap == NULL) {
//		*cap = nou;
//	}
//	else {
//		nou->next = *cap;
//		*cap = nou;
//	}
//}
//
//void pop(nodStiva** cap, student* s) {
//	if (*cap != NULL) {
//		(*s).ID = (*cap)->stud.ID;
//		(*s).nume = (char*)malloc(strlen((*cap)->stud.nume) + 1);
//		strcpy((*s).nume, (*cap)->stud.nume);
//		(*s).nota = (*cap)->stud.nota;
//		nodStiva* temp = *cap;
//		*cap = (*cap)->next;
//		free(temp->stud.nume);
//		free(temp);
//	}
//}
//
//void afisareStiva(nodStiva* cap) {
//	nodStiva* temp = cap;
//	while (temp != NULL) {
//		printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", temp->stud.ID, temp->stud.nume, temp->stud.nota);
//		temp = temp->next;
//	}
//}
//
//void put(nodCoada** prim, nodCoada** ultim, student s) {
//	nodCoada* nou = (nodCoada*)malloc(sizeof(nodCoada));
//	nou->stud.ID = s.ID;
//	nou->stud.nume = (char*)malloc(strlen(s.nume) + 1);
//	strcpy(nou->stud.nume, s.nume);
//	nou->stud.nota = s.nota;
//	nou->next = NULL;
//	if (*prim == NULL || *ultim == NULL) {
//		*prim = nou;
//		*ultim = nou;
//	}
//	else {
//		(*ultim)->next = nou;
//		*ultim = nou;
//	}
//}
//
//void get(nodCoada** prim, nodCoada** ultim, student* s) {
//	if (*prim != NULL && *ultim != NULL) {
//		(*s).ID = (*prim)->stud.ID;
//		(*s).nume = (char*)malloc(strlen((*prim)->stud.nume) + 1);
//		strcpy((*s).nume, (*prim)->stud.nume);
//		(*s).nota = (*prim)->stud.nota;
//		nodCoada* temp = *prim;
//		(*prim) = (*prim)->next;
//		free(temp->stud.nume);
//		free(temp);
//	}
//}
//
//void afisareCoada(nodCoada* prim) {
//	nodCoada* temp = prim;
//	while (temp != NULL) {
//		printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", temp->stud.ID, temp->stud.nume, temp->stud.nota);
//		temp = temp->next;
//	}
//}
//
//void main() {
//	char buffer[20];
//	int nrElem;
//	student s;
//	nodStiva** cap = NULL;
//	nodCoada** prim = NULL;
//	nodCoada** ultim = NULL;
//	FILE* f = fopen("Text.txt", "r");
//	fscanf(f, "%d", &nrElem);
//	for (int i = 0; i < nrElem; i++) {
//		fscanf(f, "%d", &s.ID);
//		fscanf(f, "%s", buffer);
//		s.nume = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//		strcpy(s.nume, buffer);
//		fscanf(f, "%d", &s.nota);
//		push(&cap, s);
//		put(&prim, &ultim, s);
//	}
//	afisareStiva(cap);
//	printf("---------------------------------\n");
//	student s1;
//	pop(&cap, &s1);
//	printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", s1.ID, s1.nume, s1.nota);
//	printf("---------------------------------\n");
//	printf("---------------------------------\n");
//	afisareCoada(prim);
//	get(&prim, &ultim, &s1);
//	printf("---------------------------------\n");
//	printf("Studentul cu ID-ul %d pe nume %s are nota %d\n", s1.ID, s1.nume, s1.nota);
//}