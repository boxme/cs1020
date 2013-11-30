#include <iostream>
#include <string>
#include <stdio.h>

//size of the array is a prime number and choosen so that load factor is less than 0.5
#define Size 2029

using namespace std;

class Data {
private:
    string DNA;
    int occurance;
public:
    //initializer
    Data();
    //function to insert the data into the table
    void insertion(string);
    //getting functions
    int getOccurance() {return occurance;}
    string getString() {return DNA;}
};

Data::Data() {
    DNA = " ";
    occurance = 0;
}
//adding a new element into the array and increasing the occurance by 1
// if it's a collision, the occurance will increase
void Data::insertion(string DNA) {
    this->DNA = DNA;
    this->occurance += 1;
}

//first hash function
int hash1(string substring, int K) {
    int sum = 0;
    for (int i=0; i<K; ++i) {
        sum += sum*37 + substring[i];
        //to prevent the integer from overflowing during the addition
        sum = sum % Size;
    }
    return sum % Size;
}

//second hash function
int hash2(int key) {
    int S = Size-1;
    return (key % S) + 1;
};

void storage(Data table[], string DNA, int N, int K) {
    for (int i=0; i<N; ++i) {
        if (i+K-1 != N) {
            string substring = DNA.substr(i, K);
            int key = hash1(substring, K); int i=1
            //if statement to take care of different substrings with same addresses
            while (table[key].getOccurance() != 0 && table[key].getString() != substring) {
                //the key will be changed & the array is wrapped around
                key = (key + i*hash2(key)) % Size;
                ++i;
            }
            table[key].insertion(substring);
        }
        else {
            break;
        }
    }
}

int searchTable(Data table[], string Query, int K) {
    int key = hash1(Query, K);
    if (table[key].getOccurance() == 0)
        return 0;
    else {
        //keep searching until the string is found or reached an empty array slot
        while (table[key].getOccurance() != 0 && table[key].getString() != Query ) {
            key = (key + hash2(key)) % Size;
        }
    }
    return table[key].getOccurance();
}

int main()
{
    int N, K, Q;
    string DNA, Query;
    
    cin >> N >> K;
    cin >> DNA;
    cin >> Q;
    
    //initializing all the elements in the table to have occurance 0
    //so the array is not empty
    Data table[Size];
    for (int i=0; i<Size; ++i) {
        Data newData;
        table[i] = newData;
    }
    
    storage(table, DNA, N, K);
    
    while (Q>0) {
        cin >> Query;
        cout << searchTable(table, Query, K) << endl;
        Q--;
    }
}