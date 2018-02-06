#include "Nappula.h"
#include "Asema.h"

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

bool Nappula::onkoSiirtoMahdollinen(Asema* asema,int loppuRivi, int loppuSarake) {
	if (loppuRivi >= 0 && loppuRivi <= 7) {
		if (loppuSarake >= 0 && loppuSarake <= 7) {
			if (!asema->lauta[loppuRivi][loppuSarake]) {
				return true;
			}
			else if (asema->getSiirtovuoro() == asema->lauta[loppuRivi][loppuSarake]->getVari()) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}