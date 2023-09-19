#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoList {
private:
    vector<string> tasks;
    vector<bool> completed;

public:
    
    void add(const string& description) {
        tasks.push_back(description);
        completed.push_back(false);
        cout << "Task added: " << description << endl;
    }

    
    void view() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "Tasks in the list:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << "[" << (completed[i] ? "X" : " ") << "] " << i + 1 << ". " << tasks[i] << endl;
            }
        }
    }

    
    void markCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
            completed[taskIndex - 1] = true;
            cout << "Task marked as completed: " << tasks[taskIndex - 1] << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    
    void remove(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
            cout << "Task removed: " << tasks[taskIndex - 1] << endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
            completed.erase(completed.begin() + taskIndex - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        cout << "\nTodo List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            cout << "Goodbye!" << endl;
            break;
        }

        cin.ignore(); 

        switch (choice) {
            case 1:
                {
                    cout << "Enter task description: ";
                    string description;
                    cin >> description;
                    todoList.add(description);
                    break;
                }
            case 2:
                todoList.view();
                break;
            case 3:
                {
                    int taskIndex;
                    cout << "Enter the task number to mark as completed: ";
                    cin >> taskIndex;
                    todoList.markCompleted(taskIndex);
                    break;
                }
            case 4:
                {
                    int taskIndex;
                    cout << "Enter the task number to remove: ";
                    cin >> taskIndex;
                    todoList.remove(taskIndex);
                    break;
                }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
