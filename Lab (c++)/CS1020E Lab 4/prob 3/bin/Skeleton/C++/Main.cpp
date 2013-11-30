#include "RMQ.h"

int main(){
	RMQ rmq = RMQ();
	
    int x=0;
    
    for (int i=1; i<10; i++) {
        cout << 1+(1<<(i-1)) << endl;
    }
	return 0;
}