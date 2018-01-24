#include "Asema.h"

Nappula Asema::vk(L"\u2654", 0, 4);
Nappula Asema::vd(L"\u2655", 0, 3);
Nappula Asema::vt(L"\u2656", 0, 0);
Nappula Asema::vl(L"\u2657", 0, 2);
Nappula Asema::vr(L"\u2658", 0, 1);
Nappula Asema::vs(L"\u2659", 0, 5);

Nappula Asema::mk(L"\u265A", 1, 10);
Nappula Asema::md(L"\u265B", 1, 9);
Nappula Asema::mt(L"\u265C", 1, 6);
Nappula Asema::ml(L"\u265D", 1, 8);
Nappula Asema::mr(L"\u265E", 1, 7);
Nappula Asema::ms(L"\u265F", 1, 11);

Asema::Asema(){
	// LAUDAN ALUSTUS
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			lauta[i][j] = NULL;
		}
	}

	// Asetetaan valkoiset nappulat laudalle
	lauta[0][0] = &vt;
	lauta[0][1] = &vr;
	lauta[0][2] = &vl;
	lauta[0][3] = &vd;
	lauta[0][4] = &vk;
	lauta[0][5] = &vl;
	lauta[0][6] = &vr;
	lauta[0][7] = &vt;
	// Sotilaat
	lauta[1][0] = &vs;
	lauta[1][1] = &vs;
	lauta[1][2] = &vs;
	lauta[1][3] = &vs;
	lauta[1][4] = &vs;
	lauta[1][5] = &vs;
	lauta[1][6] = &vs;
	lauta[1][7] = &vs;

	// Asetetaan mustat nappulat laudalle
	lauta[7][0] = &mt;
	lauta[7][1] = &mr;
	lauta[7][2] = &ml;
	lauta[7][3] = &md;
	lauta[7][4] = &mk;
	lauta[7][5] = &ml;
	lauta[7][6] = &mr;
	lauta[7][7] = &mt;
	// Sotilaat
	lauta[6][0] = &ms;
	lauta[6][1] = &ms;
	lauta[6][2] = &ms;
	lauta[6][3] = &ms;
	lauta[6][4] = &ms;
	lauta[6][5] = &ms;
	lauta[6][6] = &ms;
	lauta[6][7] = &ms;
} // ASEMA KONSTRUKTORI LOPPU


  // VIIKKO 2

void Asema::paivitaAsema(Siirto* siirto) {
/*
		// mikä nappula on alkuruudussa
	Ruutu alkuRuutu = siirto->getAlkuruutu();
	Ruutu loppuRuutu = siirto->getLoppuruutu();
			// jos joku alla olevista niin päivitä
	Nappula *valittuNappula = NULL;
	valittuNappula = lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()];
	int vuorossaOlevaPelaaja = getSiirtovuoro();

	// Jos kyseessä on linnoitus käydään läpi iffi, muussa tapauksessa tehdään elsen sisällä oleva switchi
	//Lyhyt linnoitus
	if (siirto->onkoLyhytLinna() == true) {
		switch(vuorossaOlevaPelaaja){
			case 0:
				if (!getOnkoValkeaKTliikkunut && !getOnkoValkeaKuningasLiikkunut) {

					lauta[0][6] = &vk;
					lauta[0][4] = NULL;
					lauta[0][5] = &vt;
					lauta[0][7] = NULL;

					onkoValkeaKuningasLiikkunut = true;
					onkoValkeaDTliikkunut = true;
					setSiirtovuoro(1);
				}
				break;
			case 1:
				if (!getOnkoMustaKTliikkunut && !getOnkoMustaKuningasLiikkunut) {

					lauta[0][6] = &vk;
					lauta[0][4] = NULL;
					lauta[0][5] = &vt;
					lauta[0][7] = NULL;

					onkoMustaKuningasLiikkunut = true;
					onkoMustaDTliikkunut = true;
					setSiirtovuoro(0);
				}
				break;
		}
		

	}
	//Pitkä linnoitus
	else if (siirto->onkoPitkaLinna() == true) {
		switch (vuorossaOlevaPelaaja) {
		case 0:
			if (!getOnkoValkeaDTliikkunut && !getOnkoValkeaKuningasLiikkunut) {
				
				lauta[0][1] = &vk;
				lauta[0][4] = NULL;
				lauta[0][2] = &vt;
				lauta[0][0] = NULL;

				onkoValkeaKuningasLiikkunut = true;
				onkoValkeaDTliikkunut = true;
				setSiirtovuoro(1);
			}
			break;
		case 1:
			if (!getOnkoMustaDTliikkunut && !getOnkoMustaKuningasLiikkunut) {

				lauta[7][1] = &mk;
				lauta[7][4] = NULL;
				lauta[7][2] = &mt;
				lauta[7][0] = NULL;

				onkoMustaKuningasLiikkunut = true;
				onkoMustaDTliikkunut = true;
				setSiirtovuoro(0);
			}
			break;
		}
		
	}
	else {
		// Valitaan oikea tapahtuma switchissä, ELI TÄSSÄ ON ASEMAN PÄIVITYS
		switch (valittuNappula->getKoodi()) {
			//VALKOISET
		case VT:
			if (alkuRuutu.getSarake() == 0) {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				onkoValkeaDTliikkunut = true;
				setSiirtovuoro(1);
			}
			else if (alkuRuutu.getSarake() == 7) {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				onkoValkeaKTliikkunut = true;
				setSiirtovuoro(1);
			}
			else {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				setSiirtovuoro(1);
			}
			break;
		case VR:
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(1);
			break;
		case VL:
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(1);
			break;
		case VD:
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(1);
			break;
		case VK:
			if (!getOnkoValkeaKuningasLiikkunut) {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				onkoValkeaKuningasLiikkunut = true;
				setSiirtovuoro(1);
			}
			else {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				setSiirtovuoro(1);
			}
			break;
		case VS:
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(1);
			break;

			// MUSTAT
		case MT:
			if (alkuRuutu.getSarake() == 0) {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				onkoMustaDTliikkunut = true;
				setSiirtovuoro(0);
			}
			else if (alkuRuutu.getSarake() == 7) {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				onkoMustaKTliikkunut = true;
				setSiirtovuoro(0);
			}
			else {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				setSiirtovuoro(0);
			}
			break;
		case MR:
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(0);
			break;
		case ML:
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(0);
			break;
		case MD:
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(0);
			break;
		case MK:
			if (!getOnkoMustaKuningasLiikkunut) {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				onkoMustaKuningasLiikkunut = true;
				setSiirtovuoro(0);
			}
			else {
				lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
				lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
				setSiirtovuoro(0);
			}
			break;
		case MS:
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(0);
			break;

		}
	}*/
}


int Asema::getSiirtovuoro() {
	return siirtovuoro;
}
void Asema::setSiirtovuoro(int vari) {
	this->siirtovuoro = vari;
}
bool Asema::getOnkoValkeaKuningasLiikkunut() {
	return onkoValkeaKuningasLiikkunut;
}
bool Asema::getOnkoMustaKuningasLiikkunut() {
	return onkoMustaKuningasLiikkunut;
}
bool Asema::getOnkoValkeaDTliikkunut() {
	return onkoValkeaDTliikkunut;
}
bool Asema::getOnkoValkeaKTliikkunut() {
	return onkoValkeaKTliikkunut;
}
bool Asema::getOnkoMustaDTliikkunut() {
	return onkoMustaDTliikkunut;
}
bool Asema::getOnkoMustaKTliikkunut() {
	return onkoMustaKTliikkunut;
}