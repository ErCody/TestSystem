#pragma once

#include "User.h"
#include "LoginSystem.h"
#include "TestSystem.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include <Windows.h>
#include <time.h>
#include <conio.h>


class ConsoleUI {
private:
	std::string login, password;

	void showMessage(const std::string& message);

	void userRegUI(User& user);

	void userLogUI(User& user);

public:
	ConsoleUI(std::string& login, std::string& pasword);
	void welcomeScreen(User& user);

	void adminRegUI(User& user);

	void mainScreen(TestHandler& test);

	void adminPanel(User& user);

	void usersPanel(User& user);

	void testScreen(TestHandler& test);
};

