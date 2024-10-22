#include<stdio.h>
#include<stdlib.h>
struct Node{
        int data;
        struct Node* link;
};
struct Node* start=NULL;
struct Node* getnode(){
        int item;
        printf("enter the value to insert:");
        scanf("%d",&item);
        struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
        if(new_node==NULL){
                printf("memory allocation failed");
                exit(1);
        }
        new_node->data=item;
        new_node->link=NULL;
        return new_node;
}
void enqueue(){
        struct Node*new_node=getnode();
        if(start==NULL){
                start=new_node;
        }else{
                struct Node*ptr=start;
		while(ptr->link != NULL){
			ptr=ptr->link;
	        }
		ptr->link=new_node;
	}
	printf("%d is pushed\n",new_node->data);
}
int dequeue(){
        if (start == NULL){
		printf("queue is empty\n");
		return 0;
        } else {
        	struct Node* ptr = start;
        	start=start->link;
                free(ptr);
		return 1;
        }
}
void traverse() {
        if (start == NULL) {
                printf("queue is empty.\n");
        } else {
		printf("queue elements:");
        	struct Node* ptr = start;
        	while (ptr != NULL) {
                	printf("-> %d", ptr->data);
                	ptr = ptr->link;
        	}
        }
}
void freeList() {
        while (start != NULL) {
                dequeue();
        }
}
int main(){
        int choice;
        while(1){
                printf("\nQUEUE MENU\n");
                printf("1.enqueue\n");
                printf("2.dequeue\n");
                printf("3.traverse\n");
                printf("4.exit\n");
                printf("\nenter your choice:");
                scanf("%d",&choice);
                switch(choice){
                        case 1:enqueue();
                                break;
                        case 2:if(dequeue()){
                                	printf("item dequeued\n");
				}
                                break;
                        case 3:traverse();
                                break;
                        case 4:
                                printf("existig program");
                                freeList();
                                exit(0);
                        default:
                                printf("Invalid choice\n");
                }
        }
        return 0;
}
