#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> tasks;
    int choice;
    string task;
    int index;

    do {
        cout << "\n--- To-Do List ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                cin.ignore();
                getline(cin, task);
                tasks.push_back(task);
                break;
            case 2:
                cout << "\nTasks:\n";
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
                break;
            case 3:
                cout << "Enter task number to remove: ";
                cin >> index;
                if (index > 0 && index <= tasks.size()) {
                    tasks.erase(tasks.begin() + index - 1);
                    cout << "Task removed.\n";
                } else {
                    cout << "Invalid number.\n";
                }
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
