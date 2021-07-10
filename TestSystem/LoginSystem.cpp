#include "LoginSystem.h"
#include "FileSystem.h"
#include "User.h"

#include <fstream>
#include <iostream>

#include <string>


namespace LoginSystem {

	//Локальная функция для проверки, существует ли такой пользователь или нет
	bool isUserExist(const std::string& userLogin) {
		std::string path = USER_PATH + userLogin + '/' + userLogin + ".txt";
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

	//Локальная функция для проверки совпадения пароля
	bool passwordMatch(const std::string& userLogin, std::string& userPassword) {
		std::string path = USER_PATH + userLogin + '/' + userLogin + ".txt";
		std::string password = FileSystem::getFileData(path, PASSWORD);
		passwordDecryption(password);
		if (password == userPassword) {
			return true;
		}

		return false;
	}

	bool userLogin(const std::string& userLogin, std::string& userPassword) {
		if (isUserExist(userLogin) && passwordMatch(userLogin, userPassword)) {
			return true;
		}
		return false;
	}

	bool userReg(const std::string& userLogin, std::string& userPassword) {
		if (isUserExist(userLogin) || !passwordCheck(userPassword)) {
			return false;
		}
		FileSystem::createDirectory(USER_PATH + userLogin);
		std::string path = USER_PATH + userLogin + '/' + userLogin + ".txt";
		passwordEncryption(userPassword);
		FileSystem::createFile_w(path, userPassword);
		return true;
	}

	bool isAdminExist() {
		std::string path = ADMIN_PATH + "admin.txt";
		if (FileSystem::isExist(path)) {
			return true;
		}
		return false;
	}

	bool adminReg(std::string& adminPassword) {
		if (!passwordCheck(adminPassword)) {
			return false;
		}

		std::string path = ADMIN_PATH + "admin.txt";
		passwordEncryption(adminPassword);
		FileSystem::createFile_w(path, adminPassword);
		return true;
	}
}