#define _CRT_SECURE_NO_WARNINGS

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define ATZEKALDE_IMAGE ".\\img\\jangela.bmp"

void JOKOA_atzekaldeaSortu1();

#include "funtzioak.h"

POSIZIOA ERREALITATE_FISIKOA_saltoa1(POSIZIOA posizioa, int tartekoPos);
POSIZIOA ERREALITATE_FISIKOA_mugimendua1(POSIZIOA posizioa);

int dy1 = 5;

int jokatu2()
{
	int mugitu = 0, salto = 0, salto2 = 0, salto3 = 0, salto1 = 0, salto0 = 0, tiro = 0, tartekoPos, norabidea, ez, mamuKont = 3;
	int ebentu = 0, noraBegira = 0, nibela = 0;
	JOKO_ELEMENTUA bala, jokalaria, jokalarialeft, atea, mamua, mamua1, mamua3;
	POSIZIOA aux;
	EGOERA jokalariaEgoera = JOLASTEN, mamuaEgoera1 = JOLASTEN, mamuaEgoera2 = JOLASTEN, mamuaEgoera3 = JOLASTEN, mamuaEgoera4 = JOLASTEN;

	jokalaria.pos.x = 0;
	jokalaria.pos.y = 442;

	mamua.pos.x = 40;
	mamua.pos.y = 300;

	mamua1.pos.x = 270;
	mamua1.pos.y = 410;

	mamua3.pos.x = 1000;
	mamua3.pos.y = 270;

	bala.pos.x = 0;
	bala.pos.y = -100;

	JOKOA_atzekaldeaSortu1();

	atea.id = JOKOA_ateaSortu();
	jokalaria.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	noraBegira = 1;
	jokalarialeft.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	mamua.id = mamuaSortu();
	mamua1.id = mamuaSortu();
	mamua3.id = mamuaSortu();

	bala.id = balaSortu();

	tartekoPos = jokalaria.pos.y - 130;

	do {

		Sleep(4);

		ebentu = ebentuaJasoGertatuBada();

		//---------------------------------------Teklen funtzioak-------------------------------------------------
		if (ebentu == TECLA_RIGHT && jokalaria.pos.x < 1200)
		{
			noraBegira = 0;
			aux = ERREALITATE_FISIKOA_mugimendua1(jokalaria.pos);
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
			dy1 = 9;
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

		//-----------------------------------Hitboxak---------------------------------------------------------------
		if (jokalaria.pos.x + 70 > mamua1.pos.x && jokalaria.pos.x < mamua1.pos.x + 40 && jokalaria.pos.y > mamua1.pos.y && jokalaria.pos.y < mamua1.pos.y + 40 && jokalariaEgoera != GALDU)
		{
			jokalariaEgoera = GALDU;
			irudiaKendu(jokalaria.id);
		}

		if (jokalaria.pos.x + 70 > mamua3.pos.x && jokalaria.pos.x - 40 < mamua3.pos.x && jokalaria.pos.y + 50 > mamua3.pos.y && jokalaria.pos.y - 50 < mamua3.pos.y + 40 && jokalariaEgoera != GALDU)
		{
			jokalariaEgoera = GALDU;
			irudiaKendu(jokalaria.id);
		}

		if (jokalaria.pos.x + 70 > mamua.pos.x && jokalaria.pos.x < mamua.pos.x + 40 && jokalaria.pos.y + 10 > mamua.pos.y && jokalaria.pos.y < mamua.pos.y + 40 && jokalariaEgoera != GALDU)
		{
			jokalariaEgoera = GALDU;
			irudiaKendu(jokalaria.id);
		}

		if (bala.pos.x > mamua1.pos.x && bala.pos.x < mamua1.pos.x + 50 && bala.pos.y > mamua1.pos.y && bala.pos.y < mamua1.pos.y + 60 && mamuaEgoera2 != GALDU)
		{
			mamuaEgoera2 = GALDU;
			irudiaKendu(mamua1.id);
			mamua1.pos.x = -100;
			tiro = 0;
			mamuKont--;
		}

		if (bala.pos.x > mamua3.pos.x && bala.pos.x < mamua3.pos.x + 50 && bala.pos.y > mamua3.pos.y && bala.pos.y < mamua3.pos.y + 60 && mamuaEgoera4 != GALDU)
		{
			mamuaEgoera4 = GALDU;
			irudiaKendu(mamua3.id);
			mamua3.pos.x = -100;
			tiro = 0;
			mamuKont--;
		}

		if (bala.pos.x > mamua.pos.x && bala.pos.x < mamua.pos.x + 50 && bala.pos.y > mamua.pos.y && bala.pos.y < mamua.pos.y + 60 && mamuaEgoera1 != GALDU)
		{
			mamuaEgoera1 = GALDU;
			irudiaKendu(mamua.id);
			mamua.pos.x = -100;
			tiro = 0;
			mamuKont--;
		}

		//---------------------------------Mamuen egoera-----------------------------------------
		Sleep(7);
		if (mamuaEgoera1 == JOLASTEN)
		{
			mamua.pos.y = lehenengoMamua1(mamua, salto3, 80);
			if (mamua.pos.y <= 80)
			{
				salto3 = 1;
			}
			if (mamua.pos.y >= 300)
			{
				salto3 = 0;
			}
		}

		if (mamuaEgoera4 == JOLASTEN)
		{
			mamua1.pos.x = bigarrenMamua1(mamua1, salto0, 240);
			if (mamua1.pos.x <= 240)
			{
				salto0 = 1;
			}
			if (mamua1.pos.x >= 620)
			{
				salto0 = 0;
			}
		}

		//----------------------------------------Saltoa---------------------------------------------------
		if (salto)
		{
			aux = ERREALITATE_FISIKOA_saltoa1(jokalaria.pos, tartekoPos);
			jokalaria.pos.y = aux.y;

			if (jokalaria.pos.y > 440)
			{
				salto = 0;
			}

			if ((jokalaria.pos.x > 195 && jokalaria.pos.x < 640) && (jokalaria.pos.y > 380 && dy1 < 0))
			{
				salto = 0;
			}

			if ((jokalaria.pos.x > 740 && jokalaria.pos.x < 885) && (jokalaria.pos.y > 355 && dy1 < 0))
			{
				salto = 0;
			}
		}

		if (((jokalaria.pos.y < 440) && ((jokalaria.pos.x > 0 && jokalaria.pos.x < 195) || (jokalaria.pos.x > 640 && jokalaria.pos.x < 740) || (jokalaria.pos.x > 885))) && (!salto))
		{
			jokalaria.pos.y += 4;
		}

		if (jokalaria.pos.y > 440)
		{
			jokalaria.pos.y = 440;
		}

		pantailaGarbitu();

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

		if (mamuKont == 0)
		{
			irudiaKendu(atea.id);
			mamuKont--;
		}

		//----------------------------Alde grafikoa kargatu eta bistaratu-----------------------------------------
		pantailaGarbitu();
		irudiaMugitu(norabidea, jokalaria.pos.x, jokalaria.pos.y);
		irudiaMugitu(ez, -200, -200);
		irudiaMugitu(bala.id, bala.pos.x, bala.pos.y);
		irudiaMugitu(mamua.id, mamua.pos.x, mamua.pos.y);
		irudiaMugitu(mamua1.id, mamua1.pos.x, mamua1.pos.y);
		irudiaMugitu(mamua3.id, mamua3.pos.x, mamua3.pos.y);
		irudiakMarraztu();
		pantailaBerriztu();

	} while ((jokalariaEgoera != GALDU) && (mamuKont > 0 || jokalaria.pos.x < 1100)); //   Hiltzean jokoa gelditzen da

	if (mamuKont <= 0)
	{
		nibela = 1;
	}
	if (jokalariaEgoera == GALDU)
	{
		nibela = 0;
	}

	irudiaKendu(jokalaria.id);
	pantailaGarbitu();
	pantailaBerriztu();

	return nibela;
}

void JOKOA_atzekaldeaSortu1()
{
	int atzekaldeId = -1;
	atzekaldeId = irudiaKargatu(ATZEKALDE_IMAGE);
	irudiaMugitu(atzekaldeId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
}

POSIZIOA ERREALITATE_FISIKOA_saltoa1(POSIZIOA posizioa, int tartekoPos) {

	Sleep(2);
	posizioa.y = posizioa.y - dy1;
	if (posizioa.y < tartekoPos)
	{
		dy1 = -dy1;
	}

	return posizioa;
}

POSIZIOA ERREALITATE_FISIKOA_mugimendua1(POSIZIOA posizioa) {
	//Sleep(1);
	posizioa.x = posizioa.x + 10;
	return posizioa;
}