#pragma once

#include "Ruutu.h"

class Siirto {
public:
	Siirto();
	Siirto(Ruutu, Ruutu);
	Siirto(bool lyhytLinna, bool pitkaLinna); // Poikkeussiirto linnoitusta varten
	Ruutu getAlkuruutu() const;
	Ruutu getLoppuruutu() const;
	bool onkoLyhytLinna() const;
	bool onkoPitkaLinna() const;
private:
	Ruutu _alkuRuutu;
	Ruutu _loppuRuutu;
	int _miksiKorotetaan = 0;
	bool _lyhytLinna;
	bool _pitkaLinna;
};

bool operator==(const Siirto& lhs, const Siirto& rhs);
