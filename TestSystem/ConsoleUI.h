#pragma once

#include "User.h"
#include "LoginSystem.h"

#include <iostream>
#include <fstream>

#include <Windows.h>
#include <time.h>
#include <conio.h>


class ConsoleUI {
private:
	std::string login, password;

	void showMessage(const std::string& message);

	void userRegUI();

	void userLogUI();

public:
	ConsoleUI(std::string login, std::string pasword);
	void welcomeScreen();

	void adminRegUI();

	void mainScreen();

	void adminPanel();
};

