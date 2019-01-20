#define _CRT_SECURE_NO_WARNINGS
/*#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"*/

//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#define JOKOA_SOUND ".\\sound\\nightonbaldmountain.wav"


#include <stdio.h>
#include "nibelak.h"

int main(int argc, char * str[]) {
	int jarraitu = 0, nibela = 0;

	if (sgHasieratu() == -1)
	{
		fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
		return 1;
	}
	do
	{
		audioInit();
		loadTheMusic(JOKOA_SOUND);
		playMusic();
		nibela = 0;
		printf("menua. \n");
		nibela = menua();
		if (nibela == 1)
		{
			printf("Nibela hasiko da.\n");
			nibela = jokatu2();
			if (nibela == 1)
			{
				printf("bigarrena.\n");
				nibela = jokatu();
				if (nibela == 1)
				{
					nibela = hirugarrena();
					if (nibela == 1)
					{
						nibela = boss();
					}
				}
			}
		}
		if (nibela == 2)
		{
			printf("Kredituak agertuko dira. \n");
			nibela = kredituak();
		}
		if (nibela == 3)
		{
			printf("Jokoa itxiko da. \n");
		}
		toggleMusic();
		audioTerminate();
	} while (nibela != 3);
	sgItxi();
	return 0;
}
