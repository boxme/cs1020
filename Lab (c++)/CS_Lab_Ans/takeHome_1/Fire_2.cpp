#include <iostream>
#include <string>

using namespace std;


int main ()
{
    int M_row = 0;
    int N_column = 0;
    int time = 1;
    int num_burnt = 0;
    int Timer[22][22] = {0};

    //second part of user input
    int T = 0;
    int Q = 0;
    int x = 0;
    int y = 0;
    
    cin >> M_row >> N_column;

    string forest[22][22] = {"S"};

    cin >> T;

    //initialize the forest with trees
    for (int i=1; i < M_row+1; i++) {
        for (int j=1; j < N_column+1; j++) {
            cin >> forest[i][j];
        }
    }

    while (count > M_row*N_column) {
    
    //Burn all the trees
    string fake_forest[22][22] = {"S"};
    int count = 0;
    for (int i=1; i < M_row+1; i++) {
        for (int j=1; j < N_column+1; j++) {
            
            if (forest[i][j] == "F")
                fake_forest[i][j] = "F";
                fake_forest[i][j-1] = "F";
                fake_forest[i][j+1] = "F";
                fake_forest[i-1][j] = "F";
                fake_forest[i+1][j] = "F";
        }
    }
    
    //copy over to real forest and record the time 
    for (int i=1; i < M_row+1; i++) {
        for (int j=1; j <N_column; j++) {
            
            forest[i][j] = fake_forest[i][j];

            if (fake_forest[i][j] == "F") {
                count++;
            }

            if (fake_forest[i][j] == "F" && Timer[i][j] == 0) {
                Timer[i][j] = time;
            }

            if (time == T) {
                num_burnt = count;
            }
        }
    }
    time++;
    }

    // reinitialize the fake_forest[22][22]
    fake_forest[22][22] = {"S"};

    //at time = T, what is the forest like?
    while (T >= 0) {
    for (int i=1; i < M_row; i++) {
        for (int j=1; j < N_column; j++) {
            
            if (Timer[i][j] = T) {
                fake_forest[i][j] = "F";
            }
        }
    }
        T--;
    }
}



