#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

class Account_Query
{
private:
	std::string m_accountNumber;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_totalBalance;

public:
	void ReadData();
	void ShowData();
	void WriteRec();
	void ReadRec();
	void SearchRec();
	void DeleteRec();
	void EditRec();
};
