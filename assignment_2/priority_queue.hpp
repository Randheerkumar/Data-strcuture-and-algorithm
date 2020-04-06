/**
 *
 * CS202 - Data Structures and Algorithms
 * Assignment 2
 *
 * @author: Priyansh Saxena
 */ 

#ifndef PQ_HPP
#define PQ_HPP 1
  
#include "seqLinearList.hpp"

/*
 * This class must implement a max-heap.
 *
 * The underlying container to be used for storing the elements
 * of heap must be seqLinearList from the previous assignment.
 * 
 */
template<class T>
class priority_queue {
    
  LinearList<T> container;
  unsigned int size;
    int temp;
  public:

  /*
   * Default contructor.
   * Should construct an empty priority_queue.
   * Size of the created priority_queue should be zero.
   */
   priority_queue(){
    size=0;
    temp=1000;
    LinearList<T> container(temp);

   }

  /*
   * Copy constructor.
   * Creates a new priority_queue which is a copy of the provided priority_queue.
   */
   priority_queue(const priority_queue<T> & x);

   /*
    * Destructor.
    * Frees all the memory acquired by the priority_queue.
    */
    ~priority_queue(){

    }

   /*
    * Returns the number of elements in the priority_queue.
    */
    inline int length();

   /*
    * Returns a boolean indicating whether the priority_queue is empty.
    */
    inline bool empty();

   /*
    * Gets the top-element of the priority-queue.
    */
    T top();

   /*
    * Inserts a new element in the priority_queue.
    */
    void push(int k);

   /*
    * Removes the top-element from the priority_queue.
    */
    void pop();



    /***********************************
     *
     **     Bonus Marks Question      **
     *
     **********************************/
   /*
    * Exchanges the contents of the container adaptor by those of x, 
    * swapping both the underlying container value 
    * and their comparison function using the corresponding swap non-member functions (unqualified).
    * 
    */
    void swap (priority_queue& x); // noexcept;
     
};
template<class T>
priority_queue<T> ::priority_queue(const priority_queue<T> & x){
 
    container=intobj2;

}

template<class T>
inline int priority_queue<T> ::   length(){
  int t;
  t= container.length();
  return t;
}

template<class T>
void priority_queue<T> :: push(int k){
  int len;
  len=length();
  //len--;
  container.insert(len,k);
  container.Max_heapify(1,len);

}


template<class T>
void priority_queue<T> :: pop(){
  int temp,len,last;
  // cout<<"u are in pop function\n";
  //temp=container.returnListElement(1);
  //cout<<temp;
  len=length();
 // cout<<"u are in pop function\n";
    last=container.returnListElement(len);
  //cout<<"last element is given by "<<last<<"\n";

  container.insert(0,last);

}

template <class T>
T priority_queue<T> :: top(){
  T tp;
  int k;
  tp=0;
  //cout<<"you are in top function\n";
  tp=container.returnListElement(1);
  //cout<<"top is in top:"<<tp;
  return tp;

}


#endif
