/*
 * abestiak.h
 *
 *  Created on: 26 may. 2019
 *      Author: grana
 */

#ifndef ABESTIAK_H_
#define ABESTIAK_H_

#include "estrukturak.h"

//Noten teklak jotzen ari diren edo ez jakiteko
int notaIkutu(int tecla);

//Soinua sortzeko
void notaJo(int tekla, INSTRUMENTUA *instrumentoa);

//Abestiko noten parametroak irakurtzeko (Debug bakarrik)
void zerrendaPantailaratu(ABESTIA* burua);

//Abestiak erreproduzitzeko
void erreproduzitu(ABESTIA* burua, INSTRUMENTUA *instrumentoa);

//Abestien fitxategia irakurtzeko
ABESTIA* fitxIrakurri(int abestiKop);

//Abesti berri bat zerrendaren amaieran sartzeko
ABESTIA* sartuBukaeran(ABESTIA* burua, ABESTIA* berria);

//Abesti berri bat sortzeko
int grabatuAbestia(INSTRUMENTUA *instrumentoa);

//Fade-Out efektu bat jartzeko noten amaieran
void fadeOut(INSTRUMENTUA *instZerrenda, int tekla, int denbora);

//Abesti guztiak zerrenda kateatu batean gordetzeko
ABESTI_ZERRENDA* abestiakKargatu(ABESTI_ZERRENDA* burua, int *abestiKop, int refresh);

//Abesti berri bat zerrendan sartzeko
ABESTI_ZERRENDA *abestiaZerrendanSartu(ABESTI_ZERRENDA* burua, ABESTI_ZERRENDA* berria, int refresh);

//Erreprodukzio menuan/modoan sartzeko
void erreprodukzioMenua(ABESTI_ZERRENDA *abestiZerrenda, INSTRUMENTUA *instrumentoa, int abestiKop);

#endif /* ABESTIAK_H_ */
