/********************************
 * Name: 
 * Matric No: 
 * plab: 
 ********************************/

#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include <string>

using namespace std;

int main() {
	int n, m; string op;
	while(cin >> n) {
		bool isQ = true, isS = true;
		MyStack s; MyQueue q;
		while(n--) {
			cin >> op;
			if(op == "push") {
				cin >> m;
				s.push(m); q.enqueue(m);
			} else if(op == "pop") {
				cin >> m;
				if(!s.isEmpty() && s.getTop() == m) s.pop();
				else isS = false;
				if(!q.isEmpty() && q.getFront() == m) q.dequeue();
				else isQ = false;
			} else {
				s.reverse(); q.reverse();
			}
		}
		if(isS && isQ) {
			cout << "stack or queue" << endl;
		} else if(isS) {
			cout << "stack" << endl;
		} else if(isQ) {
			cout << "queue" << endl;
		} else {
			cout << "impossible" << endl;
		}
	}
}
