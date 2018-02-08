#include "Sotilas.h"
#include "Asema.h"

void Sotilas::annaSiirrot(std::list<Siirto>& lista, Ruutu* alkuRuutu, Asema* asema, int vari) {
	if (vari == 0) {
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 1, alkuRuutu->getSarake()) && asema->lauta[alkuRuutu->getRivi() + 1][alkuRuutu->getSarake()] == NULL) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake())));

			if (alkuRuutu->getRivi() == 1) {
				if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 2, alkuRuutu->getSarake()) && asema->lauta[alkuRuutu->getRivi() + 2][alkuRuutu->getSarake()] == NULL) {
					lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 2, alkuRuutu->getSarake())));
				}
			}
		}
		// Onko ly�ntimahdollisuutta oikea puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() + 1) && asema->lauta[alkuRuutu->getRivi() + 1][alkuRuutu->getSarake() + 1] != NULL) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() + 1)));
		}
		// Onko ly�ntimahdollisuutta vasen puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() - 1) && asema->lauta[alkuRuutu->getRivi() + 1][alkuRuutu->getSarake() - 1] != NULL) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() - 1)));
		}
		// Onko ohestaly�ntimahdollisuutta oikea puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi(), alkuRuutu->getSarake() + 1) && asema->lauta[alkuRuutu->getRivi()][alkuRuutu->getSarake() + 1] != NULL && asema->lauta[alkuRuutu->getRivi()][alkuRuutu->getSarake() + 1]->getKoodi() == MSO) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() + 1)));
		}
		// Onko ohestaly�ntimahdollisuutta vasen puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi(), alkuRuutu->getSarake() - 1)) {
			if (asema->lauta[alkuRuutu->getRivi()][alkuRuutu->getSarake() - 1] != NULL) {
				if(asema->lauta[alkuRuutu->getRivi()][alkuRuutu->getSarake() - 1]->getKoodi() == MSO) {
					lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() + 1, alkuRuutu->getSarake() - 1)));
				}
			}
		}
	}
	else {
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 1, alkuRuutu->getSarake()) && asema->lauta[alkuRuutu->getRivi() - 1][alkuRuutu->getSarake()] == NULL) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake())));

			if (alkuRuutu->getRivi() == 6) {
				if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 2, alkuRuutu->getSarake()) && asema->lauta[alkuRuutu->getRivi() - 2][alkuRuutu->getSarake()] == NULL) {
					lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 2, alkuRuutu->getSarake())));
				}
			}
		}
		// Onko ly�ntimahdollisuutta oikea puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() + 1) && asema->lauta[alkuRuutu->getRivi() - 1][alkuRuutu->getSarake() + 1] != NULL) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() + 1)));
		}
		// Onko ly�ntimahdollisuutta vasen puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() - 1) && asema->lauta[alkuRuutu->getRivi() - 1][alkuRuutu->getSarake() -1] != NULL) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() - 1)));
		}
		// Onko ohestaly�ntimahdollisuutta oikea puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi(), alkuRuutu->getSarake() + 1) && asema->lauta[alkuRuutu->getRivi()][alkuRuutu->getSarake() + 1] != NULL && asema->lauta[alkuRuutu->getRivi()][alkuRuutu->getSarake() + 1]->getKoodi() == VSO) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() + 1)));
		}
		// Onko ohestaly�ntimahdollisuutta vasen puoli
		if (onkoSiirtoMahdollinen(asema, alkuRuutu->getRivi(), alkuRuutu->getSarake() - 1) && asema->lauta[alkuRuutu->getRivi()][alkuRuutu->getSarake() - 1] != NULL && asema->lauta[alkuRuutu->getRivi()][alkuRuutu->getSarake() - 1]->getKoodi() == VSO) {
			lista.push_back(Siirto(*alkuRuutu, Ruutu(alkuRuutu->getRivi() - 1, alkuRuutu->getSarake() - 1)));
		}
	}
}
