#pragma once

#include "Siirto.h"

class MinMaxPaluu {
public:
	MinMaxPaluu(double evaluointi, Siirto paras)
		: evaluointiArvo(evaluointi), parasSiirto(paras){}
	double evaluointiArvo;
	Siirto parasSiirto;
};
