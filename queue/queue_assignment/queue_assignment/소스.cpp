#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

//front deletion
//rear insertion

typedef struct Node
{
	Node*	next;
	Node*	prev;
	int		element;
} Node;

typedef struct queue //큐하나가 창구
{
	Node*	front;
	Node*	rear;
	queue*	next; //다음 창구를 가리키는 포인터 //마지막 창구는 널이된다
	int		size;
}queue;

typedef struct queueManager
{
	queue*	first;
	int		numOfQ;
}qManager;

void insertion() //하나의 큐에 손님 집어넣는 함수
{

}

Node* POP() //하나의 큐에서 손님 꺼내는 함수
{

}

queue* createQ(int K)
{
	queue* q = (queue*)malloc(sizeof(queue));
	if (q == NULL)
		exit(1);
	q->front = NULL;
	q->rear = NULL;
	q->next = NULL;
	q->size = K;
	return q;
}

int main()
{
	int	M; //창구 개수
	int	K; //창구의 최대 수용인원
	int	N; //고객의 수

	scanf("%d %d %d", &M, &K, &N);

	qManager* manager = (qManager*)malloc(sizeof(qManager));
	if (manager == NULL)
		exit (1);
	manager->numOfQ = M;

	manager->first = createQ(K);
	queue* lastQ = manager->first; //마지막 창구를 가리키게 되는 큐포인터
	for (int i = 1;i < M;i++) {
		queue* tmp = createQ(K); //새창구 만들기
		lastQ->next = tmp;
		lastQ = tmp;
	}


}
