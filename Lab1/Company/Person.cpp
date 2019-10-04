#include "Person.h"

Person::Person(const char* firstName, const char* middleName, const char* lastName) 
{
	this->firstName = firstName;
	this->middleName = middleName;
	this->lastName = lastName;
	this->id = idDistributor++;
}

const char* Person::getFirstName() 
{
	if (this != nullptr)
		return firstName;
	return nullptr;
}
const char* Person::getMiddleName() 
{
	if (this != nullptr)
		return middleName;
	return nullptr;
}
const char* Person::getLastName() 
{
	if (this != nullptr)
		return lastName;
	return nullptr;
}

const unsigned char Person::getCompanyCount() 
{
	if (this != nullptr)
		return this->companies.size();
	return -1;
}

const unsigned int Person::getID()
{
	if(this != nullptr)
		return id;
	return 0;
}

std::vector<Company>& Person::getCompanies() 
{
	if (this != nullptr)
		return companies;
}

bool Person::recruitApplication(Company& company)
{
		int chance = rand() % 10 - getCompanyCount();
		if (chance > 4 || companies.size()==0)
		{
			this->getCompanies().push_back(company);
			return true;
		}
		else
			return false;
}

void Person::tryToGetJob(Company& company) 
{
	if (this != nullptr && company.jobApplication(*this)==true)
    {
		this->getCompanies().push_back(company);
	}
}

void Person::resign(Company& company) 
{
	if (this != nullptr) 
	{
		if (company.checkPerson(*this) == true) 
		{
			const char* name = company.getName();
			companies.erase(std::remove_if(companies.begin(), companies.end(), [name](Company& company) {
				return company.getName() == name;
			} ));

			unsigned int id = this->id;
			company.getPersons().erase(std::remove_if(company.getPersons().begin(), company.getPersons().end(), [id](Person& person) {
				return person.getID() == id;
			} ));
		}
	}
}
