#define _CRT_SECURE_NO_WARNINGS

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define KREDITU_IMAGE ".\\img\\Kredituak.bmp"

int kredituakSortu();

int kredituak()
{
	int nibela, ebentu;

	kredituakSortu();

	do
	{
		ebentu = ebentuaJasoGertatuBada();

	}while (ebentu != TECLA_z);
	
	nibela = 0;

	return nibela;
}


int kredituakSortu()
{
	int kredituak = -1;
	kredituak = irudiaKargatu(KREDITU_IMAGE);
	irudiaMugitu(kredituak, 0, -50);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return kredituak;
}
