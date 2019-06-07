/*
 * estrukturak.h
 *
 *  Created on: 26 may. 2019
 *      Author: grana
 */

#ifndef ESTRUKTURAK_H_
#define ESTRUKTURAK_H_
#define KEYDOWN 0
#define KEYUP 1

typedef struct
{
	Mix_Chunk* audio;
	int state;
	int channel;
	//int imageID;

}AUDIO;

typedef struct
{
	AUDIO DO; //Usamos este formato porque de otro modo no funcionan los acordes (pulsación simultánea)
	AUDIO RE;
	AUDIO MI;
	AUDIO FA;
	AUDIO SOL;
	AUDIO LA;
	AUDIO SI;
	AUDIO DOM;
	AUDIO REM;
	AUDIO DOSOST;
	AUDIO RESOST;
	AUDIO FASOST;
	AUDIO SOLSOST;
	AUDIO LASOST;
	AUDIO DOMSOST;

}NOTA;

typedef struct Instrumentua {
	int id;
	char izena[128];
	char path[128];
	NOTA *nota;
	struct Instrumentua *ptrHurrengoa;
}INSTRUMENTUA;

typedef struct Abestia
{
	INSTRUMENTUA instrumentua;
	float denbora;
	float pulsDenbora;
	int tecla;
	int notaKop;
	struct Abestia* ptrHurrengoa;
}ABESTIA;

typedef struct AbestiZerrenda {

	int id;
	//char izenburua[128];
	ABESTIA *abestia;
	struct AbestiZerrenda* ptrHurrengoa;

}ABESTI_ZERRENDA;

typedef struct Posizioa
{
	int x;
	int y;
}POSIZIOA;

typedef struct Tile
{
	int id;
	POSIZIOA pos;
	struct Tile* pHurrengoa;
}GH_TILE;

#endif /* ESTRUKTURAK_H_ */
