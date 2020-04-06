#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1

#include "AbstractGraph.hpp"


/*
* A class to represent an UndirectedGraph
* Subclasses AbstractGraph
*/
class UndirectedGraph : public AbstractGraph {

	GraphAdjacencyBase *base;
		
 	public:
    struct node{
      int data;
      struct node   *next;
    };
    struct node *front=NULL;
    struct node *rear=NULL;
    

  	/*
   	* Constructor: UndirectedGraph
   	*
   	* Parameters: mode
   	* Used to decide which representation to use
   	* 'm' for AdjacencyMatrix
   	* 'l' for AdjacencyList
   	*/
  	UndirectedGraph(int vertices, char mode);
  	/*
  	* Destructor
  	*/
  	~UndirectedGraph(){}; 
   void work(int&){}
   void dfs(void (*work)(int&));
   void bfs(void (*work)(int&));
   bool edgeExists(int i,int j);
   int vertices();
   int edges();
   void add(int i,int j);
   void enqueue(int v);
   int dequeue();
   void remove(int i,int j);
   
  	
	};//AdjacencyList obj(vex);
UndirectedGraph :: UndirectedGraph(int numVertices, char rep){
                 if(rep=='m')
                  base=new AdjacencyMatrix(numVertices);
                 else
                  base= new AdjacencyList(numVertices);
}
void UndirectedGraph :: dfs(void (*work)(int&)){

}
void UndirectedGraph :: bfs(void (*work)(int&)){
             struct node* w;
              struct node *temp;
              int count=0,v,n;
               n=base->vertices();
               int visited[n+2]={0};
              for(int i=1; i<=n; i++){
              front = rear = NULL;
              //printf("%d\n",v);
              while(visited[i] )
                i++;
              visited[i] = 1;
              enqueue(i);
              count++;
              while(front)
              {
                v = dequeue();
                temp=vex.vertex[v];
                for(w = temp; w; w = w->next)
                {
                   if(!visited[w->data])
                  {
                      printf("%d\n",w->data);
                      enqueue(w->data);
                     visited[w->data] = 1;
                  }
                }
              }
            }
            cout<<"no of black shapes are: "<<count<<endl;
}
bool UndirectedGraph :: edgeExists(int i,int j){
                      base->edgeExists(i,j);
}
int UndirectedGraph :: vertices(){
                       base->vertices();
}
int UndirectedGraph :: edges(){
                     int n;
                     n=base->edges();
                     cout<<n/2<<endl;
}
void UndirectedGraph :: add(int i,int j){
                      base->add(i,j);
                      base->add(j,i);
}
void UndirectedGraph :: remove(int i,int j){
                  base->remove(i,j);
                  base->remove(j,i);
}


void  UndirectedGraph :: enqueue(int v)
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
int  UndirectedGraph :: dequeue()
{
  struct node* temp;
  int v;
  temp = front;
  v = temp->data;
  front = temp->next;
  free(temp);
  return v;
}


#endif /* ifndef UNDIRECTED_GRAPH */
