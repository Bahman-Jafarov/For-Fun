using System;

namespace LearnCSharp
{
    public class Program
    {
        static void Main(string[] args)
        {
            var stopWatch = new StopWatch();
            while (true)
            {
                Console.WriteLine();
                Console.Write("'0' Exit, '1' Start, '2' Stop, '3' Show Time, '4' Reset, '5' Show List: ");
                string choice = Console.ReadLine();
                switch (choice)
                {
                    case "0": Console.WriteLine();              return;
                    case "1": stopWatch.Start();                 break;
                    case "2": stopWatch.Stop();                  break;
                    case "3": stopWatch.ShowTime();              break;
                    case "4": stopWatch.Reset();                 break;
                    case "5": stopWatch.ShowList();              break;
                    default: Console.WriteLine("Wrong choice!"); break;
                }
            }
        }    
    }    
}