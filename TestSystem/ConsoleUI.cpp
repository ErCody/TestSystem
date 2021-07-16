#include "ConsoleUI.h"

void ConsoleUI::showMessage(const std::string& message) {
	std::cout << "|" << message << '|' << std::endl;
	std::cout << '|';
	for (size_t i = 0; i < message.length(); i++) {
		std::cout << '_';
	}
	std::cout << "|\n" << std::endl;
}

void ConsoleUI::userRegUI(User& user) {
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
		system("cls");
		showMessage("Tip: You can't edit this data soon. DM Admin if you want to edit data.");
		std::cout << "You must enter information about yourself." << std::endl;
		user.setLogin(login);
		std::cin >> user;
		break;
	}
}

void ConsoleUI::userLogUI(User& user) {
	system("cls");
	while (true) {
		std::cout << "Enter login: ";
		std::getline(std::cin, login);
		std::cout << "Enter password: ";
		std::getline(std::cin, password);
		if (!LoginSystem::userLogin(login, password, user)) {
			system("cls");
			showMessage("Error: Invalid Password or Login");
			continue;
		}
		break;
	}
}

ConsoleUI::ConsoleUI(std::string& login, std::string& pasword) :
	login(login),
	password(password) {}

void ConsoleUI::welcomeScreen(User& user) {
	std::cout << "Testing System" << std::endl;
	std::cout << "1.Registration\n2.Login System\n3.Help\n";
	char ch = _getch();
	switch (ch) {
	case '1': userRegUI(user); break; 
	case '2': userLogUI(user); break; 
	default: break;
		
	}

}

void ConsoleUI::adminRegUI(User& user) {
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

void ConsoleUI::mainScreen(TestHandler& test) {
	std::cout << " Welcome Back" << std::endl;
	std::cout << "1.Take Test\n";
	char ch = _getch();

	switch (ch) {
	case '1': testScreen(test); break;
	//case '2': ; break;
	default: break;
	}
}

void ConsoleUI::adminPanel(User& user) {
	std::cout << "Admin Panel." << std::endl;
	std::cout << "1.Users Panel\n2.Tests Panel\n";
	char ch = _getch();
	switch (ch) {
	case '1': usersPanel(user); break;
	//case '2': ; break;
	default: break;
	}
}

void ConsoleUI::usersPanel(User& user) {
	system("cls");
	std::ifstream usersFile;
	std::string temp;
	std::string _temp;
	uint16_t _line;
	uint64_t ID = 1;
	line _line_ = NONE;
	std::map<uint64_t, std::string> users;

	std::cout << "1.Add user\n2.Edit User\n3.Delete User\n";
	char ch = _getch();

	switch (ch) {
	case '1': 
		system("cls");
		std::cout << "Enter login: "; std::getline(std::cin, temp);
		std::cout << "Enter password: "; std::getline(std::cin, _temp);
		user.addUser(temp, _temp); break;
	case '2': 
		system("cls");
		usersFile.open(USER_FILE_PATH);
		std::cout << "List of users." << std::endl;
		while (getline(usersFile, temp)) {
			users[ID] = temp;
			std::cout << ID << " " << temp << std::endl;
			++ID;
		}
		std::cout << "Enter login ID: "; 
		std::cin >> ID;
		std::cout << "What you want to edit? ";
		std::cout << "1.Password\n2.Name\n3.Number\n4.Email\n5.Passport num\n";
		std::cin >> _line;
		switch (_line) {
		case 1: _line_ = PASSWORD; break;
		case 2: _line_ = NAME; break;
		case 3: _line_ = NUMBER; break;
		case 4: _line_ = EMAIL; break;
		case 5: _line_ = PASPORT_NUM; break;
		default: break;
		}
		std::cin.ignore();
		std::cout << "Enter new data: "; getline(std::cin, temp);
		user.editUser(users[ID], temp, _line_);
		break;
	case '3':
		system("cls");
		usersFile.open(USER_FILE_PATH);
		std::cout << "List of users." << std::endl;
		while (getline(usersFile, temp)) {
			users[ID] = temp;
			std::cout << ID << " " << temp << std::endl;
			++ID;
		}
		std::cin.ignore();
		std::cout << "Enter login ID: ";
		std::cin >> ID;

		user.deleteUser(users[ID]);
		break;
	default: break;
	}
}

void ConsoleUI::testScreen(TestHandler& test) {
	system("cls");
	std::vector<std::string> temp = test.getCategories();
	std::string cat, path;
	std::stringstream str;
	uint16_t rightAnswer;
	int ch; char pressedC;

	std::cout << "Choose category: " << std::endl;

	for (auto value : temp) {
		uint16_t counter = 1;
		std::cout << counter << ". " << value << std::endl;
		counter++;
	}

	pressedC = _getch();
	str << pressedC;
	str >> ch;
	cat = temp[ch - 1];
	temp = test.getTests(temp[ch - 1]);
	system("cls");
	std::cout << "Choose tests: " << std::endl;
	for (auto value : temp) {
		uint16_t counter = 1;
		std::cout << counter << ". " << value << std::endl;
		counter++;
	}

	pressedC = _getch();
	str << pressedC;
	str >> ch;
	path = TESTS_PATH + cat + '/' + temp[ch - 1];
	for (int i = 1; i < JsonSystem::getCount(path); i++) {
		system("cls");
		rightAnswer = 0;
		test.loadQuestion(path, std::to_string(i));
		std::cout << test;

		ch = _getch();
		
		if (test.isRight(std::to_string(i), std::to_string(ch - 48))) {
			std::cout << "Your Answer is right." << std::endl;
			rightAnswer++;
		}
		else {
			std::cout << "Your Answer is wrong." << std::endl;
		}
		Sleep(1500);
		
	}
	double grade = (rightAnswer * 12) / 4;
	std::cout << "Your grade: " << grade << std::endl;
	Sleep(1500);
	system("cls");
}
