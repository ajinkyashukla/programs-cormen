/**
* Simple bubble sort program
* @version 1.0
* @author ajinkya shukla <ajinkyashukla02@gmail.com>
*/

#include<iostream>


using namespace std;

int main() {

	int n,temp;

	cout << "Enter the number of integers  to be sorted: ";
	
	cin >> n;

	int a[n];

	cout << "\nEnter the integers: ";

	for(int i=0;i<n;i++)
		cin >> a[i];

/*The for loop compares each element with all the elements and swaps it if the element on the RHS is greater. */
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i;j++) {
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}

	cout << "Sorted Integers:";
	for(int i=0;i<n;i++)
		cout << a[i];
return 0;
}
