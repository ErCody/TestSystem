#include "User.h"
#include "FileSystem.h"
std::string User::getName() {
	return userName;
}

std::string User::getNumber() {
	return userNumber;
}

std::string User::getEmail() {
	return userEmail;
}

std::string User::getPasportNum() {
	return userPasportNum;
}

void User::setName(const std::string& newName) {
	userName = newName;
}

void User::setNumber(const std::string& newNumber) {
	userNumber = newNumber;
}

void User::setEmail(const std::string& newEmail) {
	userEmail = newEmail;
}

void User::setPasportNum(const std::string& newPasportNum) {
	userPasportNum = newPasportNum;
}

bool User::deleteUser(const std::string& login) {
	std::string path = USER_PATH + login + '/' + login + ".txt";
	if (!FileSystem::isExist(path)) {
		return false;
	}
	std::remove(path.c_str());
	return true;
}

std::istream& operator>>(std::istream& is, User& newUser) {
	std::cout << "Your full name: "; std::getline(is, newUser.userName);
	std::cout << "Your number: "; std::getline(is, newUser.userNumber);
	std::cout << "Your Email: "; std::getline(is, newUser.userEmail);
	std::cout << "Your passport number: "; std::getline(is, newUser.userPasportNum);
	return is;
}
