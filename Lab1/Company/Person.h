#pragma once

#include "Company.h"
#include <vector>

static unsigned int idDistributor = 0;

class Company;

class Person {
private:
	std::vector <Company> companies;
	const char* firstName;
	const char* middleName;
	const char* lastName;
	unsigned int id;
public:
	Person(const char* firstName, const char* middleName, const char* lastName);
	const char* getFirstName();
	const char* getMiddleName();
	const char* getLastName();
	const unsigned char getCompanyCount();
	const unsigned int getID();
	std::vector <Company>& getCompanies();
	void tryToGetJob(Company& company);
	bool recruitApplication(Company& company);
	void resign(Company& company);
};