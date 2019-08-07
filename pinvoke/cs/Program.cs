using System;
using System.Diagnostics;
using System.Security;


using System.Runtime.InteropServices;

namespace cs
{
    class Program
    {

        [DllImport("libvisit.so", EntryPoint="visit", CallingConvention = CallingConvention.FastCall), SuppressUnmanagedCodeSecurity]
	//[SuppressUnmanagedCodeSecurity]
        public static extern void visit();

        static void Main(string[] args)
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();

            long num_reps = 1000L * 1000 * 1000 * 1 ;
            for (long i = 0; i < num_reps; i++) {
              visit();
            }
            sw.Stop();
            Console.WriteLine("Elapsed={0}",sw.Elapsed);
        }
    }
}
