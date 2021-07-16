#include <iostream> 
#include <string> 
#include "ConsoleUI.h"
#include <fstream>
#include "FileSystem.h"
#include "TestSystem.h"


class Application {
	std::string login, password;
public:
	void run() {

		ConsoleUI UI(login, password);
		User activeUser;
		TestHandler testHandler;

		if (!LoginSystem::isAdminExist()) {
			UI.adminRegUI(activeUser);
		}
		UI.welcomeScreen(activeUser);
		while (true) {
			if (activeUser.getIsAdmin()) {
				UI.adminPanel(activeUser);
			}
			else {
				UI.mainScreen(testHandler);
			}
		}
	}

};


void passwordEncryption(std::string& userPassword) {
	for (size_t i = 0; i < userPassword.size() - 4; i++) {
		userPassword[i] = userPassword[i] + i;
	}
	for (size_t i = 4; i < userPassword.size(); i++) {
		userPassword[i] = userPassword[i] - i;
	}
}

//Локальная функция для дешифровки пароля
void passwordDecryption(std::string& userPassword) {
	for (size_t i = 0; i < userPassword.size() - 4; i++) {
		userPassword[i] = userPassword[i] - i;
	}
	for (size_t i = 4; i < userPassword.size(); i++) {
		userPassword[i] = userPassword[i] + i;
	}
}

int main() {
	Application app;
	app.run();
	
}