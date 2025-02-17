#include <iostream>
#include <list>
#include <string>

using namespace std;

//add task to list using push back
void addTask(list<std::string>& tasks) {
    string task;
    cout << "Enter task: ";
    cin >> task;
    tasks.push_back(task);
}

//remove task from list using erase
void removeTask(list<std::string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove\n";
        return;
    }
    tasks.pop_back();
}

//show tasks in list
void showTasks(list<std::string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks\n";
        return;
    }
    cout << "Tasks:\n";
    for (auto task : tasks) {
        cout << task << endl;
    }
}

//main function
int main() {
    list<std::string> tasks; // Declare a list of strings to store tasks
    int choice;
    
    do {
        cout << "1. Add task\n2. Remove task\n3. Show tasks\n4. Exit\n";
        
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                removeTask(tasks);
                break;
            case 3:
                showTasks(tasks);
                break;
            case 4:
                cout << "Exiting\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    while(choice != 4);
}