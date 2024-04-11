#include "Task.h"
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>

void saveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName)
{
	std::ofstream ostream(fileName);
	ostream << tasks.size(); //사이즈 설정

	for (const Task& task : tasks) {
		std::string description = task.description;
		std::replace(description.begin(), description.end(), ' ', '_'); //description의 공백을 _ 로 바꾼다.

		ostream << '\n' << description << ' ' << task.done; //텍스트 파일에 할 일과 완료 여부(1 / 0)가 입력된다.
	}
}

std::vector<Task> loadTasksFromFile(const std::string& fileName)
{
	if (!std::filesystem::exists(fileName)) {
		return std::vector<Task>();
	}
	std::vector<Task> tasks;
	std::ifstream istream(fileName);

	int n; //할 일 리스트의 개수 
	istream >> n;

	for (int i = 0; i < n; i++) {
		std::string description;
		bool done;

		istream >> description >> done;
		std::replace(description.begin(), description.end(), '_', ' '); //description의 _을 공백으로 바꾼다.
		tasks.push_back(Task{ description, done }); //벡터에 description과 done을 패러미터로 갖는 Task형 엘리먼트가 입력된다.
	}

	return tasks;

}
