#ifndef __LINKED_QUEUE_
#define __LINKED_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

typedef struct Node Node;
typedef struct Queue Queue;

typedef struct Node
{
	Node *next;
	void *data;
} Node;
typedef struct Queue
{
	Node *front;
	Node *rear;
	int datasize;
	int length;
	void(*Enqueue)(Queue *queue, void *endata);
	int(*Dequeue)(Queue *queue, void *dedata);
	int(*isEmpty)(Queue *queue);
	void(*DeleteQueue)(Queue *queue);
} Queue;

void CreateQueue(Queue *queue, int datasize);
void Enqueue(Queue *queue, void *endata);
int Dequeue(Queue *queue, void *dedata);
int isEmpty(Queue *queue);
void DeleteQueue(Queue *queue);
Node *makeNode(int datasize);
#endif
