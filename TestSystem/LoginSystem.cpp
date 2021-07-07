#include "LoginSystem.h"
#include "FileSystem.h"

#include <fstream>
#include <iostream>

#include <string>


//Локальная функция для проверки, существует ли такой пользователь или нет
bool isUserExist(const std::string& userLogin) {
	std::string path = USER_PATH + userLogin + ".txt";
	if (FileSystem::isExist(path)) {
		return true;
	}
	return false;
	
}

//Локальная функция для проверки пароля по критериям
bool passwordCheck(const std::string& userPassword) {
	uint8_t upLetterCounter = 0;
	uint8_t numCounter = 0;

	//Минимальный размер 5, максимальный 15
	if (userPassword.length() <= 5 && userPassword.length() >= 15) {
		return false;
	}

	//Подсчет заглавных букв и цифр
	for (char value : userPassword) {
		if (std::isupper(value)) {
			++upLetterCounter;
		}
		else if (std::isdigit(value)) {
			++numCounter;
		}
	}

	if (upLetterCounter == 0 || numCounter == 0) {
		return false;
	}
	return true;
}

//Локальная функция для шифрования пароля
void passwordEncryption(std::string& userPassword) {
	for (size_t i = 0; i < userPassword.size() - 4; i++) {
		userPassword[i] = userPassword[i] + i;
	}
	for (size_t i = 4; i < userPassword.size(); i++) {
		userPassword[i] = userPassword[i] - i;
	}
}
//Локальная функция для дешифровки пароля
void passwordDecryption(std::string& userPassword) {
	for (size_t i = 0; i < userPassword.size() - 4; i++) {
		userPassword[i] = userPassword[i] - i;
	}
	for (size_t i = 4; i < userPassword.size(); i++) {
		userPassword[i] = userPassword[i] + i;
	}
}

bool userLogin(const std::string& userLogin, std::string& userPassword) {
	if (FileSystem::isExist(userLogin)) {
		/*
		*  Code
		*/
		return true;
	}
	return true;
}

bool userReg(const std::string& userLogin, std::string& userPassword) {
	if (isUserExist(userLogin) || !passwordCheck(userPassword)) {
		return false;
	}
	std::string path = USER_PATH + userLogin + ".txt";
	std::ofstream newUser;

	passwordEncryption(userPassword);

	newUser.open(path);
	newUser.write(reinterpret_cast<const char*>(userPassword.c_str()), userPassword.size());
	return true;
}
