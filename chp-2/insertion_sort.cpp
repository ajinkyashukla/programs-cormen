/**
* Simple insertion sort program
* @version 1.0
* @author ajinkya shukla <ajinkyashukla02@gmail.com>
*/


#include<iostream>

using namespace std;

int main() {

	int n,j,key;

	cout << "Enter the number of intergers to be sorted: ";
	
	cin >> n; 
	int a[n];

	cout <<"\n" << "Enter the Integers: ";

	for(int i=0;i<n;i++) 
		cin >> a[i];

	/*
	The for loop stores one element in key. All the elements before key are 	shifted one position to right till an element less than key is found or		till elements before key are exhausted.The key element is then replaced 	with the position where inner while loop exits.
	*/
	
	for(int i=1;i<n;i++) {

		key=a[i];
		j=i-1;

		while(j>=0 && key < a[j]) {
			a[j+1]=a[j];
			j--;
		}
		
		
		a[j+1]=key;
	}

	cout << "\n" << "Sorted Integers:";

	for(int i=0;i<n;i++) {
		cout << a[i] << " ";
	}
	return 0;
}
