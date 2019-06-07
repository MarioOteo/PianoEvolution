/*
 * ghModea.c
 *
 *  Created on: 5 jun. 2019
 *      Author: grana
 */
#include "kontrolak.h"
//#include "irudiak.h"
//#include "estrukturak.h"
//#include "funtzioak.h"
//#include "ghModea.h"


int longOrShort(int tecla, char spritePath[])
{
	int length = 0;

	//Hemen ez da beharrezkoa begiratzea a-tik l-ra, ez bada w, e, t, y, u edo o horietako bat izango da, beste teklak ez ditulako grabatzen
	switch(tecla)
		{
		case TECLA_w:
			length = SPRITE_SHORT_LENGTH;
			strcpy(spritePath, SPRITE_SHORT);
			break;

		case TECLA_e:
			length = SPRITE_SHORT_LENGTH;
			strcpy(spritePath, SPRITE_SHORT);
			break;

		case TECLA_t:
			length = SPRITE_SHORT_LENGTH;
			strcpy(spritePath, SPRITE_SHORT);
			break;

		case TECLA_y:
			length = SPRITE_SHORT_LENGTH;
			strcpy(spritePath, SPRITE_SHORT);
			break;

		case TECLA_u:
			length = SPRITE_SHORT_LENGTH;
			strcpy(spritePath, SPRITE_SHORT);
			break;

		case TECLA_o:
			length = SPRITE_SHORT_LENGTH;
			strcpy(spritePath, SPRITE_SHORT);
			break;

		default:
			length = SPRITE_LONG_LENGTH;
			strcpy(spritePath, SPRITE_LONG);
			break;
		}

	return length;
}

char* messageBasedOnScore(int score, int dim)
{
	int percent;
	char* mezua;

	score /= 10;
	percent = ((float) score/dim) * 100;
	if(percent == 100)
	{
		mezua = (char*)malloc(sizeof(char) * 76);
		sprintf(mezua, "\"Zorionak!, Perfekto egin duzu: %d\%\"", percent);
	}
	else if( percent >= 75)
	{
		mezua = (char*)malloc(sizeof(char) * 67);
		sprintf(mezua, "\"Zorionak!, Oso txukun jo duzu: %d\%\"", percent);
	}
	else if( percent >= 50)
	{
		mezua = (char*)malloc(sizeof(char) * 30);
		sprintf(mezua, "\"Ongi egin duzu: %d\%\"", percent);
	}
	else if( percent >= 25)
	{
		mezua = (char*)malloc(sizeof(char) * 35);
		sprintf(mezua, "\"Benetan saiatu zara?: %d\%\"", percent);
	}
	else
	{
		mezua = (char*)malloc(sizeof(char) * 45);
		sprintf(mezua, "\"Behintzat errex daukazu hobetzeko: %d\%\"", percent);
	}

	return mezua;
}

int songLength(ABESTIA* song)
{
	int dim = 0;
	ABESTIA* aux = song;

	while(aux != NULL)
	{
		dim++;
		aux = aux->ptrHurrengoa;
	}

	return dim;
}

void bukaerakoPuntuazioaPant(int puntuazioa, int dim)
{
	char* mezua;
	int tekla, irudiID;

	irudiID = irudiaKargatu(GAME_OVER);
	irudiakMarraztu();
	mezua = messageBasedOnScore(puntuazioa, dim);
	textuaIdatzi(70, 220, mezua);
	SDL_RenderPresent(gRenderer);

	do
	{
		tekla = ebentuaJasoGertatuBada(NULL, 0);
	}while(tekla != TECLA_ESCAPE && tekla != TECLA_ENTER);

	irudiaKendu(irudiID);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);

	free(mezua);
}

int diskaEzabatuBeharDa(GH_TILE** burua, INSTRUMENTUA* instZerrenda, ABESTIA** zerrenda, int length)
{
	int tecla, puntuaketa = 0;

	tecla = ebentuaJasoGertatuBada(instZerrenda, 1);
	if(notaIkutu(tecla) == 1)
	{
		notaJo(tecla, instZerrenda);
		if(zuzenEmanDio(tecla, (*burua), (*zerrenda)) == 1)
		{
			irudiaKendu((*burua)->id);
			(*burua) = zerrendakoLehenElementuaEzabatu((*burua));
			(*zerrenda) = ABESTIA_zerrendakoLehenElementuaEzabatu((*zerrenda));
			puntuaketa = 10;
		}
	}
	else if((*burua) != NULL)
	{
		if((*burua)->pos.y >= HITBOX_BUKAERA - length) //35 borobilaren R
		{
			irudiaKendu((*burua)->id);
			(*burua) = zerrendakoLehenElementuaEzabatu((*burua));
			(*zerrenda) = ABESTIA_zerrendakoLehenElementuaEzabatu((*zerrenda));
		}
	}

	return puntuaketa;
}

ABESTIA* ABESTIA_zerrendakoLehenElementuaEzabatu(ABESTIA* burua)
{
	GH_TILE *tmp;

	if(burua != NULL)
	{
		tmp = burua->ptrHurrengoa;
		burua->ptrHurrengoa = NULL;
		//free(burua);
		burua = tmp;
	}

	return burua;
}

GH_TILE* zerrendakoLehenElementuaEzabatu(GH_TILE* burua)
{
	GH_TILE *tmp;

	if(burua != NULL)
	{
		tmp = burua->pHurrengoa;
		burua->pHurrengoa = NULL;
		free(burua);
		burua = tmp;
	}

	return burua;
}

GH_TILE* diskaBukaeranSartu(GH_TILE* burua, GH_TILE* berria)
{
	GH_TILE* aux= burua;

	if(burua == NULL)
	{
		burua = berria;
	}
	else
	{
		while(aux->pHurrengoa != NULL)
		{
			aux = aux->pHurrengoa;
		}
		aux->pHurrengoa = berria;
	}

	return burua;
}

GH_TILE* diskaGuztiakMugitu(GH_TILE* burua, int konstante)
{
	GH_TILE* aux = burua;

	while(aux != NULL)
	{
		aux->pos.y += konstante;
		irudiaMugitu(aux->id, aux->pos.x, aux->pos.y);
		aux = aux->pHurrengoa;
	}
	//Hemen jarrita Render hobeto ibiltzen da programa, baina irudien mugimendua itsusia da
	pantailaGarbitu();
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);

	return burua;
}

int zuzenEmanDio(int tecla, GH_TILE* burua, ABESTIA* aux)
{
	int ret = 0;
	GH_TILE* auxBurua = burua;

	if(burua != NULL)
	{
		if(tecla == aux->tecla && auxBurua->pos.y > HITBOX_HASIERA - SPRITE_LONG_LENGTH && auxBurua->pos.y < HITBOX_BUKAERA - SPRITE_LONG_LENGTH)
		{
			ret = 1;
			printf("Eres un ganador!\n");
		}
	}


	return ret;
}

int notaAraberaXPos(int tecla)
{
	int xPos = 0;

	switch(tecla)
	{
	case TECLA_a:
		xPos = 56;
		break;

	case TECLA_s:
		xPos = 156;
		break;

	case TECLA_d:
		xPos = 256;
		break;

	case TECLA_f:
		xPos = 356;
		break;
	case TECLA_g:
		xPos = 456;
		break;

	case TECLA_h:
		xPos = 556;
		break;

	case TECLA_j:
		xPos = 656;
		break;

	case TECLA_k:
		xPos = 756;
		break;

	case TECLA_l:
		xPos = 856;
		break;

	case TECLA_w:
		xPos = 126;
		break;

	case TECLA_e:
		xPos = 226;
		break;

	case TECLA_t:
		xPos = 426;
		break;

	case TECLA_y:
		xPos = 526;
		break;

	case TECLA_u:
		xPos = 626;
		break;

	case TECLA_o:
		xPos = 826;
		break;


	}

	return xPos;
}

void startGuitarMode(ABESTIA* zerrenda, INSTRUMENTUA* instZerrenda)
{
	int konstante, puntuaketa = 0, idGuitar, hitBox, dim;
	char spritePath[40];
	ABESTIA* aux;
	GH_TILE* burua = NULL, *tmp;
	float expiredTime = 0;

	aux = zerrenda;
	konstante = (400 / aux->denbora) * ESTIMATED_EX_TIME;
	dim = songLength(zerrenda);
	idGuitar = irudiaSortu(PIANO_HERO);
	while(aux != NULL)
	{
		clock_t begin = clock();
		if(expiredTime >= aux->denbora)
		 {
		 	tmp = (GH_TILE*)malloc(sizeof(GH_TILE));
		 	hitBox = longOrShort(aux->tecla, spritePath);
		 	tmp->id = irudiaSortu(spritePath);
		 	tmp->pHurrengoa = NULL;
		 	tmp->pos.y = 0;
			tmp->pos.x = notaAraberaXPos(aux->tecla);
		 	burua = diskaBukaeranSartu(burua, tmp);
		 	aux = aux->ptrHurrengoa;
		  	expiredTime = 0;
		  	teklakKonprobatu(instZerrenda, 15);
		 }
		puntuaketa += diskaEzabatuBeharDa(&burua, instZerrenda, &zerrenda, hitBox);
		if(aux != NULL && burua != NULL) burua = diskaGuztiakMugitu(burua, konstante);
		clock_t end = clock();
		expiredTime += end - begin;
	}
	while(burua != NULL)
	{
		pantailaGarbitu();
		puntuaketa += diskaEzabatuBeharDa(&burua, instZerrenda, &zerrenda, hitBox);
		if(burua != NULL)burua = diskaGuztiakMugitu(burua, konstante);

	}
	bukaerakoPuntuazioaPant(puntuaketa, dim);
	irudiaKendu(idGuitar);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);
	//free(burua);
}

ABESTIA* abestiaAukeratu(ABESTI_ZERRENDA *abestiZerrenda)
{
	int tekla, irudiID;
	ABESTIA* abestia = NULL;
		//int abestiNum = 1;
		char mezua[128];

		irudiID = irudiaKargatu(PIANO_HERO);
		irudiakMarraztu();

		if (abestiZerrenda == NULL)
		{
			textuaIdatzi(170, 150, "EZ DITUZU ABESTIRIK HEMEN!");
			textuaIdatzi(175, 200, "ZOAZ ZERBAIT GRABATZERA!");
			SDL_RenderPresent(gRenderer);

			do
			{
				tekla = ebentuaJasoGertatuBada(NULL, 0);
			}while (tekla != TECLA_ESCAPE);
		}

		else
		{
				textuaIdatzi(395, 160, "1. Abestia");
				SDL_RenderPresent(gRenderer);

				do
				{
					abestia = abestiZerrenda->abestia;
					tekla = ebentuaJasoGertatuBada(NULL, 0);

					if (tekla == TECLA_DOWN)
					{
						textuaEzabatu();

						abestiZerrenda = abestiZerrenda->ptrHurrengoa;
						sprintf(mezua, "%d. Abestia", (abestiZerrenda->id + 1));
						if (abestiZerrenda->id + 1 >= 10) textuaIdatzi(380, 160, mezua);
						else textuaIdatzi(395, 160, mezua);
						SDL_RenderPresent(gRenderer);
					}

				}while(tekla != TECLA_ENTER);
		}

		irudiaKendu(irudiID);

		return abestia;
}

