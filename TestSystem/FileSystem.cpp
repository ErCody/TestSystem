#include <string>
#include <set>
#include "FileSystem.h"
#include <map>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <json/json.h>
#include <json/value.h>

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

	void deleteAll(const std::string& path) {
		std::filesystem::remove_all(path);
	}

	inline line operator++(line& eDOW, int) {
		const line ePrev = eDOW;
		const int i = static_cast<int>(eDOW);
		eDOW = static_cast<line>((i + 1) % 7);
		return ePrev;
	}

	void editDataLine(const std::string& path, const std::string& text, line _line) {
		std::fstream file;
		std::string data;
		line counter = PASSWORD;
		for (size_t i = 1; i < _line; i++) {
			data.append(getFileData(path, counter) + '\n');
			counter++;
		}
		data.append(text + '\n');
		counter++;
		for (size_t i = _line; i < 5; i++) {
			data.append(getFileData(path, counter) + '\n');
			counter++;
		}
		file.open(path);
		file.write(data.c_str(), data.size());
		
	}

	void writeDataEnd(const std::string& path, std::string text) {
		std::ofstream file;
		text += '\n';
		file.open(path, std::ios::app);
		file.write(text.c_str(), text.size());
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

	std::vector<std::string> getVectorData(const std::string& path){
		std::vector<std::string> data;
		std::ifstream file;
		std::string curData;
		file.open(path);
		while (getline(file, curData)) {
			data.push_back(curData);
		}
		return data;
	}
   
}

namespace JsonSystem {

	std::string toString(testID id) {
		switch (id) {
		case QUESTION: return "Question"; break;
		case VAR_A:	   return "VAR_A"; break;
		case VAR_B:    return "VAR_B"; break;
		case VAR_C:    return "VAR_C"; break;
		case RIGHT:    return "RIGHT"; break;
		default:       return "<Error>"; break;
		}
	}

	std::pair<std::string, std::string> getDataID(const std::string& path, const std::string& testNum, testID id) {
		std::pair<std::string, std::string> data;
		std::string temp;
		std::ifstream testFile;

		Json::Value testData;
		Json::StreamWriterBuilder textBuilder;

		testFile.open(path, std::ifstream::binary);
		testFile >> testData;

		temp = toString(id);

		data.first = temp;
		data.second = Json::writeString(textBuilder, testData[testNum][temp]);
		return data;
	}

	uint16_t getCount(const std::string& path) {
		std::ifstream testFile;

		Json::Value testData;
		Json::StreamWriterBuilder textBuilder;

		testFile.open(path, std::ifstream::binary);
		testFile >> testData;
		return testData["Count"].asUInt();
	}

}
