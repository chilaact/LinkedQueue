#include "LinkedQueue.h"

void CreateQueue(Queue *queue, int datasize)
{
	Node *newNode = makeNode(datasize);
	queue->front = newNode;
	queue->rear = newNode;
	queue->datasize = datasize;
	queue->length = 0;
	queue->Enqueue = Enqueue;
	queue->Dequeue = Dequeue;
	queue->isEmpty = isEmpty;
	queue->DeleteQueue = DeleteQueue;
}

void Enqueue(Queue *queue, void *endata)
{
	Node *newNode = makeNode(queue->datasize);
	memcpy(queue->rear->data, endata, queue->datasize);

	queue->rear->next = newNode;
	queue->rear = newNode;
	queue->length++;
}

int Dequeue(Queue *queue, void *dedata)
{
	if (queue->isEmpty(queue))
		return FALSE;
	else
	{
		Node *deNode = queue->front;

		memcpy(dedata, deNode->data, queue->datasize);
		queue->front = deNode->next;
		free(deNode->data);
		free(deNode);
		queue->length--;
		return TRUE;
	}
}

int isEmpty(Queue *queue)
{
	if (queue->front == queue->rear)
		return TRUE;
	else
		return FALSE;
}

void DeleteQueue(Queue *queue)
{
	void *dedata = malloc(sizeof(char));
	while (queue->Dequeue(queue, dedata))
		;
	free(dedata);
	free(queue->rear->data);
	free(queue->rear);
	free(queue);
}

Node *makeNode(int datasize)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = malloc(datasize);
	newNode->next = newNode;
	return newNode;
}