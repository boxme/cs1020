#include <iostream>

using namespace std;

int main ()
{
    int N = 0;
    cin >> N;
    int input[300][2] = {0};
    
    int x, y;
    
    for (int i=0; i != N; i++) {
        cin >> x >> y;
        input[i][0] = x;
        input[i][1] = y;
    }
    
    int num_point = 0;
    int temp_num = 2;
    
    for (int i=0; i<N-2; i++) {
        for (int j=i+1; j<N-1; j++) {
            for (int k=j+1; k<N; k++) {
                int leftHand = (input[j][0]-input[i][0])*(input[k][1]-input[i][1]);
                int rightHand = (input[k][0]-input[i][0])*(input[j][1]-input[i][1]);
                if (leftHand == rightHand ) {
                    temp_num++;
                }
            }
            if (temp_num!=2 && temp_num > num_point) {
                num_point = temp_num;
            }
            temp_num = 2;
        }
    }
    
    cout << num_point << endl;
}