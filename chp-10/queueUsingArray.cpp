/**
* Simple queue using array program
* @version 1.0
* @author ajinkya shukla <ajinkyashukla02@gmail.com>
*/

#include<iostream>
#include<stdlib.h>

using namespace std;
static int *queue,size,head,tail;

bool isEmpty();
bool isFull();
void enqueue();
void dequeue();
void display();

int main(){	
	cout<<"Enter queue size(>0)";
	cin>>size;

	if(size>0){
		int option=-1;
	
		try{
			queue=new int[size];
		}
		catch(std::bad_alloc& ba){
			cout<<"Could not allocate memory.\n";
			exit(0);		
		}
		while(option!=4){
			cout<<"1.Insert 2.Delete 3.Display 4.Exit\n";
			cout<<"Enter option:";
			cin >>option;
			switch(option){
				case 1:enqueue();break;
				case 2:dequeue();break;
				case 3:display();break;
				case 4:break;
				default:cout<<"Invalid option\n";		
			}
		}
	}
	else{
		cout<<"Invalid queue size.";	
	}
	return 0;	
}
bool isEmpty(){
	if(tail==0){
		return true;	
	}
	else{
		return false;	
	}
}
bool isFull(){
	if(tail==size){
		return true;
	}
	else{
		return false;	
	}
}
void enqueue(){
	if(isFull()==false){
		int element;
		cout<<"Enter element : ";
		cin>>element;
		queue[tail++]=element;
	}
	else{
		cout<<"Queue overflow.\n";
	}
}
void dequeue(){
	if(isEmpty()==false){
		cout<<queue[head++]<<" deleted\n";

//The for loop shifts the elements one place to the left whenever an element is removed.

		for(int i=head;i<tail;i++){
			queue[i-1]=queue[i];
		}
		--head;
		--tail;	
	}
	else{
		cout<<"Queue underflow.\n";	
	}
}
void display(){
	if(isEmpty()==false){
		for(int i=head;i<tail;i++){
			cout<<queue[i]<<" ";		
		}
		cout<<"\n";
	}
	else{
		cout<<"Queue underflow.\n";	
	}
}
