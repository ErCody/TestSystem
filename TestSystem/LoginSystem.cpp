#include "LoginSystem.h"
#include "FileSystem.h"

#include <fstream>
#include <iostream>

#include <string>


//��������� ������� ��� ��������, ���������� �� ����� ������������ ��� ���
bool isUserExist(const std::string& userLogin) {
	std::string path = USER_PATH + userLogin + ".txt";
	if (FileSystem::isExist(path)) {
		return true;
	}
	return false;
	
}

//��������� ������� ��� �������� ������ �� ���������
bool passwordCheck(const std::string& userPassword) {
	uint8_t upLetterCounter = 0;
	uint8_t numCounter = 0;

	//����������� ������ 5, ������������ 15
	if (userPassword.length() <= 5 && userPassword.length() >= 15) {
		return false;
	}

	//������� ��������� ���� � ����
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

//��������� ������� ��� ���������� ������
void passwordEncryption(std::string& userPassword) {
	for (size_t i = 0; i < userPassword.size() - 4; i++) {
		userPassword[i] = userPassword[i] + i;
	}
	for (size_t i = 4; i < userPassword.size(); i++) {
		userPassword[i] = userPassword[i] - i;
	}
}
//��������� ������� ��� ���������� ������
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
