#include "Company.h"
#include <iostream>
#include <ctime>

unsigned int Person::idDistributor;

int main() {

	Person::idDistributor = 0;

	srand(time(0));	


	Employe Ivan ("Ivan", "Ivanov", "Ivanich");
	Employe Tigr ("Tigr", "Evstratov", "Gilgamechovish");
	Employe Pantera ("Pantera", "Best", "Ever");
	Employe Aloysius ("Aloysius", "Adalbertus", "Kalkstein");
	Employe Augusta("Augusta", "Ada", "Lovelace");
	Employe Biba("Biba", "Byba", "Berg");
	Employe Kola("Kola", "Andreev", "Girasimovich");



	Boss *BossIvan = new Boss(Ivan, "Dahl");
	Boss *BossAugusta = new Boss(Augusta, "Hyperion");
	Boss *BossTigr = new Boss(Tigr, "Maliwan");

	Ivan.tryToGetJob(*BossTigr);
	Ivan.tryToGetJob(*BossAugusta);
	Ivan.tryToGetJob(*BossTigr);

	BossIvan->tryToHire(Ivan);
	BossIvan->tryToHire(Kola);
	BossAugusta->tryToHire(Kola);
	BossTigr->tryToHire(Kola);

	BossAugusta->dismiss(Ivan);
	Ivan.resign(*BossAugusta);
	Ivan.resign(*BossTigr);

	BossIvan->getCompany()->getPersonName("Kola", "Andreev", "Girasimovich");
	std::cout << *BossIvan->getCompany() << *BossAugusta->getCompany() << *BossTigr->getCompany();
	getchar();
	return 0;
}