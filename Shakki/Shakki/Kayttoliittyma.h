#pragma once

#include <iostream>
#include <Windows.h>
#include "Asema.h"
#include "Siirto.h"

class Kayttoliittyma{

public:
	Kayttoliittyma(Asema* asema);
	Asema* _asema;
	void piirraLauta();
	Siirto annaVastustajanSiirto();
};
