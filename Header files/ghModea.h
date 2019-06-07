/*
 * ghModea.h
 *
 *  Created on: 5 jun. 2019
 *      Author: grana
 */

#ifndef GHMODEA_H_
#define GHMODEA_H_

#define SPRITE_LONG_LENGTH 195
#define SPRITE_SHORT_LENGTH 84
#define HITBOX_HASIERA 340
#define HITBOX_BUKAERA 558

//Hau neurtzeko exekuzio proba bat egin dugu startGuitarMode funtzioan
#define ESTIMATED_EX_TIME 20000

//Joko modua hasieratzeko
void startGuitarMode(ABESTIA* zerrenda, INSTRUMENTUA* instZerrenda);

//Sprite baten bizitza denbora amaitzen denean hau ezabatzeko
int diskaEzabatuBeharDa(GH_TILE** burua, INSTRUMENTUA* instZerrenda, ABESTIA** zerrenda, int length);

//Spriten zerrendako lehen elementua ezabatzeko
GH_TILE* zerrendakoLehenElementuaEzabatu(GH_TILE* burua);

//Abestiaren zerrendaren lehen elementua ezabatzeko
ABESTIA* ABESTIA_zerrendakoLehenElementuaEzabatu(ABESTIA* burua);

//Abestiaren nota sprite bihurtu eta zerrendaren amaieran sartzeko
GH_TILE* diskaBukaeranSartu(GH_TILE* burua, GH_TILE* berria);

//Zerrenda guztia aurrerantz mugitzeko
GH_TILE* diskaGuztiakMugitu(GH_TILE* burua, int konstante);

//Zerrendaren elementu kopurua kalkulatzeko
int zerrendaLuzeraNeurtu(ABESTIA* zerrenda);

//Erabiltzaileak jokoan nota ondo errepikatu duen jakiteko
int zuzenEmanDio(int tecla, GH_TILE* burua, ABESTIA* aux);

//Sprite-aren posizioa dagokion notaren arabera jakiteko
int notaAraberaXPos(int tecla);

//Ondo egindako %ren arabera zein mezu jarri behar den jakiteko
char* messageBasedOnScore(int score, int dim);

//Abestiak dauzkan nota kopurua jakiteko
int songLength(ABESTIA* song);

//Nota normala edo sostenitua den jakiteko, eta horrela sprite egokia aukeratzeko
int longOrShort(int tecla, char spritePath[]);

//Puntuazioa eta dagokion mezua pantailaratzeko
void bukaerakoPuntuazioaPant(int puntuazioa, int dim);

//Jokoan erabiliko den abestia aukeratzeko
ABESTIA* abestiaAukeratu(ABESTI_ZERRENDA *abestiZerrenda);

#endif /* GHMODEA_H_ */
