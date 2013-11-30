#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int num_arr = 0;
    int arr[100][100] ={0};
    int num_oper = 0;
    string command_1 = "";
    string command_2 = "";
    
    cin >> num_arr;
    
    for (int x = 0; x < num_arr; x++) {
        
        for (int y = 0; y < num_arr; y++) {
            cin >> arr[x][y];
        }
    }
    
    cin >> num_oper;
    
    
    for (int z = 0; z < num_oper; z++) {
        cin >> command_1 >> command_2;
        
        if (command_1 == "Rotate") {
            int temp = 0;
            int times = 0;
            
            if (command_2 == "90") {
                times = 1;
            } else if (command_2 == "180") {
                times = 2;
            } else if (command_2 == "270") {
                times = 3;
            }
            for (int i = 0; i < times; i++) {
                
                for (int x = 0; x < (num_arr/2); x++) {
                    for (int y = x; y < (num_arr - 1 - x); y++) {
                        temp = arr[x][y];
                        arr[x][y] = arr[num_arr - 1 - y][x];
                        arr[num_arr - 1 - y][x] = arr[num_arr - 1 - x][num_arr - 1 - y];
                        arr[num_arr - 1 - x][num_arr - 1 - y] = arr[y][num_arr - 1 - x];
                        arr[y][num_arr - 1 - x] = temp;
                    }
                }
            }
            
        }
        if (command_1 == "Reflect") {
            int temp = 0;
            
            if (command_2 == "x") {
                
                for (int x = 0; x < (num_arr / 2); x++) {
                    for (int y = 0; y < num_arr; y++) {
                        
                        temp = arr[(num_arr - 1) - x][y];
                        arr[(num_arr - 1) - x][y] = arr[x][y];
                        arr[x][y] = temp;
                    }   
                }
            } else if (command_2 == "y") {
                
                for (int y = 0; y < (num_arr / 2); y++) {
                    for (int x = 0; x < num_arr; x++) {
                        
                        temp = arr[x][(num_arr - 1) - y];
                        arr[x][(num_arr - 1) - y] = arr[x][y];
                        arr[x][y] = temp;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < num_arr; i++) {
        for (int j = 0; j < num_arr; j++) {
            if (j == (num_arr - 1)) {
                cout << arr[i][j];
                break;
            }
            else    
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}