#pragma once

#include <iostream>
#include <Windows.h>
#include "Asema.h"

class Kayttoliittyma{

public:
	Kayttoliittyma(Asema* asema);
	Asema* _asema;
	void piirraLauta();
};
