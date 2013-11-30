#include <iostream>
#include <string>
#include <stdio.h>

#define Size 2011

using namespace std;

class Data {
private:
    string substring;
public:
    Data();
    
    //methods
    void insertion(string);
    //    void dataEntry(Data table[], string substring, int N, int K);
    
    //getter
    string getString() {return substring;}
};

Data::Data() {
    substring = "NULL";
}

//hash function
int hash1(string substring, int K) {
    int sum = 0;
    for (int i=0; i<K; ++i) {
        sum += sum*37 + substring[i];
        sum %= Size;
    }
    return sum % Size;
}

void Data::insertion(string substring) {
    this->substring = substring;
}

void dataEntry(Data table[], string String, int N, int K) {
    for (int i=0; i<N; ++i) {
        if (i+K-1 != N) {
            string substr = String.substr(i, K);
            int key = hash1(substr, K);
            int j=1;
            //find an empty slot to keep the substring
            while (table[key].getString() != "NULL" && table[key].getString() != substr) {
                key = (key + (2*j-1)) % Size;
                j++;
                //if there is a repeat collision, discard
            }
            table[key].insertion(substr);
        }
        else
            break;
    }
}

int find(Data table1[], Data table2[], string substring, int K) {
    int key1 = hash1(substring, K), j1=1;
    int key2 = hash1(substring, K), j2=1;
    bool inString1 = true, inString2 = true;
    
    //find substring in string1
    while (table1[key1].getString() != "NULL" && table1[key1].getString() != substring) {
        key1 = (key1 + (2*j1-1)) % Size;
        j1++;
    }
    if (table1[key1].getString() == "NULL")
        inString1 = false;
    
    //find substring in string2
    while (table2[key2].getString() != "NULL" && table2[key2].getString() != substring) {
        key2 = (key2 + (2*j2-1)) % Size;
        j2++;
    }
    if (table2[key2].getString() == "NULL")
        inString2 = false;
    
    //return result
    if (inString1 && inString2)
        return 3;
    else if (inString1)
        return 1;
    else if (inString2)
        return 2;
    else
        return 0;
}

int main()
{
    int N, K, Query;
    string string1, string2, substring;
    Data table1[Size], table2[Size];
    
    cin >> N >> K;
    cin >> string1;
    cin >> string2;
    cin >> Query;
    
    //setting up the hash table 1 & 2 respectively
    dataEntry(table1, string1, N, K);
    dataEntry(table2, string2, N, K);
    
    while (Query>0) {
        cin >> substring;
        cout << find(table1, table2, substring, K) << endl;
        Query--;
    }
}