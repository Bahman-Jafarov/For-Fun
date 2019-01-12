using System;
using System.Collections.Generic;

namespace LearnCSharp
{
    public class StopWatch
    {
        private DateTime startTime;
        private DateTime stopTime;
        private TimeSpan timeSpan;
        private bool started = false;
        private List<TimeSpan> records = new List<TimeSpan>();

        public void Start()
        {
            if (started)
            {
                Console.WriteLine("Time had started!");
                return;
            }
                
            startTime = DateTime.Now;
            started = true;
            Console.WriteLine("Time has started!");
        }

        public void Stop()
        {
            if(!started)
            {
                Console.WriteLine("Time has not started!");
                return;
            }

            stopTime = DateTime.Now;
            timeSpan += stopTime - startTime;
            records.Add(timeSpan);
            started = false;
            Console.WriteLine("Time has stopped!");
        }

        public void ShowTime()
        {
            if(started)
            {
                Console.WriteLine("Time has not stopped!");
                return;
            }

            Console.WriteLine(timeSpan);
        }

        public void Reset()
        {
            timeSpan = TimeSpan.Zero;
            started = false;
        }

        public void ShowList()
        {
            int i = 0;
            foreach (var time in records)
            {
                Console.WriteLine("{0}. {1}", ++i, time);
            }
        }
    }
}