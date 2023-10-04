#include <map>

class MyHashMap {
public:
        map<int,int> temp;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
   
            temp[key]=value;
        
    }
    
    int get(int key) {
        if(temp.find(key)!=temp.end()) return temp[key];
        return -1;
    }
    
    void remove(int key) {
        temp.erase(key);
    }
};