#pragma once
#include <string>
#include <iostream>
#include "FileSystem.h"
class User {
private:
	std::string login, password;
	std::string userName;
	std::string userNumber;
	std::string userEmail;
	std::string userPassportNum;
	bool isAdmin = false;
	std::string path;
public:
	std::string getName() const;
	std::string getNumber() const;
	std::string getEmail() const;
	std::string getPassportNum() const;

	std::string getLogin() const;
	std::string getPassword() const;

	bool getIsAdmin() const;



	void setName(const std::string& newName);
	void setNumber(const std::string& newNumber);
	void setEmail(const std::string& newEmail);
	void setPassportNum(const std::string& newPasportNum);
	void setPath(const std::string& path);

	void setLogin(const std::string& login);
	void setPassword(const std::string& password);

	void setAdmin(bool isAdmin);

	void sendData();
	//Admin func

	void deleteUser(const std::string& login);
	void editUser(const std::string& login, std::string text, line _line);
	void addUser(const std::string& login, std::string& password);

	friend std::istream& operator >>(std::istream& is, User& newUser);
	friend std::ostream& operator <<(std::ostream& os, const User& user);
};

