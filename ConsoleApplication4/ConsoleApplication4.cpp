// ConsoleApplication4.cpp : Defines the entry point for the console application
//no bugs today; creating new functions

#include "stdafx.h"
#include "commands.h"

using namespace std;

//----------------------

int main()
{
	setup();

	string c;
	cmd *run = list;
	vector <profiles> *plist = &accounts;
	int returnValue = 0;

	printf("%sdownloading data[--        ] 27%%\r", KGRN);
	Sleep(420);
	printf("%s", DLINE);
	printf("downloading data[---       ]32%%\r");
	Sleep(220);
	read(plist);
	printf("%s", DLINE);
	printf("data downloaded[----------]100%%\n");

	while (c != "quit")
	{
		startOfLoop:

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

			PrintCommands(plist);

			printf("\n");

			while (returnValue != EXITCODE)
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
						returnValue = run->run(plist);
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
			returnValue = 0;
		}

		else if (c == accounts[0].name && accounts[0].isActive)
		{
			if (!(accounts[0].isAccountActive))
			{
				accountIsDisabled(0, plist);
				goto startOfLoop;
			}
			string n = accounts[0].name;

			printf("%s", CUP);
			printf("%slogin_enteruser$- ", KYEL);
			printf("%s****", KCYN);

			printf("\n");
			printf("%s%s1_", KYEL, n.c_str());
			printf("%sUSER", KBLU);
			printf("%s: $- ", KYEL);

			printf("%sCOMMANDS\n", KCYN);

			PrintCommands_user(plist);

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
						run->run(plist);
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
			returnValue = 0;
		}

		else if (c == accounts[1].name && accounts[1].isActive)
		{
			if (!(accounts[1].isAccountActive))
			{
				accountIsDisabled(0, plist);
				goto startOfLoop;
			}
			string n = accounts[1].name;

			printf("%s", CUP);
			printf("%slogin_enteruser$- ", KYEL);
			printf("%s****", KCYN);

			printf("\n");
			printf("%s%s_", KYEL, n.c_str());
			printf("%sUSER", KBLU);
			printf("%s: $- ", KYEL);

			printf("%sCOMMANDS\n", KCYN);

			PrintCommands_user(plist);

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
						run->run(plist);
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
		else if (c == "quit");
		else
		{
			printf("%s", CUP);
			printf("%slogin_enteruser$- ", KYEL);
			printf("%sunknown password\n", KRED);
		}
	}
	return 0;
}