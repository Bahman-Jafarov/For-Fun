#include <iostream>
#include <stdlib.h>

char a[10]{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
void board();
int checkWin();

int main()
{
	int player = 1, i, choice;
	char mark;

	
	do
	{
		system("CLS");
		board();
		player = (player % 2) ? 1 : 2;
		std::cout << "Player " << player << " enter a number: ";
		std::cin >> choice;
		mark = (player == 1) ? 'X' : 'O';
		if (a[choice] == (char)(choice+48))
			a[choice] = mark;
		else
		{
			std::cout << "Invalid input";
			player--;
		}

		i = checkWin();
		player++;

		
	} while (i == -1);

	system("CLS");
	board();
	if (i == 1)
		std::cout << "\n====> Player " << --player << " win\n\n";
	else
		std::cout << "\n====> Game draw\n\n";
	
	system("pause");
}


int checkWin()
{
	if (a[1] == a[2] && a[2] == a[3]) return 1;
	if (a[4] == a[5] && a[5] == a[6]) return 1;
	if (a[7] == a[8] && a[8] == a[9]) return 1;
	if (a[1] == a[4] && a[4] == a[7]) return 1;
	if (a[2] == a[5] && a[5] == a[8]) return 1;
	if (a[3] == a[6] && a[6] == a[9]) return 1;
	if (a[1] == a[5] && a[5] == a[9]) return 1;
	if (a[3] == a[5] && a[5] == a[7]) return 1;

	if (a[1] != '1' && a[2] != '2' && a[3] != '3' &&
		a[4] != '4' && a[5] != '5' && a[6] != '6' &&
		a[7] != '7' && a[8] != '8' && a[9] != '9')
		return 0;
	
	return -1;
}


void board()
{
	std::cout << "\n\n\tTic Tac Toe\n\n";
	std::cout << "Player 1 - <X>, Player 2 - <O>\n\n";
	std::cout << "         " << "  |  " << "   |  " << "\n";
	std::cout << "        " << a[1] << "  |  " << a[2] << "  |  " << a[3] << std::endl;
	std::cout << "      _____|_____|_____\n";
	std::cout << "         " << "  |  " << "   |  " << "\n";
	std::cout << "        " << a[4] << "  |  " << a[5] << "  |  " << a[6] << std::endl;
	std::cout << "      _____|_____|_____\n";
	std::cout << "         " << "  |  " << "   |  " << "\n";
	std::cout << "        " << a[7] << "  |  " << a[8] << "  |  " << a[9] << std::endl;
	std::cout << "         " << "  |  " << "   |  " << "\n";
}