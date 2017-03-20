#define _CRT_SECURE_NO_WARNINGS
#ifndef MODULE_H
#define MODULE_H
//Our abstract base class
#include <iostream>

using namespace std;

class Module
{
public:
	Module()
	{
		cout << "\nA Module instance or instance of one of the inherited classes has just been created.\n\n";
	}

	virtual void driver() = 0;
};
#endif
