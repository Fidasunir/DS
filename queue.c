#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int queue[MAX],front=-1,rear=-1;
void enqueue(){
	int element;
	if(rear==MAX-1){
		printf("queue overflow");
		return;
	}
	printf("element to be enqueued:");
	scanf("%d",&element);
	if(front==-1){
		front=0;
	}
	rear++;
	queue[rear]=element;
	printf("element enqueued to the queue=%d\n",element);
}
void dequeue(){
	if(front==-1||front>rear){
		printf("queue underflow");
		return;
	}
	printf("dequeued element:\n",queue[front]);
	front++;
	if(front>rear){
		front=rear-1;
	}
}
void display(){
	int i;
	if(front==-1){
		printf("queue is empty");
		return;
	}
	printf("queue elements are:\n");
	for(i=front;i<=rear;i++){
		printf("%d",queue[i]);
	}
	printf("\n");
}
int main(){
        int ch;
        while(1){
	        printf("\nqueue menu\n");
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
                                printf("invalid choice");
                }
        }
        return 0;
}
