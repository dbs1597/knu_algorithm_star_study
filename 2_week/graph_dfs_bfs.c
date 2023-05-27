#include <stdio.h>

typedef struct node {

	int edge;
	struct node *next;

}node;

typedef struct stack {

	int val;
	struct node *next;

}Stack;

int main() {
    int vert_num, edge_num, start;

    scanf("%d %d %d", &vert_num, &edge_num, &start);

    printf("0\n");

    node **graph[5];

    printf("0\n");

    for(int i=1;i<=vert_num;i++) {
        printf("1\n");
        graph[i]->edge = i;
        graph[i]->next = NULL;
    }

    printf("0\n");

    for(int i=0;i<edge_num;i++) {
        int edge1, edge2;
        scanf("%d %d", &edge1, &edge2);

        printf("1\n");

        node *element, *temp;
        element->edge = edge2;
        element->next = NULL;

        printf("2\n");

        temp = graph[edge1];
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = element;

        printf("3\n");
    }

    for(int i=1;i<vert_num;i++) {
        node *temp = graph[i];
        while(temp->next != NULL) {
            printf("%d ", temp->edge);
            temp = temp->next;
        }
        printf("\n");
    }
}