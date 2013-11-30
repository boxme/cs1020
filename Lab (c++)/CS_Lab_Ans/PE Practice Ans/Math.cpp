#include <iostream>

using namespace std;

void printResult(unsigned long long result[][2], int M) {
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            while (result[i][j] >= M){
                result[i][j] %= M;
            }
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void addition(unsigned long long result[][2], unsigned long long identity[][2]) {
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++)
            result[i][j] += identity[i][j];
    }
}

void copyArray(unsigned long long newMatrix[][2], unsigned long long matrix[][2]) {
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++)
            matrix[i][j] = newMatrix[i][j];
    }
}

void multiply(unsigned long long original[][2], unsigned long long matrix[][2]) {
    unsigned long long newMatrix[2][2] = {0};
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++)
                newMatrix[i][j] += original[i][k] * matrix[k][j];
        }
    }
    copyArray(newMatrix, matrix);
}

void computation(unsigned long long matrix[][2], unsigned long long temp[][2], unsigned long long result[][2], int N) {
    if (N==2) {
        multiply(matrix, matrix); //matrix^2
        addition(result, matrix); //A+A^2
    }
    else {
        if (N%2 == 0) {
            computation(matrix, temp, result, N/2);
            copyArray(result, temp);
            multiply(matrix, temp);
            multiply(matrix, matrix);
            addition(result, temp);
        }
        else {
            unsigned long long tmp[2][2];
            copyArray(matrix, tmp);                   //copy original matrix to tmp
            computation(matrix, temp, result, N-1);
            multiply(matrix, tmp);                   //get A^N
            copyArray(tmp, matrix);                 //get the matrix to A^N
            addition(result, matrix);
        }
    }
}

int main ()
{
    unsigned long long matrix[2][2] = {0};
    unsigned long long temp[2][2] = {0};
    unsigned long long result[2][2] = {0};
    
    unsigned long long identity[2][2] = {{1, 0},
                                         {0, 1}};
    int N , M;
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cin >> matrix[i][j];
            result[i][j] = matrix[i][j];
            temp[i][j] = matrix[i][j];
        }
    }
    
    cin >> N >> M;

    if (N==1)
        addition(result, identity);
    else {
        computation(matrix, temp, result, N);
        addition(result, identity);
    }
    
    printResult(result, M);
}