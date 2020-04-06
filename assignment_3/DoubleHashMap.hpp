/*
 * DoubleHashMap.hpp
 *
 * This is an interface for a hash table using Double Hashing.
 */

#ifndef DOUBLEHASHMAP_HPP_
#define DOUBLEHASHMAP_HPP_

using namespace std;
namespace cs202
{
template<class Key, class Value>
class DoubleHashMap  : public Dictionary<Key,Value>
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
     * Constructor: DoubleHashMap
     * Creates a Double Hash Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	DoubleHashMap();
    /*
     * Constructor:DoubleHashMap
     * Creates an empty Double Hash Map with the ability to hold atleast num Key value pairs.
     */
	DoubleHashMap(const int& num);
    /*
     * Constructor: Double Hash Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	DoubleHashMap(DoubleHashMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~DoubleHashMap(){};
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * DoubleHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key);
    virtual bool has(const Key& key);
    virtual void remove(const Key& key);
    virtual Value get(const Key& key);
    virtual void put(const Key& key, const Value& value);
    int hash(int KEY){
        return(KEY%mod);

     }
};
template<class Key,class Value>
DoubleHashMap<Key,Value> :: DoubleHashMap(){
    
}
template<class Key,class Value>
DoubleHashMap<Key,Value> ::DoubleHashMap(const int& num){
    size=num;
    mod=num;
    hashTable=new Key[size];
    data=new Value[size];
    for(int i=0; i<size; i++){
        hashTable[i]=-1;
    }

}
template<class Key,class Value>
DoubleHashMap<Key,Value> ::DoubleHashMap(DoubleHashMap<Key, Value>& ht){
               size=ht.size;
               mod=ht.mod;
               hashTable=new Key[size];
               data=new Value[size];
               for(int i=0; i<size; i++){
               hashTable[i]=ht.hashTable[i];
    }

}
template<class Key,class Value>
 bool DoubleHashMap<Key,Value> ::has(const Key &key){
       int index ,i=0;
       int count=0,prob;
       index=hash(key);
       prob=mod-index;
       while(hashTable[index]!=key){
       index=(index+i*prob)%mod;
      i++;
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
void DoubleHashMap<Key,Value> :: remove(const Key& key){
     int index,prob;
    int count=0,i=0;
    index=hash(key);
    prob=mod-index;
    while(hashTable[index]!=key){
        index=(index+i*prob)%mod; i++;
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
Value DoubleHashMap<Key,Value> ::get(const Key& key){
    int index ,i=0;
    int count=0,prob;
    index=hash(key);
    prob=mod-index;
    while(hashTable[index]!=key){
        index=(index+i*prob)%mod; i++;
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
void DoubleHashMap<Key,Value> :: put(const Key& key, const Value& value){
    int KEY=key,res=0,prob;
    //cout<<KEY<<endl;
    res=get(KEY);
    int index =hash(KEY);
    prob=mod-index;
    int count=0,i=0;
    if(res==-1){
      while(hashTable[index]!= (-1 ) && hashTable[index]!= -2){
            index=(index+i*prob)%mod;
            count++; i++;
             if(count>size){
                rehash();
               // cout<<"size is :"<<size<<endl;
                count=0;
            //return ;
            }
        }
        hashTable[index]=key;
        data[index]=value;
    }
    else{
        while(hashTable[index]!=key){
        index=(index+ i*prob)%mod; i++;
        }
        data[index]=value;
    }


}
template<class Key,class Value>
Value& DoubleHashMap<Key,Value> :: operator[](const Key& key){

}

}
//cs202 :: DoubleHashMap<int,int> obj(11);
#endif 
