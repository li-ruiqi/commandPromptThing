// ConsoleApplication4.cpp : Defines the entry point for the console application
//no bugs today; creating new functions

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

//----------------------

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
	int(*run)();
};

vector <profiles> accounts(10);

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

bool unknownCodeFailure(string c)
{
	try
	{
		int a = stoll(c, 0, 10);
		if (c == "0")
			return false;
		else if (a < 1 || a > 9)
			return true;

	}
	catch (...)
	{
		return false;
	}
}

int PrintCommands()
{
	printf("%s\ncommandList - lists commands\n", KGRN);
	printf("editUser - edits data in an account\n");
	printf("showUserData - prints all data from a account\n");
	printf("addUser - creates new account\n");
	printf("deleteUser - deletes an account and wipes data\n");
	printf("disableUser - disables an user, making in not usable\n");
	printf("save - saves stuff to hard drive\n");
	printf("exit - exits program\n");
	return 0;
}

int addNewAccount()
{
	string c = "";

	int profileNum = 0;
	while (accounts[profileNum].isActive)
	{
		profileNum++;
	}

	accounts[profileNum].isActive = true;

	printf("%s", CUP);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%saddUser - %d - ", KCYN, profileNum);
	printf("%sEnter_Name - %s", KMAG, KCYN);

	getline(cin, c);

	accounts[profileNum].name = c;

	printf("%s%s", CUP, DLINE);
	printf("\r");
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%saddUser - %d - ", KCYN, profileNum);
	printf("%sEnter_Password - ", KMAG);
	printf("%s", KCYN);

	getline(cin, c);

	accounts[profileNum].password = c;
	return 0;
}

int getAccount()
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

	if (unknownCodeFailure(c) || !(accounts[a].isActive))
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
	printf("%s%s\n", KGRN, accounts[a].name.c_str());
	printf("%spassword: ", KMAG);
	printf("%s%s\n", KGRN, accounts[a].password.c_str());
	printf("%spoints: ", KMAG);
	printf("%s%d\n", KGRN, accounts[a].pts);
	return 0;
}

int deleteAccount_run()
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

	if (unknownCodeFailure(c) || !(accounts[a].isActive))
	{
		failCode();
		return 0;
	}

	if (a == 11)
		a = 0;

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
	accounts[a].name = accounts[a].password = "N/A";
	accounts[a].pts = 0;
	accounts[a].isAccountActive = true;
	accounts[a].isActive = false;

	printf("data deleted");


	return 0;
}

int editAccount()
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

	if (unknownCodeFailure(c) || !(accounts[a].isActive))
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

	printf("%s%d\n", KGRN, accounts[a].pts);

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
		accounts[a].pts += i;
	}
	return 0;
}

int disableAccount()
{
	string c;
	printf("%s", CUP);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN", KBLU);
	printf("%s: $- ", KYEL);
	printf("%sdisableUser - ", KCYN);
	printf("%senter account data - ", KMAG);

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
	if (unknownCodeFailure(c) || !(accounts[a].isActive))
	{
		failCode();
		return 0;
	}

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
	printf("%s", DLINE);
	accounts[a].isAccountActive = false;

	return 0;
}

int save()
{
	return 0;
}

int exit_run()
{
	printf("\n%sexiting %s\"", KYEL, KMAG);
	printf("%sAccount1_", KYEL);
	printf("%sADMIN%s\"\n", KBLU, KMAG);
	
	printf("%ssaving data[--        ] 27%%\r", KBLU);
	Sleep(420);
	printf("%s", DLINE);
	printf("saving data[---       ]32%%\r");
	
	save();
	Sleep(220);
	printf("%s", DLINE);
	
	printf("data saved[----------]100%%\n\n");

	return 0;
}

cmd list[100] =
{
	{ "commandList", PrintCommands },
	{ "?", PrintCommands },
	{"help", PrintCommands},
	{ "addUser", addNewAccount },
	{ "showUserData", getAccount },
	{ "exit", exit_run},
	{ "editUser", editAccount},
	{ "disableUser", disableAccount},
	{ "deleteUser", deleteAccount_run},
	{ "", NULL }
};

cmd listUsers[100] =
{
	{ "commandList", PrintCommands },
	{ "?", PrintCommands },
	{ "help", PrintCommands },
	{ "openAccountData", getAccount },
	{ "exit", exit_run },
	{ "", NULL }
};

int main()
{
	// setup
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

	//end

	string c;
	cmd *run = list;

	while (c != "quit")
	{
		printf("%slogin_enteruser$- ", KYEL);
		a();

		getline(cin, c);

		if (c == "2007")
		{
			printf("%s", CUP);
			printf("%slogin_enteruser$- ", KYEL);
			printf("%s****", KCYN);

			printf("\n");
			printf("%sAccount1_", KYEL);
			printf("%sADMIN", KBLU);
			printf("%s: $- ", KYEL);

			printf("%sCOMMANDS\n", KCYN);

			PrintCommands();

			printf("\n");

			while (c != "exit")
			{
				printf("%sAccount1_", KYEL);
				printf("%sADMIN", KBLU);
				printf("%s: $- ", KYEL);
				a();

				getline(cin, c);


				run = list;

				while (!run->commandName.empty())
				{
					if (run->commandName == c)
					{
						run->run();
						break;
					}
					run++;
				}

				printf("\n");
				if (run->run == NULL)
				{
					printf("%sAccount1_", KYEL);
					printf("%sADMIN", KBLU);
					printf("%s: $- ", KYEL);
					printf("%sINVALID INPUT\n", KRED);
				}
			}
		}

		else if (c == accounts[0].name && accounts[0].isActive)
		{
			string n = accounts[0].name;

			printf("%s", CUP);
			printf("%slogin_enteruser$- ", KYEL);
			printf("%s****", KCYN);

			printf("\n");
			printf("%s%s1_", KYEL, n.c_str());
			printf("%sUSER", KBLU);
			printf("%s: $- ", KYEL);

			printf("%sCOMMANDS\n", KCYN);

			PrintCommands();

			printf("\n");

			while (c != "exit")
			{
				printf("%s%s_", KYEL, n.c_str());
				printf("%sUSER", KBLU);
				printf("%s: $- ", KYEL);
				a();

				getline(cin, c);


				run = listUsers;

				while (!run->commandName.empty())
				{
					if (run->commandName == c)
					{
						run->run();
						break;
					}
					run++;
				}

				printf("\n");
				if (run->run == NULL)
				{
					printf("%s%s_", KYEL, n.c_str());
					printf("%sUSER", KBLU);
					printf("%s: $- ", KYEL);
					printf("%sINVALID INPUT\n", KRED);
				}
			}
		}
		else
		{
			printf("%s", CUP);
			printf("%slogin_enteruser$- ", KYEL);
			printf("%sunknown password\n", KRED);
		}
	}
	getchar();
	return 0;
}