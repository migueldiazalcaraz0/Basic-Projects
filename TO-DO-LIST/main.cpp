#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_menu() {
    cout << "WELCOME TO MIGUEL'S TO-DO LIST" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. Remove a task" << endl;
    cout << "3. List all tasks" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    vector<string> tasks;
    int choice = 0;
    char second_choice;

    while (true) {
        print_menu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string task;
            cout << "Enter a task: ";
            cin.ignore(); // To ignore leftover newline from `cin`
            getline(cin, task);
            tasks.push_back(task);
            cout << "Task added successfully!\n";

            while (true) {
                cout << "Would you like to add another task? Yes [Y] No [N]: ";
                cin >> second_choice;

                // Convert to uppercase for consistency
                second_choice = toupper(second_choice);

                if (second_choice == 'Y') {
                    cout << "Enter a task: ";
                    cin.ignore(); // Ignore leftover newline
                    getline(cin, task);
                    tasks.push_back(task);
                    cout << "Task added successfully!\n";
                } else if (second_choice == 'N') {
                    break; // Exit the inner loop and return to the main menu
                } else {
                    cout << "Invalid choice. Please enter Y or N.\n";
                }
            }
        }

        if (choice == 2) {
            if (tasks.empty()) {
                cout << "No tasks to remove.\n";
                continue;
            }

            cout << "Which task would you like to remove:\n";
            for (int i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i] << endl; 
            }

            int taskIndex;
            cin >> taskIndex;

            if (taskIndex > 0 && taskIndex <= tasks.size()) {
                tasks.erase(tasks.begin() + (taskIndex - 1)); // Erases task
                cout << "Task has been eliminated.\n";
            } else {
                cout << "Not a valid task number!\n";
            }
        }

        if (choice == 3) {
            if (tasks.empty()) {
                cout << "No tasks in the list.\n";
            } else {
                cout << "Here are your tasks:\n";
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
            }
        }

        if (choice == 4) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }
    }

    return 0;
}
