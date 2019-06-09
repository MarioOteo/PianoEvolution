#ifndef IRUDIAK_H_
#define IRUDIAK_H_

#define MAX_IMG 500

#include <SDL2/SDL.h>
#include <SDL_mixer.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
#include <stdio.h>
#include <time.h>


#define MAIN ".//img//UI//Piano.bmp"
#define PULL_DO ".//img//UI//Piano_PULS_Do.bmp"
#define PULL_RE ".//img//UI//Piano_PULS_Re.bmp"
#define PULL_MI ".//img//UI//Piano_PULS_Mi.bmp"
#define PULL_FA ".//img//UI//Piano_PULS_Fa.bmp"
#define PULL_SOL ".//img//UI//Piano_PULS_Sol.bmp"
#define PULL_LA ".//img//UI//Piano_PULS_La.bmp"
#define PULL_SI ".//img//UI//Piano_PULS_Si.bmp"
#define PULL_DOM ".//img//UI//Piano_PULS_DoM.bmp"
#define PULL_REM ".//img//UI//Piano_PULS_ReM.bmp"

#define PULL_DO_SOST ".//img//UI//Piano_PULS_DoSOST.bmp"
#define PULL_RE_SOST ".//img//UI//Piano_PULS_ReSOST.bmp"
#define PULL_FA_SOST ".//img//UI//Piano_PULS_FaSOST.bmp"
#define PULL_SOL_SOST ".//img//UI//Piano_PULS_SolSOST.bmp"
#define PULL_LA_SOST ".//img//UI//Piano_PULS_LaSOST.bmp"
#define PULL_DOM_SOST ".//img//UI//Piano_PULS_DoMSOST.bmp"

#define PULL_REC ".//img//UI//Piano_PULS_REC.bmp"
#define PULL_PLAY ".//img//UI//Piano_PULS_PLAY.bmp"
#define PULL_PAUSE ".//img//UI//Piano_PULS_PAUSE.bmp"
#define PULL_INST ".//img//UI//Piano_PULS_INSTRUMENTO.bmp"

#define PIANO_HERO ".//img//UI//Piano_GH.bmp"
#define SPRITE_LONG ".//img//UI//Piano_GH_Larga.bmp"
#define SPRITE_SHORT ".//img//UI//Piano_GH_Corta.bmp"
#define GAME_OVER ".//img//UI//Piano_GH_GAMEOVER.bmp"
#define SONG_SELECT ".//img//UI//Piano_GH_SELECT.bmp"

#define KONTROLAK ".//img//UI//Controles.bmp"

#define JUKEBOX ".//img//UI//Jukebox.bmp"
#define JUKEBOX_ERROR ".//img//UI//Jukebox_ERROR.bmp"
#define JUKEBOX_PAUSE ".//img//UI//Jukebox_PAUSE.bmp"
#define JUKEBOX_PLAYING ".//img//UI//Jukebox_PLAYING.bmp"

typedef struct Img
{
	int id;
	SDL_Surface* imagen;
	SDL_Texture* texture;
	SDL_Rect dest;
}IMG;
SDL_Renderer* gRenderer;

int irudiaMarraztu(SDL_Texture* texture, SDL_Rect *pDest);
void irudiakMarraztu(void);
int irudiaSortu(char* imgName);
int irudiarenPosizioaAurkitu(int id);
void pantailaGarbitu();
void  irudiaMugitu(int numImg, int x, int y);
void irudiaKendu(int id);
#endif /* IRUDIAK_H_ */
