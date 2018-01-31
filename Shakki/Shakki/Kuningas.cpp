#include "Kuningas.h"

void Kuningas::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {
	lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi(), alkuRuutu->getSarake() + 1))); // Klo 12
	lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() + 1)));
	lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake())));
	lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() - 1)));
	lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi(), alkuRuutu->getSarake() - 1))); // Klo 6
	lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() - 1)));
	lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake())));
	lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() + 1)));
}
