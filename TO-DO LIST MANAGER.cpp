//********************************************* TO-DO LIST MANAGER***********************************************

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". "<<tasks[i].description;
            if (tasks[i].completed) {
                cout << " [Completed]"<<endl;
            }
            else
            {
                cout<<" [Pending]"<<endl;
            }
        }
    }

    void markTaskCompleted(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed: " << tasks[taskNumber - 1].description << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
            cout << "Task removed: " << tasks[taskNumber - 1].description << endl;
            tasks.erase(tasks.begin() + taskNumber - 1);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;

    cout << "\n************Welcome to the ToDo List Manager!!************"<< endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear the newline character from the buffer
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            }
            case 4: {
                int taskNumber;
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            }
            case 5:
                cout << "\n************GOODBYE!!************" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
