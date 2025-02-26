#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> strings;
    string input;

    cout << "Enter 5 words of your choice: ";

    for(auto i=0; i<5; i++) {
        cin >> input;
        strings.push_back(input);
    }

    cout << "The strings in reverse order are: ";
    for(auto i=strings.rbegin(); i!=strings.rend(); i++) {
        cout << *i << " ";
    }
    return 0;
}
