#pragma once
#include <string>
namespace LoginSystem {
	bool userLogin(const std::string& userLogin, std::string& userPassword);

	bool userReg(const std::string& userLogin, std::string& userPassword);

	bool adminReg(std::string& adminPassword);

	bool isAdminExist();
}