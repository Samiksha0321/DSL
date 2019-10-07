//============================================================================
// Name        : Practice.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
};

void push(node **head_ref, int new_data){
	node* new_node = new node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void insertAfter(node* prev_node, int new_data){
	if(prev_node == NULL){
		cout<<"prev node cannot be null"<<endl;
		return;
	}
	node* new_node = new node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(node **head_ref,int new_data){
	node* new_node = new node();
	node* last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	while(last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

void print(node* n){
	while(n != NULL){
		cout<<" "<<n->data;
		n = n->next;
	}
}

int main(){
	node* head = NULL;
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);
	print(head);
	return 0;
}
