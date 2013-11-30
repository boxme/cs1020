#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int row_M = 0;
    int column_N = 0;
    int timer = 1;
    int burnt = 0;
    
    //second part of user input
    int T = 0;
    int Q = 0;
    
    cin >> row_M >> column_N;
    
    string forest[22][22] = {"S"};
    string fake_forest  [22][22] = {"S"};
    
    // Setting up the forest
    for (int i = 1; i < (row_M + 1); i++){
        for (int j = 1; j < (column_N + 1); j++) {
            cin >> forest[i][j];
            fake_forest[i][j] = forest[i][j];
        }
    }
    
    //input for T, Q
    cin >> T;
    cin >> Q;
    
    //array to keep the timing before a tree burns
    int timing[22][22] = {0};
    
    while (burnt != (row_M * column_N)) {
        
        //set number of trees burn to zero
        burnt = 0;
        
        //burn all the trees
        for (int i = 1; i < (row_M + 1); i++) {
            for (int j = 1; j < (column_N + 1); j++) {
                
                if (forest[i][j] == "F") {
                    fake_forest[i][j] = "F";
                    fake_forest[i-1][j] = "F";
                    fake_forest[i+1][j] = "F";
                    fake_forest[i][j-1] = "F";
                    fake_forest[i][j+1] = "F";
                }
            }
        }
        
        //setting time into timing array
        for (int i = 1; i < (row_M + 1); i++) {
            for (int j = 1; j < (column_N + 1); j++) {
                
                if (forest[i][j] == "S") {
                    timing[i][j] = timer;
                }
            }
        }
        
        //copying the fake forest to real forest
        for (int i = 1; i < (row_M + 1); i++) {
            for(int j = 1; j < (column_N + 1); j++) {
                forest[i][j] = fake_forest[i][j];
                fake_forest[i][j] = "S";
            }
        }
        
        //count the total number of trees burnt per loop
        for (int i = 1; i < (row_M + 1); i++){
            for (int j = 1; j < (column_N + 1); j++) {
                
                if (forest[i][j] == "F") {
                    burnt = burnt + 1;
                }
            }
        }
        timer++;
    }
    
    //    // Print out final array
    //    for (int i = 1; i < (row_M + 1); i++) {
    //        for(int j = 1; j < (column_N + 1); j++) {
    //            cout << timing[i][j] << " ";
    //        }
    //        cout << endl;
    //    }
    
    //total trees burnt for T minutes
    burnt = 0;
    
    for (int i = 1; i < (row_M + 1); i++) {
        for (int j = 1; j < (column_N + 1); j++) {
            
            if (timing[i][j] <= T) {
                burnt = burnt + 1;
            }
        }
    }
    
    int coord_xy[100][2] = {0};
    
    //check for safety duration of trees
    for (int i = 0; i < Q; i++) {
        cin >> coord_xy[i][0] >> coord_xy[i][1];
    }
    
    //output total number of burnt trees
    cout << "Number of burnt trees: " << burnt << "." << endl;
    
    //output longest period the tree is safe
    for (int i = 0; i < Q; i++) {
        cout << "Tree at (" << coord_xy[i][0] << "," <<
        coord_xy[i][1] << ") is safe for " <<
        timing[(coord_xy[i][0])][(coord_xy[i][1])] << " minutes." <<
        endl;
    }
    
}