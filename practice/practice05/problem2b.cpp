#include <iostream>
#include <algorithm>
#include <vector> 


using namespace std;

int main() 
{
    vector<int> nums; 

    cout << "Enter 5 numbers of your choice: ";

    for(auto i=0; i<5; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    cout << "Largest Number in Vector: " << *max_element(nums.begin(), nums.end()) << endl;
    cout << "Smallest Number in Vector: " << *min_element(nums.begin(), nums.end()) << endl;
}