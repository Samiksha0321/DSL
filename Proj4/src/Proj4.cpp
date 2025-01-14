//============================================================================
// Name        : Proj4.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

struct node{
	int prn;
	char name[20];
	node *next;
};

class panclub{
    int num,cnt;
    char nm[20];
    node *head;
 public:
    panclub(){
     num=cnt=0;
     head=NULL;
    }
    void enter_data();
    node *create();
    void display(node *);
    node *concat(node *,node *);
    void reverse(node *);
    node* insert_president(node *);
    void insert_sec(node *);
    void insert_member(node *);
    node* del_president(node *);
    node* del_secretary(node *);
    node* del_member(node *);
};

void panclub::enter_data(){
	node* h;
	h = NULL;
	cout<<"\n\nEnter the Panclub Data:\n";
	h=create();
	cout<<"\nSE Comp Division A List are as follows..\n\n";
	display(h);
	cout<<"\n\nReverse List of SE Div A:\n\n";
	reverse(h);
	insert_sec(h);
	cout<<"\nAfter insertion of Secretary: \n";
	display(h);
	h=insert_president(h);
	cout<<"\nAfter insertion of President: \n";
	display(h);
	insert_member(h);
	cout<<"\n After insertion of member...\n";
	display(h);
	h=del_president(h);
	cout<<"\n\nAfter deletion of president...\n";
	display(h);
	h=del_secretary(h);
	cout<<"\n\nAfter deletion of secretary...\n";
	display(h);
	h=del_member(h);
	cout<<"\n\nAfter deletion of member...\n";
	display(h);
}

node* panclub::create(){
	node *temp,*n1;
    temp=n1=NULL;
    cout<<"\nNo. of students data u want to insert : ";
    cin>>cnt;
    do{
        n1=new node;
        cout<<"\nEnter prn number of student:";
        cin>>num;
        n1->prn=num;

        cout<<"\nEnter the name of student:";
        cin>>nm;
        strcpy(n1->name,nm);

        n1->next=NULL;
        if(head==NULL){
            head=n1;
            temp=head;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=n1;
        }
        cnt--;
    }while(cnt>0);

    return head;
}

void panclub::display(node *head) {
	node *temp;
	temp=head;
	while(temp!=NULL){
		if(temp->next==NULL){
			cout<<"["<<temp->prn<<"|"<<temp->name<<"]->NULL";
		}
		else{
			cout<<"["<<temp->prn<<"|"<<temp->name<<"]->";
		}
		temp=temp->next;
	}
}

node* panclub::concat(node *head1,node *head2){
    node *head3,*temp,*temp1;
    head3=temp=temp1=NULL;
    temp=head1;
    head3=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp1=head2;
    temp->next=temp1;
    return head3;
}
void panclub::reverse(node *head){
    node *temp;
    temp=head;
    if(temp==NULL)
        return;
    reverse(temp->next);
    cout<<"["<<temp->prn<<"|"<<temp->name<<"]->";
}

node* panclub::insert_president(node *head){
	node *temp,*n2;
	temp=n2=NULL;
	temp=head;
	n2=new node;
	cout<<"\nEnter the PRN number of President: ";
	cin>>n2->prn;
	cout<<"\nEnter the name of President: ";
	cin>>n2->name;
	n2->next=temp;
	head=n2;
	return head;
}

void panclub::insert_member(node *head){
	node *temp,*n2;
	int pn;
	temp=head;
	n2=new node;
	cout<<"\nEnter the PRN number of Member: ";
	cin>>n2->prn;
	cout<<"\nEnter the name of Member: ";
	cin>>n2->name;
	n2->next=NULL;
	cout<<"\nEnter the PRN number after which u want to add this member: ";
	cin>>pn;
	while(temp!=NULL){
		if(temp->prn==pn){
			n2->next=temp->next;
			temp->next=n2;
			break;
		}
		temp=temp->next;
	}
	cout<<"\n\nMember added sucessfully....!!";
}

void panclub::insert_sec(node *head){
	node *temp,*n2;
	temp=head;
	n2=new node;
	cout<<"\nEnter the PRN number of Secretary: ";
	cin>>n2->prn;
	cout<<"\nEnter the Name of Secretary: ";
	cin>>n2->name;
	n2->next=NULL;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n2;
}

node* panclub::del_president(node *head){
	node *temp;
	temp=head;
	head=temp->next;
	free(temp);
	return head;
}

node* panclub::del_secretary(node *head){
	node *temp,*t1;
	temp=head;
	while(temp->next!=NULL){
		t1=temp;
		temp=temp->next;
	}
	t1->next=NULL;
	free(temp);
	return head;
}

node* panclub::del_member(node *head){
	node *temp,*t1;
	int pn;
	temp=head;
	cout<<"\nEnter the PRN number after which u want to delete member: ";
	cin>>pn;
	while(temp!=NULL){
		if(temp->prn==pn){
			t1=temp->next;
			temp->next=t1->next;
			free(t1);
			break;
		}
		temp=temp->next;
	}
	cout<<"\n\nMember removed successfully....!!";
	return head;
}

int main(){
    panclub p1,p2,p3;
    node *h1,*h2,*h3;
    h1=h2=h3=NULL;
    int ch;
	cout<<"\n1.Enter data of SE A Division:";
	cout<<"\n2.Enter data of SE B Division:";
	cout<<"\n3.Concatenation of List";
	cout<<"\n4.Exit";
	cout<<"\nChoice: ";
	cin>>ch;
	switch(ch){
		case 1: p1.enter_data();
				break;
		case 2: p2.enter_data();
				break;
		case 3: h3=p3.concat(h1,h2);
				cout<<"\n\nThe concatenation of Div: A and Div: B are as follows.\n\n";
				p3.display(h3);
				break;

	}while(ch!=4);
	return 0;
}
