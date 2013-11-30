#include <iostream>

using namespace std;

int Knapsack(int *weightOfEachItem, int maxWeight, int numItems) {
    if (maxWeight < *weightOfEachItem || numItems == 0)
        return 1;
    else {
        return
        + Knapsack(weightOfEachItem+1, maxWeight-(*weightOfEachItem), numItems-1)
        + Knapsack(weightOfEachItem+1, maxWeight, numItems-1);
    }
}

int main()
{
    int numItems, maxWeight;
    cin >> numItems >> maxWeight;
    
    int *weightOfEachItem = new int[numItems];
    
    for (int i=0; i<numItems; i++) {
        cin >> weightOfEachItem[i];
    }
    
    sort(weightOfEachItem, weightOfEachItem+numItems);
    
    cout << Knapsack(&weightOfEachItem[0], maxWeight, numItems)<< endl;
}

