#include "Company.h"

Company::Company(const string& name) 
{
	this->name = name;
}

string& Company::getName()
{
	return this->name;
}

Person& Company::getPersonName(const string& firstName, const string& middleName, const string& lastName)
{
	auto iterator = std::find_if(persons.begin(), persons.end(), [&firstName, &middleName, &lastName](Person* current) {
		return (current->getFirstName() == firstName)
			&& (current->getMiddleName() == middleName)
			&& (current->getLastName() == lastName);
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

std::vector <Person*>&const Company::getPersons()
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

std::ostream& operator<<(std::ostream & out, Company& company)
{
	out << company.getName() << ":\n";
	if (company.boss != nullptr)
	{
		out << "  Boss:\n"<<"   " << company.boss->getMiddleName() << " " << company.boss->getFirstName() << " " << company.boss->getLastName() << "\n";
	}
	out << "  Employe:\n";
	for (auto i = company.getPersons().begin(); i != company.getPersons().end(); i++) 
	{
		out << "   " << (*i)->getMiddleName() << " " << (*i)->getFirstName() << " " << (*i)->getLastName() << "\n";
	}
	out << "\n";
	return out;
}
