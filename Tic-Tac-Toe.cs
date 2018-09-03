
using System;

namespace LearnCSharp
{
    class Program
    {
        static char[] a = new char[10] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


        private static void Main(string[] args)
        {
            int player = 1, i;

            do
            {
                Console.Clear();
                Board();
                player = (Convert.ToBoolean(player % 2)) ? 1 : 2;
                var mark = (player == 1) ? 'X' : 'O'; 
                Console.Write("Player {0}, enter a number: ", player);
                var choice = Convert.ToInt32(Console.ReadLine());

                if (a[choice] == Convert.ToChar(choice+48))
                    a[choice] = mark;
                else
                {
                    Console.WriteLine("Invalid input");
                    player--;
                }

                i = CheckWin();
                player++;

            } while (i == -1);

            player--
            Console.Clear();
            Board();
            if(i == 1)
                Console.WriteLine("====> Player {0} win!", player);
            else
            {
                Console.WriteLine("====> Draw!");
            }
            
        }

        public static int CheckWin()
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


        public static void Board()
        {
            Console.Write("\n\n\tTic Tac Toe\n\n");
            Console.Write("Player 1 - <X>, Player 2 - <O>\n\n");
            Console.Write("           |     |  \n");
            Console.WriteLine("        " + a[1] + "  |  " + a[2] + "  |  " + a[3]);
            Console.Write("      _____|_____|_____\n");
            Console.Write("           |     |  \n");
            Console.WriteLine("        " + a[4] + "  |  " + a[5] + "  |  " + a[6]);
            Console.Write("      _____|_____|_____\n");
            Console.Write("           |     |  \n");
            Console.WriteLine("        " + a[7] + "  |  " + a[8] + "  |  " + a[9]);
            Console.Write("           |     |  \n");
        }
    }
}
