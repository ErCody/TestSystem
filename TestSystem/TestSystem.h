#pragma once
#include "FileSystem.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

class TestHandler {
private:
	std::map<std::string, std::string> qData;
	std::vector<std::string> categories;
	std::string curPath;

	void loadCategory();
public:
	TestHandler();
	void loadQuestion(const std::string& path, const std::string& testNum);

	std::map<std::string, std::string> getData();

	bool isRight(const std::string& testNum, const std::string& answer);

	std::vector<std::string> getCategories();

	friend std::ostream& operator <<(std::ostream& os, const TestHandler& test);

	std::vector<std::string> getTests(const std::string& category);
};


