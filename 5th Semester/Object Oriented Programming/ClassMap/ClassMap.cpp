#include <iostream>

template<typename K, typename V>

class Map
{
    private:
    struct Element
    {
        K key;
        V value;
        int index;
    };
    public:
    Map();
    Map(K,V);
    int count();
    V find(K);
    K find(V);
    void insert(V);
    void delete_element(K);
    void begin();
    void end();
    V operator[K];  
};