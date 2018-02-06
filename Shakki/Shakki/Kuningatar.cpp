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

	for (int i = 1; i < 8; i++) {
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + i, alkuRuutu->getSarake() + i)));
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - i, alkuRuutu->getSarake() + i)));
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - i, alkuRuutu->getSarake() - i)));
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + i, alkuRuutu->getSarake() - i)));
	}
	
	// Yläoikealle
	//for (int i = alkuRuutu->getRivi() + 1, int j = alkuRuutu->getSarake() + 1; i < 
}
