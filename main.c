#include "kontrolak.h"
//#include "irudiak.h"
//#include "estrukturak.h"
//#include "funtzioak.h"
//#include "abestiak.h"
//#include "SDL_ttf.h"
//#include "text.h"

int main()
{
	int tecla = -1;
	int abestiKop = 0;
	int chanKop = 15; //Nota kopurua
	INSTRUMENTUA *instZerrenda = NULL;
	ABESTI_ZERRENDA *abestiZerrenda = NULL;

	SDLhasieratu();
	TTF_Init();

	chanKop = Mix_AllocateChannels(chanKop);
	printf("Channel amount: %d\n", chanKop);
	instZerrenda = instrumentuakKargatu(instZerrenda);
	abestiZerrenda = abestiakKargatu(abestiZerrenda, &abestiKop, 0);

	do
	{
		tecla = ebentuaJasoGertatuBada(instZerrenda, 1);
		instZerrenda = ebentoaDetektatu(tecla, instZerrenda, &abestiZerrenda, &abestiKop);

		textuaIdatzi(650, 80, instZerrenda->izena);
		SDL_RenderPresent(gRenderer);

		if (tecla == KEYUP) teklakKonprobatu(instZerrenda, chanKop);

	}while(tecla != TECLA_ESCAPE);

	TTF_Quit();
	SDL_Quit();
	return 0;
}

