#include "Ratsu.h"

void Ratsu::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {

	// Oikea ylänurkka
		// vasen
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() + 2)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() + 2)));
		}
			// oikea
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 2, alkuRuutu->getSarake() + 1)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 2, alkuRuutu->getSarake() + 1)));
		}

	// Oikea alanurkka
		// oikea
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 2, alkuRuutu->getSarake() - 1)) {
		
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 2, alkuRuutu->getSarake() - 1)));
		}

		// vasen
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() - 2)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() - 2)));
		}


	
	// Vasen alanurkka
	// oikea
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() - 2)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() - 2)));
		}
		// vasen
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 2, alkuRuutu->getSarake() - 1)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 2, alkuRuutu->getSarake() - 1)));
		}


	// Vasen ylänurkka
		// vasen
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 2, alkuRuutu->getSarake() + 1)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 2, alkuRuutu->getSarake() + 1)));
		}
		// oikea
	
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() + 2)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() + 2)));
		}
	




}