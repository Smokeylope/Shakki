#include "Kuningatar.h"
#include "Asema.h"

void Kuningatar::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {
	// Ylös
	for (int i = alkuRuutu->getRivi() + 1; i < 8; i++) {
		int j = alkuRuutu->getSarake();

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

	// Alas
	for (int i = alkuRuutu->getRivi() - 1; i >= 0; i--) {
		int j = alkuRuutu->getSarake();

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

	// Oikealle
	for (int j = alkuRuutu->getSarake() + 1; j < 8; j++) {
		int i = alkuRuutu->getRivi();

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

	// Vasemmalle
	for (int j = alkuRuutu->getSarake() - 1; j >= 0; j--) {
		int i = alkuRuutu->getRivi();

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
	
	// Yläoikealle
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

	// Ylävasemmalle
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
