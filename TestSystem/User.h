#pragma once
#include <string>
class User {
private:
	std::string userName;
	std::string userNumber;
	std::string userEmail;
	std::string userPasportNum;
public:
	std::string getName();
	std::string getNumber();
	std::string getEmail();
	std::string getPasportNum();

	void setName(const std::string& newName);
	void setNumber(const std::string& newNumber);
	void setEmail(const std::string& newEmail);
	void setPasportNum(const std::string& newPasportNum);
};


