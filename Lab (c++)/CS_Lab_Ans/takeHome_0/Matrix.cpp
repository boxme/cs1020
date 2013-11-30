#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int array[100][100];
    int N, M, x, y;

    int sum = 0;
    cin >> N >> M;

    for (x = 0; x < N; x++)
    {
        for (y = 0; y < M; y++)
        {
            cin >> array[x][y];
        }
    }

    string input_1 = "";
    int input_2 = 0;

    cin >> input_1 >> input_2;

    if (input_1 == "ROW")
    {
        x = input_2;
        for (y = 0; y< M; y++)
        { 
            sum += array[x-1][y];
        }
    } else if (input_1 == "COLUMN")
    {
        y = input_2;
        for (x = 0; x < N; x++)
        {
            sum += array[x][y-1];
        }
    }
    cout << sum << endl;
}
