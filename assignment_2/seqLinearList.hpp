#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP

#include <iostream>
#include <cstring>

using namespace std;

template<class Item>
class LinearList{

	private:
		int MaxSize;
		Item *element;    // 1D dynamic elementay


		int len;
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList(){
                    MaxSize=0;
                    len=0;
                   };
        LinearList( int& MaxListSize);           

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList(){
                     //delete []element;
                  }

                   
		/* Indexing operator.
     		 * It should behave the same way elementay indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i){          //return i'th element of list
                        if (i>MaxSize)
                         cout<<"index is out of range"<<endl;
                        else return element[i];
                 }; 
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty(){
                  if (*element==0) return true;
                   else return false;
                 };

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length(){
                        return len;
                 };

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize(){
                    return MaxSize;
                  };

		/* Returns the k-th element of the list. 
		 * */
		int  returnListElement(const int k){
			       return(element[k]);              
                 };

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x){
			if(x==element[k])
                         return true;
                        else
                       return false;
		}

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x){
			int k=len;
			while(k>=0){
				if(element[len]==x) 
                                return k;
				k--;
			}
			return 0;
		};

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x){
			element[k]=x;

		};

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x){
			          len++;
                int index=k;
                index++;
                //k++;
                      element[index]=-10000;
                      heap_increase_key(index,x);

                }
   void heap_increase_key(int size, int key);
   void  Max_heapify(int i,int heapsize);
      
               
};

template<class Item>
 LinearList<Item>:: LinearList( int& MaxListSize){
                     MaxSize=MaxListSize;
                     element=new Item[MaxSize];
                    *element=0;
                     len=0;
                }
template<class Item>
void LinearList<Item> :: heap_increase_key(int size, int key){
          int temp;
          element[size]=key;
          while(size>1 && element[size/2]<element[size]){
               temp=element[size];
               element[size]=element[size/2];
               element[size/2]=temp;
               size=size/2;
          }
        }

template<class Item>      
void LinearList<Item> :: Max_heapify(int i,int heapsize){
    int l,r,largest;
    int temp;
    l=2*i ;
    r=2*i +1;
    if((l<= heapsize) && (element[l]>=element[i]) )
        largest=l;
    else largest=i;
    if((r<=heapsize) && (element[r]>element[largest]))
        largest=r;
    if(largest !=i){
         temp=element[i];
         element[i]=element[largest];
         element[largest]=temp;
         Max_heapify(largest,heapsize);
    }
} 
        int L=1000000;
LinearList<int> intobj2(L);

#endif
