#include "Nappula.h"

Nappula::Nappula(std::wstring unicode, int vari, int koodi)
{
	_unicode = unicode;
	_vari = vari;
	_koodi = koodi;
}

void Nappula::setKoodi(int koodi)
{
	_koodi = koodi;
}

int Nappula::getKoodi()
{
	return _koodi;
}

void Nappula::setUnicode(std::wstring unicode)
{
	_unicode = unicode;
}

std::wstring Nappula::getUnicode()
{
	return _unicode;
}

void Nappula::setVari(int vari)
{
	_vari = vari;
}

int Nappula::getVari()
{
	return _vari;
}
