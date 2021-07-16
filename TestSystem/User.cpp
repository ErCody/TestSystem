#include "User.h"
#include "FileSystem.h"
#include "LoginSystem.h"
#include <fstream>

std::string User::getName() const {
	return userName;
}

std::string User::getNumber() const {
	return userNumber;
}

std::string User::getEmail() const {
	return userEmail;
}

std::string User::getPassportNum() const {
	return userPassportNum;
}

std::string User::getLogin() const {
	return login;
}

std::string User::getPassword() const {
	return password;
}

bool User::getIsAdmin() const {
	return isAdmin;
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

void User::setPassportNum(const std::string& newPassportNum) {
	userPassportNum = newPassportNum;
}

void User::setPath(const std::string& path) {
	this->path = path;
}

void User::setLogin(const std::string& login) {
	this->login = login;
}

void User::setPassword(const std::string& password) {
	this->password = password;
}

void User::setAdmin(bool isAdmin) {
	this->isAdmin = isAdmin;
}

void User::sendData() {
	path = USER_PATH + login + '/' + login + ".txt";
	FileSystem::writeDataEnd(path, userName);
	FileSystem::writeDataEnd(path, userNumber);
	FileSystem::writeDataEnd(path, userEmail);
	FileSystem::writeDataEnd(path, userPassportNum);
}

void User::deleteUser(const std::string& login) {
	std::string path = USER_PATH + login + '/';

	FileSystem::deleteAll(path);
}

void User::editUser(const std::string& login, std::string text, line _line) {
	std::string path = USER_PATH + login + '/' + login + ".txt";
	FileSystem::editDataLine(path, text, _line);
}

void User::addUser(const std::string& login, std::string& password) {

	User newUser;
	LoginSystem::userReg(login, password);
	newUser.setLogin(login);
	std::cin >> newUser;

}



std::istream& operator>>(std::istream& is, User& newUser) {
	std::string temp;
	std::cout << "Your full name: "; std::getline(is, temp);
	newUser.setName(temp);
	std::cout << "Your number: "; std::getline(is, temp);
	newUser.setNumber(temp);
	std::cout << "Your Email: "; std::getline(is, temp);
	newUser.setEmail(temp);
	std::cout << "Your passport number: "; std::getline(is, temp);
	newUser.setPassportNum(temp);

	newUser.sendData();
	return is;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
	os << "Full Name: " << user.getName() << std::endl;
	os << "Phone Number: " << user.getNumber() << std::endl;
	os << "Email: " << user.getEmail() << std::endl;
	os << "Passport Number: " << user.getPassportNum() << std::endl;
	return os;
}
