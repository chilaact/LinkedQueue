#include "LinkedQueue.h"

int main()
{
	Queue *intQueue = (Queue*)malloc(sizeof(Queue));
	Queue *strQueue = (Queue*)malloc(sizeof(Queue));

	int idata[5] = { 0, 1, 2, 3, 4 };
	char *sdata[3] = { "aa", "bbbb", "cc" };
	void *dedata = malloc(sizeof(char));

	CreateQueue(intQueue, sizeof(int));
	intQueue->Enqueue(intQueue, &idata[0]);
	printf("Enqueue : %d\n", *(int *)(intQueue->front->data));
	printf("Length : %d\n", intQueue->length);
	intQueue->Enqueue(intQueue, &idata[1]);
	printf("Length : %d\n", intQueue->length);
	intQueue->Enqueue(intQueue, &idata[2]);
	printf("Length : %d\n", intQueue->length);
	printf("\n");

	if (intQueue->Dequeue(intQueue, dedata)) {
		printf("Dequeue : %d\n", *(int *)dedata);
		printf("Length : %d\n", intQueue->length);
	}
	if (intQueue->Dequeue(intQueue, dedata)) {
		printf("Dequeue : %d\n", *(int *)dedata);
		printf("Length : %d\n", intQueue->length);
	}
	if (intQueue->Dequeue(intQueue, dedata)) {
		printf("Dequeue : %d\n", *(int *)dedata);
		printf("Length : %d\n", intQueue->length);
	}
	if (intQueue->Dequeue(intQueue, dedata)) {
		printf("Dequeue : %d\n", *(int *)dedata);
		printf("Length : %d\n", intQueue->length);
	}
	printf("\n");

	intQueue->DeleteQueue(intQueue);

	CreateQueue(strQueue, sizeof(char *));

	strQueue->Enqueue(strQueue, &sdata[0]);
	printf("Enqueue : %s\n", *(char **)(strQueue->front->data));
	printf("Length : %d\n", strQueue->length);
	printf("\n");

	if (strQueue->Dequeue(strQueue, dedata)) {
		printf("Dequeue : %s\n", *(char **)dedata);
		printf("Length : %d\n", strQueue->length);
	}
	printf("\n");
	if (strQueue->Dequeue(strQueue, dedata)) {
		printf("Dequeue : %s\n", *(char **)dedata);
		printf("Length : %d\n", strQueue->length);
	}
	strQueue->DeleteQueue(strQueue); 
}