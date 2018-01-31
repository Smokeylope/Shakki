#include "Lahetti.h"

void Lahetti::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {
		for (int i = 1; i < 8; i++) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + i, alkuRuutu->getSarake() + i)));
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - i, alkuRuutu->getSarake() + i)));
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - i, alkuRuutu->getSarake() - i)));
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + i, alkuRuutu->getSarake() - i)));
		}
}
