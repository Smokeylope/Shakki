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

		if (asema.getSiirtovuoro() == 0) {
			MinMaxPaluu paluu = asema.alphaBetaMax(-100000, 100000, 2, &asema);
			asema.paivitaAsema(&paluu.parasSiirto);

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
		}
		else {
			MinMaxPaluu paluu = asema.alphaBetaMin(-100000, 100000, 2, &asema);
			asema.paivitaAsema(&paluu.parasSiirto);
		}

		system("cls");
	}

	return 0;
}