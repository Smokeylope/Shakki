#include "Siirto.h"

Siirto::Siirto(Ruutu alku, Ruutu loppu) {
	_alkuRuutu = alku;
	_loppuRuutu = loppu;
}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinna) {
	_lyhytLinna = lyhytLinna;
	_pitkaLinna = pitkaLinna;
}

Ruutu Siirto::getAlkuruutu() {
	return _alkuRuutu;
}

Ruutu Siirto::getLoppuruutu() {
	return _loppuRuutu;
}

bool Siirto::onkoLyhytLinna() {
	return _lyhytLinna;
}

bool Siirto::onkoPitkaLinna() {
	return _pitkaLinna;
}
