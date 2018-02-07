#include "Ruutu.h"

Ruutu::Ruutu(int rivi, int sarake) {
	_rivi = rivi;
	_sarake = sarake;
}

int Ruutu::getRivi() const {
	return _rivi;
}

int Ruutu::getSarake() const {
	return _sarake;
}

bool operator==(const Ruutu& lhs, const Ruutu& rhs)
{
	if (lhs.getRivi() == rhs.getRivi() && lhs.getSarake() == rhs.getSarake()) {
		return true;
	}
	else {
		return false;
	}
}
