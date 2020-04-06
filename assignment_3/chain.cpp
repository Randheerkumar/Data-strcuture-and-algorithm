#include<iostream>
#include<cstdio>
#include"Dictionary.hpp"
#include"ChainedMap.hpp"


using namespace std;

int main(){
	int data,key,temp,result;
	int size=13;
	char ch,a;
	cs202 :: ChainedMap<int,int> openob;
 
   cs202 :: ChainedMap<int,int> om1(size);
   cs202 ::ChainedMap<int,int> om2(om1);
   cout<<"please enter key and value\n";
   do{
		scanf("%d%d%c",&key,&data,&ch);
		om2.put(key,data);
   }while(ch!='\n');
   cout<<"please enter your choice\n";
                cout<<"i: for insertion\ns: for searching\nd:for deleting\ne: for exit\nk:for key-searching\n" ;
                while(cin>>a){
                switch(a){
                	case 'i':cout<<"enter the key and value \n";
                	         cin>>key>>data;
                	         om2.put(key,data);
                	         break;
                	case 's':cout<<"enter the key for searching \n";
                	         cin>>key;
                	         result=om2.get(key);
                	         if(result==-1)   cout<<"key is not found\n";
                	         else cout<<"value is: "<<result<<endl;
                	         break;

                	case 'd':cout<<"enter the key for deleting\n";
                	         cin>>key;
                	         om2.remove(key);
                	         break;
                	case 'k':cout<<"enter the key\n";
                	         cin>>key;
                	         cout<<om2.has(key);
                	         break;       

                	case 'e': return 0;
                	default : cout<<"wrong choice , enter agian\n";
                }
                cout<<"\nplease again enter your choice\n";
            }
 return 0;      	
}