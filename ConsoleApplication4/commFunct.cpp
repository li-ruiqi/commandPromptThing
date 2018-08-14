#include "stdafx.h"
#include "commands.h"

using namespace std;

vector <profiles> accounts(10);

//------prep funct------

void a()
{
	printf("%s", KCYN);
}

void failCode()
{
	printf("%s%s", CUP, DLINE);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%serrorFunct - ", KCYN);
	printf("%sinvalide - ", KMAG);
	printf("%s", KCYN);
	printf("%sERROR\n\n", KRED);
	printf("%sposible errors:\n\n", KBLU);
	printf("%s1)input contains invalid character\n", KGRN);
	printf("2)a number greater than 0 - 9 was entered\n");
	printf("3)account does not exist\n");
}

int setup()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return GetLastError();
	}

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return GetLastError();
	}

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(hOut, dwMode))
	{
		return GetLastError();
	}

	return 0;
}

bool unknownCodeFailure(string c)
{
	try
	{
		int a = stoll(c, 0, 10);
		if (c == "0")
			return false;
		else if (a > 0 && a < 10)
			return false;

	}
	catch (...)
	{
		return true;
	}
	return true;
}

//--------------------

void accountIsDisabled(int a, vector <profiles> *p)
{
	printf("\n%sERROR_203%s: account access denied\n", KRED, KYEL);
	printf("%ssorry, %s, your account is temporarily disabled\n", KGRN, (*p)[a].name.c_str());
	printf("please contact admin to reinable your account\n\n");
}

//--------functs--------

int PrintCommands_user(vector <profiles> *p)
{
	printf("%s\ncommandList - lists commands\n", KGRN);
	printf("showProfile - prints all data from a account\n");
	printf("save - saves stuff to hard drive\n");
	return 0;
}

//--------------------

int PrintCommands(vector <profiles> *p)
{
	printf("%s\ncommandList - lists commands\n", KGRN);
	printf("editUser - edits data in an account\n");
	printf("showUserData - prints all data from a account\n");
	printf("addUser - creates new account\n");
	printf("deleteUser - deletes an account and wipes data\n");
	printf("disableUser - disables an user, making in not usable\n");
	printf("enableUser - enables a disabled account");
	printf("save - saves stuff to hard drive\n");
	printf("exit - exits program\n");
	printf("wipe_data_accounts - *%sdo not use%s* - resets all data\n", KRED, KGRN);
	return 0;
}

//--------------------

int addNewAccount(vector <profiles> *p)
{
	string c = "";

	int profileNum = 0;
	while ((*p)[profileNum].isActive)
	{
		profileNum++;
		if (profileNum == 9)
			return 0;
	}

	(*p)[profileNum].isActive = true;

	printf("%s", CUP);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%saddUser - %d - ", KCYN, profileNum);
	printf("%sEnter_Name - %s", KMAG, KCYN);

	getline(cin, c);

	(*p)[profileNum].name = c;

	printf("%s%s", CUP, DLINE);
	printf("\r");
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%saddUser - %d - ", KCYN, profileNum);
	printf("%sEnter_Password - ", KMAG);
	printf("%s", KCYN);

	getline(cin, c);

	(*p)[profileNum].password = c;
	return 0;
}

//--------------------



int getAccount(vector <profiles> *p)
{
	string c;
	int a = 0;

	printf("%s", CUP);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%sshowUserData - ", KCYN);
	printf("%senter account number - ", KMAG);
	printf("%s", KCYN);

	getline(cin, c);
	try
	{
		a = stoll(c, 0, 10);
	}
	catch (...)
	{
		failCode();
		return 0;
	}

	if (unknownCodeFailure(c) || !((*p)[a].isActive))
	{
		failCode();
		return 0;
	}

	printf("%sobtaining data[--        ] 27%%\r", KBLU);

	Sleep(200);
	printf("%s", DLINE);

	printf("obtaining data[---       ]32%%\r");
	Sleep(1000);
	printf("%s", DLINE);

	printf("obtaining data[----------]100%%\n\n");
	printf("%s", DLINE);
	printf("DONE\n\n");
	printf("printing data...\n\n");

	if (a == 11)
		a = 0;

	printf("%sname: ", KMAG);
	printf("%s%s\n", KGRN, (*p)[a].name.c_str());
	printf("%spassword: ", KMAG);
	printf("%s%s\n", KGRN, (*p)[a].password.c_str());
	printf("%spoints: ", KMAG);
	printf("%s%d\n", KGRN, (*p)[a].pts);
	return 0;
}

//--------------------

int deleteAccount_run(vector <profiles> *p)
{
	string c;
	printf("%s", CUP);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%sdeleteUser - ", KCYN);
	printf("%senter account number - ", KMAG);

	getline(cin, c);

	int a = 0;

	try
	{
		a = stoll(c, 0, 10);
	}
	catch (...)
	{
		failCode();
		return 0;
	}

	if (unknownCodeFailure(c) || !((*p)[a].isActive))
	{
		failCode();
		return 0;
	}

	printf("%sobtaining data[--        ] 27%%\r", KBLU);
	Sleep(200);
	printf("%s", DLINE);
	printf("obtaining data[---       ]32%%\r");
	printf("%s", DLINE);
	Sleep(1000);
	printf("obtaining data[----------]100%%\n\n");
	printf("%s", DLINE);

	for (int i = 0; i < 10; i++)
	{
		if (i % 3 == 0)
			printf("%sdeleting.", DLINE);
		else if (i % 3 == 1)
			printf("deleting..");
		else
			printf("deleting...");

		Sleep(250);
		printf("\r");
	}
	(*p)[a].name = (*p)[a].password = "N/A";
	(*p)[a].pts = 0;
	(*p)[a].isAccountActive = true;
	(*p)[a].isActive = false;
	(*p)[a].trophies = 0;

	printf("data deleted");


	return 0;
}

//--------------------

int submitData_run(vector <profiles> *p)
{
	vector <int> list (10);
	string c;
	int i = 0;
	printf("%sobtaining data[--        ] 27%%\r", KBLU);
	Sleep(420);
	printf("%s", DLINE);
	printf("obtaining data[---       ]32%%\r");
	Sleep(220);
	printf("%s", DLINE);
	printf("data obtained[----------]100%%\n\n");
	printf("%stip: enter \"END\" to end the list\n\n", KGRN);
	
	while (true)
	{
		printf("%ssubmitGameData.%sUserNum - ", KGRN, KBLU);
		a();

		getline(cin, c);
		if (c == "END")
		{
			printf("exiting code");
			break;
		}

		int a;

		try
		{
			a = stoll(c, 0, 10);
		}
		catch (...)
		{
			failCode();
			return 0;
		}

		if (unknownCodeFailure(c) || !((*p)[a].isActive))
		{
			failCode();
			return 0;
		}

		printf("%ssubmitGameData.%sUserPoints - ", KGRN, KBLU);

		getline(cin, c);

		int b;

		try
		{
			b = stoll(c, 0, 10);
		}
		catch (...)
		{
			failCode();
			return 0;
		}

		if (unknownCodeFailure(c))
		{
			failCode();
			return 0;
		}

		(*p)[a].pts = 0;
		
		list[i] = b;
		
		i++;
		if (a == 9)
		{
			printf("reached max amount");
			break;
		}
	}

	sort(list.begin(), list.end());

	for (int x = 0; x < 10; x++)
	{

	}
	
	return 0;
}

//--------------------

int editAccount(vector <profiles> *p)
{
	string c;
	int a = 0;
	int i;

	printf("%s", CUP);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%seditUser - ", KCYN);
	printf("%senter account number - ", KMAG);
	printf("%s", KCYN);

	getline(cin, c);

	try
	{
		a = stoll(c, 0, 10);
	}
	catch (...)
	{
		failCode();
		return 0;
	}

	if (unknownCodeFailure(c) || !((*p)[a].isActive))
	{
		failCode();
		return 0;
	}

	if (a == 11)
		a = 0;

	printf("%sobtaining data[--        ] 27%%\r", KBLU);
	Sleep(420);
	printf("%s", DLINE);
	printf("obtaining data[---       ]32%%\r");
	Sleep(220);
	printf("%s", DLINE);
	printf("data obtained[----------]100%%\n\n");

	printf("DONE\n\n");

	printf("printing data...\n\n");

	printf("%s%d\n", KGRN, (*p)[a].pts);

	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%seditUser - ", KCYN);
	printf("%sData_edit.Account%d.type - ", KMAG, a);
	printf("%s", KCYN);

	getline(cin, c);
	if (c == "points")
	{
		printf("%s%s", CUP, DLINE);
		printf("%sAccount1_", KYEL);
		printf("%sADMIN", KBLU);
		printf("%s: $- ", KYEL);
		printf("%seditUser - ", KCYN);
		printf("%sData_edit.Account%d.value - ", KMAG, a);
		printf("%s", KCYN);

		getline(cin, c);

		i = stoll(c, 0, 10);
		if (i == 0)
		{
			printf("%s%s", CUP, DLINE);
			printf("%sAccount1_", KYEL);
			printf("%sADMIN", KBLU);
			printf("%s: $- ", KYEL);
			printf("%seditUser - ", KCYN);
			printf("%sData_edit.Account%d.value - ", KMAG, a);
			printf("%sERROR\n\n", KRED);
			printf("%sposible errors:%s\n1)input contains invalid character\n2)a zero was inputed\n", KBLU, KGRN);

			return 0;
		}
		(*p)[a].pts += i;
	}
	return 0;
}

//--------------------

int accountList(vector <profiles> *p)
{
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%suser_%dData - ", KGRN, i);

		if (!(*p)[i].isActive)
			printf("%sFAIL%s:account dosen't exit\n", KRED, KYEL);
		else if (!(*p)[i].isAccountActive)
			printf("%sFAIL%s:account is disabled\n", KRED, KYEL);
		else
		{
			printf("%sstatus - \n\n", KBLU);
			printf("\t%sname: %s%s\n", KMAG, KGRN, (*p)[i].name.c_str());
			printf("\t%spassword:%s %s\n", KMAG, KGRN, (*p)[i].password.c_str());
			printf("\t%spoints: %s%d\n", KMAG, KGRN, (*p)[i].pts);
			printf("\t%strophies: %s%d\n\n", KMAG, KGRN, (*p)[i].trophies);
		}
	}
	printf("\n%sEND", KGRN);
	return 0;
}

//--------------------

int disableAccount(vector <profiles> *p)
{
	string c;
	printf("%s", CUP);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%sdisableUser - ", KCYN);
	printf("%senter account number - ", KMAG);
	printf("%s", KCYN);

	getline(cin, c);
	int a = 0;

	try
	{
		a = stoll(c, 0, 10);
	}
	catch (...)
	{
		failCode();
		return 0;
	}
	if (unknownCodeFailure(c) || !((*p)[a].isActive))
	{
		failCode();
		return 0;
	}
	printf("%s", KBLU);
	for (int i = 0; i < 10; i++)
	{
		if (i % 3 == 0)
			printf("%sdisabling.", DLINE);
		else if (i % 3 == 1)
			printf("disabling..");
		else
			printf("disabling...");

		Sleep(250);
		printf("\r");
	}

	printf("%s\rdisabled\n", DLINE);

	(*p)[a].isAccountActive = false;

	return 0;
}

//----------------------

int enableAccount(vector <profiles> *p)
{
	string c;
	printf("%s", CUP);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%senableUser - ", KCYN);
	printf("%senter account number - ", KMAG);
	printf("%s", KCYN);

	getline(cin, c);
	int a = 0;

	try
	{
		a = stoll(c, 0, 10);
	}
	catch (...)
	{
		failCode();
		return 0;
	}
	if (unknownCodeFailure(c) || !((*p)[a].isActive))
	{
		failCode();
		return 0;
	}
	if ((*p)[a].isAccountActive)
	{
		printf("%saccount already enabled, exiting function\n", KGRN);
		return 0;
	}
	printf("%s", KBLU);
	for (int i = 0; i < 10; i++)
	{
		if (i % 3 == 0)
			printf("%senabling.", DLINE);
		else if (i % 3 == 1)
			printf("enabling..");
		else
			printf("enabling...");

		Sleep(250);
		printf("\r");
	}

	printf("%s\renabled\n", DLINE);

	(*p)[a].isAccountActive = true;

	return 0;
}

//--------------------

int exit_run(vector <profiles> *p)
{
	printf("\n%sexiting %s\"", KYEL, KMAG);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN%s\"\n", KBLU, KMAG);

	printf("%ssaving data[--        ] 27%%\r", KBLU);
	Sleep(420);
	printf("%s", DLINE);
	printf("saving data[---       ]32%%\r");

	save(p);
	Sleep(220);
	printf("%s", DLINE);

	printf("data saved[----------]100%%\n\n");

	return 0;
}

//--------------------

cmd list[100] =
{
	{ "commandList", PrintCommands },
	{ "?", PrintCommands },
	{ "help", PrintCommands },
	{ "addUser", addNewAccount },
	{ "showUserData", getAccount },
	{ "exit", exit_run },
	{ "editUser", editAccount },
	{ "disableUser", disableAccount },
	{ "deleteUser", deleteAccount_run },
	{ "save", save},
	{ "enableUser", enableAccount},
	{ "wipe_data_accounts", wipe_data_test},
	{ "exit_WIPE", exit_NULLSAVE},
	{"userList", accountList},
	{ "", NULL }
};

cmd listUsers[100] =
{
	{ "commandList", PrintCommands_user },
	{ "?", PrintCommands_user },
	{ "help", PrintCommands_user },
	{ "openProfile", getAccount },
	{ "exit", exit_run },
	{ "friendList", accountList},
	{ "", NULL }
};