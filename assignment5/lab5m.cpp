#include<iostream>
#include<cstdio>
//#include"AdjacencyList.hpp"
#include "GraphAdjacencyBase.hpp"
#include"AdjacencyMatrix.hpp"
//#include"AbstractGraph.hpp"

using namespace std;

int main(){
        int a,b,n;
        char ch;
        cout<<"enter maximum number of vertices\n";
        cin>>n;
       // cout<<"object is gonna create\n";
        AdjacencyMatrix obj(n);
	cout<<"please enter the edges\n";
	do{
		scanf("%d%d%c",&a,&b,&ch);
		obj.add(a,b);
	}while(ch !='\n');
	cout<<"enter the edges you want to search\n";
	cin>>a>>b;
	cout<<obj.edgeExists(a,b)<<endl;
	cout<<"enter the edges you want to remove\n";
	cin>>a>>b;
	obj.remove(a,b);
	cout<<"no of edgess is :\t"<<obj.edges()<<endl;
	//cout<<"enter a vertex for degree calculation\n";
	//cin>>a;
	//cout<<obj.degree(a)<<endl;
	cout<<"enter the edges you want to search\n";
	cin>>a>>b;
	cout<<obj.edgeExists(a,b)<<endl; 


	


return 0;
}
