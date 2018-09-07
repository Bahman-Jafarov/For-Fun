
using System;
using System.IO;

namespace LearnCSharp
{
    public class AccountQuery
    {
        private string accountNumber { get; set; }
        private string firstName { get; set; }
        private string lastName { get; set; }
        private string totalBalance { get; set; }

        public void ShowData()
        {
            Console.Clear();
            string[] lines = File.ReadAllLines("record.txt");
            foreach (var line in lines)
            {
                string[] key = line.Split(' ');
                Console.WriteLine("\n---------------------------------");
                Console.WriteLine("Account number: " + key[0]);
                Console.WriteLine("First name: " + key[1]);
                Console.WriteLine("Last Name: " + key[2]);
                Console.WriteLine("Current balance: $" + key[3]);
                Console.WriteLine();
            }
            Console.ReadLine();

        }

        public void ReadData()
        {
            Console.Clear();
            Console.WriteLine();
            Console.Write("Enter account number: ");
            accountNumber = Console.ReadLine();
            Console.Write("Enter first name: ");
            firstName = Console.ReadLine();
            Console.Write("Enter last name: ");
            lastName = Console.ReadLine();
            Console.Write("Enter current balance: $");
            totalBalance = Console.ReadLine();
        }

        
        public void WriteData(StreamWriter filex)
        {
            filex.Write(accountNumber);
            filex.Write(' ');
            filex.Write(firstName);
            filex.Write(' ');
            filex.Write(lastName);
            filex.Write(' ');
            filex.Write(totalBalance);
            filex.WriteLine();
        }

        public void WriteRec()
        {
            Console.Clear();
            StreamWriter file = new StreamWriter("record.txt", true);
            ReadData();
            WriteData(file);
            file.Close();
        }

        public void SearchRec()
        {
            Console.Clear();
            int count = 0;
            string[] lines = File.ReadAllLines("record.txt");
            foreach (var line in lines)
            {
                count++;
            }

            if(count == 0)
                Console.WriteLine("There is no record.");
            else
            {
                Console.WriteLine("File has {0} record(s).", count);
                Console.Write("Enter record key to search: ");
                string input = Console.ReadLine();

                foreach (var line in lines)
                {
                    if(line.Contains(input))
                    {
                        string[] key = line.Split(' ');
                        Console.WriteLine("\n---------------------------------");
                        Console.WriteLine("Account number: " + key[0]);
                        Console.WriteLine("First name: " + key[1]);
                        Console.WriteLine("Last Name: " + key[2]);
                        Console.WriteLine("Current balance: $" + key[3]);
                        Console.WriteLine();
                    }
                }
            }
            Console.WriteLine();
            Console.ReadLine();
        }

        public void EditRec()
        {
            Console.Clear();
            Console.Write("Enter account number to update: ");
            string input = Console.ReadLine();

            string[] lines = File.ReadAllLines("record.txt");
            var file = new StreamWriter("recordcopy.txt");

            foreach (var line in lines)
            {
                string[] key = line.Split(' ');
                if (key[0] == input)
                {
                    ReadData();
                    WriteData(file);
                }
                else
                {
                    file.Write(line, true);
                    file.WriteLine();
                }
            }

            File.Open("record.txt", FileMode.Open).Close();
            File.Delete("record.txt");

            file.Close();
            File.Move("recordcopy.txt", "record.txt");

            Console.WriteLine("Record updated succesfully.");
            Console.WriteLine();
            Console.ReadLine();
        }


        public void DeleteRec()
        {
            Console.Clear();
            Console.Write("Enter account number to delete: ");
            string input = Console.ReadLine();

            string[] lines = File.ReadAllLines("record.txt");
            var file = new StreamWriter("recordcopy.txt");

            foreach (var line in lines)
            {
                string[] key = line.Split(' ');
                if (key[0] == input)
                    continue;
                else
                {
                    file.Write(line, true);
                    file.WriteLine();
                }
            }

            File.Open("record.txt", FileMode.Open).Close();
            File.Delete("record.txt");

            file.Close();
            File.Move("recordcopy.txt", "record.txt");

            Console.WriteLine("Record deleted succesfully.");
            Console.WriteLine();
            Console.ReadLine();
        }
    }
}
