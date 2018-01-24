#include <io.h>
#include <fcntl.h>
#include "Kayttoliittyma.h"

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	Asema asema;
	Kayttoliittyma kayttoliittyma(&asema);

	// PELI LOOP
	while (true) {
		kayttoliittyma.piirraLauta();
		Siirto siirto = kayttoliittyma.annaVastustajanSiirto();
		asema.paivitaAsema(&siirto);
		system("cls");
	}

	return 0;
}