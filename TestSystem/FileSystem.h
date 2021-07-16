#pragma once
#include <string>
#include <set>
#include <filesystem>
#include <map>

//Folder with user data
const std::string USER_PATH = "./files/userData/";
const std::string ADMIN_PATH = "./files/userData/adminData/";
const std::string USER_FILE_PATH = "./files/userData/users.txt";
const std::string TESTS_PATH = "./files/testData/";
const std::string FILE_CATEG_PATH = "./files/testData/categories.txt";

enum line {
	PASSWORD = 1,
	NAME,
	NUMBER,
	EMAIL,
	PASPORT_NUM,
	NONE = 0
};

enum testID {
	QUESTION, 
	VAR_A, 
	VAR_B,
	VAR_C,
	RIGHT
};


namespace FileSystem {
	bool isExist(const std::string& path);

	void createBaseDirectory();

	void createDirectory(const std::string& path);

	void createFile_w(const std::string& path, std::string text);

	void deleteAll(const std::string& path);

	void editDataLine(const std::string& path, const std::string& text, line _line);

	void writeDataEnd(const std::string& path, std::string text);

	std::string getFileData(const std::string& path, line line);

	std::vector<std::string> getVectorData(const std::string& path);

}

namespace JsonSystem {
	std::pair<std::string, std::string> getDataID(const std::string& path, const std::string& testNum, testID id);

	uint16_t getCount(const std::string& path);
}
