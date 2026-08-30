#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <cctype>
using namespace std;
class Person {
protected:
	int  id;
	string name, password;
public:
	Person(int id, string name, string password);
	int getId() const;
	string getName() const;
	string getPassword() const;
	void setId(int id);
	virtual void setName(string name) = 0;
	virtual void setPassword(string password) = 0;
	virtual void display() const;
};
