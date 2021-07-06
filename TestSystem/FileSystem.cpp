#include <string>

#include "FileSystem.h"
#include <filesystem>
#include <fstream>



namespace FileSystem {
	bool isExist(const std::string& path) {
		std::ifstream fileCheck;
		fileCheck.open(path);
		if (fileCheck.is_open()) {
			return true;
		}
		return false;
	}
	inline void createBaseDirectory() {
		std::filesystem::create_directories("./files/userData/adminData");
		std::filesystem::create_directories("./files/testData");
	}
}