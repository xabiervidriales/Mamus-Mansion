#define _CRT_SECURE_NO_WARNINGS

#include "funtzioak.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>


#define ATZEKALDE_IMAGE ".\\img\\Ganbara.bmp"
#define ATEA_IMAGE ".\\img\\atea.bmp"
#define BOSS_IMAGE ".\\img\\Boss.bmp"
#define MANIKI_IMAGE ".\\img\\Manikia.bmp"
#define KUTXAK_IMAGE ".\\img\\Kutxak.bmp"
#define EZKUTU_IMAGE ".\\img\\Ezkutu.bmp"
#define BIHOTZA_IMAGE ".\\img\\bihotza.bmp"
#define BOSSBIZITZA_IMAGE ".\\img\\bossbizitza.bmp"
#define GALDU_IMAGE ".\\img\\Galdu.bmp"
#define IRABAZI_IMAGE ".\\img\\Irabazi.bmp"

void JOKOA_atzekaldeaSortu4();
int bossSortu();
int manikiaSortu();
int ezkutuaSortu();
int bihotzaSortu();
int bossBizitzaSortu();
int galduSortu();
int kutxakSortu();
int irabaziSortu();

POSIZIOA ERREALITATE_FISIKOA_mugimendua4(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_saltoa4(POSIZIOA posizioa, int tartekoPos);
POSIZIOA bossMugimendua(POSIZIOA bossPosizioa, int igotzen, int zigzag, int bueltatu);
POSIZIOA jokalariaJarraitu1(POSIZIOA posizioa, POSIZIOA mamupos);


int dy5 = 15;


int boss()
{
	int mugitu = 0, salto = 0, salto2 = 0, salto3 = 0, bueltatu = 0, tiro = 0, tartekoPos, norabidea, ez, bossBizitza = 5, jokalariBizitza = 3, hasieraraBueltatu = 0, bossBabestu = 0, mamuKont = 0, kendu = 0, kendu2 = 0, kargatu = 0;
	int ebentu = 0, nibela = 0, noraBegira = 0, igotzen = 0;
	JOKO_ELEMENTUA bala, jokalaria, jokalarialeft, boss, maniki, kutxak, ezkutu, mamua, bihotz1, bihotz2, bihotz3, bossBizitza1, bossBizitza2, bossBizitza3, bossBizitza4, bossBizitza5;
	POSIZIOA aux;
	EGOERA jokalariaEgoera = JOLASTEN, bossEgoera = JOLASTEN, mamua1 = JOLASTEN;
	JOKOAN mamuaJokoan = ITXAROTEN;

	jokalaria.pos.x = 0;
	jokalaria.pos.y = 442;

	bala.pos.x = -100;
	bala.pos.y = -100;

	boss.pos.x = 1000;
	boss.pos.y = 335;

	maniki.pos.x = -100;
	maniki.pos.y = -100;

	kutxak.pos.x = 2000;
	kutxak.pos.y = -100;

	ezkutu.pos.x = -300;
	ezkutu.pos.y = -300;

	mamua.pos.x = -100;
	mamua.pos.y = -442;

	bihotz2.pos.x = 50;
	bihotz2.pos.y = 20;

	bihotz3.pos.x = 80;
	bihotz3.pos.y = 20;

	bossBizitza2.pos.x = 840;
	bossBizitza2.pos.y = 20;

	bossBizitza3.pos.x = 880;
	bossBizitza3.pos.y = 20;

	bossBizitza4.pos.x = 920;
	bossBizitza4.pos.y = 20;

	bossBizitza5.pos.x = 960;
	bossBizitza5.pos.y = 20;

	JOKOA_atzekaldeaSortu4();


	jokalaria.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	noraBegira = 1;
	jokalarialeft.id = JOKOA_jokalariaIrudiaSortu(noraBegira);
	bala.id = balaSortu();
	boss.id = bossSortu();
	maniki.id = manikiaSortu();
	kutxak.id = kutxakSortu();
	ezkutu.id = ezkutuaSortu();
	mamua.id = mamuaSortu();
	tartekoPos = jokalaria.pos.y - 130;
	bihotz1.id = bihotzaSortu();
	bihotz2.id = bihotzaSortu();
	bihotz3.id = bihotzaSortu();
	bossBizitza1.id = bossBizitzaSortu();
	bossBizitza2.id = bossBizitzaSortu();
	bossBizitza3.id = bossBizitzaSortu();
	bossBizitza4.id = bossBizitzaSortu();
	bossBizitza5.id = bossBizitzaSortu();

	do {

		Sleep(4);

		ebentu = ebentuaJasoGertatuBada();

		if (boss.pos.y >= 320)
		{
			igotzen = 1;
		}

		if (boss.pos.y <= 180)
		{
			igotzen = 0;
		}

		if (boss.pos.x >= 1000)
		{
			bueltatu = 1;
		}

		if (boss.pos.x <= 180)
		{
			bueltatu = 0;
		}


		//---------------------------------------Teklen funtzioak-------------------------------------------------
		if (ebentu == TECLA_RIGHT && jokalaria.pos.x < 1200)
		{
			noraBegira = 0;
			aux = ERREALITATE_FISIKOA_mugimendua4(jokalaria.pos);
			jokalaria.pos.x = aux.x;
		}

		if (ebentu == TECLA_LEFT && jokalaria.pos.x > 15)
		{
			noraBegira = 1;
			jokalaria.pos.x -= 10;
		}

		if (ebentu == TECLA_SPACE && !salto)
		{
			tartekoPos = jokalaria.pos.y - 140;
			salto = 1;
			dy5 = 12;
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
		if (jokalaria.pos.x + 60 > maniki.pos.x + 30 && jokalaria.pos.x < maniki.pos.x + 40 && jokalaria.pos.y + 70 > maniki.pos.y && jokalaria.pos.y < maniki.pos.y + 90 && jokalariaEgoera != GALDU)
		{
			jokalariBizitza--;
			kendu = 1;
			maniki.pos.x = -2000;
		}

		if (jokalaria.pos.x + 60 > kutxak.pos.x + 20 && jokalaria.pos.x < kutxak.pos.x + 40 && jokalaria.pos.y + 70 > kutxak.pos.y + 20 && jokalaria.pos.y < kutxak.pos.y + 90 && jokalariaEgoera != GALDU)
		{
			jokalariBizitza--;
			kendu = 1;
			kutxak.pos.x = -2000;
		}

		if (jokalaria.pos.x + 70 > mamua.pos.x && jokalaria.pos.x < mamua.pos.x + 40 && jokalaria.pos.y > mamua.pos.y && jokalaria.pos.y < mamua.pos.y + 40 && jokalariaEgoera != GALDU)
		{
			jokalariBizitza--;
			kendu = 1;
			mamua.pos.x = -2000;
			mamua1 = GALDU;
		}

		if (bala.pos.x > boss.pos.x && bala.pos.x < boss.pos.x + 100 && bala.pos.y > boss.pos.y && bala.pos.y < boss.pos.y + 200 && bossEgoera != GALDU && !bossBabestu)
		{
			bossBizitza--;
			kendu2 = 1;
			tiro = 0;
			hasieraraBueltatu = 1;
			if (bossBizitza == 0)
			{
				bossEgoera = GALDU;
				jokalariaEgoera = IRABAZI;
				irudiaKendu(boss.id);
				irudiaKendu(bossBizitza1.id);
				boss.pos.x = -100;
				maniki.pos.x = 2000;
				kutxak.pos.x = 2000;
				mamua.pos.x = 2000;
				kargatu = 1;
			}
		}

		if (bala.pos.x > mamua.pos.x && bala.pos.x < mamua.pos.x + 50 && bala.pos.y > mamua.pos.y && bala.pos.y < mamua.pos.y + 60 && mamua1 != GALDU)
		{
			mamua1 = GALDU;
			mamua.pos.x = -100;
			tiro = 0;
			mamuKont--;
		}


		//----------------------------------Egoerak-------------------------------------------------------------

		if (mamuaJokoan == JOKATZEN)
		{
			mamua.pos = jokalariaJarraitu1(jokalaria.pos, mamua.pos);
		}

		if (jokalariBizitza == 2 && kendu)
		{
			irudiaKendu(bihotz3.id);
			kendu = 0;
		}

		if (jokalariBizitza == 1 && kendu)
		{
			irudiaKendu(bihotz2.id);
			kendu = 0;
		}

		if (jokalariBizitza == 0 && kendu == 1)
		{
			irudiaKendu(bihotz1.id);
			kendu = 0;
			kargatu = 1;
			jokalariaEgoera = GALDU;
		}
		//---------------------------------Boss-aren patroia-----------------------------------------

		if (bossBizitza == 5)
		{

			boss.pos = bossMugimendua(boss.pos, igotzen, 0, bueltatu);
			Sleep(7);
		}

		if (bossBizitza == 4)
		{
			if (kendu2 == 1)
			{
				kendu2 = 0;
				irudiaKendu(bossBizitza5.id);
			}
			boss.pos = bossMugimendua(boss.pos, igotzen, 0, bueltatu);
			if (hasieraraBueltatu)
			{
				bossBabestu = 1;
				jokalaria.pos.x -= 10;
				if (jokalaria.pos.x < 50)
				{
					hasieraraBueltatu = 0;
					maniki.pos.x = 1000;
					maniki.pos.y = 435;
				}
			}

			if (bossBabestu)
			{
				ezkutu.pos.x = boss.pos.x;
				ezkutu.pos.y = boss.pos.y;
			}

			Sleep(7);

			if (!hasieraraBueltatu && maniki.pos.x > 20)
			{
				maniki.pos.x -= 8;
				kutxak.pos.x = 1000;
				kutxak.pos.y = 435;
			}

			if (maniki.pos.x < 20 && kutxak.pos.x > 20)
			{
				maniki.pos.x = -100;
				kutxak.pos.x -= 8;
			}

			if (kutxak.pos.x < 20)
			{
				kutxak.pos.x = 2000;
				bossBabestu = 0;
				ezkutu.pos.x = -300;
				ezkutu.pos.y = -300;
			}
		}

		if (bossBizitza == 3)
		{
			if (kendu2 == 1)
			{
				kendu2 = 0;
				irudiaKendu(bossBizitza4.id);
			}
			boss.pos = bossMugimendua(boss.pos, igotzen, 0, bueltatu);
			if (hasieraraBueltatu)
			{
				bossBabestu = 1;
				jokalaria.pos.x -= 10;
				if (jokalaria.pos.x < 50)
				{
					hasieraraBueltatu = 0;
					maniki.pos.x = 1000;
					maniki.pos.y = 435;
				}
			}

			if (bossBabestu)
			{
				ezkutu.pos.x = boss.pos.x;
				ezkutu.pos.y = boss.pos.y;
			}

			Sleep(7);

			if (!hasieraraBueltatu && maniki.pos.x > 20 && mamuaJokoan == ITXAROTEN)
			{
				maniki.pos.x -= 8;
				kutxak.pos.x = 1000;
				kutxak.pos.y = 435;
			}

			if (maniki.pos.x < 20 && kutxak.pos.x > 20 && mamuaJokoan == ITXAROTEN)
			{
				maniki.pos.x = -100;
				kutxak.pos.x -= 8;
			}

			if (kutxak.pos.x < 20 && mamuaJokoan == ITXAROTEN)
			{
				kutxak.pos.x = 2000;
				mamuaJokoan = JOKATZEN;
				mamua.pos.x = 500;
				mamua.pos.y = 100;

			}

			if (mamua1 == GALDU && mamuaJokoan == JOKATZEN)
			{
				bossBabestu = 0;
				ezkutu.pos.x = -300;
				ezkutu.pos.y = -300;
				mamuaJokoan = ITXAROTEN;
				mamua1 = JOLASTEN;
			}
		}

		if (bossBizitza == 2)
		{
			if (kendu2 == 1)
			{
				kendu2 = 0;
				irudiaKendu(bossBizitza3.id);
			}
			boss.pos = bossMugimendua(boss.pos, igotzen, 1, bueltatu);
			if (hasieraraBueltatu)
			{
				bossBabestu = 1;
				jokalaria.pos.x -= 10;
				if (jokalaria.pos.x < 50)
				{
					hasieraraBueltatu = 0;
					maniki.pos.x = 1000;
					maniki.pos.y = 435;
				}
			}

			if (bossBabestu)
			{
				ezkutu.pos.x = boss.pos.x;
				ezkutu.pos.y = boss.pos.y;
			}

			Sleep(7);

			if (!hasieraraBueltatu && maniki.pos.x > 20 && mamuaJokoan == ITXAROTEN)
			{
				maniki.pos.x -= 8;
				kutxak.pos.x = 1000;
				kutxak.pos.y = 435;
			}

			if (maniki.pos.x < 20 && kutxak.pos.x > 20 && mamuaJokoan == ITXAROTEN)
			{
				maniki.pos.x = -100;
				kutxak.pos.x -= 8;
			}

			if (kutxak.pos.x < 20 && mamuaJokoan == ITXAROTEN)
			{
				kutxak.pos.x = 2000;
				mamuaJokoan = JOKATZEN;
				mamua.pos.x = 500;
				mamua.pos.y = 100;

			}

			if (mamua1 == GALDU && mamuaJokoan == JOKATZEN)
			{
				bossBabestu = 0;
				ezkutu.pos.x = -300;
				ezkutu.pos.y = -300;
				mamuaJokoan = ITXAROTEN;
				mamua1 = JOLASTEN;
			}
		}

		if (bossBizitza == 1)
		{
			if (kendu2 == 1)
			{
				kendu2 = 0;
				irudiaKendu(bossBizitza2.id);
			}
			boss.pos = bossMugimendua(boss.pos, igotzen, 1, bueltatu);
			if (hasieraraBueltatu)
			{
				bossBabestu = 1;
				jokalaria.pos.x -= 10;
				if (jokalaria.pos.x < 50)
				{
					hasieraraBueltatu = 0;
					maniki.pos.x = 1000;
					maniki.pos.y = 435;
				}
			}

			if (bossBabestu)
			{
				ezkutu.pos.x = boss.pos.x;
				ezkutu.pos.y = boss.pos.y;
			}

			Sleep(7);

			if (!hasieraraBueltatu && maniki.pos.x > 20 && mamuaJokoan == ITXAROTEN)
			{
				maniki.pos.x -= 8;
				kutxak.pos.x = 1000;
				kutxak.pos.y = 435;
			}

			if (maniki.pos.x < 20 && kutxak.pos.x > 20 && mamuaJokoan == ITXAROTEN)
			{
				maniki.pos.x = -100;
				kutxak.pos.x -= 8;
			}

			if (kutxak.pos.x < 20 && mamuaJokoan == ITXAROTEN)
			{
				kutxak.pos.x = 2000;
				mamuaJokoan = JOKATZEN;
				mamua.pos.x = 500;
				mamua.pos.y = 100;

			}

			if (mamua1 == GALDU && mamuaJokoan == JOKATZEN)
			{
				bossBabestu = 0;
				ezkutu.pos.x = -300;
				ezkutu.pos.y = -300;
				mamuaJokoan = ITXAROTEN;
				mamua1 = JOLASTEN;
			}
		}

		//----------------------------------------Saltoa eta jausia---------------------------------------------------
		if (salto)
		{
			aux = ERREALITATE_FISIKOA_saltoa4(jokalaria.pos, tartekoPos);
			jokalaria.pos.y = aux.y;

			if (jokalaria.pos.y > 440)
			{
				salto = 0;
			}
		}

		pantailaGarbitu();

		//----------------------------Norabidearen arabera, jokalariaren begirada aldatu-----------------------------
		if (!noraBegira)
		{
			norabidea = jokalaria.id;
			ez = jokalarialeft.id;

			if (bala.pos.x < 1200 && bala.pos.x > 0 && tiro == 1)
			{
				bala.pos.x += 16;
				if (bala.pos.x > 1240)
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
				bala.pos.x -= 16;
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
		irudiaMugitu(boss.id, boss.pos.x, boss.pos.y);
		irudiaMugitu(maniki.id, maniki.pos.x, maniki.pos.y);
		irudiaMugitu(kutxak.id, kutxak.pos.x, kutxak.pos.y);
		irudiaMugitu(ezkutu.id, ezkutu.pos.x, ezkutu.pos.y);
		irudiaMugitu(mamua.id, mamua.pos.x, mamua.pos.y);
		irudiaMugitu(bihotz2.id, bihotz2.pos.x, bihotz2.pos.y);
		irudiaMugitu(bihotz3.id, bihotz3.pos.x, bihotz3.pos.y);
		irudiaMugitu(bossBizitza2.id, bossBizitza2.pos.x, bossBizitza2.pos.y);
		irudiaMugitu(bossBizitza3.id, bossBizitza3.pos.x, bossBizitza3.pos.y);
		irudiaMugitu(bossBizitza4.id, bossBizitza4.pos.x, bossBizitza4.pos.y);
		irudiaMugitu(bossBizitza5.id, bossBizitza5.pos.x, bossBizitza5.pos.y);

		irudiakMarraztu();
		pantailaBerriztu();

		if (jokalariaEgoera == GALDU && kargatu == 1)
		{
			galduSortu();
			kargatu = 0;
			irudiaKendu(jokalaria.id);
		}

		if (jokalariaEgoera == IRABAZI && kargatu == 1)
		{
			irabaziSortu();
			kargatu = 0;
			irudiaKendu(jokalaria.id);
		}

	} while (ebentu != TECLA_z); //   Hiltzean jokoa gelditzen da

	nibela = 0;

	pantailaGarbitu();
	pantailaBerriztu();

	return nibela;
}

POSIZIOA ERREALITATE_FISIKOA_mugimendua4(POSIZIOA posizioa) {
	//Sleep(1);
	posizioa.x = posizioa.x + 10;
	return posizioa;
}

POSIZIOA ERREALITATE_FISIKOA_saltoa4(POSIZIOA posizioa, int tartekoPos) {

	Sleep(2);
	posizioa.y = posizioa.y - dy5;
	if (posizioa.y < tartekoPos)
	{
		dy5 = -dy5;
	}

	return posizioa;
}

POSIZIOA bossMugimendua(POSIZIOA bossPosizioa, int igotzen, int zigzag, int bueltatu)
{
	Sleep(8);

	if (bossPosizioa.y <= 320 && !igotzen)
	{
		bossPosizioa.y += 1;
	}

	if (bossPosizioa.y >= 180 && igotzen)
	{
		bossPosizioa.y -= 1;
	}

	if (zigzag)
	{
		if (!bueltatu)
		{
			bossPosizioa.x += 3;
		}

		if (bueltatu)
		{
			bossPosizioa.x -= 3;
		}
	}

	return bossPosizioa;
}

POSIZIOA jokalariaJarraitu1(POSIZIOA posizioa, POSIZIOA mamupos)
{
	Sleep(5);
	if (mamupos.x > posizioa.x)
	{
		mamupos.x -= 3;
	}
	if (mamupos.x < posizioa.x)
	{
		mamupos.x += 3;
	}
	if (mamupos.y > posizioa.y)
	{
		mamupos.y -= 3;
	}
	if (mamupos.y < posizioa.y)
	{
		mamupos.y += 3;
	}
	return mamupos;
}

void JOKOA_atzekaldeaSortu4()
{
	int atzekaldeId = -1;
	atzekaldeId = irudiaKargatu(ATZEKALDE_IMAGE);
	irudiaMugitu(atzekaldeId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
}

int bossSortu()
{
	int bossId = -1;
	bossId = irudiaKargatu(BOSS_IMAGE);
	irudiaMugitu(bossId, 1000, 335);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return bossId;
}

int manikiaSortu()
{
	int ManikiId = -1;
	ManikiId = irudiaKargatu(MANIKI_IMAGE);
	irudiaMugitu(ManikiId, -300, -300);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return ManikiId;
}

int kutxakSortu()
{
	int kutxakId = -1;
	kutxakId = irudiaKargatu(KUTXAK_IMAGE);
	irudiaMugitu(kutxakId, 2000, -300);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return kutxakId;
}

int ezkutuaSortu()
{
	int ezkutuId = -1;
	ezkutuId = irudiaKargatu(EZKUTU_IMAGE);
	irudiaMugitu(ezkutuId, -300, -300);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return ezkutuId;
}

int bihotzaSortu()
{
	int bihotzId = -1;
	bihotzId = irudiaKargatu(BIHOTZA_IMAGE);
	irudiaMugitu(bihotzId, 20, 20);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return bihotzId;
}

int bossBizitzaSortu()
{
	int BossBizitzaId = -1;
	BossBizitzaId = irudiaKargatu(BOSSBIZITZA_IMAGE);
	irudiaMugitu(BossBizitzaId, 800, 20);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return BossBizitzaId;
}

int galduSortu()
{
	int galduId = -1;
	galduId = irudiaKargatu(GALDU_IMAGE);
	irudiaMugitu(galduId, 0, -40);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return galduId;
}

int irabaziSortu()
{
	int irabaziId = -1;
	irabaziId = irudiaKargatu(IRABAZI_IMAGE);
	irudiaMugitu(irabaziId, 0, -40);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return irabaziId;
}