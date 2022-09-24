#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _list{
	char phoneNumber[14];
	char *personName;
	struct _list *next;
}list;

void initNode(list *l){
	l->personName = NULL;
	l->next = NULL;
}

void addNode(list *l, char *phoneNumber, char *personName){
	list *temp = l;
	list *newNode;

	newNode = (list*)malloc(sizeof(list)*1);
	strcpy(newNode->phoneNumber, phoneNumber);
	newNode->personName = (char*)malloc(strlen(personName) + 1);
	strcpy(newNode->personName, personName);
	newNode->next = NULL;

	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = newNode;
}

list* searchBeforeNode(list *l, char *personName){
	list *temp = l;
	while(temp->next != NULL && strcmp(temp->next->personName, personName)){
		temp = temp->next;
	}
	if(!strcmp(temp->next->personName, personName)){
		return temp;
	}
	return NULL;
}

void deleteNode(list *l, char *personName){
	list *temp = searchBeforeNode(l, personName);
	list *nextNext = temp->next->next;

	free(temp->next);
	temp->next = nextNext;
}
	
void showList(list *l){
	list *temp;
	temp = l;
	temp = temp->next;
	while(temp->next != NULL){
		printf("phoneNumber : %s / name : %s\n", temp->phoneNumber, temp->personName);
		temp = temp->next;
	}
	printf("phoneNumber : %s / name : %s\n", temp->phoneNumber, temp->personName);
}

void showNode(list *l){
		printf("phoneNumber : %s / name : %s\n", l->phoneNumber, l->personName);
}

void finalizeList(list *l){
	list *temp = l->next;
	list *tempForFree = l;
	while(tempForFree->next != NULL){
		free(tempForFree);
		tempForFree = temp;
		temp = temp->next;
	}
	free(tempForFree);
}

int main(){
	list *head;
	head = (list*)malloc(sizeof(list)*1);
	initNode(head);
	
	int stay = 1;
	while(stay){
		printf("\nchoose method\n1 : add\n2 : delete\n3 : print\n4 : search\n5 : exit\n");
		int chosenNum;

		scanf("%d", &chosenNum);
		if(chosenNum == 1){
			printf("put Number and Name : ");
			char number[14];
			char name[100];
			scanf("%s%s", number, name);

			addNode(head, number, name);
		}
		if(chosenNum == 2){
			printf("put Name : ");
			char name[100];
			scanf("%s", name);

			deleteNode(head, name);
		}
		if(chosenNum == 3){
			showList(head);
		}
		if(chosenNum == 4){
			printf("put name : ");
			list *foundNode;
			char name[100];
			scanf("%s", name);

			foundNode = searchBeforeNode(head, name);
			if(foundNode != NULL){
				showNode(foundNode->next);
			}
		}
		if(chosenNum == 5){
			finalizeList(head);
			stay = 0;
		}
	}
	return 0;
}
