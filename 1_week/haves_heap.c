#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COMPARE(A, B) ((A) < (B)) ? -1 : ((A) == (B)) ? 0 : 1

#define SWAP(A, B, T) (T) = (A); (A) = (B); (B) = (T);

int* heap, heapSize;
int key = 0; // 계산의 용이를 위해 0번 인덱스 사용 x

void heapInsert(int value);
void insertSort(int idx);
int heapDelete(void);
void deleteSort(int focus);
void heapUpsize(void);
void heapDownsize(void);
void heapPrint(void);

int main() {
	int temp, num;

	heap = (int*)malloc(2 * sizeof(int));
	heapSize = 2;

	scanf(" %d", &num);

	for (int i = 1; i <= num; i++) {
		heapInsert(i);
	}

	heapPrint();

	free(heap);

	return 0;
}

// 데이터를 가장 마지막에 추가함 -> 이후 부모 노드와 크기를 비교 후 교환하는 방식으로 자리를 찾음
// 삽입하는 경우에만 완전 이진트리에 대해 고민하면 됨
void heapInsert(int value) {
	// heap의 크기가 부족하지 않으면 데이터 삽입
	if (key < heapSize - 1) {
		heap[++key] = value;
	}
	// 부족한 경우 크기 확장 후 삽입
	else {
		heapUpsize();
		heap[++key] = value;
	}
	// 원소가 두개 이상인 경우 정렬을 진행
	if (key > 1) insertSort(key);
	return;
}

void insertSort(int idx) {
	int temp;
	// 가리키는 원소가 루트라면 종료
	if (idx <= 1) return;
	switch (COMPARE(heap[idx], heap[idx / 2])) {
	case -1: return;// 부모 > 자식 인 경우 가만히 둠
	case 0: return; // 부모 == 자식 인 경우 가만히 둠
	case 1: // 부모 < 자식 인 경우 두 값을 바꾼 뒤 재귀로 진행
		SWAP(heap[idx], heap[idx / 2], temp);
		insertSort(idx / 2);
		return;
	}
}

// 힙의 루트를 제거한 뒤 가장 마지막에 넣은 데이터를 루트에 넣어줌 -> 이후 자식 노드 중 큰 값과 교환하는 방식으로 자리를 찾음
int heapDelete(void) {
	int root;
	// heap이 비어있는 경우 리턴
	if (key < 1) {
		printf("heap empty!\n");
		return 0;
	}
	// heap의 루트값 저장 후 마지막 값을 루트에 둠
	root = heap[1];
	heap[1] = heap[key--];

	// 배열의 크기가 사용하는 공간보다 4배 이상 큰 경우 크기를 줄임
	if (heapSize > key * 4) heapDownsize();

	// heap의 두개 이상의 데이터가 있는 경우 루트부터 정렬 시도
	if (key > 1) deleteSort(1);
	printf("root : %3d\n", root);
	return root;
}

void deleteSort(int idx) {
	int temp;
	// 자식 노드가 하나도 없는 경우 리턴
	if (idx * 2 > key) {
		return;
	}
	// 자식 노드가 하나 뿐인 경우, 부모가 자식보다 작은 경우 교환, 큰 경우 리턴
	else if (idx * 2 == key) {
		if (heap[idx] < heap[idx * 2]) {
			SWAP(heap[idx], heap[idx * 2], temp);
			deleteSort(idx * 2);
			return;
		}
		return;
	}
	// 비교중인 값이 두 자식 노드보다 크다면 리턴
	else if (heap[idx] > heap[idx * 2] && heap[idx] > heap[idx * 2 + 1]) {
		return;
	}
	// 비교중인 값이 한개 이상의 자식 노드 보다 작다면
	else {
		switch (COMPARE(heap[idx * 2], heap[idx * 2 + 1])) {
		case -1: // 오른쪽 노드의 값이 더 큰경우
			SWAP(heap[idx], heap[idx * 2 + 1], temp);
			deleteSort(idx * 2 + 1); // 오른쪽 노드의 idx로 재귀
			return;
		case 0: // 자식 노드의 값이 같은 경우, 왼쪽과 교환
			SWAP(heap[idx], heap[idx * 2], temp);
			deleteSort(idx * 2); // 왼쪽 노드의 idx로 재귀
			return;
		case 1: // 왼쪽 노드의 값이 더 큰경우
			SWAP(heap[idx], heap[idx * 2], temp);
			deleteSort(idx * 2); // 왼쪽 노드의 idx로 재귀
			return;
		}
	}
}

// 힙의 크기를 두배 키움
// 레벨이 증가할 때마다 키움
void heapUpsize(void) {
	heap = (int*)realloc(heap, heapSize * 2 * sizeof(int));
	heapSize *= 2;
}

// 힙의 크기를 두배 줄임
// 레벨이 감소하는 경우 줄임
void heapDownsize(void) {
	if (heapSize / 2 > 2) {
		heap = (int*)realloc(heap, heapSize / 2 * sizeof(int));
		heapSize /= 2;
	}
	else return;
}

void heapPrint(void) {
	for (int i = 1; i <= key; i++) {
		printf("%2d", heap[i]);
	}
}