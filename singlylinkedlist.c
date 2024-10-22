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
void insertAtHead(){
	struct Node*new_node=getnode();
	if(start==NULL){
		start=new_node;
	}else{
		new_node->link=start;
		start=new_node;
	}
}
void insertTail() {
	struct Node* new_node = getnode();
	if (start == NULL) {
		start = new_node;
	} else {
	struct Node* ptr = start;
	while (ptr->link != NULL) {
		ptr = ptr->link;
	}
	ptr->link = new_node;
	}
}
void deleteAtHead() {
	if (start == NULL) {
		printf("List is empty, nothing to delete.\n");
	} else {
		struct Node* ptr = start;
		start = start->link;
		free(ptr);
		printf("Head node deleted successfully.\n");
	}
}
void deleteTail() {
	if (start == NULL) {
		printf("List is empty, nothing to delete.\n");
	} else if (start->link == NULL) {
	free(start);
	start = NULL;
	printf("Tail node deleted successfully.\n");
	} else {
		struct Node* ptr = start;
		struct Node* prev = NULL;
		while (ptr->link != NULL) {
		prev = ptr;
		ptr = ptr->link;
	}
	prev->link = NULL;
	free(ptr);
	printf("Tail node deleted successfully.\n");
	}
}
void traverse() {
	if (start == NULL) {
		printf("List is empty.\n");
	} else {
	struct Node* ptr = start;
	while (ptr != NULL) {
		printf("-> %d", ptr->data);
		ptr = ptr->link;
	}
	}
}
void freeList() {
	while (start != NULL) {
		deleteAtHead();
	}
}
int main(){
	int choice;
	while(1){
		printf("\nMENU\n");
		printf("1.insertion at head\n");
		printf("2.insertion at tail\n");
		printf("3.deletion at head\n");
		printf("4.deletion at tail\n");
		printf("5.traverse list\n");
		printf("6.exit\n");
		printf("\nenter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:insertAtHead();
				printf("node inserted at head\n");
				break;
			case 2:insertTail();
                                printf("node inserted at tail\n");
                                break;
			case 3:deleteAtHead();
                                break;
			case 4:deleteTail();
                                break;
			case 5:
                                printf("current list:");
				traverse();
                                break;
			case 6:
				printf("existig program");
				freeList();
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
