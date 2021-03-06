#include "Asema.h"

Kuningas Asema::vk(L"\u2654", 0, 4);
Kuningatar Asema::vd(L"\u2655", 0, 3);
Torni Asema::vt(L"\u2656", 0, 0);
Lahetti Asema::vl(L"\u2657", 0, 2);
Ratsu Asema::vr(L"\u2658", 0, 1);
Sotilas Asema::vs(L"\u2659", 0, 5);
Sotilas Asema::vso(L"\u2659", 0, 13);

Kuningas Asema::mk(L"\u265A", 1, 10);
Kuningatar Asema::md(L"\u265B", 1, 9);
Torni Asema::mt(L"\u265C", 1, 6);
Lahetti Asema::ml(L"\u265D", 1, 8);
Ratsu Asema::mr(L"\u265E", 1, 7);
Sotilas Asema::ms(L"\u265F", 1, 11);
Sotilas Asema::mso(L"\u265F", 1, 12);

Asema::Asema(){
	startTime = std::time(NULL);

	siirtovuoro = 0;
	valkeaKuningasUhattu = false;
	mustaKuningasUhattu = false;

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
	time = std::time(NULL);
	int timePlayed = time - startTime;

		// mik� nappula on alkuruudussa
	Ruutu alkuRuutu = siirto->getAlkuruutu();
	Ruutu loppuRuutu = siirto->getLoppuruutu();

	if (alkuRuutu.getRivi() < 0)
	{
		bool asd = true;
	}
			// jos joku alla olevista niin p�ivit�
	Nappula *valittuNappula = NULL;
	valittuNappula = lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()];
	int vuorossaOlevaPelaaja = getSiirtovuoro();

	// Jos kyseess� on linnoitus k�yd��n l�pi iffi, muussa tapauksessa tehd��n elsen sis�ll� oleva switchi
	//Lyhyt linnoitus
	if (siirto->onkoLyhytLinna() == true) {
		switch(vuorossaOlevaPelaaja){
			case 0:
				if (!getOnkoValkeaKTliikkunut() && !getOnkoValkeaKuningasLiikkunut()) {

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
				if (!getOnkoMustaKTliikkunut() && !getOnkoMustaKuningasLiikkunut()) {

					lauta[7][6] = &mk;
					lauta[7][4] = NULL;
					lauta[7][5] = &mt;
					lauta[7][7] = NULL;

					onkoMustaKuningasLiikkunut = true;
					onkoMustaDTliikkunut = true;
					setSiirtovuoro(0);
				}
				break;
		}
		

	}
	//Pitk� linnoitus
	else if (siirto->onkoPitkaLinna() == true) {
		switch (vuorossaOlevaPelaaja) {
		case 0:
			if (!getOnkoValkeaDTliikkunut() && !getOnkoValkeaKuningasLiikkunut()) {
				
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
			if (!getOnkoMustaDTliikkunut() && !getOnkoMustaKuningasLiikkunut()) {

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
		if (valittuNappula->getKoodi() == VS && siirto->getAlkuruutu().getRivi() == 1 && siirto->getLoppuruutu().getRivi() == 3){
			valittuNappula = &vso;
		}

		if (valittuNappula->getKoodi() == MS && siirto->getAlkuruutu().getRivi() == 6 && siirto->getLoppuruutu().getRivi() == 4) {
			valittuNappula = &mso;
		}

		// Valitaan oikea tapahtuma switchiss�, ELI T�SS� ON ASEMAN P�IVITYS
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
			if (!getOnkoValkeaKuningasLiikkunut()) {
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
			if (loppuRuutu.getSarake() != alkuRuutu.getSarake() && lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] == NULL) {
				lauta[loppuRuutu.getRivi() - 1][loppuRuutu.getSarake()] = NULL;
			}
			if (loppuRuutu.getRivi() == 7) {
				valittuNappula = &vd;
			}
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(1);
			break;
		case VSO:
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
			if (!getOnkoMustaKuningasLiikkunut()) {
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
			if (loppuRuutu.getSarake() != alkuRuutu.getSarake() && lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] == NULL) {
				lauta[loppuRuutu.getRivi() + 1][loppuRuutu.getSarake()] = NULL;
			}
			if (loppuRuutu.getRivi() == 0) {
				valittuNappula = &md;
			}
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(0);
			break;
		case MSO:
			lauta[loppuRuutu.getRivi()][loppuRuutu.getSarake()] = valittuNappula;
			lauta[alkuRuutu.getRivi()][alkuRuutu.getSarake()] = NULL;
			setSiirtovuoro(0);
			break;

		}
	}
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

void Asema::annaLaillisetSiirrot(std::list<Siirto>& lista, bool omaVuoro) {
	std::list<Siirto> tmpLista;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Nappula* nappula = lauta[i][j];
			Ruutu ruutu(i, j);

			if (nappula) {
				if (siirtovuoro == 0 && nappula->getKoodi() == VK) {
					kuningasRuudut[0] = ruutu;
				}

				if (siirtovuoro == 1 && nappula->getKoodi() == MK) {
					kuningasRuudut[1] = ruutu;
				}

				if (nappula->getVari() == siirtovuoro) {
					if (omaVuoro) {
						lauta[i][j]->annaSiirrot(tmpLista, &ruutu, this, siirtovuoro);
					}
					else {
						lauta[i][j]->annaSiirrot(lista, &ruutu, this, siirtovuoro);
					}
					// Jos nappula on ohestaly�t�v� muutetaan se takaisin normaaliksi sotilaaksi
					if (nappula->getKoodi() == VSO) {
						lauta[i][j] = &vs;
					}
					if (nappula->getKoodi() == MSO) {
						lauta[i][j] = &ms;
					}
				}
			}
		}
	}

	if (omaVuoro) {
		if (onkoRuutuUhattu(this, kuningasRuudut[0])) {
			valkeaKuningasUhattu = true;
		}
		else {
			valkeaKuningasUhattu = false;
		}

		if (onkoRuutuUhattu(this, kuningasRuudut[1])) {
			mustaKuningasUhattu = true;
		}
		else {
			mustaKuningasUhattu = false;
		}

		for (std::list<Siirto>::iterator i = tmpLista.begin(); i != tmpLista.end(); i++) {
			Asema uusiAsema(*this);
			int alkuRivi = i->getAlkuruutu().getRivi();
			int alkuSarake = i->getAlkuruutu().getSarake();
			int loppuRivi = i->getLoppuruutu().getRivi();
			int loppuSarake = i->getLoppuruutu().getSarake();
			Nappula* nappula = uusiAsema.lauta[alkuRivi][alkuSarake];
			uusiAsema.lauta[loppuRivi][loppuSarake] = nappula;
			uusiAsema.lauta[alkuRivi][alkuSarake] = NULL;

			if (nappula->getKoodi() == VK || nappula->getKoodi() == MK) {
				kuningasRuudut[siirtovuoro] = Ruutu(loppuRivi, loppuSarake);
			}

			if (!onkoRuutuUhattu(&uusiAsema, kuningasRuudut[siirtovuoro])) {
				lista.push_back(*i);
			}
		}

		// TORNITUKSEN TARKASTUS

		// Valkea
		// Kuninkaan puoli / Lyhyt
		if (getSiirtovuoro() == 0 && !onkoValkeaKuningasLiikkunut && !onkoValkeaKTliikkunut && lauta[0][5] == NULL && lauta[0][6] == NULL) {
			if (!onkoRuutuUhattu(this, Ruutu(0, 5)) && (!onkoRuutuUhattu(this, Ruutu(0, 6)))) {
				lista.push_back(Siirto(true, false));
			}
		}
		// Kuningattaren puoli / Pitk�
		if (getSiirtovuoro() == 0 && !onkoValkeaKuningasLiikkunut && !onkoValkeaDTliikkunut && lauta[0][1] == NULL && lauta[0][2] == NULL && lauta[0][3] == NULL) {
			if (!onkoRuutuUhattu(this, Ruutu(0, 1)) && (!onkoRuutuUhattu(this, Ruutu(0, 2)) && (!onkoRuutuUhattu(this, Ruutu(0, 3))))) {
				lista.push_back(Siirto(false, true));
			}
		}

		// Musta
		// Kuninkaan puoli / Lyhyt
		if (getSiirtovuoro() == 1 && !onkoMustaKuningasLiikkunut && !onkoMustaKTliikkunut && lauta[7][5] == NULL && lauta[7][6] == NULL) {
			if (!onkoRuutuUhattu(this, Ruutu(7, 5)) && (!onkoRuutuUhattu(this, Ruutu(7, 6)))) {
				lista.push_back(Siirto(true, false));
			}
		}
		// Kuningattaren puoli / Pitk�
		if (getSiirtovuoro() == 1 && !onkoMustaKuningasLiikkunut && !onkoMustaDTliikkunut && lauta[7][1] == NULL && lauta[7][2] == NULL && lauta[7][3] == NULL) {
			if (!onkoRuutuUhattu(this, Ruutu(7, 1)) && (!onkoRuutuUhattu(this, Ruutu(7, 2)) && (!onkoRuutuUhattu(this, Ruutu(7, 3))))) {
				lista.push_back(Siirto(false, true));
			}
		}
	}
}

bool Asema::onkoRuutuUhattu(Asema* asema, const Ruutu& ruutu) {
	if (asema->siirtovuoro == 0) {
		asema->siirtovuoro = 1;
	}
	else {
		asema->siirtovuoro = 0;
	}
	//asema->siirtovuoro = asema->siirtovuoro == 0 ? 1 : 0;
	std::list<Siirto> siirrot;
	asema->annaLaillisetSiirrot(siirrot, false);
	
	for (std::list<Siirto>::iterator i = siirrot.begin(); i != siirrot.end(); i++) {
		if (i->getLoppuruutu() == ruutu) {
			//siirtovuoro = siirtovuoro == 0 ? 1 : 0;
			if (asema->siirtovuoro == 0) {
				asema->siirtovuoro = 1;
			}
			else {
				asema->siirtovuoro = 0;
			}
			return true;
		}
	}

	//siirtovuoro = siirtovuoro == 0 ? 1 : 0;
	if (asema->siirtovuoro == 0) {
		asema->siirtovuoro = 1;
	}
	else {
		asema->siirtovuoro = 0;
	}
	return false;
}

double Asema::evaluoi() {
	double evaluointiArvo = 0.0;

	double materiaaliArvot[14] = {
		500, 320, 330, 900, 20000, 100,		// Valkeat
		-500, -320, -330, -900, -20000, -100,	// Mustat
		-100, 100							// Ohestaly�nti
	};

	double ratsuTaulukko[64] =
	{
		-50,-40,-30,-30,-30,-30,-40,-50,
		-40,-20,  0,  0,  0,  0,-20,-40,
		-30,  0, 10, 15, 15, 10,  0,-30,
		-30,  5, 15, 20, 20, 15,  5,-30,
		-30,  0, 15, 20, 20, 15,  0,-30,
		-30,  5, 10, 15, 15, 10,  5,-30,
		-40,-20,  0,  5,  5,  0,-20,-40,
		-50,-10,-30,-30,-30,-30,-10,-50
	};

	double sotilasTaulukko[64] =
	{
		0,  0,  0,  0,  0,  0,  0,  0,
		50, 50, 50, 50, 50, 50, 50, 50,
		10, 10, 20, 30, 30, 20, 10, 10,
		5,  5, 10, 25, 25, 10,  5,  5,
		0,  0,  0, 20, 20,  0,  0,  0,
		5, -5,-10,  0,  0,-10, -5,  5,
		5, 10, 10,-20,-20, 10, 10,  5,
		0,  0,  0,  0,  0,  0,  0,  0
	};

	double lahettiTaulukko[64] =
	{
		-20,-10,-10,-10,-10,-10,-10,-20,
		-10,  0,  0,  0,  0,  0,  0,-10,
		-10,  0,  5, 10, 10,  5,  0,-10,
		-10,  5,  5, 10, 10,  5,  5,-10,
		-10,  0, 10, 10, 10, 10,  0,-10,
		-10, 10, 10, 10, 10, 10, 10,-10,
		-10,  5,  0,  0,  0,  0,  5,-10,
		-20,-10,-10,-10,-10,-10,-10,-20	
	};

	double torniTaulukko[64] =
	{
		0,  0,  0,  0,  0,  0,  0,  0,
		5, 10, 10, 10, 10, 10, 10,  5,
		-5,  0,  0,  0,  0,  0,  0, -5,
		-5,  0,  0,  0,  0,  0,  0, -5,
		-5,  0,  0,  0,  0,  0,  0, -5,
		-5,  0,  0,  0,  0,  0,  0, -5,
		-5,  0,  0,  0,  0,  0,  0, -5,
		0,  0,  0,  5,  5,  0,  0,  0
	};

	double daamiTaulukko[64] =
	{
		-20,-10,-10, -5, -5,-10,-10,-20,
		-10,  0,  0,  0,  0,  0,  0,-10,
		-10,  0,  5,  5,  5,  5,  0,-10,
		-5,  0,  5,  5,  5,  5,  0, -5,
		0,  0,  5,  5,  5,  5,  0, -5,
		-10,  5,  5,  5,  5,  5,  0,-10,
		-10,  0,  5,  0,  0,  0,  0,-10,
		-20,-10,-10, -5, -5,-10,-10,-20
	};

	double kuningasTaulukko[64] =
	{
		-30,-40,-40,-50,-50,-40,-40,-30,
		-30,-40,-40,-50,-50,-40,-40,-30,
		-30,-40,-40,-50,-50,-40,-40,-30,
		-30,-40,-40,-50,-50,-40,-40,-30,
		-20,-30,-30,-40,-40,-30,-30,-20,
		-10,-20,-20,-20,-20,-20,-20,-10,
		20, 20,  0,  0,  0,  0, 20, 20,
		20, 30, 10,  0,  0, 10, 30, 20
	};

	double* taulukonRuutujenArvot[14] = {
		torniTaulukko, ratsuTaulukko, lahettiTaulukko, daamiTaulukko, kuningasTaulukko, sotilasTaulukko,	// Valkeat
		torniTaulukko, ratsuTaulukko, lahettiTaulukko, daamiTaulukko, kuningasTaulukko, sotilasTaulukko,	// Mustat
		sotilasTaulukko, sotilasTaulukko																	// Ohestaly�nti
	};

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (lauta[i][j]) {
				// Ensin lasketaan materiaaliarvo
				evaluointiArvo += (materiaaliArvot[lauta[i][j]->getKoodi()]);
				// Sitten lis�t��n evaluointiarvoon ruudun arvo

				Nappula* nappula = lauta[i][j];

				if (nappula->getVari() == 0) {
					double ruudunArvo = taulukonRuutujenArvot[lauta[i][j]->getKoodi()][(7 - i) * 8 + j];
					evaluointiArvo += taulukonRuutujenArvot[lauta[i][j]->getKoodi()][(7 - i) * 8 + j];
				}
				else {
					double ruudunArvo = taulukonRuutujenArvot[lauta[i][j]->getKoodi()][i * 8 + j];
					evaluointiArvo -= taulukonRuutujenArvot[lauta[i][j]->getKoodi()][i * 8 + j];
				}
			}

		}
	}

	/*if (siirtovuoro == 1) {
		evaluointiArvo = -evaluointiArvo;
	}*/

	return evaluointiArvo;
}

MinMaxPaluu Asema::maxi(int syvyys, Asema* asema) {
	if (syvyys == 0) {
		return MinMaxPaluu(asema->evaluoi(), Siirto());
	}
	
	MinMaxPaluu max(-100000.0, Siirto());
	std::list<Siirto> siirrot;
	asema->annaLaillisetSiirrot(siirrot, true);

	if (siirrot.size() == 0) {
		if (valkeaKuningasUhattu) {
			return MinMaxPaluu(-100000.0, Siirto());
		}
		else {
			return MinMaxPaluu(0.0, Siirto());
		}
	}

	for (std::list<Siirto>::iterator i = siirrot.begin(); i != siirrot.end(); i++) {
		Asema uusiAsema(*asema);
		uusiAsema.paivitaAsema(&*i);
		MinMaxPaluu tulos = uusiAsema.mini(syvyys - 1, &uusiAsema);

		if (tulos.evaluointiArvo > max.evaluointiArvo) {
			max = tulos;
			max.parasSiirto = *i;
		}
	}

	return max;
}

MinMaxPaluu Asema::mini(int syvyys, Asema* asema) {
	if (syvyys == 0) {
		return MinMaxPaluu(asema->evaluoi(), Siirto());
	}

	MinMaxPaluu min(100000.0, Siirto());
	std::list<Siirto> siirrot;
	asema->annaLaillisetSiirrot(siirrot, true);

	if (siirrot.size() == 0) {
		if (mustaKuningasUhattu) {
			return MinMaxPaluu(100000.0, Siirto());
		}
		else {
			return MinMaxPaluu(0.0, Siirto());
		}
	}

	for (std::list<Siirto>::iterator i = siirrot.begin(); i != siirrot.end(); i++) {
		Asema uusiAsema(*asema);
		uusiAsema.paivitaAsema(&*i);
		MinMaxPaluu tulos = uusiAsema.maxi(syvyys - 1, &uusiAsema);

		if (tulos.evaluointiArvo < min.evaluointiArvo) {
			min = tulos;
			min.parasSiirto = *i;
		}
	}
	
	return min;
}

MinMaxPaluu Asema::alphaBetaMax(double alpha, double beta, int syvyys, Asema* asema) {
	if (syvyys == 0) {
		return MinMaxPaluu(asema->evaluoi(), Siirto());
	}

	//MinMaxPaluu max(-100000.0, Siirto());
	Siirto parasSiirto;
	std::list<Siirto> siirrot;
	asema->annaLaillisetSiirrot(siirrot, true);

	if (siirrot.size() == 0) {
		if (valkeaKuningasUhattu) {
			return MinMaxPaluu(-100000.0, Siirto());
		}
		else {
			return MinMaxPaluu(0.0, Siirto());
		}
	}

	for (std::list<Siirto>::iterator i = siirrot.begin(); i != siirrot.end(); i++) {
		Asema uusiAsema(*asema);
		uusiAsema.paivitaAsema(&*i);
		MinMaxPaluu tulos = uusiAsema.alphaBetaMin(alpha, beta, syvyys - 1, &uusiAsema);

		if (tulos.evaluointiArvo >= beta) {
			return MinMaxPaluu(beta, *i);
		}

		if (tulos.evaluointiArvo > alpha) {
			alpha = tulos.evaluointiArvo;
			parasSiirto = *i;
		}
	}

	return MinMaxPaluu(alpha, parasSiirto);
}

MinMaxPaluu Asema::alphaBetaMin(double alpha, double beta, int syvyys, Asema* asema) {
	if (syvyys == 0) {
		return MinMaxPaluu(asema->evaluoi(), Siirto());
	}

	//MinMaxPaluu min(100000.0, Siirto());
	Siirto parasSiirto;
	std::list<Siirto> siirrot;
	asema->annaLaillisetSiirrot(siirrot, true);

	if (siirrot.size() == 0) {
		if (mustaKuningasUhattu) {
			return MinMaxPaluu(100000.0, Siirto());
		}
		else {
			return MinMaxPaluu(0.0, Siirto());
		}
	}

	for (std::list<Siirto>::iterator i = siirrot.begin(); i != siirrot.end(); i++) {
		Asema uusiAsema(*asema);
		uusiAsema.paivitaAsema(&*i);
		MinMaxPaluu tulos = uusiAsema.alphaBetaMax(alpha, beta, syvyys - 1, &uusiAsema);

		if (tulos.evaluointiArvo <= alpha) {
			return MinMaxPaluu(alpha, *i);
		}

		if (tulos.evaluointiArvo < beta) {
			beta = tulos.evaluointiArvo;
			parasSiirto = *i;
		}
	}

	return MinMaxPaluu(beta, parasSiirto);
}

