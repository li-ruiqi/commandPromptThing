#include "stdafx.h"
#include "commands.h"

using namespace std;

int read(vector <profiles> *p)
{
	FileHEADER header;

	FILE *fp;

	fopen_s(&fp, "tests.abc", "r+");

	fread(&header, sizeof(header), 1, fp);
	if (header.magic != MNUM)
	{
		return -1;
	}

	for (int i = 0; i < header.size; i++)
	{
		int strSizeN;
		int strSizeP;

		fread(&strSizeN, sizeof(strSizeN), 1, fp);
		(*p)[i].name.resize(strSizeN);
		fread((void *)(*p)[i].name.c_str(), strSizeN, 1, fp);

		fread(&strSizeP, sizeof(strSizeP), 1, fp);
		(*p)[i].password.resize(strSizeP);
		fread((void *)(*p)[i].password.c_str(), strSizeP, 1, fp);

		fread(&(*p)[i].isActive, sizeof((*p)[i].isActive), 1, fp);

		fread(&(*p)[i].isAccountActive, sizeof((*p)[i].isAccountActive), 1, fp);

		fread(&(*p)[i].pts, sizeof((*p)[i].pts), 1, fp);
	}
	fclose(fp);
	return 0;
}
int save(vector <profiles> *p)
{
	FileHEADER header;

	FILE *fp;

	fopen_s(&fp, "tests.abc", "wb+");

	fwrite(&header, sizeof(header), 1, fp);

	for (int i = 0; i < header.size; i++)
	{
		int strSizeN = (*p)[i].name.size();
		int strSizeP = (*p)[i].password.size();

		fwrite(&strSizeN, sizeof(strSizeN), 1, fp);

		fwrite((*p)[i].name.c_str(), strSizeN, 1, fp);

		fwrite(&strSizeP, sizeof(strSizeP), 1, fp);
		fwrite((*p)[i].password.c_str(), strSizeP, 1, fp);

		fwrite(&(*p)[i].isActive, sizeof((*p)[i].isActive), 1, fp);

		fwrite(&(*p)[i].isAccountActive, sizeof((*p)[i].isAccountActive), 1, fp);

		fwrite(&(*p)[i].pts, sizeof((*p)[i].pts), 1, fp);
	}
	fclose(fp);
	return 0;
}