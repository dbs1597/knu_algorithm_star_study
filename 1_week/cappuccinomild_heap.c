#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_UNSIGNED 4294967295

unsigned int* heap;
unsigned int rear;

void swap(unsigned int *a, unsigned int *b) {
	
	unsigned int temp;

	temp = *a;
	*a = *b;
	*b = temp;

}

void insert(unsigned int val) {
	
	int i = 1;

	heap[rear] = val;
	i = rear++;

	while (heap[(int)i / 2] < val) {
		swap(&heap[(int)i / 2], &heap[i]);
		i /= 2;
	}

	return;
}

unsigned int pop() {

	unsigned int return_val;
	int i;

	//empty heap
	if (rear == 1) {
		return 0;
	}

	//head
	return_val = heap[1];

	//leaf swap
	heap[1] = heap[rear];
	heap[rear] = 0;

	i = 1;
	while(1){

		//left is bigger
		if (heap[i * 2] > heap[i * 2 + 1]){
			if (heap[i * 2] > heap[i]) {

				swap(&heap[i * 2], &heap[i]);
				i = i * 2;

			}
			else
				break;
		}

		else if (heap[i * 2] < heap[i * 2 + 1]){
			if (heap[i * 2 + 1] > heap[i]){

				swap(&heap[i * 2 + 1], &heap[i]);
				i = i * 2 + 1;


			}
			else
				break;
		}

		else
			break;

	}

	return return_val;
}

int main() {
	
	int i, size;
	unsigned int flag;

	//init rear
	scanf("%d", &size);

	rear = 1;
	heap = (unsigned int*)calloc(size, sizeof(unsigned int));
	heap[0] = MAX_UNSIGNED;

	for (i = 0; i < size; i++) {

		scanf("%d", &flag);
			
		//출력
		if (flag == 0) {
			printf("%d\n", pop());
		}

		//입력
		else {
			insert(flag);
		}

	}

	return 0;
}