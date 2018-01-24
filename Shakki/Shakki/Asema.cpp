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
	lauta[0][3] = &vk;
	lauta[0][4] = &vd;
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
	lauta[7][3] = &mk;
	lauta[7][4] = &md;
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
