#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"
#include<cstdlib>

/*
 * 	Class AdjacencyList
 *	Can be used to represent a Graph using adjacency-list.
 */
class AdjacencyList : public GraphAdjacencyBase {

	int size;

	public:
	struct node{
		int data;
		struct node *next;
	};
        struct node **vertex;
        AdjacencyList(){};
	AdjacencyList(int vertices){
            int i=0;
            size=vertices;
            vertex=new  node*[vertices];
            for(i=0; i<vertices; i++)
            	vertex[i]=NULL;
		
	};
	~AdjacencyList(){};
	bool edgeExists(int i,int j);
	int vertices();
	int edges();
	void add(int i,int j);
	void remove(int i,int j);
	int degree(int i);
   // struct node* addofarr(int v);
		  	
};  AdjacencyList vex;	
 bool AdjacencyList ::  edgeExists(int i, int j){
              struct node *temp;
              temp=vertex[i];
              while(temp){
              	if(temp->data==j)
              		return true;
              	temp=temp->next;
              }
              return false;
 }

 int AdjacencyList ::  vertices(){
            int i=0,count=0,flag[size]={0};
            struct node *temp;
            for(i=0; i<size; i++){
                 temp=vertex[i];
                 if(temp)
                 	if(flag[i]==0)
                 	{
                 		flag[i]=1;
                 		count++;
                 	}
                 while(temp){
                 	
                    if(flag[temp->data]==0){
                    	count++; 
                    	flag[temp->data]=1;
                    }

                    temp=temp->next;
                 }

            }
            return count;
 }
 int AdjacencyList :: edges(){
 	           int i=0,count=0;
            struct node *temp;
            for(i=0; i<size; i++){
                 temp=vertex[i];
                 while(temp){
                 	temp=temp->next;
                  count++;
                 }

            }
            return count;

 }
void AdjacencyList :: add(int i, int j){
	struct node *temp;
		temp=new(struct node);
		if(vertex[i]==NULL){
		vertex[i]=temp;
		temp->data=j;
		temp->next=NULL;
        }
        else{
             struct node *front;
              front=vertex[i];
               vertex[i]=temp;
               temp->data=j;
               temp->next=front;
             }
        
}

void AdjacencyList :: remove(int i, int j){
         struct node *temp=new(struct node);
         struct node *prev_temp=new(struct node);
         temp=vertex[i];
         prev_temp=temp;
         if(!temp)
         	return;
         else if(temp->data==j)
         {
         	vertex[i]=temp->next;
         }
         else{
         	while(temp->data != j){
         		prev_temp=temp;
         		temp=temp->next;
         	}
         	prev_temp->next=temp->next;
         }
                

}
int AdjacencyList :: degree(int i){
	struct node *temp;
	int count=0;
	temp=vertex[i];
	while(temp){
		temp=temp->next;
		count++;
	}
	return count;

}
/*struct node* AdjacencyList :: addofarr(int v){
  return vertex[v];
}*/









#endif /* ifndef ADJACENCY_LIST */
