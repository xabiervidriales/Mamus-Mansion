#define _CRT_SECURE_NO_WARNINGS

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define ATZEKALDE_IMAGE ".\\img\\menua.bmp"
#define LOGO_IMAGE ".\\img\\logo.bmp"

#include "funtzioak.h"

void JOKOA_atzekaldeaSortu();
int logoSortu();

POSIZIOA ERREALITATE_FISIKOA_saltoa(POSIZIOA posizioa, int tartekoPos);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);

int dy = 5;

int menua()
{
	int mugitu = 0, salto = 0, salto2 = 0, salto3 = 0, tiro = 0, tartekoPos, norabidea, ez;
	int ebentu = 0, nibela = 0, noraBegira = 0;
	JOKO_ELEMENTUA bala, jokalaria, jokalarialeft, logo;
	POSIZIOA aux;

	jokalaria.pos.x = 200;
	jokalaria.pos.y = 100;

	bala.pos.x = 0;
	bala.pos.y = -100;

	logo.pos.x = 400;
	logo.pos.y = -200;

	JOKOA_atzekaldeaSortu();
	jokalaria.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	noraBegira = 1;
	jokalarialeft.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	logo.id = logoSortu();
	bala.id = balaSortu();

	tartekoPos = jokalaria.pos.y - 130;

	do {

		Sleep(4);

		ebentu = ebentuaJasoGertatuBada();

		if (logo.pos.y < 90)
		{
			logo.pos.y += 1;
		}

		//---------------------------------------Teklen funtzioak-------------------------------------------------
		if (ebentu == TECLA_RIGHT && jokalaria.pos.x < 1200)
		{
			noraBegira = 0;
			aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
			jokalaria.pos.x = aux.x;
		}

		if (ebentu == TECLA_LEFT && jokalaria.pos.x > 15)
		{
			noraBegira = 1;
			jokalaria.pos.x -= 10;
		}

		if (ebentu == TECLA_SPACE && !salto)
		{
			tartekoPos = jokalaria.pos.y - 130;
			salto = 1;
			dy = 9;
		}

		if (ebentu == TECLA_d && !tiro)
		{
			tiro = 1;
			bala.pos.x = jokalaria.pos.x + 70;
			if (noraBegira)
			{
				bala.pos.x = jokalaria.pos.x + 35;
				tiro = -1;
			}
			bala.pos.y = jokalaria.pos.y + 40;
		}

		//----------------------------------------Saltoa---------------------------------------------------
		if (salto)
		{
			aux = ERREALITATE_FISIKOA_saltoa(jokalaria.pos, tartekoPos);
			jokalaria.pos.y = aux.y;

			if (jokalaria.pos.y > 440)
			{
				salto = 0;
			}

			if ((((jokalaria.pos.x > 602 && jokalaria.pos.x < 830) && (jokalaria.pos.y > 356)) || ((jokalaria.pos.x < 602 && jokalaria.pos.x > 545) && (jokalaria.pos.y > 386)) || ((jokalaria.pos.x > 538 && jokalaria.pos.x < 545) && (jokalaria.pos.y > 386)) || ((jokalaria.pos.x < 538 && jokalaria.pos.x > 453) && (jokalaria.pos.y > 411))) && (dy < 0))
			{
				salto = 0;
			}
		}

		Sleep(7);

		if (((jokalaria.pos.y < 440 && jokalaria.pos.x > 830) || (jokalaria.pos.y < 390 && (jokalaria.pos.x < 602 && jokalaria.pos.x > 545)) || ((jokalaria.pos.x < 538 && jokalaria.pos.x > 453) && jokalaria.pos.y < 415) || (jokalaria.pos.x < 453 && jokalaria.pos.y < 440)) && (!salto))
		{
			jokalaria.pos.y += 4;
		}

		if (jokalaria.pos.y > 440)
		{
			jokalaria.pos.y = 440;
		}

		pantailaGarbitu();

		//----------------------------------------nibeletara sarrerak-----------------------------------

		if (jokalaria.pos.x > 1000)
		{
			nibela = 2;
		}
		if ((jokalaria.pos.x > 800 && jokalaria.pos.x < 900) && jokalaria.pos.y < 390)
		{
			nibela = 1;
		}
		if (jokalaria.pos.x < 100)
		{
			nibela = 3;
		}

		//----------------------------Norabidearen arabera, jokalariaren begirada aldatu-----------------------------
		if (!noraBegira)
		{
			norabidea = jokalaria.id;
			ez = jokalarialeft.id;

			if (bala.pos.x < 1200 && bala.pos.x > 0 && tiro == 1)
			{
				bala.pos.x += 8;
				if (bala.pos.x > 1150)
				{
					bala.pos.y = -100;
					bala.pos.y = 0;
				}
			}
			else
			{
				tiro = 0;
			}
		}

		if (noraBegira)
		{
			norabidea = jokalarialeft.id;
			ez = jokalaria.id;

			if (bala.pos.x < 1200 && bala.pos.x > 0 && tiro == -1)
			{
				bala.pos.x -= 8;
				if (bala.pos.x < 5)
				{
					bala.pos.y = -100;
					bala.pos.y = 0;
				}
			}
			else
			{
				tiro = 0;
			}
		}

		if (!tiro)
		{
			bala.pos.y = -100;
			bala.pos.y = 0;
		}

		//----------------------------Alde grafikoa kargatu eta bistaratu-----------------------------------------
		pantailaGarbitu();
		irudiaMugitu(norabidea, jokalaria.pos.x, jokalaria.pos.y);
		irudiaMugitu(ez, -200, -200);
		irudiaMugitu(bala.id, bala.pos.x, bala.pos.y);
		irudiaMugitu(logo.id, logo.pos.x, logo.pos.y);
		irudiakMarraztu();
		pantailaBerriztu();

	} while (nibela == 0); //   Hiltzean jokoa gelditzen da

	irudiaKendu(jokalaria.id);
	pantailaGarbitu();
	pantailaBerriztu();

	return nibela;
}

void JOKOA_atzekaldeaSortu()
{
	int atzekaldeId = -1;
	atzekaldeId = irudiaKargatu(ATZEKALDE_IMAGE);
	irudiaMugitu(atzekaldeId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
}

int logoSortu()
{
	int logo = -1;
	logo = irudiaKargatu(LOGO_IMAGE);
	irudiaMugitu(logo, 100, 442);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return logo;
}

POSIZIOA ERREALITATE_FISIKOA_saltoa(POSIZIOA posizioa, int tartekoPos) {

	Sleep(2);
	posizioa.y = posizioa.y - dy;
	if (posizioa.y < tartekoPos)
	{
		dy = -dy;
	}

	return posizioa;
}

POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa) {
	//Sleep(1);
	posizioa.x = posizioa.x + 10;
	return posizioa;
}