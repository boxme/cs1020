#ifndef rmq_h
#define rmq_h

#include "StackEle.h"
#include <vector>
#include <stack>

using namespace std;

class RMQ{
private:
	vector <int> A;
	stack <StackEle *> stk;
    StackEle *root;
public:
    
    void clear();
	void addElement(const int &x);
    void insertRootNode();
    void buildTree();
	int getIntervalMin(int c, int d, StackEle *cur);
//    int getIntervalMin(int c, int d);
    StackEle *getRoot() {return root;}
};

#endif