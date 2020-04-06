#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP

#include <iostream>
#include <cstring>

using namespace std;

template<class Item>
class LinearList{

	private:
		int MaxSize;
		Item *element;    // 1D dynamic arrayr


		int len;
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList(){
                    MaxSize=0;
                    len=0;
                   };

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList( int& MaxListSize){
                     MaxSize=MaxListSize;
                     cout<<"u have entered"<<MaxSize<<endl; 
                     cout<<"please enter the element of the list"<<endl;
                     element=new Item[MaxSize];
                    *element=0;
                     len=0;
                }

		/* Destructor. 
		 * Must free all the memory contained by the list */
		//~LinearList();

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i){          //return i'th element of list
                        if (i>len-1)
                         cout<<"index is out of range"<<endl;
                        else return *(element+i);
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
		Item  returnListElement(const int k){
                       
                 };

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x);

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x);

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x);

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x){
                      element[k]=x;
                      len++;
                      cout<<k<<"len is "<<len<<"   "<<*(element+k)<<endl;
                }
};

#endif
