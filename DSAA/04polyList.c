#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	This file is writed only with C. 
	Don't understand how to use the array and stack in this question.
*/

typedef struct _monoData {
	int coefficient;
	int exponent;
} MonoData;

typedef struct _monomial {
	MonoData data;
	struct _monomial * next;
} Mono;

Mono * createPoly();
void destoryPoly(Mono * head);
void insertPoly(Mono * head, int co, int ex);
void showMap(Mono * head);
Mono * addPoly(Mono * LP, Mono * LQ);

int main() {
//	Don't understand how to use the array in this question.
//	int arr[30] = { 0 };
	Mono * LP = createPoly();
	Mono * LQ = createPoly();

	for (int i = 1; i < 5; i++) {
		insertPoly(LP, i, i + 9);
		insertPoly(LQ, 5 - i, 6 - i);
	}
	insertPoly(LP, -3, 4);

	printf("LP  = ");
	showMap(LP);
	printf("LQ  = ");
	showMap(LQ);

	Mono * LPQ = createPoly();
	LPQ = addPoly(LP, LQ);

	printf("LPQ = ");
	showMap(LPQ);

	destoryPoly(LP);
	destoryPoly(LQ);
	destoryPoly(LPQ);
	return 0;
}

Mono * createPoly() {
	Mono * head = (Mono*)malloc(sizeof(Mono));
	if (NULL == head) {
		printf("malloc error!\n");
		exit(-1);
	}

	head->next = NULL;
	return head;
}
void destoryPoly(Mono * head) {
	Mono * t;
	while (head) {
		t = head;
		head = head->next;
		free(t);
	}
}
void insertPoly(Mono * head, int co, int ex) {
	Mono * cur = (Mono*)malloc(sizeof(Mono));
	if (NULL == cur)
		exit(-1);
	cur->data.coefficient = co;
	cur->data.exponent = ex;

	while((head->next != NULL) && (head->next->data.exponent <= ex)) {
		if (head->next->data.exponent == ex) {
			if (head->next->data.coefficient + co)
				head->next->data.coefficient += co;
			else {
				Mono * temp = (Mono*)malloc(sizeof(Mono));
				temp = head->next;
				head->next = temp->next;
				free(temp);
			}
			return;
		}
		head = head->next;
	}
	cur->next = head->next;
	head->next = cur;
}
void showMap(Mono * head) {
	head = head->next;
	if (head == NULL)
		printf("0\n");
	while (head->next) {
		printf("%dx^%d + ", head->data.coefficient, head->data.exponent);
		head = head->next;
	}
	printf("%dx^%d\n", head->data.coefficient, head->data.exponent);
}
Mono * addPoly(Mono * LP, Mono * LQ) {
	Mono * sum = (Mono*)malloc(sizeof(Mono));
	if (sum == NULL)
		exit(-1);
	LP = LP->next;
	while (LP) {
		insertPoly(sum, LP->data.coefficient, LP->data.exponent);
		LP = LP->next;
	}
	LQ = LQ->next;
	while (LQ) {
		insertPoly(sum, LQ->data.coefficient, LQ->data.exponent);
		LQ = LQ->next;
	}
	return sum;
}

