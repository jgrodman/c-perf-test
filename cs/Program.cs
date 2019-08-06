using System;

using System.Diagnostics;


using System.Runtime.InteropServices;

namespace cs
{
    class Program
    {

        [DllImport("libvisit.so", EntryPoint="visit", CallingConvention=CallingConvention.StdCall)]
        public static extern void visit(IntPtr callback);

        public delegate void Callback();

        static void cb() {
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            Callback myCb = new Callback(cb);
            IntPtr pMyCb = Marshal.GetFunctionPointerForDelegate(myCb);

            Stopwatch sw = new Stopwatch();
            sw.Start();
            visit(pMyCb);
            sw.Stop();
            Console.WriteLine("Elapsed={0}",sw.Elapsed);
        }
    }
}
