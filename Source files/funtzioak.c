#include "kontrolak.h"
//#include "irudiak.h"
//#include "abestiak.h"
//#include "funtzioak.h"


void pausaMenua()
{
	int egoera = 1;
	int irudiID = -1;

	irudiID = animazioa(TECLA_p);

	printf("Pausa\n");
	while(egoera == 1)
	{
		if(ebentuaJasoGertatuBada(NULL, 0) == TECLA_p) egoera = 0;
	}

	irudiaKendu(irudiID);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);

	printf("Go\n");
}

int animazioa(int tekla)
{
	int irudiaID;

	switch(tekla)
		{
		case TECLA_a:
			irudiaID = irudiaSortu(PULL_DO);
			irudiaMugitu(irudiaID, 50, 180);
			break;

		case TECLA_s:
			irudiaID = irudiaSortu(PULL_RE);
			irudiaMugitu(irudiaID, 150, 180);
			break;

		case TECLA_d:
			irudiaID = irudiaSortu(PULL_MI);
			irudiaMugitu(irudiaID, 250, 180);
			break;

		case TECLA_f:
			irudiaID = irudiaSortu(PULL_FA);
			irudiaMugitu(irudiaID, 350, 180);
			break;

		case TECLA_g:
			irudiaID = irudiaSortu(PULL_SOL);
			irudiaMugitu(irudiaID, 450, 180);
			break;

		case TECLA_h:
			irudiaID = irudiaSortu(PULL_LA);
			irudiaMugitu(irudiaID, 550, 180);
			break;

		case TECLA_j:
			irudiaID = irudiaSortu(PULL_SI);
			irudiaMugitu(irudiaID, 650, 180);
			break;

		case TECLA_k:
			irudiaID = irudiaSortu(PULL_DOM);
			irudiaMugitu(irudiaID, 750, 180);
			break;

		case TECLA_l:
			irudiaID = irudiaSortu(PULL_REM);
			irudiaMugitu(irudiaID, 850, 180);
			break;

		case TECLA_w:
			irudiaID = irudiaSortu(PULL_DO_SOST);
			irudiaMugitu(irudiaID, 120, 180);
			break;

		case TECLA_e:
			irudiaID = irudiaSortu(PULL_RE_SOST);
			irudiaMugitu(irudiaID, 220, 180);
			break;

		case TECLA_t:
			irudiaID = irudiaSortu(PULL_FA_SOST);
			irudiaMugitu(irudiaID, 420, 180);
			break;

		case TECLA_y:
			irudiaID = irudiaSortu(PULL_SOL_SOST);
			irudiaMugitu(irudiaID, 520, 180);
			break;

		case TECLA_u:
			irudiaID = irudiaSortu(PULL_LA_SOST);
			irudiaMugitu(irudiaID, 620, 180);
			break;

		case TECLA_o:
			irudiaID = irudiaSortu(PULL_DOM_SOST);
			irudiaMugitu(irudiaID, 820, 180);
			break;

		case TECLA_p:
			irudiaID = irudiaSortu(PULL_PAUSE);
			irudiaMugitu(irudiaID, 290, 50);
			break;

		case TECLA_1:
			irudiaID = irudiaSortu(PULL_REC);
			irudiaMugitu(irudiaID, 50, 50);
			break;

		case TECLA_2:
			irudiaID = irudiaSortu(PULL_PLAY);
			irudiaMugitu(irudiaID, 170, 50);
			break;

		case TECLA_3:
			irudiaID = irudiaSortu(PULL_INST);
			irudiaMugitu(irudiaID, 410, 50);
			break;
		}

	irudiakMarraztu();
	//SDL_RenderPresent(gRenderer);

	return irudiaID;
}

void SDLhasieratu()
{
	SDL_Window* test;
	SDL_Surface* surface;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) printf("SDL couldn't start! SDL error: %s", SDL_GetError());
	else
	{
		test = SDL_CreateWindow("Test", 500, 500, 1000, 600, SDL_WINDOW_RESIZABLE);
		if(test == NULL)printf("Window couldn't be created. . . Error: %s", SDL_GetError());
		else
		{
			gRenderer = SDL_CreateRenderer(test, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			surface = SDL_GetWindowSurface(test);
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
			if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
					printf("Mix_OpenAudio: %s\n", Mix_GetError());
					exit(2);
			}
			else
			{
				//pianoaHasieratu();
				SDL_UpdateWindowSurface(test);
				irudiaSortu(MAIN);
				SDL_RenderPresent(gRenderer);
			}
		}
	}
}

INSTRUMENTUA *ebentoaDetektatu(int tekla, INSTRUMENTUA *instZerrenda, ABESTI_ZERRENDA **abestiZerrenda, int *abestiKop)
{
	ABESTI_ZERRENDA *abestiZerrendaBerria = NULL;
	ABESTIA* abestia;
	int irudiID = -1;

	if(notaIkutu(tekla) == 1)
	{
		notaJo(tekla, instZerrenda);
		irudiID = animazioa(tekla);
		irudiaKendu(irudiID);
		//irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}

	switch (tekla)
	{
		case TECLA_1:
			printf("Grabatzen\n");
			irudiID = animazioa(tekla);
			SDL_RenderPresent(gRenderer);
			grabatuAbestia(instZerrenda);
			*abestiZerrenda = abestiakKargatu(abestiZerrendaBerria, abestiKop, 1); //Refrescar las grabaciones
			irudiaKendu(irudiID);
			printf("Grabatzen amaitu da\n");
			irudiakMarraztu();
			//SDL_RenderPresent(gRenderer);
			break;

		case TECLA_2:
			printf("Erreproduzitzen\n");
			//irudiID = animazioa(tekla);
			erreprodukzioMenua(*abestiZerrenda, instZerrenda, *abestiKop);
			printf("Bukatu erreproduzitzen\n");
			//irudiaKendu(irudiID);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			break;

		case TECLA_3:
			irudiID = animazioa(tekla);
			SDL_RenderPresent(gRenderer);
			instZerrenda = instrumentuzAldatu(instZerrenda);
			SDL_Delay(500);
			irudiaKendu(irudiID);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			break;

		case TECLA_p:
			irudiID = animazioa(tekla);
			SDL_RenderPresent(gRenderer);
			printf("Pausa\n");
			pausaMenua();
			irudiaKendu(irudiID);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			break;

		case TECLA_SPACE:
			kontrolakBistaratu();
			break;

		case TECLA_ENTER:
			abestia = abestiaAukeratu(*abestiZerrenda);
			if (abestia != NULL)
			{
				startGuitarMode(abestia, instZerrenda);
				*abestiZerrenda = NULL;
				*abestiZerrenda = abestiakKargatu(*abestiZerrenda, &abestiKop, 1);
			}
			break;
	}

	//irudiakMarraztu();
	//SDL_RenderPresent(gRenderer);

	return instZerrenda;
}

int ebentuaJasoGertatuBada(INSTRUMENTUA *instrumentoa, int keyUpMatters)
{
	int ret = 0;
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_a:
					ret = TECLA_a;
					break;
				case SDLK_s:
					ret = TECLA_s;
					break;
				case SDLK_d:
					ret = TECLA_d;
					break;
				case SDLK_f:
					ret = TECLA_f;
					break;
				case SDLK_g:
					ret = TECLA_g;
					break;
				case SDLK_h:
					ret = TECLA_h;
					break;
				case SDLK_j:
					ret = TECLA_j;
					break;
				case SDLK_k:
					ret = TECLA_k;
					break;
				case SDLK_l:
					ret = TECLA_l;
					break;
				case SDLK_w:
					ret = TECLA_w;
					break;
				case SDLK_e:
					ret = TECLA_e;
					break;
				case SDLK_t:
					ret = TECLA_t;
					break;
				case SDLK_y:
					ret = TECLA_y;
					break;
				case SDLK_u:
					ret = TECLA_u;
					break;
				case SDLK_o:
					ret = TECLA_o;
					break;
				case SDLK_1:
					ret = TECLA_1;
					break;
				case SDLK_2:
					ret = TECLA_2;
					break;
				case SDLK_3:
					ret = TECLA_3;
					break;
				case SDLK_0:
					ret = TECLA_0;
					break;
				case SDLK_p:
					ret = TECLA_p;
					break;
				case SDLK_ESCAPE:
					ret = TECLA_ESCAPE;
					break;
				case SDLK_SPACE:
					ret = TECLA_SPACE;
					break;
				case SDLK_UP:
					ret = TECLA_UP;
					break;
				case SDLK_DOWN:
					ret = TECLA_DOWN;
					break;
				case SDLK_RETURN:
					ret = TECLA_ENTER;
					break;
			}
			break;

		case SDL_KEYUP:
			{
				if (keyUpMatters == 1)
				{
				case SDLK_1:
					return KEYUP;

				case SDLK_a:
					if (instrumentoa->nota->DO.state == KEYUP)
					{
						Mix_FadeOutChannel(0, 500);
					}

				case SDLK_s:
					if (instrumentoa->nota->RE.state == KEYUP)
					{
						Mix_FadeOutChannel(1, 500);
					}


				case SDLK_d:
					if (instrumentoa->nota->MI.state == KEYUP)
					{
						Mix_FadeOutChannel(2, 500);
					}


				case SDLK_f:
					if (instrumentoa->nota->FA.state == KEYUP)
					{
						Mix_FadeOutChannel(3, 500);
					}


				case SDLK_g:
					if (instrumentoa->nota->SOL.state == KEYUP)
					{
						Mix_FadeOutChannel(4, 500);
					}


				case SDLK_h:
					if (instrumentoa->nota->LA.state == KEYUP)
					{
						Mix_FadeOutChannel(5, 500);
					}


				case SDLK_j:
					if (instrumentoa->nota->SI.state == KEYUP)
					{
						Mix_FadeOutChannel(6, 500);
					}


				case SDLK_k:
					if (instrumentoa->nota->DOM.state == KEYUP)
					{
						Mix_FadeOutChannel(7, 500);
					}


				case SDLK_l:
					if (instrumentoa->nota->REM.state == KEYUP)
					{
						Mix_FadeOutChannel(8, 500);
					}


				case SDLK_w:
					if (instrumentoa->nota->DOSOST.state == KEYUP)
					{
						Mix_FadeOutChannel(9, 500);
					}


				case SDLK_e:
					if (instrumentoa->nota->RESOST.state == KEYUP)
					{
						Mix_FadeOutChannel(10, 500);
					}


				case SDLK_t:
					if (instrumentoa->nota->FASOST.state == KEYUP)
					{
						Mix_FadeOutChannel(11, 500);
					}


				case SDLK_y:
					if (instrumentoa->nota->SOLSOST.state == KEYUP)
					{
						Mix_FadeOutChannel(12, 500);
					}


				case SDLK_u:
					if (instrumentoa->nota->LASOST.state == KEYUP)
					{
						Mix_FadeOutChannel(13, 500);
					}


				case SDLK_o:
					if (instrumentoa->nota->DOMSOST.state == KEYUP)
					{
						Mix_FadeOutChannel(14, 500);
					}
				}
			}

			ret = KEYUP;
			break;
		}
	}

	return ret;
}

void teklakKonprobatu(INSTRUMENTUA *instrumento, int chanKop)
{
	for (int i = 0; i <= chanKop; i++)
	{
		if (Mix_FadingChannel(i) == MIX_NO_FADING)
		{
			switch(i)
			{
				case 0:
					//irudiaKendu(instrumento->nota->DO.imageID);
					instrumento->nota->DO.state = KEYUP;
					Mix_FadeOutChannel(0, 500);
					break;
				case 1:
					//irudiaKendu(instrumento->nota->RE.imageID);
					instrumento->nota->RE.state = KEYUP;
					Mix_FadeOutChannel(1, 500);
					break;
				case 2:
					//irudiaKendu(instrumento->nota->MI.imageID);
					instrumento->nota->MI.state = KEYUP;
					Mix_FadeOutChannel(2, 500);
					break;
				case 3:
					//irudiaKendu(instrumento->nota->FA.imageID);
					instrumento->nota->FA.state = KEYUP;
					Mix_FadeOutChannel(3, 500);
					break;
				case 4:
					//irudiaKendu(instrumento->nota->SOL.imageID);
					instrumento->nota->SOL.state = KEYUP;
					Mix_FadeOutChannel(4, 500);
					break;
				case 5:
					//irudiaKendu(instrumento->nota->LA.imageID);
					instrumento->nota->LA.state = KEYUP;
					Mix_FadeOutChannel(5, 500);
					break;
				case 6:
					//irudiaKendu(instrumento->nota->SI.imageID);
					instrumento->nota->SI.state = KEYUP;
					Mix_FadeOutChannel(6, 500);
					break;
				case 7:
					//irudiaKendu(instrumento->nota->DOM.imageID);
					instrumento->nota->DOM.state = KEYUP;
					Mix_FadeOutChannel(7, 500);
					break;
				case 8:
					//irudiaKendu(instrumento->nota->REM.imageID);
					instrumento->nota->REM.state = KEYUP;
					Mix_FadeOutChannel(8, 500);
					break;
				case 9:
					//irudiaKendu(instrumento->nota->DOSOST.imageID);
					instrumento->nota->DOSOST.state = KEYUP;
					Mix_FadeOutChannel(9, 500);
					break;
				case 10:
					//irudiaKendu(instrumento->nota->RESOST.imageID);
					instrumento->nota->RESOST.state = KEYUP;
					Mix_FadeOutChannel(10, 500);
					break;
				case 11:
					//irudiaKendu(instrumento->nota->FASOST.imageID);
					instrumento->nota->FASOST.state = KEYUP;
					Mix_FadeOutChannel(11, 500);
					break;
				case 12:
					//irudiaKendu(instrumento->nota->SOLSOST.imageID);
					instrumento->nota->SOLSOST.state = KEYUP;
					Mix_FadeOutChannel(12, 500);
					break;
				case 13:
					//irudiaKendu(instrumento->nota->LASOST.imageID);
					instrumento->nota->LASOST.state = KEYUP;
					Mix_FadeOutChannel(13, 500);
					break;
				case 14:
					//irudiaKendu(instrumento->nota->DOMSOST.imageID);
					instrumento->nota->DOMSOST.state = KEYUP;
					Mix_FadeOutChannel(14, 500);
					break;
			}
		}
	}

	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);
}

void kontrolakBistaratu()
{
	int tekla, id;

	id = irudiaSortu(KONTROLAK);
	SDL_RenderPresent(gRenderer);

	do
	{
		tekla = ebentuaJasoGertatuBada(NULL, 0);
	}while (tekla != TECLA_SPACE);

	irudiaKendu(id);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);
}
