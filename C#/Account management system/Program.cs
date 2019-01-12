using System;
using System.Threading;

namespace LearnCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            AccountQuery acc = new AccountQuery();


            while (true)
            {
                Console.Clear();
                Console.WriteLine("\n\t\tACCOUNT INFORMATION SYSTEM");
                Console.WriteLine("\n\t\t\tMAIN MENU");

                Console.Write("\n\t1.Add record to file");
                Console.Write("\n\t2.Show record from file");
                Console.Write("\n\t3.Search record from file");
                Console.Write("\n\t4.Update record");
                Console.Write("\n\t5.Delete record");
                Console.Write("\n\t6.Quit");
                Console.Write("\n\n\tEnter your choice: ");

                int choice = Convert.ToInt32(Console.ReadLine());

                switch (choice)
                {
                    case 1: acc.WriteRec();       break;
                    case 2: acc.ShowData();       break;
                    case 3: acc.SearchRec();      break;
                    case 4: acc.EditRec();        break;
                    case 5: acc.DeleteRec();      break;
                    case 6: Console.WriteLine(); return;
                    default:
                        Console.WriteLine("\n\tEnter corret choice");
                        Thread.Sleep(1500);
                        break;
                }
            }

        }
    }
}