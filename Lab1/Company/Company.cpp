#include "Company.h"

Company::Company(const string& name) 
{
	this->name = name;
}

string& Company::getName()
{
	return this->name;
}

void Company::tryToHire(Person& person)
{
	if (person.recruitApplication(*this) == true && this->checkPerson(person) == false) 
	{
		persons.push_back(&person);
	}
}

bool Company::jobApplication(Person& person)
{
	if (this->checkPerson(person) == true) 
	{
		return false;
	}
	else
	{
		int chance = rand() % 10 - person.getCompanyCount();
		if (chance > 4 || persons.size()==0)
        {
			persons.push_back(&person);
			return true;
		}
		else 
			return false;
	}
}

Person& Company::getPersonName(const char* firstName, const char* middleName, const char* lastName) 
{
	auto iterator = std::find_if(persons.begin(), persons.end(), [firstName, middleName, lastName](Person* current) {
		return ((*current).getFirstName() == firstName
			&& (*current).getMiddleName() == middleName
			&& (*current).getLastName() == lastName);
	} );
	if (iterator != persons.end())
		return **iterator;
}

Person& Company::getPersonID(unsigned int id) 
{
	auto iterator = std::find_if(persons.begin(), persons.end(), [id](Person* current){
		return (*current).getID() == id;
	} );
	if (iterator != persons.end())
		return **iterator;
}

std::vector <Person*>& Company::getPersons() 
{
	return persons;
}

bool Company::checkPerson(Person& person) 
{
	unsigned int id = person.getID();
	auto iterator = std::find_if(persons.begin(), persons.end(), [id](Person* person) {
		return (*person).getID() == id;
	});
	if (iterator != persons.end())
		return true;
	else
		return false;
}

void Company::dismiss(Person& person) 
{
		unsigned int id = person.getID();
		persons.erase(std::remove_if(persons.begin(), persons.end(), [id](Person* person) {
			return (*person).getID() == id;
		}));

		string& name = this->name;
		person.getCompanies().erase(std::remove_if(person.getCompanies().begin(), person.getCompanies().end(), [name](Company* company) {
			return (*company).getName() == name;
		}));
}

std::ostream& operator<<(std::ostream & out, Company& company)
{
	out << company.getName() << ":\n";
	for (auto i = company.getPersons().begin(); i != company.getPersons().end(); i++) 
	{
		out << "   " << (*i)->getMiddleName() << " " << (*i)->getFirstName() << " " << (*i)->getLastName() << "\n";
	}
	out << "\n";
	return out;
}
