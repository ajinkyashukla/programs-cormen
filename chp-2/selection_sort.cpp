/**
* Simple selection sort program
* @version 1.0
* @author ajinkya shukla <ajinkyashukla02@gmail.com>
*/

#include<iostream>

using namespace std;

int main() {

	int n,min,min_index,i,j;

	cout << "Enter number of integers to be sorted: ";

	cin >> n;

	int a[n];

	cout << "\n" << "Enter the integers: ";

	for(i=0;i<n;i++) 
		cin >> a[i];

	/*
	The for loop selects the minimum element in the left over array and swaps it with the 0th,1st .. n-1th element.
	*/

	for(i=0;i<n;i++) {
		min=a[i];
		min_index=i;

		for(j=i+1;j<n;j++)
			if(a[j]<min ){ 
				min=a[j];
				min_index=j;
			}

		a[min_index]=a[i];
		a[i]=min;
	}

	cout << "\n" << "Sorted Integers:";

	for(i=0;i<n;i++) 
		cout << a[i] << " ";
	
	return 0;
}
