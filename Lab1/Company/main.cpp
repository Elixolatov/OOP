#include "Company.h"
#include <iostream>
#include <ctime>

int main() {
	srand(time(0));
	Company Dahl("Dahl");
	Company Hyperion("Hyperion");
	Company Maliwan("Maliwan");

	Person Ivan("Ivan", "Ivanov", "Ivanich");
	Person Tigr("Tigr", "Evstratov", "Gilgamechovish");
	Person Pantera("Pantera", "Best", "Ever");
	Person Aloysius("Aloysius", "Adalbertus", "Kalkstein");
	Person Augusta("Augusta", "Ada", "Lovelace");
	Person Biba("Biba", "Byba", "Berg");
	Person Kola("Kola", "Andreev", "Girasimovich");

	Ivan.tryToGetJob(Maliwan);
	Ivan.tryToGetJob(Hyperion);
	Ivan.tryToGetJob(Dahl);

	Dahl.dismiss(Ivan);
	Ivan.resign(Maliwan);

	Tigr.tryToGetJob(Dahl);
	Biba.tryToGetJob(Dahl);
	Kola.tryToGetJob(Dahl);
	Kola.tryToGetJob(Maliwan);
	Kola.tryToGetJob(Hyperion);
	Aloysius.tryToGetJob(Maliwan);\
	Biba.tryToGetJob(Hyperion);

	Dahl.tryToHire(Pantera);
	Dahl.tryToHire(Kola);
	Dahl.tryToHire(Biba);
	Maliwan.tryToHire(Biba);
	Maliwan.tryToHire(Kola);
	Maliwan.tryToHire(Augusta);
	Maliwan.tryToHire(Tigr);


	std::cout << Dahl << Hyperion << Maliwan;
	getchar();
	return 0;
}