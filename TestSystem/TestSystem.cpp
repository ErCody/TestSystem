#include "TestSystem.h"

inline testID operator++(testID& eDOW, int) {
	const testID ePrev = eDOW;
	const int i = static_cast<int>(eDOW);
	eDOW = static_cast<testID>((i + 1) % 7);
	return ePrev;
}


void TestHandler::loadCategory() {
	 categories = FileSystem::getVectorData(FILE_CATEG_PATH);
}

TestHandler::TestHandler() {
	loadCategory();
}

void TestHandler::loadQuestion(const std::string& path, const std::string& testNum) {
	qData.clear();
	testID ID = QUESTION;
	curPath = path;
	for (size_t i = 0; i < 4; i++) {
		qData.insert(JsonSystem::getDataID(curPath, testNum, ID));
		ID++;
	}
}


std::map<std::string, std::string> TestHandler::getData() {
	return qData;
}

bool TestHandler::isRight(const std::string& testNum, const std::string& answer) {
	std::pair<std::string, std::string> answ = JsonSystem::getDataID(curPath, testNum, RIGHT);
	if (answer == answ.second) {
		return true;
	}
	return false;
}

std::vector<std::string> TestHandler::getCategories() {
	return categories;
}

std::vector<std::string> TestHandler::getTests(const std::string& category) {
	return FileSystem::getVectorData(TESTS_PATH + category + "/tests.txt");
}

std::ostream& operator<<(std::ostream& os, const TestHandler& test) {
	for (const auto& [key, value] : test.qData) {
		os << value << std::endl;
	}
	
	return os;
}


