#define _CRT_SECURE_NO_WARNINGS

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#include "OurTypes.h"

#define JOKALARI_IMAGE ".\\img\\jokalari.bmp"
#define JOKALARIEZK_IMAGE ".\\img\\jokalariezk.bmp"
#define ATEA_IMAGE ".\\img\\atea.bmp"
#define BALA_IMAGE ".\\img\\bala.bmp"
#define MAMUA_IMAGE ".\\img\\mamua.bmp"
#define SUA_IMAGE ".\\img\\sua.bmp"

int JOKOA_jokalariaIrudiaSortu(int noraBegira)
{
	int jokalariId = -1;

	if (!noraBegira)
	{
		jokalariId = irudiaKargatu(JOKALARI_IMAGE);
	}

	if (noraBegira)
	{
		jokalariId = irudiaKargatu(JOKALARIEZK_IMAGE);
	}

	irudiaMugitu(jokalariId, -10, -10);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return jokalariId;

}

int mamuaSortu()
{
	int mamua = -1;
	mamua = irudiaKargatu(MAMUA_IMAGE);
	irudiaMugitu(mamua, 100, 442);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return mamua;
}

int mamuaSortu2()
{
	int mamua = -1;
	mamua = irudiaKargatu(MAMUA_IMAGE);
	irudiaMugitu(mamua, 500, 442);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return mamua;
}

int mamuaSortu3()
{
	int mamua = -1;
	mamua = irudiaKargatu(MAMUA_IMAGE);
	irudiaMugitu(mamua, 500, 442);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return mamua;
}

int JOKOA_ateaSortu()
{
	int ateaId = -1;
	ateaId = irudiaKargatu(ATEA_IMAGE);
	irudiaMugitu(ateaId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return ateaId;
}

int balaSortu()
{
	int balaId = -1;
	balaId = irudiaKargatu(BALA_IMAGE);
	irudiaMugitu(balaId, 100, 200);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return balaId;
}

int lehenengoMamua(JOKO_ELEMENTUA mamua, int salto3)
{
	int tartekoPos = 300;

	if ((mamua.pos.y > tartekoPos) && (!salto3))
	{
		mamua.pos.y -= 1;
	}

	if ((salto3) && (mamua.pos.y <= 442))
	{
		mamua.pos.y += 1;
	}
	return mamua.pos.y;
}

int bigarrenMamua(JOKO_ELEMENTUA mamuaDesli, int salto2)
{
	int tartekoPos = 300;

	if ((mamuaDesli.pos.x > tartekoPos) && (!salto2))
	{
		mamuaDesli.pos.x -= 1;
	}

	if ((salto2) && (mamuaDesli.pos.x <= 442))
	{
		mamuaDesli.pos.x += 1;
	}
	return mamuaDesli.pos.x;
}

int SuaSortu()
{
	int SuaId = -1;
	SuaId = irudiaKargatu(SUA_IMAGE);
	irudiaMugitu(SuaId, 395, 210);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return SuaId;
}

int lehenengoMamua1(JOKO_ELEMENTUA mamua, int salto3, int tartekoPos)
{

	if ((mamua.pos.y > tartekoPos) && (!salto3))
	{
		mamua.pos.y -= 1;
	}

	if ((salto3) && (mamua.pos.y <= 473))
	{
		mamua.pos.y += 1;
	}
	return mamua.pos.y;
}

int bigarrenMamua1(JOKO_ELEMENTUA mamuaDesli, int salto2, int tartekoPos)
{

	if ((mamuaDesli.pos.x > tartekoPos) && (!salto2))
	{
		mamuaDesli.pos.x -= 1;
	}

	if ((salto2) && (mamuaDesli.pos.x <= 720))
	{
		mamuaDesli.pos.x += 1;
	}
	return mamuaDesli.pos.x;
}