#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "AbstractGraph.hpp"
#include "cstdlib"

/*
* A class to represent a directed graph.
*/
class DirectedGraph : AbstractGraph {
	
	GraphAdjacencyBase *base;
	
	public:
		struct node{
			int data;
			struct node   *next;
		};
		struct node *front=NULL;
		struct node *rear=NULL;
		
	/*
	 * Constructor: DirectedGraph
	 *
	 * Parameters: mode
	 * Used to decide which representation to use
	 * 'm' for AdjacencyMatrix
	 * 'l' for AdjacencyList
	 */
	DirectedGraph(int numVertices, char rep);
	/*
	 * Destructor
	 */
	~DirectedGraph(){};
	 void work(int&){}
	 void dfs(void (*work)(int&));
	 void bfs(void (*work)(int&));
	 bool edgeExists(int i,int j);
	 int vertices();
	 int edges();
	 void add(int i,int j);
	 void remove(int i,int j);
	 void enqueue(int v);
	 int dequeue();
	 //int degree(int i);
		
};
DirectedGraph :: DirectedGraph(int numVertices, char rep){
                 if(rep=='m')
                 	base=new AdjacencyMatrix(numVertices);
                 else
                 	base= new AdjacencyList(numVertices);
}
void DirectedGraph :: dfs(void (*work)(int&)){
                      
}
void DirectedGraph :: bfs(void (*work)(int&)){
                  
}
bool DirectedGraph :: edgeExists(int i,int j){
                      base->edgeExists(i,j);
}
int DirectedGraph :: vertices(){
                       base->vertices();
}
int DirectedGraph :: edges(){
	                int n;
                     n=base->edges();
                     cout<<n;
}
void DirectedGraph :: add(int i,int j){
                      base->add(i,j);
}
void DirectedGraph :: remove(int i,int j){
                  base->remove(i,j);
}
/*int DirectedGraph :: degree(int i){

}*/
void  DirectedGraph :: enqueue(int v)
{
	struct node* temp;
	temp = new (struct node);
	temp->data = v;
	temp->next = NULL;
	if(front)
		rear->next = temp;
	else
		front = temp;
	rear = temp; 
}
int  DirectedGraph :: dequeue()
{
	struct node* temp;
	int v;
	temp = front;
	v = temp->data;
	front = temp->next;
	free(temp);
	return v;
}



#endif /* ifndef DIRECTED_GRAPH */
