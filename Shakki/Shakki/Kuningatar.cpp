#include "Kuningatar.h"
#include "Asema.h"

void Kuningatar::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {
	// Ylös
	for (int i = alkuRuutu->getRivi() + 1; i < 8; i++) {
		if (!asema->lauta[i][alkuRuutu->getSarake()]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, alkuRuutu->getSarake())));
		}
		else {
			break;
		}
	}

	// Alas
	for (int i = alkuRuutu->getRivi() - 1; i >= 0; i--) {
		if (!asema->lauta[i][alkuRuutu->getSarake()]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, alkuRuutu->getSarake())));
		}
		else {
			break;
		}
	}

	// Oikealle
	for (int i = alkuRuutu->getSarake() + 1; i < 8; i++) {
		if (!asema->lauta[alkuRuutu->getRivi()][i]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, alkuRuutu->getSarake())));
		}
		else {
			break;
		}
	}

	// Vasemmalle
	for (int i = alkuRuutu->getSarake() - 1; i >= 0; i--) {
		if (!asema->lauta[alkuRuutu->getRivi()][i]) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(i, alkuRuutu->getSarake())));
		}
		else {
			break;
		}
	}
	
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
