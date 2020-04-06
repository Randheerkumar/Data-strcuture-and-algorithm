#include<iostream>
#include<cstdio>


using namespace std;

struct node{
	 int data;
     int value;
	 struct node *next;
};

int hash(int,int);
void hashChainInsert(int,  struct node**,int ,int );
void disp(struct node**);
int hashDelete(int data,struct node *d_arr[]);
int hashSearch(int data,struct node *d_arr[]);
void linearDelete(int data, int size,int arr[]);
void linearInsert(int data, int size,int arr[],int value,int inf[]);
int linearSearch(int data, int size,int arr[],int inf[]);
void doubleDelete(int data, int size,int arr[]);
int doubleSearch(int data, int size,int arr[],int inf[]);
void doubleInsert(int data, int size,int arr[],int value,int inf[]);


int valid=1,M,maxOffset;
int main(){
	int m,data,value,del,user[100],i=0,hashValue,choice,size;
	char ch,a;
	cout<<"please enter the size of hash table\n";
	        cin>>m;
	        M=m;
	        struct node  *hashTable[m]={NULL};
     size=m;
    int tablesize[size],m_arr[M];

	cout<<"please enter your choice\n1:chain hashing,   2:linear probing,   3:double hashing\n";
    cin>>choice;
    switch(choice)
	{   
	   case 1:
		    cout<<"i: for insertion\ns: for searching\nd: for deleting\ne: for exit\np: for printing";
		    while(cin>>a){
    			switch(a){
    				case 'i':do{
							scanf("%d%d%c",&data,&value,&ch);
							hashValue=hash(data,m);
						    hashChainInsert(hashValue,&hashTable[0],data,value);
   				            }while(ch!='\n');
    	        			break;

    				case 's':cout<<"enter the number u want to search\n";
    		         		cin>>del;
                     		cout<<hashSearch(del,hashTable)<<endl; ;
    	        			break;

    				case 'd':cout<<"enter the number u want to delete\n";
    		        	    cin>>del;
    		        	 	hashDelete(del,hashTable);
    	         			break;

    	   	    	case 'p':disp(&hashTable[0]);
    	                     break;    	
    				case 'e': return 0;   

            		default: cout<<"u have enter wrong choice\n";                         

   			 	}
   		  		cout<<"again enter your choice\n";
  	   	    }
  	        break;
  	   case 2:cout<<"please enter the key and element u want to insert\n";
  	                for(i=0; i<size; i++){
  	                	tablesize[i]=-1;          // initialization of array;
  	                }
  	                do{
							scanf("%d%d%c",&data,&value,&ch);
							linearInsert(data,size,tablesize,value,m_arr);
   				       }while(ch!='\n');
                cout<<"please enter your choice\n";
                cout<<"i: for insertion\ns: for searching\nd:for deleting\ne: for exit\n" ;
                while(cin>>a){
                switch(a){
                	case 'i':cout<<"enter the key and elment u want to insert\n";
                	         cin>>data>>value;
                	         linearInsert(data,size,tablesize,value,m_arr);
                	         break;
                	case 's':cout<<"enter the elment u want to search\n";
                	         cin>>data;
                	         cout<<linearSearch(data,size,tablesize,m_arr)<<endl;
                	         break;

                	case 'd':cout<<"enter the elment u want to delete\n";
                	         cin>>data;
                	         linearDelete(data,size,tablesize);
                	         break;

                	case 'e': return 0;
                	default : cout<<"wrong choice , enter agian\n";
                }
            }
  	         break;
  	   case 3:cout<<"inter the maximum size of offset\n";
  	          cin>>maxOffset;
  	          cout<<"please enter the key and value u want to insert\n";
  	                for(i=0; i<size; i++){
  	                	tablesize[i]=-1;          // initialization of array;
  	                }
  	                do{
							scanf("%d%d%c",&data,&value,&ch);
							doubleInsert(data,size,tablesize,value,m_arr);
   				       }while(ch!='\n');
                cout<<"please enter your choice\n";
                cout<<"i: for insertion\ns: for searching\nd:for deleting\ne: for exit\n" ;
                while(cin>>a){
                switch(a){
                	case 'i':cout<<"enter the key and elment u want to insert\n";
                	         cin>>data>>value;
                	         doubleInsert(data,size,tablesize,value,m_arr);
                	         break;
                	case 's':cout<<"enter the key u want to search\n";
                	         cin>>data;
                	         cout<<doubleSearch(data,size,tablesize,m_arr)<<endl;
                	         break;

                	case 'd':cout<<"enter the key u want to delete\n";
                	         cin>>data;
                	         doubleDelete(data,size,tablesize);
                	         break;

                	case 'e': return 0;
                	default : cout<<"wrong choice , enter agian\n";
                }
            }
  	           break;
  	   default:  cout<<"u have entered wrong choice\n";
  	             return 0;
 }    


 

}
void hashChainInsert(int hashKey,struct node *arr[],int data,int value){
	           struct node *temp=new(struct node);
	           struct node *last=new(struct node);
	           if(valid==1){
	            //int size=sizeof(*arr)/sizeof(struct node);
	            //cout<<"size of array is:"<<size<<" ";
	           /* for(int i=0; i<M; i++){
	            	cout<<arr[i]<<"  ";
	            }*/
	            valid++;
	           }
	           temp=arr[hashKey];
	           if(temp==NULL){
	           	  struct node *head;
                  head=new (struct node );
                  arr[hashKey]=head;
                  head->data=data;
                  head->value=value;
                  head->next=NULL;
                }
                else{
                	if(temp->next!=NULL){
                		while(temp->next !=NULL){
                			temp=temp->next;
                		}
                	}	
                		temp->next=last;
                		last->data=data;
                        temp->value=value;
                		last->next=NULL;
                }

}
int hashDelete(int data,struct node *d_arr[]){
	int key;
	struct node *temp=new(struct node);
	struct node *prev_temp=new(struct node);
	key=hash(data,M);
	temp=d_arr[key];
	if(temp==NULL){
		return 0;
	}
	prev_temp=temp;
	if(temp->data==data){
		d_arr[key]=temp->next;

	}
	else
	{
		while(temp->data!=data){
			if(temp->next==NULL){
				return 0;
			}
			prev_temp=temp;
			temp=temp->next;
		}
	prev_temp->next=temp->next;
    }


}
int hash(int data,int m){
	return(data%m);
}
void disp(struct node *hashTable[]){
	   struct node *temp;
    for(int j=0; j<M; j++)
    {
    	temp=hashTable[j];
    	cout<<"\n"<<"for j="<<j<<"::";
    	while(temp != NULL){
    		cout<<temp->data<<"  ";
    		temp=temp->next;
    	}


    }

}
int hashSearch(int data,struct node *d_arr[]){
	int key;
	struct node *temp= new(struct node);
	key=hash(data,M);
	temp=d_arr[key];
    if(temp==NULL){
        return -1;
    }
	while(temp->data!=data){
		if(temp->next==NULL){
			//cout<<"GIVEN ELEMENT IS NOT FOUND\n";
			return -1;
		}
		temp=temp->next;
	}
		//cout<<"GIVEN ELEMENT IS  FOUND\n";
        return (temp->value);


}

void linearInsert(int data, int size,int arr[],int value,int inf[]){
	int prob;
	int count=0;

	prob=hash(data,size);
    while(arr[prob]!= (-1 ) && arr[prob]!= -2){
    	prob=(prob+1)%size;
    	count++;
    	if(count>size){
    		cout<<"hash-table is over flow\nerror\n";
    		return ;
    	}
    }
    arr[prob]=data;
    inf[prob]=value;
}

void linearDelete(int data, int size,int arr[]){
	int prob;
	int count=0;
	prob=hash(data,size);
    while(arr[prob]!=data){
    	prob=(prob+1)%size;
    	count++;
    	if(count>size){
    		cout<<"elment is already not present\n";
    		return;
    	}
    }
    arr[prob]=-2;
}
int linearSearch(int data, int size,int arr[],int inf[]){
	int prob;
	int count=0;
	prob=hash(data,size);
    while(arr[prob]!=data){
    	prob=(prob+1)%size;
    	count++;
    	if(count>size){
    		cout<<"element is not found\n";
    		return -1;
    	}
    }
    cout<<"element is found\n";
    return(inf[prob]);
 }


void doubleInsert(int data, int size,int arr[],int value,int inf[]){
	int prob,offset;
	int count=0;
	prob=hash(data,size);
	offset=maxOffset-hash(data,maxOffset);
    while(arr[prob]!= (-1 ) && arr[prob]!= -2){
    	prob=(prob+offset)%size;
    	count++;
    	if(count>size){
    		cout<<"hash-table is over flow\nerror\n";
    		return ;
    	}
    }
    arr[prob]=data;
    inf[prob]=value;
}

void doubleDelete(int data, int size,int arr[]){
	int prob,offset;
	int count=0;
	prob=hash(data,size);
	offset=maxOffset-hash(data,maxOffset);
    while(arr[prob]!=data){
    	prob=(prob+offset)%size;
    	count++;
    	if(count>size){
    		cout<<"elment is already not present\n";
    		return;
    	}
    }
    arr[prob]=-2;
}
int doubleSearch(int data, int size,int arr[],int inf[]){
	int prob,offset;
	int count=0;
	prob=hash(data,size);
	offset=maxOffset-hash(data,maxOffset);
    while(arr[prob]!=data){
    	prob=(prob+offset)%size;
    	count++;
    	if(count>size){
    		cout<<"element is not found\n";
    		return -1;
    	}
    }
    cout<<"element is found\n";
    return(inf[prob]);
 }





































