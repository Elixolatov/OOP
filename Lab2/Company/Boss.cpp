#include "Company.h"
#include "Person.h"

Boss::Boss(Person& person, Company& company) {
		this->firstName = person.getFirstName();
		this->middleName = person.getMiddleName();
		this->lastName = person.getLastName();
		this->company = &company;
		id = person.getID();
		company.boss = this;
}

Boss::~Boss() {
	company->boss = nullptr;
	this->company = nullptr;
}

void Boss::dismiss(Person& person)
{
		if (id != person.getID()) {
			if (company->checkPerson(person) == true) {
				unsigned int id = person.getID();
				company->persons.erase(std::remove_if(company->persons.begin(), company->persons.end(), [id](Person* current) {
					return current->getID() == id;
				}), company->persons.end());

				string name = company->name;
				person.getCompanies().erase(std::remove_if(person.getCompanies().begin(), person.getCompanies().end(), [name](Company* current) {
					return current->getName() == name;
				}), person.getCompanies().end());
			}
		}
}

void Boss::tryToHire(Person& person)
{
		if (id != person.getID() && (company->checkPerson(person) == false || person.recruitApplication(*company) == true))
		{
			company->persons.push_back(&person);
		}
}

bool Boss::jobApplication(Person& person)
{
		if ((id == person.getID()) || (company->checkPerson(person) == true))
		{
			return false;
		}
		else
		{
			int chance = rand() % 10 - person.getCompanyCount();
			if (chance > 4 || company->persons.size() == 0)
			{
				company->persons.push_back(&person);
				return true;
			}
			else
				return false;
		}
}

 Company *const Boss::getCompany() {
	return company;
}