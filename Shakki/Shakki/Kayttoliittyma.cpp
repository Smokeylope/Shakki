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
			std::wcout << i;

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
		else if (siirto.length() == 6) {
			alkuSarake = siirto[1];
			alkuRivi = siirto[2];
			loppuSarake = siirto[4];
			loppuRivi = siirto[5];

			if (alkuSarake >= 'a' && alkuSarake <= 'h' && alkuRivi >= '0' && alkuRivi <= '7' &&
				loppuSarake >= 'a' && loppuSarake <= 'h' && loppuRivi >= '0' && loppuRivi <= '7') {

				siirtoKelpaa = true;
			}
		}
	}
	
	return Siirto(Ruutu(alkuRivi - '0', alkuSarake - 'a'),
		Ruutu(loppuRivi - '0', loppuSarake - 'a'));
}
