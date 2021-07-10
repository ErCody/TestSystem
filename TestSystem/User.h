#pragma once
#include <string>
#include <iostream>
class User {
private:
	std::string userName;
	std::string userNumber;
	std::string userEmail;
	std::string userPasportNum;
	bool isAdmin;
	friend std::istream& operator >>(std::istream& is, User& newUser);
public:
	std::string getName();
	std::string getNumber();
	std::string getEmail();
	std::string getPasportNum();

	void setName(const std::string& newName);
	void setNumber(const std::string& newNumber);
	void setEmail(const std::string& newEmail);
	void setPasportNum(const std::string& newPasportNum);

	//Admin func

	bool deleteUser(const std::string& login);

	friend class Application;
};

