#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class linkList {
private:
    struct linkNode {
        int value;
        linkNode *p_next;
    };
    int _size;
    linkNode *_head;
    linkNode *_tail;
    linkNode *traverse(int index);
public:
    
    //constructor
    linkList();
    ~linkList();
    
    //operations
    void insert(int value);
    bool remove(int index);
    bool move(int index);
    bool add(int index, int value);
    string check();
    
    string print();
    
    //getter
    int getLength() {return _size;}
    bool isEmpty() {return _size == 0;}
    
};

linkList::linkList() {
    _size = 0;
    _head = NULL;
    _tail = NULL;
}

linkList::~linkList() {
    while (!isEmpty()) {
        remove(1);
    }
}

string linkList::print() {
    ostringstream oss;
    for (int i=1; i<=getLength(); ++i) {
        oss << traverse(i)->value << " ";
    }
    string output = oss.str();
    return output;
}

linkList::linkNode *linkList::traverse(int index) {
    if (index < 1 || index > getLength()) {
        return NULL;
    } else {
        linkNode *cur;
        cur = _head;
        
        for (int i=1; i<index; ++i) {
            cur = cur->p_next;
        }
        return cur;
    }
}

void linkList::insert(int value) {
    int newLength = getLength() + 1;
    linkNode *newPtr = new linkNode;
    newPtr->value = value;
    newPtr->p_next = NULL;
    _size = newLength;
    
    if (_size == 1) {
        _head = newPtr;
        _tail = newPtr;
    } else {
        _tail->p_next = newPtr;
        _tail = newPtr;
    }
}

bool linkList::remove(int index) {
    linkNode *cur;
    if (index < 1 || index > getLength()) {
        return NULL;
    } else {
        if (index == 1) {
            cur = _head;
            _head = _head->p_next;
        } else if (index == getLength()){
            cur = traverse(index-1);
            _tail = cur;
            cur = cur->p_next;
        } else {
            linkNode *prev;
            prev = traverse(index-1);
            cur = prev->p_next;
            prev->p_next = cur->p_next;
        }
        delete cur;
        _size--;
        return true;
    }
}

bool linkList::move(int index) {
    linkNode *cur;
    
    if (index < 1 || index > getLength()) {
        return NULL;
    } else {
        cur = traverse(index);
        insert(cur->value);
        remove(index);
        return true;
    }
}

bool linkList::add(int index, int value){
    linkNode *cur;
    if (index < 1 || index > _size) {
        return false;
    } else {
        cur = traverse(index);
        cur->value = (cur->value + value);
        return true;
    }
}

string linkList::check() {
    int curValue = 0;
    int nextValue = 0;
    if (getLength() == 0 || getLength() == 1) {
        return "YES";
    } else {
        for (int i=1; i<getLength(); ++i) {
            curValue = traverse(i)->value;
            nextValue = traverse(i+1)->value;
            if (curValue > 0 && nextValue > 0) {
                return "NO";
            } else if (curValue < 0 && nextValue < 0) {
                return "NO";
            }
        }
        return "YES";
    }
}

int main () {
    int N, Q, index, size, value;
    linkList list;
    
    cin >> N >> Q;
    
    while (N>0) {
        cin >> value;
        list.insert(value);
        N--;
    }

    string action = "";
    
    while (Q>0) {
        cin >> action;
        if (action == "M") {
            cin >> index >> size;
            while (size>0) {
                list.move(index);
                size--;
            }
            cout << list.check() << endl;
//            cout << list.print() << endl;
        }
        if (action == "R") {
            cin >> index >> size;
            while (size > 0) {
                list.remove(index);
                size--;
            }
            cout << list.check() << endl;
//            cout << list.print() << endl;
        }
        if (action == "A") {
            cin >> index >> size >> value;
            while (size > 0) {
                list.add(index, value);
                index++;
                size--;
            }
            cout << list.check() << endl;
//            cout << list.print() << endl;
        }
        Q--;
    }
}