/**
* Simple queue using array program
* @version 1.0
* @author ajinkya shukla <ajinkyashukla02@gmail.com>
*/

#include<iostream>
using namespace std;

class Node{
	private:
		int element;
		Node* next;
	public:
		void setElement(int element);
		int getElement();
		void setNext(Node* next);
		Node* getNext();
};
void Node::setElement(int element){
	this->element=element;
}
int Node::getElement(){
	return this->element;
}
void Node::setNext(Node* next){
	this->next=next;
}
Node* Node::getNext(){
	return this->next;
}

class LinkedList{
	private:
		Node* head;
	public:
		LinkedList();
		void insertAtStart();
		void search();
		void deleteElement();
		void display();
};
LinkedList::LinkedList(){
	this->head=NULL;
}
void LinkedList::insertAtStart(){
	int element;
	cout<<"Enter element : ";
	cin>>element;
	Node *node=new Node();
	node->setElement(element);
	node->setNext(this->head);	//point the node to the node pointed by the head
	this->head=node;cout<<this->head<<" "; //point the head to the newly inserted node
}
void LinkedList::search(){
	int element,position=1;
	cout<<"Enter element : ";
	cin>>element;
	Node* temp=this->head;
	if(temp!=NULL){
		while(temp!=NULL && temp->getElement()!=element){
			temp=temp->getNext();
			position++;
		}
		if(temp!=NULL){
			cout<<"Element found at position "<<position<<"\n";			
		}
		else{
			cout<<"Element not found.\n";		
		}
	}
	else{
		cout<<"Linked list is empty.\n";	
	}
}
void LinkedList::deleteElement(){
	int element;
	cout<<"Enter element : ";
	cin>>element;
//two pointers are needed because there is no prev pointer to backtack when required node is found
	Node* temp1=this->head;
	Node* temp2=this->head;	
	if(this->head!=NULL){
//check if the node to be deleted is the first node
		if(temp1->getElement()==element){ 
			this->head=temp1->getNext();
			delete[] temp1,temp2;		
		}
		else{
			while(temp1!=NULL && temp1->getElement()!=element){
				temp2=temp1;
				temp1=temp1->getNext();		
			}
			if(temp1!=NULL){
				temp2->setNext(temp1->getNext());
				delete[] temp1,temp2;		
			}
			else{
				cout<<"Element not found.\n";		
			}
		}	
	}
	else{
		cout<<"Linked list is empty.\n";
	}
}
void LinkedList::display(){
	if(this->head==NULL){
		cout<<"Linked list is empty.\n";		
	}
	else{
		Node* temp;
		temp=this->head;
		while(temp!=NULL){
			cout<<temp->getElement()<<" ";
			temp=temp->getNext();
		}
		cout<<"\n";
	}
}
int main(){
	int option=-1;
	LinkedList *l=new LinkedList();

	while(option!=5){
		cout<<"1.Insert At Start 2.Search 3.Delete 4.Display 5.Exit\n";
		cout<<"Enter option: ";
		cin>>option;
		switch(option){
			case 1:l->insertAtStart();break;
			case 2:l->search();break;
			case 3:l->deleteElement();break;
			case 4:l->display();break;
			case 5:break;
			default:cout<<"Invalid option\n";
		}
	}
}
