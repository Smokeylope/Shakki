#include <io.h>
#include <fcntl.h>
#include <chrono>
#include "Kayttoliittyma.h"

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	Asema asema;
	Kayttoliittyma kayttoliittyma(&asema);

	double valkeanAika = 120.0;
	double mustanAika = 120.0;

	// PELI LOOP
	while (true) {
		kayttoliittyma.piirraLauta();
		std::wcout << "Valkean kello: " << valkeanAika << '\n';
		std::wcout << "Mustan kello: " << mustanAika << '\n';		

		auto vuoronAlku = std::chrono::high_resolution_clock::now();

		if (asema.getSiirtovuoro() == 0) {
			//MinMaxPaluu paluu = asema.maxi(3, &asema);
			/*MinMaxPaluu paluu = asema.alphaBetaMax(-100000, 100000, 2, &asema);
			if (paluu.parasSiirto.getAlkuruutu().getRivi() < 0 || valkeanAika <= 0.0){
				break;
			}
			else {
				asema.paivitaAsema(&paluu.parasSiirto);
			}*/

			std::list<Siirto> siirrot;
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
			}

			auto vuoronLoppu = std::chrono::high_resolution_clock::now();
			long long millisekunnit = std::chrono::duration_cast<std::chrono::milliseconds>(vuoronLoppu - vuoronAlku).count();
			valkeanAika -= millisekunnit * 0.001;

			if (valkeanAika < 0.0) {
				break;
			}
		}
		else {
			//MinMaxPaluu paluu = asema.mini(3, &asema);
			MinMaxPaluu paluu = asema.alphaBetaMin(-100000, 100000, 4, &asema);
			if (paluu.parasSiirto.getAlkuruutu().getRivi() < 0){
				break;
			}
			else {
				asema.paivitaAsema(&paluu.parasSiirto);
			}
			
			auto vuoronLoppu = std::chrono::high_resolution_clock::now();
			long long millisekunnit = std::chrono::duration_cast<std::chrono::milliseconds>(vuoronLoppu - vuoronAlku).count();
			mustanAika -= millisekunnit * 0.001;

			if (mustanAika < 0.0) {
				break;
			}
		}
		
		system("cls");
	}
	
	std::wcout << "Peli on päättynyt!" << std::endl;

	return 0;
}