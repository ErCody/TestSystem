#include "User.h"

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
