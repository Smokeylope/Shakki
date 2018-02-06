#include "Lahetti.h"
#include "Asema.h"

void Lahetti::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {
	
	// Yläoikealle
	int j = alkuRuutu->getSarake() + 1;

	for (int i = alkuRuutu->getRivi() + 1; i < 8 && j < 8; i++, j++) {
		if (!asema->lauta[i][j]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, alkuRuutu->getSarake())));
		}
		else {
			break;
		}
	}

	// Alaoikealle
	j = alkuRuutu->getSarake() + 1;

	for (int i = alkuRuutu->getRivi() - 1; i < 8 && j < 8; i--, j++) {
		if (!asema->lauta[i][j]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, alkuRuutu->getSarake())));
		}
		else {
			break;
		}
	}

	// Ylävasemmalle
	j = alkuRuutu->getSarake() - 1;

	for (int i = alkuRuutu->getRivi() + 1; i < 8 && j < 8; i++, j--) {
		if (!asema->lauta[i][j]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, alkuRuutu->getSarake())));
		}
		else {
			break;
		}
	}

	// Alavasemmalle
	j = alkuRuutu->getSarake() - 1;

	for (int i = alkuRuutu->getRivi() - 1; i < 8 && j < 8; i--, j--) {
		if (!asema->lauta[i][j]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, alkuRuutu->getSarake())));
		}
		else {
			break;
		}
	}
}
