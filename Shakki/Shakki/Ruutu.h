#pragma once

class Ruutu {
public:
	Ruutu(int rivi, int sarake);
	Ruutu(){}
	int getRivi() const;
	int getSarake() const;


private:
	int _sarake;
	int _rivi;
};


bool operator==(const Ruutu& lhs, const Ruutu& rhs)
{
	if (lhs.getRivi() == rhs.getRivi() && lhs.getSarake() == rhs.getSarake()) {
		return true;
	}
	else {
		return false;
	}
}