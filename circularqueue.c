#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int queue[MAX],front=-1,rear=-1,count=0;
void enqueue(){
	int element;
	if(count==MAX){
		printf("circular queue is full");
		return;
	}
	printf("enter element to be enqueued:");
	scanf("%d",&element);
	if(front==-1){
		front=0;
	}
	rear=(rear+1)%MAX;
	queue[rear]=element;
	count++;
	printf("%d enqueued to the queue\n",element);
}
void dequeue(){
	if(count==0){
		printf("circular queue is empty\n");
		return;
	}
	printf("dequeued element:%d\n",queue[front]);
	front=(front+1)%MAX;
	count--;
}
void display(){
	if(count==0){
		printf("circular queue is empty");
		return;
	}
	int j=front;
	printf("queue elements are:\n");
	for(int i=0;i<count;i++){
		printf("%d\n",queue[j]);
		j=(j+1)%MAX;
	}
	printf("\n");
}
int main(){
	int ch;
	while(1){
		printf("circular queue menu\n");
		printf("1.enqueue\n");
		printf("2.dequeue\n");
		printf("3.display\n");
		printf("4.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:enqueue();
				break;
			case 2:dequeue();
				break;
			case 3:display();
				break;
			case 4:exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
