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

typedef struct queue //ť�ϳ��� â��
{
	Node*	front;
	Node*	rear;
	queue*	next; //���� â���� ����Ű�� ������ //������ â���� ���̵ȴ�
	int		size;
}queue;

typedef struct queueManager
{
	queue*	first;
	int		numOfQ;
}qManager;

void insertion() //�ϳ��� ť�� �մ� ����ִ� �Լ�
{

}

Node* POP() //�ϳ��� ť���� �մ� ������ �Լ�
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
	int	M; //â�� ����
	int	K; //â���� �ִ� �����ο�
	int	N; //���� ��

	scanf("%d %d %d", &M, &K, &N);

	qManager* manager = (qManager*)malloc(sizeof(qManager));
	if (manager == NULL)
		exit (1);
	manager->numOfQ = M;

	manager->first = createQ(K);
	queue* lastQ = manager->first; //������ â���� ����Ű�� �Ǵ� ť������
	for (int i = 1;i < M;i++) {
		queue* tmp = createQ(K); //��â�� �����
		lastQ->next = tmp;
		lastQ = tmp;
	}


}
