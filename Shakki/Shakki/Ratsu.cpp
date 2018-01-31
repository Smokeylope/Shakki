#include "Ratsu.h"

void Ratsu::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {

		lista.push_back(Siirto(*alkuRuutu,Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() + 2))); // Oikea ylänurkka, oikea puoli, clockwise
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 2, alkuRuutu->getSarake() + 1)));
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 2, alkuRuutu->getSarake() - 1)));
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() - 2)));
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() - 2)));// Ala-keski, Vasen puoli, clockwise
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 2, alkuRuutu->getSarake() - 1)));
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 2, alkuRuutu->getSarake() + 1)));
		lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() + 2)));
}
