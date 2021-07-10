#include <iostream> 
#include <string> 
#include "ConsoleUI.h"

class Application {
	std::string login, password;
public:
	void run() {
		ConsoleUI UI(login, password);
		User activeUser;
		if (!LoginSystem::isAdminExist()) {
			UI.adminRegUI();
		}
		UI.welcomeScreen();
		UI.mainScreen();
		if (activeUser.isAdmin) {
			
		}
	}

};

int main() {

}