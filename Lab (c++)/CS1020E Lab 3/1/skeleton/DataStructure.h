#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
#include <string>

using namespace std;

class BallList {
private:
    struct Ball {
        int value;
        Ball *p_next;
        Ball *p_prev;
    };
    int _size;
    Ball *_head;
    Ball *traverse(int index);
public:
    //constructor
    BallList();
    
    //method functions
    void insert(int num);
    int search(int num);
    void erase(int num);
    void check(string action, int x, int y);
    void change(string action, int x, int index);
    string print();
    
    //getters
    int getLength() {return _size;}
};


#endif
