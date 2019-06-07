/*
 * abestiak.c
 *
 *  Created on: 26 may. 2019
 *      Author: grana
 */
#include "kontrolak.h"
//#include "irudiak.h"
//#include "abestiak.h"
//#include "soinua.h"
//#include "text.h"

void notaJo(int tekla, INSTRUMENTUA *instrumentoa)
{
	switch(tekla)
	{
	case TECLA_a:
		if (instrumentoa->nota->DO.state != KEYDOWN)
		{
			Mix_PlayChannel(instrumentoa->nota->DO.channel, instrumentoa->nota->DO.audio, 0);
			instrumentoa->nota->DO.state = KEYDOWN;
			//instrumentoa->nota->DO.imageID = irudiID;
		}
		break;

	case TECLA_s:
		if (instrumentoa->nota->RE.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->RE.channel, instrumentoa->nota->RE.audio, 0);
					instrumentoa->nota->RE.state = KEYDOWN;
					//instrumentoa->nota->RE.imageID = irudiID;
				}
		break;

	case TECLA_d:
		if (instrumentoa->nota->MI.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->MI.channel, instrumentoa->nota->MI.audio, 0);
					instrumentoa->nota->MI.state = KEYDOWN;
					//instrumentoa->nota->MI.imageID = irudiID;
				}
		break;

	case TECLA_f:
		if (instrumentoa->nota->FA.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->FA.channel, instrumentoa->nota->FA.audio, 0);
					instrumentoa->nota->FA.state = KEYDOWN;
					//instrumentoa->nota->FA.imageID = irudiID;
				}
		break;

	case TECLA_g:
		if (instrumentoa->nota->SOL.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->SOL.channel, instrumentoa->nota->SOL.audio, 0);
					instrumentoa->nota->SOL.state = KEYDOWN;
					//instrumentoa->nota->SOL.imageID = irudiID;
				}
		break;

	case TECLA_h:
		if (instrumentoa->nota->LA.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->LA.channel, instrumentoa->nota->LA.audio, 0);
					instrumentoa->nota->LA.state = KEYDOWN;
					//instrumentoa->nota->LA.imageID = irudiID;
				}
		break;

	case TECLA_j:
		if (instrumentoa->nota->SI.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->SI.channel, instrumentoa->nota->SI.audio, 0);
					instrumentoa->nota->SI.state = KEYDOWN;
					//instrumentoa->nota->SI.imageID = irudiID;
				}
		break;

	case TECLA_k:
		if (instrumentoa->nota->DOM.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->DOM.channel, instrumentoa->nota->DOM.audio, 0);
					instrumentoa->nota->DOM.state = KEYDOWN;
					//instrumentoa->nota->DOM.imageID = irudiID;
				}
		break;

	case TECLA_l:
		if (instrumentoa->nota->REM.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->REM.channel, instrumentoa->nota->REM.audio, 0);
					instrumentoa->nota->REM.state = KEYDOWN;
					//instrumentoa->nota->REM.imageID = irudiID;
				}
		break;

	case TECLA_w:
		if (instrumentoa->nota->DOSOST.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->DOSOST.channel, instrumentoa->nota->DOSOST.audio, 0);
					instrumentoa->nota->DOSOST.state = KEYDOWN;
					//instrumentoa->nota->DOSOST.imageID = irudiID;
				}
		break;

	case TECLA_e:
		if (instrumentoa->nota->RESOST.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->RESOST.channel, instrumentoa->nota->RESOST.audio, 0);
					instrumentoa->nota->RESOST.state = KEYDOWN;
					//instrumentoa->nota->RESOST.imageID = irudiID;
				}
		break;

	case TECLA_t:
		if (instrumentoa->nota->FASOST.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->FASOST.channel, instrumentoa->nota->FASOST.audio, 0);
					instrumentoa->nota->FASOST.state = KEYDOWN;
					//instrumentoa->nota->FASOST.imageID = irudiID;
				}
		break;

	case TECLA_y:
		if (instrumentoa->nota->SOLSOST.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->SOLSOST.channel, instrumentoa->nota->SOLSOST.audio, 0);
					instrumentoa->nota->SOLSOST.state = KEYDOWN;
					//instrumentoa->nota->SOLSOST.imageID = irudiID;
				}
		break;

	case TECLA_u:
		if (instrumentoa->nota->LASOST.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->LASOST.channel, instrumentoa->nota->LASOST.audio, 0);
					instrumentoa->nota->LASOST.state = KEYDOWN;
					//instrumentoa->nota->LASOST.imageID = irudiID;
				}
		break;

	case TECLA_o:
		if (instrumentoa->nota->DOMSOST.state != KEYDOWN)
				{
					Mix_PlayChannel(instrumentoa->nota->DOMSOST.channel, instrumentoa->nota->DOMSOST.audio, 0);
					instrumentoa->nota->DOMSOST.state = KEYDOWN;
					//instrumentoa->nota->DOMSOST.imageID = irudiID;
				}
		break;
	}
}

int notaIkutu(int tecla)
{
	int ret = 0;

	if(tecla == TECLA_a || tecla == TECLA_s || tecla == TECLA_d || tecla == TECLA_f || tecla == TECLA_g || tecla == TECLA_h || tecla == TECLA_j || tecla == TECLA_k || tecla == TECLA_l || tecla == TECLA_w || tecla == TECLA_e || tecla == TECLA_t || tecla == TECLA_y || tecla == TECLA_u || tecla == TECLA_o)
	{
		ret = 1;
	}

	return ret;
}

void zerrendaPantailaratu(ABESTIA* burua)
{
	ABESTIA* aux = burua;

	while(aux != NULL)
	{
		printf("%d %f\n", aux->tecla, aux->denbora);
		aux = aux->ptrHurrengoa;
	}
}

void erreproduzitu(ABESTIA* burua, INSTRUMENTUA *instrumentoa)
{
	ABESTIA* aux = burua;
	float delay;
	float fadeOutTime;
	int pausa = 0;

	zerrendaPantailaratu(burua);
	while(aux != NULL)
	{
		teklakKonprobatu(instrumentoa, 15);

		pausa = ebentuaJasoGertatuBada(NULL, 0);

		if(pausa == TECLA_p) pausaMenua();

		delay = (float)(aux->denbora/CLOCKS_PER_SEC) * 1100;
		fadeOutTime = (float)(aux->pulsDenbora/CLOCKS_PER_SEC) * 2000;

		SDL_Delay(delay);
		teklakKonprobatu(instrumentoa, 15);

		notaJo(aux->tecla, instrumentoa);
		fadeOut(instrumentoa, aux->tecla, fadeOutTime);

		aux = aux->ptrHurrengoa;
	}

	SDL_Delay(500);
}

ABESTIA* fitxIrakurri(int abestiKop)
{
	int egoera;
	ABESTIA* burua = NULL, *ptrFitx;
	FILE* fitx;

	fitx = fopen("abesti.txt", "r");
	if(fitx == NULL) printf("Errorea egon da abestien fitxategia irakurtzerakoan. . .\n");
	else
	{
		do
		{
			ptrFitx = (ABESTIA*)malloc(sizeof(ABESTIA));
			egoera = fscanf(fitx, "%d\t%f\t%f\n", &(ptrFitx->tecla), &(ptrFitx->denbora), &(ptrFitx->pulsDenbora));
			ptrFitx->ptrHurrengoa = NULL;
			if(egoera == 3) burua = sartuBukaeran(burua, ptrFitx);
			else ptrFitx = NULL;
		}while(egoera == 3);
		fclose(fitx);
	}

	return burua;
}


ABESTIA* sartuBukaeran(ABESTIA* burua, ABESTIA* berria)
{
	ABESTIA* aux = burua;

	if(burua == NULL) burua = berria;
	else
	{
		while(aux->ptrHurrengoa != NULL)
		{
			aux = aux->ptrHurrengoa;
		}
		aux->ptrHurrengoa = berria;
	}

	return burua;
}


int grabatuAbestia(INSTRUMENTUA *instrumentoa)
{
	int ret = 1, tecla = 0, puls = 0;
	FILE* fitx;
	float time;
	float pulsTime = 0;
	clock_t pulsBegin; //Declarados aquí porque si no da error al usar las varaibles
	clock_t endPuls;

	fitx = fopen("abesti.evo", "a");
	if(fitx == NULL)
	{
		printf("Errorea egon da abestiaren fitxategia sortzerakoan. . .\n");
		ret = -1;
	}
	else
	{
		do
		{
			clock_t begin = clock();
			do
			{
				tecla = ebentuaJasoGertatuBada(NULL, 1);

			}while(tecla != KEYUP && tecla != TECLA_1 && tecla != TECLA_a && tecla != TECLA_s && tecla != TECLA_d && tecla != TECLA_f && tecla != TECLA_g && tecla != TECLA_h && tecla != TECLA_j && tecla != TECLA_k && tecla != TECLA_l && tecla != TECLA_w && tecla != TECLA_e && tecla != TECLA_t && tecla != TECLA_y && tecla != TECLA_u && tecla != TECLA_o);

			if(tecla != TECLA_1)
			{
				ebentoaDetektatu(tecla, instrumentoa, NULL, 0);
				clock_t end = clock();
				time = (double)(end - begin + pulsTime);
				if (puls == 0 && tecla != 1)
				{
					fprintf(fitx, "%d\t%f", tecla, time);
					puls = 1;
					pulsBegin = clock();
				}

				if (tecla == KEYUP && puls == 1)
				{
					teklakKonprobatu(instrumentoa, 15);
					puls = 0;
					endPuls = clock();
					pulsTime = (double)(endPuls - pulsBegin);
					fprintf(fitx, "\t%f\n", pulsTime);
				}
			}

		}while(tecla != TECLA_1);

		fprintf(fitx, "-1\t-1\t-1\n");
		fclose(fitx);
	}

	return ret;
}


void fadeOut(INSTRUMENTUA *instZerrenda, int tekla, int denbora)
{
	if (denbora < 400) denbora = 400;

	switch (tekla)
	{
	case TECLA_a:
		Mix_FadeOutChannel(instZerrenda->nota->DO.channel, denbora);
		break;
	case TECLA_s:
		Mix_FadeOutChannel(instZerrenda->nota->RE.channel, denbora);
		break;
	case TECLA_d:
		Mix_FadeOutChannel(instZerrenda->nota->MI.channel, denbora);
		break;
	case TECLA_f:
		Mix_FadeOutChannel(instZerrenda->nota->FA.channel, denbora);
		break;
	case TECLA_g:
		Mix_FadeOutChannel(instZerrenda->nota->SOL.channel, denbora);
		break;
	case TECLA_h:
		Mix_FadeOutChannel(instZerrenda->nota->LA.channel, denbora);
		break;
	case TECLA_j:
		Mix_FadeOutChannel(instZerrenda->nota->SI.channel, denbora);
		break;
	case TECLA_k:
		Mix_FadeOutChannel(instZerrenda->nota->DOM.channel, denbora);
		break;
	case TECLA_l:
		Mix_FadeOutChannel(instZerrenda->nota->REM.channel, denbora);
		break;
	case TECLA_w:
		Mix_FadeOutChannel(instZerrenda->nota->DOSOST.channel, denbora);
		break;
	case TECLA_e:
		Mix_FadeOutChannel(instZerrenda->nota->RESOST.channel, denbora);
		break;
	case TECLA_t:
		Mix_FadeOutChannel(instZerrenda->nota->FASOST.channel, denbora);
		break;
	case TECLA_y:
		Mix_FadeOutChannel(instZerrenda->nota->SOLSOST.channel, denbora);
		break;
	case TECLA_u:
		Mix_FadeOutChannel(instZerrenda->nota->LASOST.channel, denbora);
		break;
	case TECLA_o:
		Mix_FadeOutChannel(instZerrenda->nota->DOMSOST.channel, denbora);
		break;
	}
}


ABESTI_ZERRENDA* abestiakKargatu(ABESTI_ZERRENDA* burua, int *abestiKop, int refresh)
{
	int egoera;
	ABESTI_ZERRENDA *pAux = NULL;
	ABESTIA *pAuxAbesti = NULL;
	FILE *fitx;

	fitx = fopen("abesti.evo", "r");

	if (fitx == NULL) printf("[ERROR]: Ezin izan da abestien fitxategia ireki!");

	else
	{
		pAux = burua;

		if (refresh == 1) *abestiKop = 0;

		do
		{
			pAux = (ABESTI_ZERRENDA*)malloc(sizeof(ABESTI_ZERRENDA));
			pAux->abestia = NULL;
			pAuxAbesti = pAux->abestia;
			pAux->id = *abestiKop;

			do
			{
				pAuxAbesti = (ABESTIA*)malloc(sizeof(ABESTIA));
				egoera = fscanf(fitx, "%d\t%f\t%f\n", &(pAuxAbesti->tecla), &(pAuxAbesti->denbora), &(pAuxAbesti->pulsDenbora));

				if (egoera == 3 && pAuxAbesti->tecla != -1)
				{
					pAuxAbesti->ptrHurrengoa = NULL;
					//pAuxAbesti = pAuxAbesti->ptrHurrengoa;
					pAux->abestia = sartuBukaeran(pAux->abestia, pAuxAbesti);
				}

				else if (egoera != EOF)
				{
					pAuxAbesti = NULL;
					egoera = 0;
				}

			}while(egoera == 3);

			pAux->ptrHurrengoa = NULL;

			if (egoera != EOF)
			{
				burua = abestiaZerrendanSartu(burua, pAux, refresh);
				*abestiKop = *abestiKop + 1;
			}

		}while(egoera != EOF);

		burua = abestiaZerrendanSartu(burua, burua, refresh);
		fclose(fitx);
	}

	return burua;
}


ABESTI_ZERRENDA *abestiaZerrendanSartu(ABESTI_ZERRENDA* burua, ABESTI_ZERRENDA* berria, int refresh)
{
	ABESTI_ZERRENDA *aux;

	aux = burua;

	if (burua == NULL)
	{
		burua = berria;
		if (burua != NULL) burua->ptrHurrengoa = NULL;
	}

	else
	{
		while (aux->ptrHurrengoa != NULL)
		{
			aux = aux->ptrHurrengoa;
		}

		aux->ptrHurrengoa = berria;
	}

	return burua;
}


void erreprodukzioMenua(ABESTI_ZERRENDA *abestiZerrenda, INSTRUMENTUA *instrumentoa, int abestiKop)
{
	int tekla, fondo;
	char mezua[128];

	if (abestiZerrenda == NULL)
	{
		fondo = irudiaKargatu(JUKEBOX_ERROR);
		irudiakMarraztu();
		textuaIdatzi(170, 250, "EZ DITUZU ABESTIRIK HEMEN!");
		textuaIdatzi(175, 300, "ZOAZ ZERBAIT GRABATZERA!");
		SDL_RenderPresent(gRenderer);

		do
		{
			tekla = ebentuaJasoGertatuBada(NULL, 0);
		}while (tekla != TECLA_ESCAPE);
	}

	else
	{
		fondo = irudiaSortu(JUKEBOX);
		printf("CANCIONES GUARDADAS: %d\n", abestiKop);
			textuaIdatzi(395, 360, "1. Abestia");
			SDL_RenderPresent(gRenderer);

			do
			{
				tekla = ebentuaJasoGertatuBada(NULL, 0);

				if (tekla == TECLA_DOWN)
				{
					textuaEzabatu();

					abestiZerrenda = abestiZerrenda->ptrHurrengoa;
					sprintf(mezua, "%d. Abestia", (abestiZerrenda->id + 1));
					if (abestiZerrenda->id + 1 >= 10) textuaIdatzi(380, 360, mezua);
					else textuaIdatzi(395, 360, mezua);
					SDL_RenderPresent(gRenderer);
				}

				if (tekla == TECLA_ENTER)
				{

					erreproduzitu(abestiZerrenda->abestia, instrumentoa);
					sprintf(mezua, "%d. Abestia", (abestiZerrenda->id + 1));
					if (abestiZerrenda->id + 1 >= 10) textuaIdatzi(380, 360, mezua);
					else textuaIdatzi(395, 360, mezua);
					//irudiakMarraztu();
					SDL_RenderPresent(gRenderer);
				}

			}while(tekla != TECLA_ESCAPE);
	}

	irudiaKendu(fondo);
}


