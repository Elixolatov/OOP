#pragma once

#include "Company.h"
#include <vector>
#include <string>

using namespace std;

class Company;

class Person {

private:
	std::vector <Company*> companies;
	string firstName;
	string middleName;
	string lastName;
	unsigned int id;
public:
	static unsigned int idDistributor;
	Person(const string& firstName, const string& middleName, const string& lastName);
	string& getFirstName();
	string& getMiddleName();
	string& getLastName();
	const unsigned char getCompanyCount();
	const unsigned int getID();
	std::vector <Company*>& getCompanies();
	void tryToGetJob(Company& company);
	bool recruitApplication(Company& company);
	void resign(Company& company);
};