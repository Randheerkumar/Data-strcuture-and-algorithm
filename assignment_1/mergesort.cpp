#include<iostream>
  using namespace std;
void merge(int arr[],int low,int middle,int high);
void mergesort(int arr[],int low,int high);
void show(int a[]);
  int main(){
  	int arr[10],i,j;
  	cout<<"enter the elment of the array\n";
  	for(i=0; i<10; i++){
  		cin>>arr[i];
  	}
  	mergesort(arr,0,9);
  	show(arr);


  }
 void mergesort(int arr[],int low,int high) {
 	int i,middle;
 	if(low<high){
 		middle=(low+high)/2;
 		mergesort(arr,low,middle);
 		mergesort(arr,middle+1,high);
 		merge(arr,low,middle,high);

 	}
 	
 }
 void merge(int arr[],int low,int middle,int high){
 	int m,n,i,j,k;
 	m=middle-low+1;
 	n=high-middle;
 	int left[m],right[n];

 	for(i=0; i<m; i++)
 		left[i]=arr[low+i];

 	for(j=0; j<n; j++)
 		right[j]=arr[middle+1+j];

 	i=0,j=0;k=low;
 	while(i<m && j<n){
 		if(left[i]<=right[j]){
 			arr[k]=left[i];
 			k++; i++;
 		}
 		else{
 			arr[k]=right[j];
 			k++;j++;
 		}
 	}
 	while(i<m){
 		arr[k]=left[i];
 		k++; i++;
 	}
 	while(j<n){
 		arr[k]=right[j];
 		k++; j++;
 	}
 }
 void show(int a[]){
 	int i;
 	for(i=0; i<10; i++)
 		cout<<a[i]<<"  ";
 }