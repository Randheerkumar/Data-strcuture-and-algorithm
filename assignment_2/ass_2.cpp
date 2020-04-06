#include<iostream>
//#include<list.hpp>
#include"priority_queue.hpp"


using namespace std;

int main(){
	int N,M,i,a;
	long long sum=0,temp;
	cout<<"enter the number of rows and fans\n";
	cin>>N>>M;
	LinearList<int> intobj(N);                                            //passing argument in the constuuctor
	cout<<"enter the number of seats vecant in corresponding row\n";
	for(i=0; i<N; i++){
		cin>>a;
		intobj2.insert(i,a);
	}
priority_queue<int> heapobj;
priority_queue<int> objcon(heapobj);
//int t1=intobj.length();
//cout<<t1<<endl;
//heapobj.length();
//temp=intobj2.returnListElement(0);
//cout<<temp<<endl;
temp=objcon.top();
//cout<<"top is :"<<temp;
i=M;
while(M>0){
      temp=objcon.top();
      objcon.pop();
      sum =sum+temp;
      temp--;
      objcon.push(temp);
      M--;
 cout<<"temp sum is:"<<sum<<endl;
}
//intobj2.print();

cout<<"sum is equal to "<<sum<<endl;

return 0;
}