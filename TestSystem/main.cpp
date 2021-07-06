#include <iostream>
#include "FileSystem.h"
#include "LoginSystem.h"
int main() {
	//FileSystem::createBaseDirectory();
	std::string l = "LoginName", p = "Password";
    std::cout << userReg(l,p);

}