#include <iostream>
#include "FileSystem.h"
#include "LoginSystem.h"
int main() {
	//FileSystem::createBaseDirectory();
	std::string l = "LoginName", p = "Password1";
    std::cout << userReg(l,p);

}