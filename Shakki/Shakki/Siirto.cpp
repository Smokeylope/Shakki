#include "Siirto.h"

Siirto::Siirto() {
	_alkuRuutu = Ruutu(-1, -1);
	_loppuRuutu = Ruutu(-1, -1);
}

Siirto::Siirto(Ruutu alku, Ruutu loppu) {
	_alkuRuutu = alku;
	_loppuRuutu = loppu;
	_lyhytLinna = false;
	_pitkaLinna = false;
}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinna) {
	_lyhytLinna = lyhytLinna;
	_pitkaLinna = pitkaLinna;
	_alkuRuutu = Ruutu(0, 0);
	_loppuRuutu = Ruutu(0, 0);
}

Ruutu Siirto::getAlkuruutu() const {
	return _alkuRuutu;
}

Ruutu Siirto::getLoppuruutu() const {
	return _loppuRuutu;
}

bool Siirto::onkoLyhytLinna() const {
	return _lyhytLinna;
}

bool Siirto::onkoPitkaLinna() const {
	return _pitkaLinna;
}

bool operator==(const Siirto& lhs, const Siirto& rhs)
{
	if (lhs.getAlkuruutu() == rhs.getAlkuruutu() && lhs.getLoppuruutu() == rhs.getLoppuruutu() &&
		lhs.onkoLyhytLinna() == rhs.onkoLyhytLinna() && lhs.onkoPitkaLinna() == rhs.onkoPitkaLinna()) {
		return true;
	}
	else {
		return false;
	}
}
