#include "Sotilas.h"

void Sotilas::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {
	if (vari == 0) {
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 1, alkuRuutu->getSarake())) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake())));

			if (alkuRuutu->getRivi() == 1) {
				if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 2, alkuRuutu->getSarake())) {
					lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 2, alkuRuutu->getSarake())));
				}
			}
		}
		// Onko lyöntimahdollisuutta oikea puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() + 1)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() + 1)));
		}
		// Onko lyöntimahdollisuutta vasen puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() - 1)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() - 1)));
		}
	}
	else {
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 1, alkuRuutu->getSarake())) {
			lista.push_back(Siirto(*alkuRuutu,
				Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake())));

			if (alkuRuutu->getRivi() == 6) {
				if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 2, alkuRuutu->getSarake())) {
					lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 2, alkuRuutu->getSarake())));
				}
			}
		}
		// Onko lyöntimahdollisuutta oikea puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() + 1)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() + 1)));
		}
		// Onko lyöntimahdollisuutta vasen puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() - 1)) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() - 1)));
		}
	}
}
