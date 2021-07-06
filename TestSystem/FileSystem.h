#pragma once
#include <string>

//Folder with user data
#define USER_PATH "./files/userData"

namespace FileSystem {
	bool isExist(const std::string& path);

	void createBaseDirectory();
}


