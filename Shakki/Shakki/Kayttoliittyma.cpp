#include "Kayttoliittyma.h"

Kayttoliittyma::Kayttoliittyma(Asema* asema) {
	_asema = asema;
}

void Kayttoliittyma::piirraLauta() {
	const char sarakkeet[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	for (int i = 7; i >= -1; i--) {
		if (i > -1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
				BACKGROUND_GREEN | BACKGROUND_BLUE);
			std::wcout << i + 1;

			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0) {
					if (i % 2 == 0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
							BACKGROUND_GREEN);
					}
					else {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
							BACKGROUND_GREEN | BACKGROUND_BLUE);
					}
				}
				else {
					if ( i % 2 != 0 ) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
							BACKGROUND_GREEN);
					}
					else {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
							BACKGROUND_GREEN | BACKGROUND_BLUE);
					}
				}
				//std::wcout << L'\u265F';

				if (_asema->lauta[i][j]) {
					std::wcout << _asema->lauta[i][j]->getUnicode();
				}
				else {
					std::wcout << " ";
				}
			}
		}
		else {
			for ( int j = 0; j < 9; j++) {
				std::wcout << sarakkeet[ j ];
			}
		}

		std::wcout << '\n';
	}
}

Siirto Kayttoliittyma::annaVastustajanSiirto() {
	std::wcout << "Siirtovuoro: " << _asema->getSiirtovuoro() << '\n';
	std::wcout << "Evaluointiarvo: " << _asema->evaluoi() << '\n';
	std::wcout << "Anna siirto:\n";

	char alkuSarake = 0;
	char alkuRivi = 0;
	char loppuSarake = 0;
	char loppuRivi = 0;
	bool siirtoKelpaa = false;

	while (!siirtoKelpaa) {
		std::string siirto;
		std::cin >> siirto;

		if (siirto == "O-O") {
			return Siirto(true, false);
		}
		else if (siirto == "O-O-O") {
			return Siirto(false, true);
		}
		else if (siirto.length() == 5) {
			alkuSarake = siirto[0];
			alkuRivi = siirto[1];
			loppuSarake = siirto[3];
			loppuRivi = siirto[4];

			if (alkuSarake >= 'a' && alkuSarake <= 'h' && alkuRivi >= '1' && alkuRivi <= '8' &&
				loppuSarake >= 'a' && loppuSarake <= 'h' && loppuRivi >= '1' && loppuRivi <= '8') {

				siirtoKelpaa = true;
			}
		}
	}
	
	return Siirto(Ruutu(alkuRivi - '1', alkuSarake - 'a'),
		Ruutu(loppuRivi - '1', loppuSarake - 'a'));
}
