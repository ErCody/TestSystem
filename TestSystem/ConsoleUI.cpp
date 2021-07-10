#include "ConsoleUI.h"

void ConsoleUI::showMessage(const std::string& message) {
	std::cout << "|" << message << '|' << std::endl;
	std::cout << '|';
	for (size_t i = 0; i < message.length(); i++) {
		std::cout << '_';
	}
	std::cout << "|\n" << std::endl;
}

void ConsoleUI::userRegUI() {
	Sleep(500);
	system("cls");
	while (true) {
		showMessage("Tip: Login must be unique. Password must be at least 5 characters,"
			"and contain uppercase letter & number");
		std::cout << "Enter login: ";
		std::getline(std::cin, login);
		std::cout << "Enter password: ";
		std::getline(std::cin, password);
		if (!LoginSystem::userReg(login, password)) {
			system("cls");
			showMessage("Error: Invalid Password or Login");
			continue;
		}
		break;
	}
}

void ConsoleUI::userLogUI() {
	system("cls");
	while (true) {
		std::cout << "Enter login: ";
		std::getline(std::cin, login);
		std::cout << "Enter password: ";
		std::getline(std::cin, password);
		if (!LoginSystem::userLogin(login, password)) {
			system("cls");
			showMessage("Error: Invalid Password or Login");
			continue;
		}
		break;
	}
}

ConsoleUI::ConsoleUI(std::string login, std::string pasword) :
	login(login),
	password(password) {}

void ConsoleUI::welcomeScreen() {
	std::cout << "Testing System" << std::endl;
	std::cout << "1.Registration\n2.Login System\n3.Help\n";
	char ch = _getch();

	switch (ch) {
	case '1': userRegUI(); break;
	case '2': userLogUI(); break;
	default: break;
	}
}

void ConsoleUI::adminRegUI() {
	std::cout << "There is no admin in system." << std::endl;
	Sleep(1500);
	system("cls");
	while (true) {
		showMessage("Tip: Password must be at least 5 characters,"
			"and contain uppercase letter & number");
		std::cout << "Enter Password for Admin user: ";
		std::getline(std::cin, password);
		if (!LoginSystem::adminReg(password)) {
			system("cls");
			showMessage("Error: Invalid Password");
			continue;
		}
		std::cout << "The application will be restarted to add an admin." << std::endl;
		Sleep(3000);
		system("cls");
		break;
	}
}

void ConsoleUI::mainScreen() {
	std::cout << " Welcome Back" << std::endl;
	std::cout << "1.Take Test\n2.Statistic\n3.Options\n";
	char ch = _getch();

	switch (ch) {
	//case '1': ; break;
	//case '2': ; break;
	default: break;
	}
}

void ConsoleUI::adminPanel() {
	std::cout << "Admin Panel." << std::endl;
	std::cout << "1.Users Panel\n2.Tests Panel\n3.\n";
	char ch = _getch();
	switch (ch) {
	//case '1': ; break;
	//case '2': ; break;
	default: break;
	}
}
