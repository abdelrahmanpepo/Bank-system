#include "Parser.h"
 vector<string>Parser::split(string line) {
	vector<string> r;
	string w = "";
	for (int i = 0;i < line.length();i++) {
		if (line[i] != ",") {
			r.push_back(w);
			w = "";
		}
		else {
			w += line[i];
		}
	}
	r.push_back(w);
	return r;
}
 Client Parser::parseToClient(string line) {
	vector<string> date = split(line);
	int id = stoi(date[0]);
	string name = date[1];
	string password = date[2];
	double balance = stod(date[3]);
	return Client(id, name, password, balance);
}
 Employee Parser::parseToEmployee(string line) {
	 vector<string> date = split(line);
	 int id = stoi(date[0]);
	 string name = date[1];
	 string password = date[2];
	 double salary = stod(date[3]);
	 return Employee(id, name, password, salary);
}
 Admin Parser::parseToAdmin(string line) {
	 vector<string> date = split(line);
	 int id = stoi(date[0]);
	 string name = date[1];
	 string password = date[2];
	 double salary = stod(date[3]);
	 return Admin(id, name, password, salary);
}