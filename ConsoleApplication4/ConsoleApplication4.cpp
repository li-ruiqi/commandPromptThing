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
	read(plist);

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
						run->run(plist);
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