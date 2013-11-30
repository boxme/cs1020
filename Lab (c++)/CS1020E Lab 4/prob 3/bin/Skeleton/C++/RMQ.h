#ifndef rmq_h
#define rmq_h

#include "StackEle.h"
#include <stack>

using namespace std;

class RMQ{
private:
    int size;
	int *A;
    int *B;
	stack <StackEle> stk;
public:
	RMQ(int size){
        this->size = size;
        A = new int[size+1]; B = new int[size+1];  //rmb that index 0 is not to be used
        A[0] = -1; B[0] = 0;                      //A[0] is the base case
	}
	
	void addElement(int x, int i){
        A[i] = x;
	}
    void setUp();
	int getIntervalMin(int c, int d);
};

#endif