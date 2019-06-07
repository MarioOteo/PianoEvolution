/*
 * instrumentuak.c
 *
 *  Created on: 24 may. 2019
 *      Author: mario
 */

#include "kontrolak.h"
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include "instrumentuak.h"

INSTRUMENTUA *instrumentuaHasieratu(INSTRUMENTUA *instrumentoa)
{
	char pathCopy[128];

	instrumentoa->nota = (NOTA*)malloc(sizeof(NOTA));

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/Do.wav");
	instrumentoa->nota->DO.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->DO.state = KEYUP;
	instrumentoa->nota->DO.channel = 0;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/Re.wav");
	instrumentoa->nota->RE.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->RE.state = KEYUP;
	instrumentoa->nota->RE.channel = 1;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/Mi.wav");
	instrumentoa->nota->MI.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->MI.state = KEYUP;
	instrumentoa->nota->MI.channel = 2;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/Fa.wav");
	instrumentoa->nota->FA.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->FA.state = KEYUP;
	instrumentoa->nota->FA.channel = 3;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/Sol.wav");
	instrumentoa->nota->SOL.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->SOL.state = KEYUP;
	instrumentoa->nota->SOL.channel = 4;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/La.wav");
	instrumentoa->nota->LA.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->LA.state = KEYUP;
	instrumentoa->nota->LA.channel = 5;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/Si.wav");
	instrumentoa->nota->SI.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->SI.state = KEYUP;
	instrumentoa->nota->SI.channel = 6;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/DoM.wav");
	instrumentoa->nota->DOM.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->DOM.state = KEYUP;
	instrumentoa->nota->DOM.channel = 7;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/ReM.wav");
	instrumentoa->nota->REM.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->REM.state = KEYUP;
	instrumentoa->nota->REM.channel = 8;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/DoSost.wav");
	instrumentoa->nota->DOSOST.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->DOSOST.state = KEYUP;
	instrumentoa->nota->DOSOST.channel = 9;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/ReSost.wav");
	instrumentoa->nota->RESOST.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->RESOST.state = KEYUP;
	instrumentoa->nota->RESOST.channel = 10;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/FaSost.wav");
	instrumentoa->nota->FASOST.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->FASOST.state = KEYUP;
	instrumentoa->nota->FASOST.channel = 11;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/SolSost.wav");
	instrumentoa->nota->SOLSOST.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->SOLSOST.state = KEYUP;
	instrumentoa->nota->SOLSOST.channel = 12;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/LaSost.wav");
	instrumentoa->nota->LASOST.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->LASOST.state = KEYUP;
	instrumentoa->nota->LASOST.channel = 13;

	strcpy(pathCopy, instrumentoa->path);
	strcat(pathCopy, "/DoMSost.wav");
	instrumentoa->nota->DOMSOST.audio = Mix_LoadWAV(pathCopy);
	instrumentoa->nota->DOMSOST.state = KEYUP;
	instrumentoa->nota->DOMSOST.channel = 14;

	return instrumentoa;
}

INSTRUMENTUA *instrumentuBatSortu(int ID, char instIzena[])
{
	INSTRUMENTUA *instBerria = NULL;

	instBerria = (INSTRUMENTUA*)malloc(sizeof(INSTRUMENTUA));

	instBerria->id = ID;
	strcpy(instBerria->izena, instIzena);
	strcpy(instBerria->path, "./notak/");
	strcat(instBerria->path, instBerria->izena);
	instBerria->ptrHurrengoa = NULL;

	instBerria = instrumentuaHasieratu(instBerria);

	return instBerria;
}

INSTRUMENTUA *bukaeranSartu(INSTRUMENTUA *instZerrenda, INSTRUMENTUA *instBerria)
{
	INSTRUMENTUA *pAux = instZerrenda;

	if (instZerrenda == NULL)
	{
		instZerrenda = instBerria;
	}
	else
	{
		while (pAux->ptrHurrengoa != NULL)
		{
			pAux = pAux->ptrHurrengoa;
		}

		pAux->ptrHurrengoa = instBerria;
	}

	return instZerrenda;
}

INSTRUMENTUA *instrumentuakKargatu(INSTRUMENTUA *instZerrenda)
{
	int end, id;
	char izena[128];
	FILE *fp;
	INSTRUMENTUA *pAux;

	fp = fopen("instrumentuak.txt", "r");

	if (fp == NULL) printf("[ERROR] EZIN DA INSTRUMENTUEN FITXATEGIA IRAKURRI");

	else
	{
		fscanf(fp, "%d\t%s\n", &id, izena);
		instZerrenda = instrumentuBatSortu(id, izena);

		pAux = instZerrenda;
		pAux = pAux->ptrHurrengoa;

		do
		{
			end = fscanf(fp, "%d\t%s\n", &id, izena);
			if (end > 0)
			{
				pAux = instrumentuBatSortu(id, izena);
				bukaeranSartu(instZerrenda, pAux);
			}

		}while (end > 0);

		fclose(fp);
		bukaeranSartu(instZerrenda, instZerrenda); //Con esto las lista será un bucle
	}

	return instZerrenda;
}

INSTRUMENTUA *instrumentuzAldatu(INSTRUMENTUA *instrumentoa)
{
	instrumentoa = instrumentoa->ptrHurrengoa;

	return instrumentoa;
}
