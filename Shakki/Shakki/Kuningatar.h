#pragma once

#include "Nappula.h"

class Kuningatar : public Nappula {
public:
	Kuningatar(std::wstring unicode, int vari, int koodi) : Nappula(unicode, vari, koodi){}
	virtual void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);
};
