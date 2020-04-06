#include<iostream>
#include <cstdio>
#include "GraphAdjacencyBase.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
//void work(int&){}

#include "DirectedGraph.hpp"
#include "UndirectedGraph.hpp"

using namespace std;

int main(){
	char ch,c,sw;
	int a,b,n,valid=0;
	cout<<"enter m:for adjecency_matrix\n or l:for adjacency_list\n";
	cin>>ch;
	cout<<"enter maximum number of vertices\n";
        cin>>n;
    cout<<"enter your choice\n u: for undirected graph\n d: for directed graph\n";
    cin>>sw;
    switch(sw){
    	case 'u':valid=1;
    	         break;
    	case 'd':valid=0;
    	         break;
    	default: cout<<"u have wrong choice\n";
    	         return 0;
    	         break;

    }
       // cout<<"object is gonna create\n";
        //AdjacencyList obj(n);
    //AdjacencyList obj2(n);
    DirectedGraph obj(n,ch);
    UndirectedGraph obj_u(n,ch);
    UndirectedGraph objc(obj_u);


    if(valid==0){

	      cout<<"please enter the edges\n";
	      do{
		       scanf("%d%d%c",&a,&b,&c);
		       obj.add(a,b);
	        }while(c !='\n');
	      cout<<"enter the edges you want to search\n";
	      cin>>a>>b;
	      cout<<obj.edgeExists(a,b)<<endl;
	      cout<<"enter the edges you want to remove\n";
	      cin>>a>>b;
	      obj.remove(a,b);
	      cout<<"no of vertices is\n"<<obj.vertices()<<endl;
	      cout<<"total edge is:\t";
	      obj.edges();
	     /*cout<<"enter vertex for degree calculation\n";
	     cin>>a;
	     cout<<obj.degree(a)<<endl; */
	     cout<<"enter the edges you want to search\n";
	     cin>>a>>b;
	     cout<<obj.edgeExists(a,b)<<endl;
    }
   else{
      	 cout<<"please enter the edges\n";
	      do{
		       scanf("%d%d%c",&a,&b,&c);
		       obj_u.add(a,b);
	        }while(c !='\n');
	      cout<<"enter the edges you want to search\n";
	      cin>>a>>b;
	      cout<<obj_u.edgeExists(a,b)<<endl;
	      cout<<"enter the edges you want to remove\n";
	      cin>>a>>b;
	      obj_u.remove(a,b);
	      cout<<"no of vertices is\n"<<obj_u.vertices()<<endl;
	      cout<<"total edge is:\t"<<endl;
	      obj_u.edges();
	     /*cout<<"enter vertex for degree calculation\n";
	     cin>>a;
	     cout<<obj.degree(a)<<endl; */
	     cout<<"enter the edges you want to search\n";
	     cin>>a>>b;
	     cout<<obj_u.edgeExists(a,b)<<endl;

   }

	return 0;
}