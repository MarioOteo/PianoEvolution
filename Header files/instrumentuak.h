/*
 * instrumentuak.h
 *
 *  Created on: 24 may. 2019
 *      Author: mario
 */

#ifndef INSTRUMENTUAK_H_
#define INSTRUMENTUAK_H_

#include "estrukturak.h"

#define PIANO_DO "./Notas/Do.wav"
#define PIANO_RE "./Notas/Re.wav"
#define PIANO_MI "./Notas/Mi.wav"
#define PIANO_FA "./Notas/Fa.wav"
#define PIANO_SOL "./Notas/Sol.wav"
#define PIANO_LA "./Notas/La.wav"
#define PIANO_SI "./Notas/Si.wav"
#define PIANO_DOM "./Notas/DoM.wav"

//Instrumentu berri bat sortzeko
INSTRUMENTUA *instrumentuBatSortu(int ID, char instIzena[]);

//Instrumentu berri bat instrumentuen zerrendaren amaieran sartzeko
INSTRUMENTUA *bukaeranSartu(INSTRUMENTUA *instZerrenda, INSTRUMENTUA *instBerria);

//Instrumentuen fitxategitik datuak irakurtzeko
INSTRUMENTUA *instrumentuakKargatu(INSTRUMENTUA *instZerrenda);

//Instrumentuei dagokien datuak sartzeko (notak, id, location path...)
INSTRUMENTUA *instrumentuaHasieratu(INSTRUMENTUA *instrumentoa);

#endif /* INSTRUMENTUAK_H_ */
