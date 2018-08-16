#pragma once

#include "data_functs.h"

using namespace std;

void a();
void accountIsDisabled(int a, vector <profiles> *p);

int PrintCommands(vector <profiles> *p);
int PrintCommands_user(vector <profiles> *p);

int setup();

extern cmd list[100];
extern cmd listUsers[100];

struct FileHEADER;