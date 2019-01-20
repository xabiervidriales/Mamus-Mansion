#define _CRT_SECURE_NO_WARNINGS

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#include "funtzioak.h"

#define ATZEKALDE_IMAGE ".\\img\\Logela.bmp"
#define ATEA_IMAGE ".\\img\\atea.bmp"

POSIZIOA ERREALITATE_FISIKOA_mugimendua2(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_saltoa2(POSIZIOA posizioa, int tartekoPos);
void JOKOA_atzekaldeaSortu2();
int JOKOA_ateaSortu2();

int dy3 = 5;

int jokatu()
{
	int mugitu = 0, salto = 0, salto2 = 0, salto3 = 0, salto1 = 0, salto0 = 0, tiro = 0, tartekoPos, norabidea, ez, mamuKont = 4;
	int ebentu = 0, noraBegira = 0, nibela = 0;
	JOKO_ELEMENTUA bala, jokalaria, jokalarialeft, atea, mamua, mamua1, mamua2, mamua3, sua;
	POSIZIOA aux;
	EGOERA jokalariaEgoera = JOLASTEN, mamuaEgoera1 = JOLASTEN, mamuaEgoera2 = JOLASTEN, mamuaEgoera3 = JOLASTEN, mamuaEgoera4 = JOLASTEN;

	jokalaria.pos.x = 0;
	jokalaria.pos.y = 440;

	mamua.pos.x = 35;
	mamua.pos.y = 210;

	mamua1.pos.x = 390;
	mamua1.pos.y = 161;

	mamua2.pos.x = 480;
	mamua2.pos.y = 140;

	mamua3.pos.x = 480;
	mamua3.pos.y = 450;

	bala.pos.x = 0;
	bala.pos.y = -100;

	sua.pos.y = 210;
	sua.pos.x = 390;

	JOKOA_atzekaldeaSortu2();

	atea.id = JOKOA_ateaSortu2();
	jokalaria.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	noraBegira = 1;
	jokalarialeft.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	mamua.id = mamuaSortu();
	mamua1.id = mamuaSortu();
	mamua2.id = mamuaSortu();
	mamua3.id = mamuaSortu();
	sua.id = SuaSortu();
	bala.id = balaSortu();

	tartekoPos = jokalaria.pos.y - 130;

	do {

		Sleep(4);

		ebentu = ebentuaJasoGertatuBada();

		if ((sua.pos.y < 440) && (mamuaEgoera2 != GALDU))
		{
			sua.pos.y += 3;
		}
		if (sua.pos.y >= 440)
		{
			sua.pos.y = 210;
		}
		if (mamuaEgoera2 == GALDU)
		{
			sua.pos.y = -100;
			sua.pos.x = -100;
		}

		//---------------------------------------Teklen funtzioak-------------------------------------------------
		if (ebentu == TECLA_RIGHT && jokalaria.pos.x < 1200)
		{
			noraBegira = 0;
			aux = ERREALITATE_FISIKOA_mugimendua2(jokalaria.pos);
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
			dy3 = 9;
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

		if (jokalaria.pos.x + 70 > mamua2.pos.x && jokalaria.pos.x < mamua2.pos.x + 40 && jokalaria.pos.y > mamua2.pos.y && jokalaria.pos.y < mamua2.pos.y + 40 && jokalariaEgoera != GALDU)
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

		if (jokalaria.pos.x + 50 > sua.pos.x && jokalaria.pos.x < sua.pos.x + 50 && jokalaria.pos.y + 10 > sua.pos.y && jokalaria.pos.y < sua.pos.y + 30 && jokalariaEgoera != GALDU)
		{
			jokalariaEgoera = GALDU;
			irudiaKendu(jokalaria.id);
		}


		if (bala.pos.x > mamua.pos.x && bala.pos.x < mamua.pos.x + 50 && bala.pos.y > mamua.pos.y && bala.pos.y < mamua.pos.y + 60 && mamuaEgoera1 != GALDU)
		{
			mamuaEgoera1 = GALDU;
			irudiaKendu(mamua.id);
			mamua.pos.x = -100;
			tiro = 0;
			mamuKont--;
		}

		if (bala.pos.x > mamua1.pos.x && bala.pos.x < mamua1.pos.x + 50 && bala.pos.y > mamua1.pos.y && bala.pos.y < mamua1.pos.y + 60 && mamuaEgoera2 != GALDU)
		{
			mamuaEgoera2 = GALDU;
			irudiaKendu(mamua1.id);
			mamua1.pos.x = -100;
			tiro = 0;
			mamuKont--;
		}

		if (bala.pos.x > mamua2.pos.x && bala.pos.x < mamua2.pos.x + 50 && bala.pos.y > mamua2.pos.y && bala.pos.y < mamua2.pos.y + 60 && mamuaEgoera3 != GALDU)
		{
			mamuaEgoera3 = GALDU;
			irudiaKendu(mamua2.id);
			mamua2.pos.x = -100;
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

		if (mamuaEgoera3 == JOLASTEN)
		{
			mamua2.pos.x = bigarrenMamua1(mamua2, salto1, 480);
			if (mamua2.pos.x <= 480)
			{
				salto1 = 1;
			}
			if (mamua2.pos.x >= 720)
			{
				salto1 = 0;
			}
		}

		if (mamuaEgoera4 == JOLASTEN)
		{
			mamua3.pos.x = bigarrenMamua1(mamua3, salto0, 480);
			if (mamua3.pos.x <= 480)
			{
				salto0 = 1;
			}
			if (mamua3.pos.x >= 720)
			{
				salto0 = 0;
			}
		}

		//----------------------------------------Saltoa---------------------------------------------------
		if (salto)
		{
			aux = ERREALITATE_FISIKOA_saltoa2(jokalaria.pos, tartekoPos);
			jokalaria.pos.y = aux.y;

			if (jokalaria.pos.y > 440)
			{
				salto = 0;
			}

			//Eskuineko mesilla
			if ((jokalaria.pos.x > 720 && jokalaria.pos.x < 835) && (jokalaria.pos.y > 348 && dy3 < 0))
			{
				salto = 0;
			}
			if ((jokalaria.pos.x > 720 && jokalaria.pos.x < 835) && (jokalaria.pos.y > 240 && jokalaria.pos.y < 300 && dy3 < 0))
			{
				salto = 0;
			}
			if ((jokalaria.pos.x > 720 && jokalaria.pos.x < 835) && (jokalaria.pos.y > 140 && jokalaria.pos.y < 200 && dy3 < 0))
			{
				salto = 0;
			}

			//Ezkerreko mesilla
			if ((jokalaria.pos.x > 300 && jokalaria.pos.x < 440) && (jokalaria.pos.y > 348 && dy3 < 0))
			{
				salto = 0;
			}
			if ((jokalaria.pos.x > 300 && jokalaria.pos.x < 440) && (jokalaria.pos.y > 240 && jokalaria.pos.y < 300 && dy3 < 0))
			{
				salto = 0;
			}
			if ((jokalaria.pos.x > 300 && jokalaria.pos.x < 440) && (jokalaria.pos.y > 140 && jokalaria.pos.y < 200 && dy3 < 0))
			{
				salto = 0;
			}
		}

		if (((jokalaria.pos.y < 440) && (jokalaria.pos.x < 300 || (jokalaria.pos.x > 440 && jokalaria.pos.x < 720) || jokalaria.pos.x > 835)) && (!salto))
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
		irudiaMugitu(mamua2.id, mamua2.pos.x, mamua2.pos.y);
		irudiaMugitu(mamua3.id, mamua3.pos.x, mamua3.pos.y);
		irudiaMugitu(sua.id, sua.pos.x, sua.pos.y);
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

POSIZIOA ERREALITATE_FISIKOA_mugimendua2(POSIZIOA posizioa) {
	//Sleep(1);
	posizioa.x = posizioa.x + 10;
	return posizioa;
}

POSIZIOA ERREALITATE_FISIKOA_saltoa2(POSIZIOA posizioa, int tartekoPos) {

	Sleep(2);
	posizioa.y = posizioa.y - dy3;
	if (posizioa.y < tartekoPos)
	{
		dy3 = -dy3;
	}

	return posizioa;
}

void JOKOA_atzekaldeaSortu2()
{
	int atzekaldeId = -1;
	atzekaldeId = irudiaKargatu(ATZEKALDE_IMAGE);
	irudiaMugitu(atzekaldeId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
}

int JOKOA_ateaSortu2()
{
	int ateaId = -1;
	ateaId = irudiaKargatu(ATEA_IMAGE);
	irudiaMugitu(ateaId, -5, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return ateaId;
}