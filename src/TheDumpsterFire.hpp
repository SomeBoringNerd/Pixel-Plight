#pragma once

/*************************************************************************************************************************/
/*

Context for that header : In C++ there's this fucking thing called "Circular declaration"

tl:dr : C++ is dumb, it took me 3 hours to find this stupid solution. Find implementation in main.cpp

**************************************************************************************************************************/
#include <string>

class MainMenu;
class Credit;

void LoadAnotherScene(std::string name);