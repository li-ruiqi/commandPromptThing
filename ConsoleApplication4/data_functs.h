#pragma once

#include "stdafx.h"
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define CUP "\x1B[1A"
#define DLINE "\x1B[1M"

#define MNUM 0x758329

struct FileHEADER
{
	int magic = MNUM;
	int size = 10;
};

struct profiles
{
	string name = "N/A";
	string password = "N/A";
	bool isActive = false;
	bool isAccountActive = true;
	int pts = 0;
};

struct cmd
{
	string commandName;
	int(*run)(vector <profiles> *p);
};

extern vector <profiles> accounts;

int read(vector <profiles> *p);
int save(vector <profiles> *p);