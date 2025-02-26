#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main() 
{
    vector<int> nums; 

    cout << "Enter 7 numbers of your choice: ";

    for(auto i=0; i<7; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    int threshold;
    cout << "Enter a threshold value: ";
    cin >> threshold;

    cout << "Numbers greater than " << threshold << " are: ";

    int num_greater_than_threshold = count_if(nums.begin(), nums.end(), [threshold](int i) { return i > threshold; });

    cout << num_greater_than_threshold; 

    int print_num = remove_if(nums.begin(), nums.end(), [threshold](int j) {return j < threshold; }) - nums.begin();

    cout << "\nNumbers in the vector after removing numbers less than " << threshold << " are: ";

    for(auto i=0; i<print_num; i++) {
        cout << nums[i] << " ";
    }


}