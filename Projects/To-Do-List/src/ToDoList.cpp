#include <vector>
#include <iostream>
#include <string>

struct Task
{
	std::string title;
	std::string description;
};

using std::cout, std::endl;

void PrintMenu(std::vector<Task>& tasks);

int main()
{
	std::vector<Task> tasks;

	bool isRunning = true;

	while (isRunning)
	{

		PrintMenu(tasks);
		cout << "What would you like to do? " << endl;

		int menuChoice;
		std::cin >> menuChoice;

		while (menuChoice > 4 || menuChoice < 1)
		{
			cout << "Choice must be 1-4. Try again" << endl;
			continue;
		}

		switch (menuChoice)
		{
		case 1:
		{
			std::string title, description;

			cout << "Enter task title: " << endl;
			std::getline(std::cin >> std::ws, title);

			cout << "Enter task description: " << endl;
			std::getline(std::cin >> std::ws, description);

			tasks.push_back({ title, description });
			break;
		}
		case 2:
		{
			int taskIndexToRemove = 0;
			while (true)
			{
				cout << "Which task would you like to remove?" << endl;
				for (int i = 0; i < tasks.size(); i++)
					cout << (i + 1) << ") " << tasks[i].title << endl;

				std::cin >> taskIndexToRemove;

				if (taskIndexToRemove > tasks.size() || taskIndexToRemove < 1)
				{
					cout << "Task must be between 1-" << tasks.size() << endl;
					continue;
				}

				tasks.erase(tasks.begin() + taskIndexToRemove - 1);
				cout << "Task removed." << endl;
				break;

			}
			break;
		}
		case 3:
		{
			cout << "Tasks:" << endl;
			for (Task task : tasks)
			{
				cout << ") " << task.title << endl;
				cout << "    - " << task.description << endl;
			}
			break;
		}
		case 4:
			cout << "Goodbye!" << endl;
			isRunning = false;
			break;
		};

	}

}


void PrintMenu(std::vector<Task>& tasks)
{
	if (tasks.size() == 0)
		cout << "1) Add Task" << std::endl;
	else
	{
		cout << "1) Add Task" << std::endl;
		cout << "2) Remove Task" << std::endl;
		cout << "3) View Task List" << std::endl;
	}
	cout << "4) Exit" << std::endl;
}