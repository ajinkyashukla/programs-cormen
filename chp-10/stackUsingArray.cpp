/**
* Simple stack using array program
* @version 1.0
* @author ajinkya shukla <ajinkyashukla02@gmail.com>
*/

#include<iostream>
#include<stdlib.h>

using namespace std;
static int *stack,top=0,size;

bool isFUll();
bool isEmpty();
void push();
void pop();
void display();

int main(){
	int option=-1;

	cout << "Enter stack size(>0) : ";
	cin >>size;

	if(size>0){
		try{
			stack=new int[size];
		}
		catch(std::bad_alloc& ba){
			cout<<"Could not allocate memory\n";
			exit(0);
		}
		
		while(option!=4){
			cout<<"1.Push 2.Pop 3.Display 4.Exit\n";
			cout << "Enter Option : ";
			cin >> option;
			switch(option){
				case 1:push();break;
				case 2:pop();break;
				case 3:display();break;
				case 4:break;
				default:cout<<"Invalid option.\n";
			}
		}
	}
	else{
		cout << "Invalid stack size.\n";
	}
	delete[] stack;
	return 0;
}
bool isFull(){
	if(top==size){
		return true;
	}
	else{
		return false;
	}
}
bool isEmpty(){
	if(top==0){
		return true;
	}
	else{
		return false;
	}
}
void push(){
	if(isFull()==false){
		int element;
		cout<<"Enter element : ";
		cin>>element;
		stack[top++]=element;
	}
	else{
		cout<<"Stack full.";
	}
}
void pop(){
	if(isEmpty()==false){
		cout<<stack[--top]<<" popped\n";
	}
	else{
		cout<<"Stack empty.\n";
	}
}
void display(){
	if(isEmpty()==false){
		for(int i=top-1;i>-1;i--){
			cout<<stack[i]<<"\n";
		}
	}
	else{
		cout<<"Stack empty.\n";
	}
}