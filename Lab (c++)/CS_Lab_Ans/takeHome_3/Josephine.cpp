#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class List{
private:
    struct Prince {
        int num;
        Prince *p_next;
    };
    Prince *_head;
    int _size;
    Prince* traverse(int index);
public:
    //constructors
    List();
    ~List();
    
    //methods
    void insert(int number);
    string remove(int index);
    
    string print();
    
    //getter
    int getLength() {return _size;}
    bool isEmpty() {return _size == 0;}
};

List::List() {
    _size = 0;
    _head = NULL;
}

List::~List() {
    while (!isEmpty()) {
        remove(1);
    }
}

string List::print() {
    ostringstream oss;
    for (int i=1; i<=getLength(); ++i) {
        if (traverse(i)->p_next == _head) {
        }
        oss << traverse(i)->num << " ";
    }
    string output = oss.str();
    return output;
}

List::Prince *List::traverse(int index) {
    Prince *cur;
    
    if (index < 1) {
        return NULL;
    } else {
        cur = _head;
        
        for (int i=1; i<index; ++i) {
            cur = cur->p_next;
        }
    }
    return cur;
}

void List::insert(int number){
    int newLength = getLength() + 1;
    Prince *newPtr = new Prince;
    newPtr->num = number;
    
    if (newLength == 1) {
        _head = newPtr;
        newPtr->p_next = newPtr;
    } else {
        Prince *cur;
        cur = traverse(getLength());
        cur->p_next = newPtr;
        newPtr->p_next = _head;
    }
    _size = newLength;
}

string List::remove(int index){
    Prince *cur = new Prince;
    Prince *prev = new Prince;
    ostringstream oss;
    
    prev = traverse(getLength());
    
    while (getLength()>0) {
        cur = prev->p_next;
        
        for (int i=1; i<index; ++i) {
            cur = cur->p_next;
            prev = prev->p_next;
        }
        prev->p_next = cur->p_next;
        oss << cur->num << " ";
        delete cur;
        _size--;
    }
    return oss.str();
}

int main () {
    List listPrince;
    int T, N, K;
    
    cin >> T;
    
    while (T>0) {
        cin >> N >> K;
        for (int i=1; i<=N; ++i) {
            listPrince.insert(i);
        }
        cout << listPrince.remove(K) << endl;
        T--;
    }
}