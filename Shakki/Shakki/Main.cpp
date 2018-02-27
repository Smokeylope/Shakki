#include <io.h>
#include <fcntl.h>
#include "Kayttoliittyma.h"

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	Asema asema;
	Kayttoliittyma kayttoliittyma(&asema);
	int valkeaSiirrot = 0;
	int mustaSiirrot = 0;
	// PELI LOOP
	while (true) {
		kayttoliittyma.piirraLauta();

		/*std::list<Siirto> siirrot;
		asema.annaLaillisetSiirrot(siirrot, true);
		bool siirtoLaillinen = false;

		while (!siirtoLaillinen) {
			Siirto siirto = kayttoliittyma.annaVastustajanSiirto();

			for (std::list<Siirto>::iterator i = siirrot.begin(); i != siirrot.end(); i++) {
				if ((*i == siirto)) {
					asema.paivitaAsema(&(*i));
					siirtoLaillinen = true;
					break;
				}
			}		
		}*/
		if (asema.getSiirtovuoro() == 0) {
			if (valkeaSiirrot == 0) {
				Siirto alkusiirto(Ruutu(1, 0), Ruutu(4, 4));
				asema.paivitaAsema(&alkusiirto);
				valkeaSiirrot++;
			}
		}
		else if (asema.getSiirtovuoro() == 1) {
			if (mustaSiirrot == 0) {
				Siirto alkusiirto(Ruutu(6, 0), Ruutu(5, 4));
				asema.paivitaAsema(&alkusiirto);
				mustaSiirrot++;
			}
		}
		else {

		MinMaxPaluu paluu = asema.maxi(2, &asema);
		asema.paivitaAsema(&paluu.parasSiirto);
		
		system("cls");
		}
	}

	return 0;
}