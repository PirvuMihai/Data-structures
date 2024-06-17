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
//	student* stud;
//	int nrElem;
//}heap;
//
//void filtrare(heap h, int index) {
//	int indexRad = index;
//	int indexStg = 2 * index + 1;
//	int indexDrp = 2 * index + 2;
//	if (indexStg<h.nrElem && h.stud[indexStg].nota > h.stud[indexRad].nota)
//		indexRad = indexStg;
//	if (indexDrp<h.nrElem && h.stud[indexDrp].nota > h.stud[indexRad].nota)
//		indexRad = indexDrp;
//	if (index != indexRad) {
//		student s = h.stud[index];
//		h.stud[index] = h.stud[indexRad];
//		h.stud[indexRad] = s;
//
//		filtrare(h, indexRad);
//	}
//}
//
//heap inserare(heap h, student s) {
//	student* nou = (student*)malloc((h.nrElem + 1) * sizeof(student));
//	for (int i = 0; i < h.nrElem; i++) {
//		nou[i] = h.stud[i];
//	}
//	h.nrElem++;
//	nou[h.nrElem - 1] = s;
//	free(h.stud);
//	h.stud = nou;
//	for (int i = (h.nrElem - 1) / 2; i >= 0; i--)
//		filtrare(h, i);
//	return h;
//}
//
//heap extragere(heap h, student* extras) {
//	student* nou = (student*)malloc((h.nrElem - 1) * sizeof(student));
//	student a = h.stud[0];
//	h.stud[0] = h.stud[h.nrElem - 1];
//	h.stud[h.nrElem - 1] = a;
//
//	*extras = h.stud[h.nrElem - 1];
//
//	h.nrElem--;
//	for (int i = 0; i < h.nrElem; i++)
//		nou[i] = h.stud[i];
//	free(h.stud);
//	h.stud = nou;
//	for (int i = (h.nrElem - 1) / 2; i >= 0; i--)
//		filtrare(h, i);
//	return h;
//}
//
//void afisareHeap(heap h) {
//	for(int i=0; i<h.nrElem; i++)
//		printf("Studentul %s are ID-ul %d si nota %d\n",h.stud[i].nume, h.stud[i].ID, h.stud[i].nota);
//}
//
//void dezalocareHeap(heap h) {
//	for (int i = 0; i < h.nrElem; i++) {
//		free(h.stud[i].nume);
//	}
//	free(h.stud);
//}
//
//void main() {
//	heap h;
//	char buffer[20];
//	FILE* f = fopen("Text.txt", "r");
//
//	fscanf(f, "%d", &h.nrElem);
//	h.stud = (student*)malloc(h.nrElem * sizeof(student));
//	for (int i = 0; i < h.nrElem; i++) {
//		fscanf(f, "%d", &h.stud[i].ID);
//		fscanf(f, "%s", buffer);
//		h.stud[i].nume = (char*)malloc(strlen(buffer) + 1);
//		strcpy(h.stud[i].nume, buffer);
//		fscanf(f, "%d", &h.stud[i].nota);
//	}
//	fclose(f);
//	for (int i = (h.nrElem - 1); i >= 0; i--)
//		filtrare(h, i);
//	afisareHeap(h);
//	printf("\n--------------------------------------\n");
//	student s;
//	s.ID = 4;
//	s.nume = (char*)malloc(strlen("Maricica")+1);
//	strcpy(s.nume, "Maricica");
//	s.nota = 11;
//	h = inserare(h, s);
//	afisareHeap(h);
//	h = extragere(h, &s);
//	printf("Studentul %s are ID-ul %d si nota %d\n",s.nume, s.ID, s.nota);
//	afisareHeap(h);
//}