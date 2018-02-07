#include "Lahetti.h"
#include "Asema.h"

void Lahetti::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {
	
	// Yl�oikealle
	int j = alkuRuutu->getSarake() + 1;

	for (int i = alkuRuutu->getRivi() + 1; i < 8 && j < 8; i++, j++) {
		if (!asema->lauta[i][j]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j]->getVari() != asema->getSiirtovuoro()) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, j)));
			break;
		}
		else {
			break;
		}
	}

	// Alaoikealle
	j = alkuRuutu->getSarake() + 1;

	for (int i = alkuRuutu->getRivi() - 1; i >= 0 && j < 8; i--, j++) {
		if (!asema->lauta[i][j]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j]->getVari() != asema->getSiirtovuoro()) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, j)));
			break;
		}
		else {
			break;
		}
	}

	// Yl�vasemmalle
	j = alkuRuutu->getSarake() - 1;

	for (int i = alkuRuutu->getRivi() + 1; i < 8 && j >= 0; i++, j--) {
		if (!asema->lauta[i][j]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j]->getVari() != asema->getSiirtovuoro()) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, j)));
			break;
		}
		else {
			break;
		}
	}

	// Alavasemmalle
	j = alkuRuutu->getSarake() - 1;

	for (int i = alkuRuutu->getRivi() - 1; i >= 0 && j >= 0; i--, j--) {
		if (!asema->lauta[i][j]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j]->getVari() != asema->getSiirtovuoro()) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, j)));
			break;
		}
		else {
			break;
		}
	}
}
