#include <Windows.h>
#include "Account_Query.h"


int main()
{
	Account_Query acc;

	while (true)
	{
		try_again:
		system("cls");
		system("color 6");
		std::cout << "\n\n\t\t\xB2\xB2\xB2\xB2  ACCOUNT INFORMATION SYSTEM \xB2\xB2\xB2\xB2\n";
		std::cout << "\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  MAIN MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";

		std::cout << "\n\t1.Add record to file";
		std::cout << "\n\t2.Show record from file";
		std::cout << "\n\t3.Search Record from file";
		std::cout << "\n\t4.Update Record";
		std::cout << "\n\t5.Delete Record";
		std::cout << "\n\t6.Quit";
		std::cout << "\n\n\tEnter your choice: ";
		int choice;
		std::cin >> choice;

		switch (choice)
		{
			case 1: acc.WriteRec();  break;
			case 2: acc.ReadRec();   break;
			case 3: acc.SearchRec(); break;
			case 4: acc.EditRec();   break;
			case 5: acc.DeleteRec(); break;
			case 6: exit(0);         break;
			default: 
				std::cout << "\n\tEnter corret choice";
				Sleep(1500);
				goto try_again;
		}
	}

	system("pause");
}