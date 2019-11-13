#pragma once

#include "Company.h"
#include <vector>
#include <string>

using namespace std;

class Company;
class Person;
class Boss;
class Employe;

class Person {

public:
	static unsigned int idDistributor;
	Person(const string firstName, const string middleName, const string lastName);
	Person() = default;
	string getFirstName();
	string getMiddleName();
	string getLastName();
	const unsigned char getCompanyCount();
	const unsigned int getID();
	std::vector <Company*>& getCompanies();
	void tryToGetJob(Boss& boss);
	bool recruitApplication(Company& company);
	void resign(Company& company);
protected:
	std::vector <Company*> companies;
	string firstName;
	string middleName;
	string lastName;
	unsigned int id;
};

class Boss : public Person {
public:
	Boss(Person& person, const string& name);
	void dismiss(Person& person);
	void tryToHire(Person& person);
	bool jobApplication(Person& person);
	Company *const getCompany();
protected:
	Company * company;
};

class Employe : public Person {
public:
	Employe(const string firstName, const string middleName, const string lastName) : Person(firstName, middleName, lastName) {}
};