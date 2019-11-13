#include "Company.h"
#include <iostream>
#include <ctime>

unsigned int Person::idDistributor;

int main() {

	Person::idDistributor = 0;

	srand(time(0));	

	Company Dahl("Dahl");
	Company Hyperion("Hyperion");
	Company Maliwan("Maliwan");

	Employe Ivan ("Ivan", "Ivanov", "Ivanich");
	Employe Tigr ("Tigr", "Evstratov", "Gilgamechovish");
	Employe Pantera ("Pantera", "Best", "Ever");
	Employe Aloysius ("Aloysius", "Adalbertus", "Kalkstein");
	Employe Augusta("Augusta", "Ada", "Lovelace");
	Employe Biba("Biba", "Byba", "Berg");
	Employe Kola("Kola", "Andreev", "Girasimovich");



	Boss *BossIvan = new Boss(Ivan, Dahl);
	Boss *BossAugusta = new Boss(Augusta, Maliwan);
	Boss *BossTigr = new Boss(Tigr, Hyperion);

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

	delete (Boss*)BossIvan;
	BossIvan = nullptr;

	BossIvan->tryToHire(Biba);

	Boss *BossPantera = new Boss(Pantera, Dahl);
	std::cout << Dahl << Hyperion << Maliwan;
	getchar();
	return 0;
}