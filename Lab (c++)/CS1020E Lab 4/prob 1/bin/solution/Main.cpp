/********************************
 * Name: 
 * Matric No: 
 * plab: 
 ********************************/

#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main() {
	int n, m; string op;
	while(cin >> n) {
		bool isQ = true, isS = true;
		stack<int> s; queue<int> q;
		while(n--) {
			cin >> op;
			if(op == "push") {
				cin >> m;
				s.push(m); q.push(m);
			} else if(op == "pop") {
				cin >> m;
				if(!s.empty() && s.top() == m) s.pop();
				else isS = false;
				if(!q.empty() && q.front() == m) q.pop();
				else isQ = false;
			} else {
				queue<int> tmpq; stack<int> tmps;
				while(!s.empty()) { tmpq.push(s.top()); s.pop(); }
				while(!tmpq.empty()) { s.push(tmpq.front()); tmpq.pop(); }
				while(!q.empty()) { tmps.push(q.front()); q.pop(); }
				while(!tmps.empty()) { q.push(tmps.top()); tmps.pop(); }
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
	return 0;
}
