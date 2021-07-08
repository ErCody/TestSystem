#pragma once
#include <string>

bool userLogin(const std::string& userLogin, std::string& userPassword);

bool userReg(const std::string& userLogin, std::string& userPassword);

bool adminReg(std::string& adminPassword);

bool isAdminExist();