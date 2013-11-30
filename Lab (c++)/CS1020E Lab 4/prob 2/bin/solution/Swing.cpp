#include <iostream>
#include <stack>

using namespace std;

int solve(int arr[], int size) {
	stack<int>check;
	int jump = 0;
	for(int i=0;i<size;i++){
		if(check.empty()){
			check.push(arr[i]);
		}
		else {
			while(!check.empty()&&check.top()<arr[i]){
				jump++;
				check.pop();
			}
			if(!check.empty()&&check.top()==arr[i]){
				jump++;
                check.pop();
			}
			if(!check.empty()&&check.top()>arr[i]){
				jump++;
				check.push(arr[i]);
			}
			if (check.empty()){
				check.push(arr[i]);
			}
		}
	}
	return jump;
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << solve(arr,N) << endl;

	return 0;
}
