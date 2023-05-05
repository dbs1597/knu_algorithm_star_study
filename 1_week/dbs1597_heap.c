#include <stdio.h>

#define HEAP_MAX_SIZE 100000

unsigned int heap[HEAP_MAX_SIZE] = {0};
unsigned int idx = 1; //heap이 삽입될 index

void heap_insert(unsigned int value);
unsigned int heap_delete();
void printheap();

int main() {

  unsigned int repeat, input = 0;

  scanf("%u", &repeat);

  for (unsigned int i=0;i<repeat;i++) {
    scanf("%u", &input);

    if (input == 0) {
      printf("%u\n", heap_delete());
    }
    else {
      heap_insert(input);
    }
  }

}

void heap_insert(unsigned int value) {
  unsigned int pos = idx;

  heap[idx++] = value;

  while(!(pos == 1)) {
    unsigned int parent = (unsigned int)(pos/2);
    if (heap[pos] > heap[pos/2]) {
      unsigned int temp = heap[pos];
      heap[pos] = heap[parent];
      heap[parent] = temp;
    }

    pos = parent;
  }
}

unsigned int heap_delete() {
  if (idx == 1) {
    return 0;
  }

  unsigned int pos = 1;
  unsigned int temp = heap[pos];

  heap[pos] = heap[idx--];
  heap[idx+1] = 0;

  while(pos*2 <= idx) {
    if ((heap[pos*2] > heap[pos]) || (heap[pos*2+1] > heap[pos])) {
      unsigned int temp = heap[pos];
      if (pos*2 > idx) {
        heap[pos] = heap[pos*2];
        heap[pos*2] = temp;
        pos*=2;
      }
      else if (heap[pos*2] > heap[pos*2+1]) {
        heap[pos] = heap[pos*2];
        heap[pos*2] = temp;
        pos*=2;
      }
      else {
        unsigned int temp = heap[pos];
        heap[pos] = heap[pos*2+1];
        heap[pos*2+1] = temp;
        pos = pos*2+1;
      }
    }
    else {break;}
  }

  return temp;
}

void printheap() {
  if (idx == 1) {
    printf("Tree has no value!");
  }

  for(unsigned int i=1;i<idx;i++) {
    printf("%d ",heap[i]);
  }
  printf("\n");
}