#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"
using namespace std;

/*
 * 	Class AdjacencyMatrix
 *	Can be used to represent a Graph using adjacency-matrix.
 */
class AdjacencyMatrix : public GraphAdjacencyBase {
	
	int size;

	public:
		int **arr;
		AdjacencyMatrix(int vertices){
             int i=0,j=0;
             size=vertices;
              arr=new int*[vertices+1];
              for(i=0; i<=vertices; i++)
              	{
              		arr[i]=new int[vertices+1];
              		for(j=0; j<=vertices; j++)
              			arr[i][j]=0;
              	}

		};
		~AdjacencyMatrix(){};
	bool edgeExists(int i,int j);
	int vertices();
	int edges();
	void add(int i,int j);
	void remove(int i,int j);
	int degree(int i);
	
};
void AdjacencyMatrix :: add(int i,int j){
         arr[i][j]=1;
}
bool AdjacencyMatrix :: edgeExists(int i,int j){
            if(arr[i][j]==1){
            	return true;
            }
            return false;
}
int AdjacencyMatrix :: vertices(){

}
int AdjacencyMatrix :: edges(){
            int i,j,count=0;
            for(i=0; i<=size; i++){
            	for(j=0;  j<=size; j++)
            		if(arr[i][j])
            			count++;
            }
            return count;
}

int AdjacencyMatrix :: degree(int i){
    
}
void AdjacencyMatrix ::  remove(int i,int j){
  arr[i][j]=0;
}
	


	

#endif /* ifndef ADJACENCY_MATRIX */
