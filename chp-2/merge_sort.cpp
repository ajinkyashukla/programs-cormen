/**
* Simple Merge sort program
* @version 1.0
* @author ajinkya shukla <ajinkyashukla02@gmail.com>
*/

#include<iostream>

using namespace std;

void split(int*,int*,int,int);
void merge(int*,int*,int,int,int);

int main() {

	int n;

	cout << "Enter the number of integers to be sorted: ";

	cin >> n;

	int a[n];
	int b[n];

	cout << "Enter the integers: ";
	
	for(int i=0;i<n;i++) 
		cin >> a[i];

	split(a,b,0,n-1);

	cout << "Sorted Integers: ";

	for(int i=0;i<n;i++)
		cout << a[i];

	return 0;
}

void split(int* a,int* b,int p,int r) {

	int q=(p+r)/2;

	if(p<r) {
		split(a,b,p,q);
		split(a,b,q+1,r);
		merge(a,b,p,q,r);
	}

}

void merge(int* a,int* b,int p,int q,int r) {
	
	int i=0,j=p,l=p,k=q+1;
	
	while(j<=q && k<=r) 
		if(a[j]<a[k])
			b[p++]=a[j++];
		else
			b[p++]=a[k++];

	if(k>r)
		for(i=j;i<=q;i++)
			b[p++]=a[j++];

	if(j>q) 
		for(i=k;i<=r;i++) 
			b[p++]=a[k++];
	
	for(i=l;i<=r;i++) 
		a[i]=b[i];

}

