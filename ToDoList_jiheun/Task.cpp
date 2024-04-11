#include "Task.h"
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>

void saveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName)
{
	std::ofstream ostream(fileName);
	ostream << tasks.size(); //������ ����

	for (const Task& task : tasks) {
		std::string description = task.description;
		std::replace(description.begin(), description.end(), ' ', '_'); //description�� ������ _ �� �ٲ۴�.

		ostream << '\n' << description << ' ' << task.done; //�ؽ�Ʈ ���Ͽ� �� �ϰ� �Ϸ� ����(1 / 0)�� �Էµȴ�.
	}
}

std::vector<Task> loadTasksFromFile(const std::string& fileName)
{
	if (!std::filesystem::exists(fileName)) {
		return std::vector<Task>();
	}
	std::vector<Task> tasks;
	std::ifstream istream(fileName);

	int n; //�� �� ����Ʈ�� ���� 
	istream >> n;

	for (int i = 0; i < n; i++) {
		std::string description;
		bool done;

		istream >> description >> done;
		std::replace(description.begin(), description.end(), '_', ' '); //description�� _�� �������� �ٲ۴�.
		tasks.push_back(Task{ description, done }); //���Ϳ� description�� done�� �з����ͷ� ���� Task�� ������Ʈ�� �Էµȴ�.
	}

	return tasks;

}
