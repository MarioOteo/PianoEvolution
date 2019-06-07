#ifndef FUNTZIOAK_H_
#define FUNTZIOAK_H_

//Pianoa edo erreprodukzioa pausatzeko
void pausaMenua();

//Teklen eta botoien animazioak bistaratzeko
int animazioa(int tekla);

//SDL libreriak hasieratzeko
void SDLhasieratu();

//Gertatu den input-ari dagokion output-a emateko
INSTRUMENTUA *ebentoaDetektatu(int tekla, INSTRUMENTUA *instZerrenda, ABESTI_ZERRENDA **abestiZerrenda, int *abestiKop);

//Teklen pultsazioak detektatzeko
int ebentuaJasoGertatuBada(INSTRUMENTUA *instrumentoa, int keyUpMatters);

//Pianoaren kontrol lehioa bistaratzeko
void kontrolakBistaratu();

//Teklen KEYDOWN/KEYUP estadoak konprobatzeko
void teklakKonprobatu(INSTRUMENTUA *instrumento, int chanKop);

#endif /* FUNTZIOAK_H_ */
