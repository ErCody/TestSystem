#include "LoginSystem.h"
#include "FileSystem.h"
#include <string>
#include <fstream>

//Local function to check if a user exists or not.
bool isUserExist(const std::string& login) {
	std::string path = USER_PATH + login + ".txt";
	if (FileSystem::isExist(path)) {
		return true;
	}
	return false;
}

void userLogin(const std::string& userLogin, const std::string& userPassword) {
	if (FileSystem::isExist(userLogin)) {
		/*
		*  Code
		*/
	}
}


bool userReg(std::string& userLogin, std::string& userPassword) {
	if (isUserExist(userLogin)) {
		return false;
	}


}
