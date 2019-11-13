#pragma once

#include "Person.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

class Person;
class Boss;
class Employe;

class Company {
private:
	Boss* boss;
	string name;
	std::vector<Person*> persons;

	friend std::ostream& operator<< (std::ostream &out, Company& company);
public:
	Company(const string& name);
	string& getName();
	std::vector <Person*>&const getPersons();

	Person& getPersonName(const string& firstName, const string& middleName, const string& lastName);
	Person& getPersonID(unsigned int id);
	bool checkPerson(Person& person);

	friend class Boss;
};