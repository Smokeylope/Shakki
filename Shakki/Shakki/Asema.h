#pragma once

#include <iostream>
#include "Kuningas.h"
#include "Kuningatar.h"
#include "Lahetti.h"
#include "Torni.h"
#include "Ratsu.h"
#include "Sotilas.h"
#include "MinMaxPaluu.h"

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

	// VIIKKO 5
	double evaluoi();
	MinMaxPaluu maxi(int syvyys, Asema* asema);
	MinMaxPaluu mini(int syvyys, Asema* asema);

private:
	static Kuningas vk;
	static Kuningatar vd;
	static Torni vt;
	static Lahetti vl;
	static Ratsu vr;
	static Sotilas vs;
	static Sotilas vso;

	static Kuningas mk;
	static Kuningatar md;
	static Torni mt;
	static Lahetti ml;
	static Ratsu mr;
	static Sotilas ms;
	static Sotilas mso;

	// VIIKKO 2
	int siirtovuoro;
	bool onkoValkeaKuningasLiikkunut = false;
	bool onkoMustaKuningasLiikkunut = false;
	bool onkoValkeaDTliikkunut = false;
	bool onkoValkeaKTliikkunut = false;
	bool onkoMustaDTliikkunut = false;
	bool onkoMustaKTliikkunut = false;

	// VIIKKO 4
	Ruutu kuningasRuudut[2];
};