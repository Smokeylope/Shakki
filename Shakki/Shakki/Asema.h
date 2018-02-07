#pragma once

#include <iostream>
#include "Kuningas.h"
#include "Kuningatar.h"
#include "Lahetti.h"
#include "Torni.h"
#include "Ratsu.h"
#include "Sotilas.h"

/*class Nappula;
class Kuningas : public Nappula;
class Kuningatar : public Nappula;
class Lahetti : public Nappula;
class Torni : public Nappula;
class Ratsu : public Nappula;
class Sotilas : public Nappula;*/

class Asema{

public:
	Asema();
	Nappula* lauta[8][8];

	// VIIKKO 2
	void paivitaAsema(Siirto* siirto);
	int getSiirtovuoro();
	void setSiirtovuoro(int vari);
	bool getOnkoValkeaKuningasLiikkunut();
	bool getOnkoMustaKuningasLiikkunut();
	bool getOnkoValkeaDTliikkunut();
	bool getOnkoValkeaKTliikkunut();
	bool getOnkoMustaDTliikkunut();
	bool getOnkoMustaKTliikkunut();

	// VIIKKO 3
	void annaLaillisetSiirrot(std::list<Siirto>& lista, bool omaVuoro);

	// VIIKKO 4
	bool onkoRuutuUhattu(Asema* asema, const Ruutu& ruutu);

private:
	static Kuningas vk;
	static Kuningatar vd;
	static Torni vt;
	static Lahetti vl;
	static Ratsu vr;
	static Sotilas vs;

	static Kuningas mk;
	static Kuningatar md;
	static Torni mt;
	static Lahetti ml;
	static Ratsu mr;
	static Sotilas ms;

	// VIIKKO 2
	int siirtovuoro;
	bool onkoValkeaKuningasLiikkunut;
	bool onkoMustaKuningasLiikkunut;
	bool onkoValkeaDTliikkunut;
	bool onkoValkeaKTliikkunut;
	bool onkoMustaDTliikkunut;
	bool onkoMustaKTliikkunut;

	// VIIKKO 4
	Ruutu kuningasRuudut[2];
};