#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{
    int num_ppl = 0;
    
    string name = "";
    
    double weight = 0;
    double height = 0;
    double BMI = 0;
    
    double l_height[1] = {0};
    double h_height[1] = {0};
    
    double l_weight[1] = {0};
    double h_weight[1] = {0};
    
    string l_name[1] = {""};
    string h_name[1] = {""};
    
    cin >> num_ppl;
    for (int x = 0; x < num_ppl; x++) {
        cin >> name >> height >> weight;
        
        if (height > h_height[0]) {
            h_height[0] = height;
            h_weight[0] = weight;
            h_name[0] = name;
        }
        if (l_height[0] == 0) {
            l_height[0] = height;
            l_weight[0] = weight;
            l_name[0] = name;
        }
        if (height < l_height[0]) {
            l_height[0] = height;
            l_weight[0] = weight;
            l_name[0] = name;
        }
    }
   //set precision to 2 significant number
   //cout.setf(ios::fixed) is to make sure SF number is set after decimal dot
    
    cout.setf(ios::fixed); 
    cout.precision(2);
    
    
    height = l_height[0] / 100;
    BMI = l_weight[0] / (height * height);
    
    cout << l_name[0] << " is the shortest with BMI equals to " << BMI << "." << endl;
    
    height = h_height[0] / 100;
    BMI = h_weight[0] / (height * height);
    
    cout << h_name[0] << " is the tallest with BMI equals to " << BMI << "." << endl;
}