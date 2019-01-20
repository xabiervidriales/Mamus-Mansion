#define _CRT_SECURE_NO_WARNINGS

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#include "funtzioak.h"

#define SUKALDEA_IMAGE ".\\img\\sukaldea.bmp"
#define ATEA_IMAGE ".\\img\\atea.bmp"

void JOKOA_atzekaldeaSortu3();
POSIZIOA ERREALITATE_FISIKOA_mugimendua3(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_saltoa3(POSIZIOA posizioa, int tartekoPos);
POSIZIOA jokalariaJarraitu(POSIZIOA posizioa, POSIZIOA mamupos);
int JOKOA_ateaSortu3();

int dy4 = 5;


int hirugarrena()
{
	int mugitu = 0, salto = 0, salto2 = 0, salto3 = 0, salto1 = 0, salto0 = 0, tiro = 0, tartekoPos, norabidea, ez, mamuKont = 5;
	int ebentu = 0, noraBegira = 0, nibela = 0;
	JOKO_ELEMENTUA bala, jokalaria, jokalarialeft, atea, mamua, mamua1, mamua2, mamua3, mamua4, sua;
	POSIZIOA aux;
	EGOERA jokalariaEgoera = JOLASTEN, mamuaEgoera1 = JOLASTEN, mamuaEgoera2 = JOLASTEN, mamuaEgoera3 = JOLASTEN, mamuaEgoera4 = JOLASTEN, mamuaEgoera5 = JOLASTEN;

	jokalaria.pos.x = 0;
	jokalaria.pos.y = 445;

	mamua.pos.x = 100;
	mamua.pos.y = 220;

	mamua1.pos.x = 260;
	mamua1.pos.y = 400;

	mamua2.pos.x = 710;
	mamua2.pos.y = 270;

	mamua3.pos.x = 1110;
	mamua3.pos.y = 163;

	mamua4.pos.x = 600;
	mamua4.pos.y = 200;

	bala.pos.x = 0;
	bala.pos.y = -100;

	sua.pos.y = 300;
	sua.pos.x = 710;

	JOKOA_atzekaldeaSortu3();

	atea.id = JOKOA_ateaSortu3();
	jokalaria.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	noraBegira = 1;
	jokalarialeft.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	mamua.id = mamuaSortu();

	mamua1.id = mamuaSortu();
	mamua2.id = mamuaSortu();
	mamua3.id = mamuaSortu();
	mamua4.id = mamuaSortu();
	bala.id = balaSortu();

	sua.id = SuaSortu();

	tartekoPos = jokalaria.pos.y - 130;

	do {

		Sleep(4);

		ebentu = ebentuaJasoGertatuBada();

		if ((sua.pos.y < 490) && (mamuaEgoera3 != GALDU))
		{
			sua.pos.y += 2;
		}
		if (sua.pos.y >= 490)
		{
			sua.pos.y = 300;
		}
		if (mamuaEgoera3 == GALDU)
		{
			sua.pos.y = -100;
			sua.pos.x = -100;
		}

		//---------------------------------------Teklen funtzioak-------------------------------------------------
		if (ebentu == TECLA_RIGHT && jokalaria.pos.x < 1200)
		{
			noraBegira = 0;
			aux = ERREALITATE_FISIKOA_mugimendua3(jokalaria.pos);
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
			dy4 = 9;
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
		if (jokalaria.pos.x + 70 > mamua1.pos.x && jokalaria.pos.x < mamua1.pos.x + 40 && jokalaria.pos.y + 50 > mamua1.pos.y && jokalaria.pos.y - 50 < mamua1.pos.y + 40 && jokalariaEgoera != GALDU)
		{
			jokalariaEgoera = GALDU;
			irudiaKendu(jokalaria.id);
		}

		if (jokalaria.pos.x + 70 > mamua2.pos.x && jokalaria.pos.x < mamua2.pos.x + 40 && jokalaria.pos.y > mamua2.pos.y && jokalaria.pos.y < mamua2.pos.y + 40 && jokalariaEgoera != GALDU)
		{
			jokalariaEgoera = GALDU;
			irudiaKendu(jokalaria.id);
		}

		if (jokalaria.pos.x + 70 > mamua3.pos.x && jokalaria.pos.x < mamua3.pos.x + 40 && jokalaria.pos.y > mamua3.pos.y && jokalaria.pos.y < mamua3.pos.y + 40 && jokalariaEgoera != GALDU)
		{
			jokalariaEgoera = GALDU;
			irudiaKendu(jokalaria.id);
		}

		if (jokalaria.pos.x + 70 > mamua.pos.x && jokalaria.pos.x < mamua.pos.x + 40 && jokalaria.pos.y > mamua.pos.y && jokalaria.pos.y < mamua.pos.y + 40 && jokalariaEgoera != GALDU)
		{
			jokalariaEgoera = GALDU;
			irudiaKendu(jokalaria.id);
		}
		if (jokalaria.pos.x + 70 > mamua4.pos.x && jokalaria.pos.x < mamua4.pos.x + 40 && jokalaria.pos.y + 50 > mamua4.pos.y && jokalaria.pos.y - 50 < mamua4.pos.y + 40 && jokalariaEgoera != GALDU)
		{
			jokalariaEgoera = GALDU;
			irudiaKendu(jokalaria.id);
		}

		if (jokalaria.pos.x + 30 > sua.pos.x && jokalaria.pos.x < sua.pos.x + 30 && jokalaria.pos.y + 20 > sua.pos.y && jokalaria.pos.y < sua.pos.y + 30 && jokalariaEgoera != GALDU)
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
		if (bala.pos.x > mamua4.pos.x && bala.pos.x < mamua4.pos.x + 50 && bala.pos.y > mamua4.pos.y && bala.pos.y < mamua4.pos.y + 60 && mamuaEgoera5 != GALDU)
		{
			mamuaEgoera5 = GALDU;
			irudiaKendu(mamua4.id);
			mamua4.pos.x = -100;
			tiro = 0;
			mamuKont--;
		}

		//---------------------------------Mamuen egoera-----------------------------------------
		Sleep(7);
		if (mamuaEgoera1 == JOLASTEN)
		{
			mamua.pos.x = bigarrenMamua1(mamua, salto3, 75);
			if (mamua.pos.x <= 75)
			{
				salto3 = 1;
			}
			if (mamua.pos.x >= 200)
			{
				salto3 = 0;
			}
		}

		if (mamuaEgoera2 == JOLASTEN)
		{
			mamua1.pos.x = bigarrenMamua1(mamua1, salto2, 260);
			if (mamua1.pos.x <= 260)
			{
				salto2 = 1;
			}
			if (mamua1.pos.x >= 635)
			{
				salto2 = 0;
			}
		}

		if (mamuaEgoera4 == JOLASTEN)
		{
			mamua3.pos.x = bigarrenMamua1(mamua3, salto0, 1110);
			if (mamua3.pos.x <= 1110)
			{
				salto0 = 1;
			}
			if (mamua3.pos.x >= 1180)
			{
				salto0 = 0;
			}
		}
		if (mamuaEgoera5 == JOLASTEN)
		{
			mamua4.pos = jokalariaJarraitu(jokalaria.pos, mamua4.pos);
		}


		//----------------------------------------Saltoa---------------------------------------------------
		if (salto)
		{
			aux = ERREALITATE_FISIKOA_saltoa3(jokalaria.pos, tartekoPos);
			jokalaria.pos.y = aux.y;

			if (jokalaria.pos.y > 445)
			{
				salto = 0;
			}

			if ((jokalaria.pos.x > 170 && jokalaria.pos.x < 300) && (jokalaria.pos.y > 330 && jokalaria.pos.y < 345 && dy4 < 0)) //1
			{
				salto = 0;
			}
			if ((jokalaria.pos.x > 170 && jokalaria.pos.x < 300) && (jokalaria.pos.y > 260 && jokalaria.pos.y < 270 && dy4 < 0)) //2
			{
				salto = 0;
			}
			if ((jokalaria.pos.x > 50 && jokalaria.pos.x < 212) && (jokalaria.pos.y > 190 && jokalaria.pos.y < 200 && dy4 < 0)) //3
			{
				salto = 0;
			}
			if ((jokalaria.pos.x > 710 && jokalaria.pos.x < 890) && (jokalaria.pos.y > 318 && jokalaria.pos.y < 330 && dy4 < 0)) //4
			{
				salto = 0;
			}
			if ((jokalaria.pos.x > 710 && jokalaria.pos.x < 890) && (jokalaria.pos.y > 243 && jokalaria.pos.y < 255 && dy4 < 0)) //5
			{
				salto = 0;
			}


		}

		if (((jokalaria.pos.x < 50 || (jokalaria.pos.x > 212 && jokalaria.pos.x < 700)) && (jokalaria.pos.y < 243)) && (!salto))
		{
			jokalaria.pos.y += 4;
		}
		if (((jokalaria.pos.x < 170 || (jokalaria.pos.x > 300 && jokalaria.pos.x < 700)) && (jokalaria.pos.y < 440 && jokalaria.pos.y > 202)) && (!salto))
		{
			jokalaria.pos.y += 4;
		}
		if ((jokalaria.pos.x > 890) && (jokalaria.pos.y < 440) && (!salto))
		{
			jokalaria.pos.y += 4;
		}

		if (jokalaria.pos.y > 445)
		{
			jokalaria.pos.y = 445;
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
		irudiaMugitu(mamua4.id, mamua4.pos.x, mamua4.pos.y);
		irudiaMugitu(sua.id, sua.pos.x, sua.pos.y);
		irudiakMarraztu();
		pantailaBerriztu();

	} while ((jokalariaEgoera != GALDU) && (mamuKont > 0 || jokalaria.pos.x < 1100)); //   Hiltzean jokoa gelditzen da

	if (mamuKont < 0)
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
POSIZIOA ERREALITATE_FISIKOA_mugimendua3(POSIZIOA posizioa) {
	//Sleep(1);
	posizioa.x = posizioa.x + 10;
	return posizioa;
}

POSIZIOA ERREALITATE_FISIKOA_saltoa3(POSIZIOA posizioa, int tartekoPos) {

	Sleep(2);
	posizioa.y = posizioa.y - dy4;
	if (posizioa.y < tartekoPos)
	{
		dy4 = -dy4;
	}
	return posizioa;
}

void JOKOA_atzekaldeaSortu3()
{
	int atzekaldeId = -1;
	atzekaldeId = irudiaKargatu(SUKALDEA_IMAGE);
	irudiaMugitu(atzekaldeId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
}

POSIZIOA jokalariaJarraitu(POSIZIOA posizioa, POSIZIOA mamupos)
{
	Sleep(5);
	if (mamupos.x > posizioa.x)
	{
		mamupos.x -= 1;
	}
	if (mamupos.x < posizioa.x)
	{
		mamupos.x += 1;
	}
	if (mamupos.y > posizioa.y)
	{
		mamupos.y -= 1;
	}
	if (mamupos.y < posizioa.y)
	{
		mamupos.y += 1;
	}
	return mamupos;
}

int JOKOA_ateaSortu3()
{
	int ateaId = -1;
	ateaId = irudiaKargatu(ATEA_IMAGE);
	irudiaMugitu(ateaId, -5, 6);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return ateaId;
}