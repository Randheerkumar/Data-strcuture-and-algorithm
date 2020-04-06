/*
 * ChainedMap.hpp
 *
 */

#ifndef CHAINEDMAP_HPP_
#define CHAINEDMAP_HPP_
using namespace std;
namespace cs202
{
 

template<class Key, class Value>
class ChainedMap  : public Dictionary<Key,Value>
{
    /*
     * Function rehash:
     * Resizes the hash table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash();
public:
    struct node{
    Key key;
    Value value;
    struct node *next;
   };

    struct node **arr;
    Key *hashTable;
    int mod,size;
    /*
     * Constructor: ChainedMap
     * Creates a Chained Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	ChainedMap();
    /*
     * Constructor:ChainedMap
     * Creates an empty Chained Map with the ability to hold atleast num Key value pairs.
     */
	ChainedMap(const int& num);
    /*
     * Constructor: Chained Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	ChainedMap(ChainedMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~ChainedMap(){

    };
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * ChainedHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key){};
    virtual bool has(const Key& key);
    virtual void remove(const Key& key);
    virtual Value get(const Key& key);
    virtual void put(const Key& key, const Value& value);
    int hash(int KEY){
        return(KEY%mod);
     }
};
template<class Key, class Value>
ChainedMap<Key,Value> :: ChainedMap(){

}

template<class Key, class Value>
ChainedMap<Key,Value> :: ChainedMap(const int& num){
    size=num;
    mod=num;
    arr=new  node*[size];
    //data=new Value[size];
    for(int i=0; i<size; i++){
        arr[i]=NULL;
    }
}

template<class Key, class Value>
ChainedMap<Key,Value> :: ChainedMap(ChainedMap<Key, Value>& ht){
    size=ht.size;
               mod=ht.mod;
               arr=new node*[size];
               //data=new Value[size];
               for(int i=0; i<size; i++){
               arr[i]=ht.arr[i];
    }

}

template<class Key, class Value>
void ChainedMap<Key,Value> ::put(const Key& key, const Value& value){
                 int hashKey,result=1;
                 struct node *temp=new(struct node);
                 struct node *last=new(struct node);
                 hashKey=hash(key);
                 temp=arr[hashKey];
                 result=has(key);

           if(result==0){
                 if(temp==NULL){
                  struct node *head;
                  head=new (struct node );
                  arr[hashKey]=head;
                  head->key=key;
                  head->value=value;
                  head->next=NULL;
                }
                else{
                    if(temp->next != NULL){
                        while(temp->next !=NULL){
                            temp=temp->next;
                        }
                    }   
                        temp->next=last;
                        last->key=key;
                        last->value=value;
                        last->next=NULL; 
                  }
           }
          else{

             while(temp->key!=key){
              temp=temp->next;
           }
             temp->value=value;      
         }
               

}
template<class Key, class Value>
bool ChainedMap<Key,Value> :: has(const Key& key){
    int index;
    struct node *temp= new(struct node);
    index=hash(key);
    temp=arr[index];
    if(temp==NULL)
        return false;
    while(temp->key!=key){
        if(temp->next==NULL){
            //cout<<"GIVEN ELEMENT IS NOT FOUND\n";
            return false;
        }
        temp=temp->next;
    }
        //cout<<"GIVEN ELEMENT IS  FOUND\n";
        return true;


}
template<class Key, class Value>
void ChainedMap<Key,Value>:: remove(const Key& key){
    int index;
    struct node *temp=new(struct node);
    struct node *prev_temp=new(struct node);
    index=hash(key);
    temp=arr[index];
    if(temp==NULL){
        return ;
    }
    prev_temp=temp;
    if(temp->key==key){
        arr[index]=temp->next;

    }
    else
    {
        while(temp->key!=key){
            if(temp->next==NULL){
                return ;
            }
            prev_temp=temp;
            temp=temp->next;
        }
    prev_temp->next=temp->next;
    }


}
template<class Key,class Value>
Value ChainedMap<Key,Value> :: get(const Key& key){

    int index;
    struct node *temp= new(struct node);
    index=hash(key);
    temp=arr[index];
    if(temp==NULL)
        return false;
    while(temp->key!=key){
        if(temp->next==NULL){
            cout<<"GIVEN ELEMENT IS NOT FOUND\n";
            return -1;
        }
        temp=temp->next;
    }
        cout<<"GIVEN ELEMENT IS  FOUND\n";
        return temp->value;


}












}




#endif /* CHAINEDMAP_HPP_ */
