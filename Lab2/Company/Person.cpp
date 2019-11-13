#include "Person.h"

Person::Person(const string& firstName, const string& middleName, const string& lastName)
{
	this->firstName = firstName;
	this->middleName = middleName;
	this->lastName = lastName;
	this->id = idDistributor++;
}

const string& Person::getFirstName()
{
		return firstName;
}
const string& Person::getMiddleName()
{
		return middleName;
}
const string& Person::getLastName()
{
		return lastName;
}

const unsigned char Person::getCompanyCount() 
{
		return this->companies.size();
}

const unsigned int Person::getID()
{
		return id;
}

std::vector<Company*>&const Person::getCompanies()
{
		return companies;
}

bool Person::recruitApplication(Company& company)
{
		int chance = rand() % 10 - getCompanyCount();
		if (chance > 4 || companies.size()==0)
		{
			this->getCompanies().push_back(&company);
			return true;
		}
		else
			return false;
}

void Person::tryToGetJob(Boss& boss) 
{
	if (boss.jobApplication(*this)==true)
    {
		this->getCompanies().push_back(boss.getCompany());
	}
}

void Person::resign(Boss& boss) 
{
	boss.dismiss(*this);
}
