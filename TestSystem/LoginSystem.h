#pragma once
#include <string>
#include "User.h"
namespace LoginSystem {
	bool userLogin(const std::string& userLogin, std::string& userPassword, User& user);

	bool userReg(const std::string& userLogin, std::string& userPassword);

	bool adminReg(std::string& adminPassword);

	bool isAdminExist();
}