#include "Person.h"

Person::Person(const string& firstName, const string& middleName, const string& lastName)
{
	this->firstName = firstName;
	this->middleName = middleName;
	this->lastName = lastName;
	this->id = idDistributor++;
}

string& Person::getFirstName()
{
		return firstName;
}
string& Person::getMiddleName()
{
		return middleName;
}
string& Person::getLastName()
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

std::vector<Company*>& Person::getCompanies() 
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

void Person::tryToGetJob(Company& company) 
{
	if (company.jobApplication(*this)==true)
    {
		this->getCompanies().push_back(&company);
	}
}

void Person::resign(Company& company) 
{
		if (company.checkPerson(*this) == true) 
		{
			string& name = company.getName();
			companies.erase(std::remove_if(companies.begin(), companies.end(), [name](Company* company) {
				return (*company).getName() == name;
			} ));

			unsigned int id = this->id;
			company.getPersons().erase(std::remove_if(company.getPersons().begin(), company.getPersons().end(), [id](Person* person) {
				return (*person).getID() == id;
			} ));
		}
}
