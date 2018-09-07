#include "Account_Query.h"

void Account_Query::ReadData()
{
	system("cls");
	std::cout << "\nEnter Account Number: ";
	std::cin >> m_accountNumber;
	std::cout << "\nEnter First Name: ";
	std::cin >> m_firstName;
	std::cout << "\nEnter Last Name: ";
	std::cin >> m_lastName;
	std::cout << "\nEnter Balance: $";
	std::cin >> m_totalBalance;
}



void Account_Query::ShowData()
{
	std::cout << "-----------------------------------------------------\n\n";
	std::cout << "\nAccount Number: " << m_accountNumber << std::endl;
	std::cout << "\nFirst Name: " << m_firstName << std::endl;
	std::cout << "\nLast Name: " << m_lastName << std::endl;
	std::cout << "\nCurrent Balance: $" << m_totalBalance << std::endl;
}



void Account_Query::WriteRec()
{
	system("cls");
	std::ofstream outfile;
	outfile.open("record.txt", std::ios::binary | std::ios::app);
	ReadData();
	outfile << m_accountNumber << ' ' << m_firstName << ' ' << m_lastName << ' ' << m_totalBalance << std::endl;
	outfile.close();
}



void Account_Query::ReadRec()
{
	system("cls");
	std::ifstream infile;
	infile.open("record.txt", std::ios::binary);

	if (!infile)
	{
		std::cout << "\nError in opening. File not found!";
		return;
	}

	std::cout << "\n\t\t\t\xB2\xB2\xB2\xB2 DATA FROM FILE \xB2\xB2\xB2\xB2\n";
	
	while (infile >> m_accountNumber >> m_firstName >> m_lastName >> m_totalBalance)
	{
		std::cout << "-----------------------------------------------------";
		std::cout << "\nAccount Number: " << m_accountNumber << std::endl;
		std::cout << "\nFirst Name: " << m_firstName << std::endl;
		std::cout << "\nLast Name: " << m_lastName << std::endl;
		std::cout << "\nCurrent Balance: $" << m_totalBalance << "\n\n\n";
	}
		
	infile.close();
	std::cout << '\n';
	system("pause");
}



void Account_Query::SearchRec()
{
	system("cls");
	std::ifstream infile;
	infile.open("record.txt", std::ios::binary);

	if (!infile)
	{
		std::cout << "\nError in opening. File not found!";
		return;
	}

	int count = 0;
	while (infile >> m_accountNumber >> m_firstName >> m_lastName >> m_totalBalance)
		count++;

	infile.close();
	infile.open("record.txt", std::ios::binary);

	if (count == 0)
		std::cout << "\nThere is no record\n";
	else
	{
		std::cout << "\nFile has " << count << " record(s).\n";
		std::cout << "\nEnter record key to search: ";
		std::string search;
		std::cin >> search;

		while (infile >> m_accountNumber >> m_firstName >> m_lastName >> m_totalBalance)
		{
			if (search.compare(m_accountNumber) == 0 ||
				search.compare(m_firstName) == 0 ||
				search.compare(m_lastName) == 0 ||
				search.compare(m_totalBalance) == 0
				)
			{
				std::cout << "\n-----------------------------------------------------";
				std::cout << "\nAccount Number: " << m_accountNumber << std::endl;
				std::cout << "\nFirst Name: " << m_firstName << std::endl;
				std::cout << "\nLast Name: " << m_lastName << std::endl;
				std::cout << "\nCurrent Balance: $" << m_totalBalance << "\n\n\n";
			}
		}
	}

	infile.close();
	std::cout << '\n';
	system("pause");
}



void Account_Query::DeleteRec()
{
	system("cls");
	std::fstream infile;
	infile.open("record.txt", std::ios::in | std::ios::out);

	std::fstream outfile;
	outfile.open("record2.txt", std::ios::binary | std::ios::out);

	if (!infile)
	{
		std::cout << "\nError in opening. File not found!";
		return;
	}

	
	std::cout << "\nEnter account number to delete: ";
	std::string number;
	std::cin.ignore();
	std::cin >> number;


	while (infile >> m_accountNumber >> m_firstName >> m_lastName >> m_totalBalance)
	{
		if (number.compare(m_accountNumber) != 0)
			outfile << m_accountNumber << ' ' << m_firstName << ' ' << m_lastName << ' ' << m_totalBalance << std::endl;
			
	}

	infile.close();
	outfile.close();
	remove("record.txt");
	rename("record2.txt", "record.txt");
	std::cout << '\n';
	system("pause");
}



void Account_Query::EditRec()
{
	system("cls");
	std::fstream infile;
	infile.open("record.txt", std::ios::in | std::ios::out);

	std::fstream outfile;
	outfile.open("record2.txt", std::ios::binary | std::ios::out);

	if (!infile)
	{
		std::cout << "\nError in opening. File not found!";
		return;
	}


	std::cout << "\nEnter account number to update: ";
	std::string number;
	std::cin.ignore();
	std::cin >> number;


	while (infile >> m_accountNumber >> m_firstName >> m_lastName >> m_totalBalance)
	{
		if (number.compare(m_accountNumber) != 0)
			outfile << m_accountNumber << ' ' << m_firstName << ' ' << m_lastName << ' ' << m_totalBalance << std::endl;
		else
		{
			system("cls");
			std::cout << "\nEnter Account Number: ";
			std::cin >> m_accountNumber;
			std::cout << "\nEnter First Name: ";
			std::cin >> m_firstName;
			std::cout << "\nEnter Last Name: ";
			std::cin >> m_lastName;
			std::cout << "\nEnter Balance: $";
			std::cin >> m_totalBalance;
			outfile << m_accountNumber << ' ' << m_firstName << ' ' << m_lastName << ' ' << m_totalBalance << std::endl;

		}

	}

	infile.close();
	outfile.close();
	remove("record.txt");
	rename("record2.txt", "record.txt");
	std::cout << '\n';
	system("pause");
}


