#include<iostream>	
#include"seqLinearList.hpp"
#include"sorting.hpp"


	int main(){
    int n,i;
    char ch;
    int a=0,l=0,k;
    cout<<"please enter the number of element :"<<endl;
    cin>>n;
    LinearList<int> intobj(n);
    intobj.isEmpty();
    cout<<"enter the element"<<endl;
    for(i=0; i<n; i++)
    {    
         cin>>a;
   	      intobj.insert(i,a);
    }
   //cout<<endl<<intobj[2]<<endl;
   intobj.isEmpty();
   Sort<int> s;
   cout<<"please enter your choice\n";
   cout<<" b:for bubblesort\n h:for heapsort\n i: insertion sort \n r: for rank sort \n";
   cout<<" q:for quicksort\n and m:for mergesort\n";
   cin>>ch;
   switch(ch){
     case 'b' :  s.bubbleSort(intobj,l,n);
                 break;
     //case  'h' :  s.heapSort(intobj,l,n);
                  //break;

     case 'i'  :  s.insertionSort(intobj,l,n);
                 break;
     case 'm'  :  s.mergeSort(intobj,l,n);         

     case 'r' :   s.rankSort(intobj,l,n);
                  break;

     case 's' :    s.selectionSort(intobj,l,n);
                 break;

     //case 'q' :    s.quickSort(intobj,l,n);
                 //  break; 

     default:break;                        


   }

   //s.insertionSort(intobj,l,n);
   //s.selectionSort(intobj,l,n);
   //s.rankSort(intobj,l,n);
   //s.bubbleSort(intobj,l,n);
    


}
