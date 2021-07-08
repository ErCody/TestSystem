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

	void createBaseDirectory() {
		std::filesystem::create_directories("./files/userData/adminData");
		std::filesystem::create_directories("./files/testData");
	}

	void createDirectory(const std::string& path) {
		std::filesystem::create_directory(path);
	}

	void createFile_w(const std::string& path, std::string text) {
		std::ofstream newFile;
		text += '\n';
		newFile.open(path);
		newFile.write(text.c_str(), text.size());
	}

	std::string getFileData(const std::string& path, line line) {
		std::string data;
		std::ifstream file;
		file.open(path);
		for (size_t i = 0; i < line; i++) {
			std::getline(file, data);
		}
		return data;
	}

   
}