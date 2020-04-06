/*
 * OpenMap.hpp
 *
 *This is a Hash Table interface using Linear indexing
 */

#ifndef OPENMAP_HPP_
#define OPENMAP_HPP_
using namespace std;
namespace cs202
{
//#include"Dictionary.hpp"
template<class Key, class Value>
class OpenMap  : public Dictionary<Key,Value>
{

    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash(){
       int i=0;
        Key temp1[mod];
        Value temp2[mod];
        for(i=0; i<mod; i++){
            temp1[i]=hashTable[i];
            temp2[i]=data[i];
        }
        hashTable=new Key[mod+1];
        data=new Value[mod+1];
        for(i=0; i<mod; i++){
            hashTable[i]=temp1[i];
            data[i]=temp2[i];
        }
         hashTable[mod]=-1;
        mod=mod+1;
        size=size+1;
        };
public:
    int size;
    Key *hashTable;
    Value *data;
    int mod;
    /*
     * Constructor: OpenMap
     * Creates a Open Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	OpenMap();
    /*
     * Constructor:OpenMap
     * Creates an empty Open Map with the ability to hold atleast num Key value pairs.
     */
	OpenMap(const int& num);
    /*
     * Constructor: Open Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	OpenMap(OpenMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~OpenMap(){
    };
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * OpenMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key);
     bool has(const Key& key);
     void remove(const Key& key);
     Value get(const Key& key);
     void put(const Key& key, const Value& value);
     int hash(int KEY){
       // cout<<KEY<<"AND   "<<m<<endl;
        return(KEY%mod);

     }
};
template<class Key,class Value>
OpenMap<Key,Value> :: OpenMap(){
    
}
template<class Key,class Value>
OpenMap<Key,Value> ::OpenMap(const int& num){
    size=num;
    mod=num;
   // cout<<"u are in pac cons  "<<size<<endl;
    hashTable=new Key[size];
    data=new Value[size];
    for(int i=0; i<size; i++){
        hashTable[i]=-1;
    }

}
template<class Key,class Value>
OpenMap<Key,Value> ::OpenMap(OpenMap<Key, Value>& ht){
               size=ht.size;
               mod=ht.mod;
               hashTable=new Key[size];
               data=new Value[size];
               for(int i=0; i<size; i++){
               hashTable[i]=ht.hashTable[i];
    }

//cout<<"u are in copy cons  "<<size<<endl;
}
template<class Key,class Value>
 bool OpenMap<Key,Value> ::has(const Key &key){
       int index ;
       int count=0;
       index=hash(key);
       while(hashTable[index]!=key){
       index=(index+1)%mod;
       count++;
      if(count>size){
            //cout<<"key is not found\n";
            return false;
        }
    }
    //cout<<"element is found\n";
    return true;

}
template<class Key,class Value>
void OpenMap<Key,Value> :: remove(const Key& key){
     int index;
    int count=0;
    index=hash(key);
    while(hashTable[index]!=key){
        index=(index+1)%mod;
        count++;
        if(count>size){
            cout<<"key is not found\n";
            return ;
        }
    }
    hashTable[index]=-2;
    data[index]=0;
    
   

}

template<class Key,class Value>
Value OpenMap<Key,Value> ::get(const Key& key){
    int index ;
    int count=0;
    index=hash(key);
    while(hashTable[index]!=key){
        index=(index+1)%mod;
        count++;
        if(count>size){
            //cout<<"key is not found\n";
            return -1;
        }
    }
    //cout<<"element is found\n";
    return data[index];
 }

template<class Key,class Value>
void OpenMap<Key,Value> :: put(const Key& key, const Value& value){
    //cout<<"u are in put\n";
    int KEY=key,res=0;
    //cout<<KEY<<endl;
    res=get(KEY);
    int index =hash(KEY);
    int count=0;
    if(res==-1){
      while(hashTable[index]!= (-1 ) && hashTable[index]!= -2){
            index=(index+1)%mod;
            count++;
             if(count>size){
                rehash();
                cout<<"size is :"<<size<<endl;
                count=0;
            //return ;
            }
        }
        hashTable[index]=key;
        data[index]=value;
    }
    else{
        while(hashTable[index]!=key){
        index=(index+1)%mod;
        }
        data[index]=value;
    }


}
template<class Key,class Value>
Value& OpenMap<Key,Value> :: operator[](const Key& key){

}

}
//cs202 :: OpenMap<int,int> obj(11);
#endif 
