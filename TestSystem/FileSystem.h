#pragma once
#include <string>

//Folder with user data
const std::string USER_PATH = "./files/userData/";
const std::string ADMIN_PATH = "./files/userData/adminData/";

enum line {
	PASSWORD = 1,
	NAME,
	NUMBER,
	EMAIL,
	PASPORT_NUM,
	NONE = 0
};

namespace FileSystem {
	bool isExist(const std::string& path);

	void createBaseDirectory();

	void createDirectory(const std::string& path);

	void createFile_w(const std::string& path, std::string text);

	std::string getFileData(const std::string& path, line line);


}


