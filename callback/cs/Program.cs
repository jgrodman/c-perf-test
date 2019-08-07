using System;
using System.Diagnostics;
using System.Security;


using System.Runtime.InteropServices;

namespace cs
{
    class Program
    {

        [DllImport("libvisit.so", EntryPoint="visit"), SuppressUnmanagedCodeSecurity]
        public static extern void visit(IntPtr callback);

	[UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void Callback();
	
	[UnmanagedFunctionPointer(CallingConvention.ThisCall)]
        public delegate void ThisCallback(IntPtr ip);


	public class InnerProgram {
          public InnerProgram() {}
	  public void cb(IntPtr ip) {}
	}

        static void cb() {
        }

        static void Main(string[] args)
        {
            Callback myCb = new Callback(cb);
            IntPtr pMyCb = Marshal.GetFunctionPointerForDelegate<Callback>(myCb);

            InnerProgram innerPg = new InnerProgram();
	    ThisCallback myInnerCb = new ThisCallback(innerPg.cb);
            IntPtr pMyInnerCb = Marshal.GetFunctionPointerForDelegate<ThisCallback>(myInnerCb);

            Stopwatch sw = new Stopwatch();
            sw.Start();
            visit(pMyCb);
            sw.Stop();
            Console.WriteLine("Elapsed={0}",sw.Elapsed);
        }
    }
}
