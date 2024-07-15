// http://rextester.com/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
           	int valor1 = 10;
			String valor2 = "Valor";

			var infere = 1;
			var infereDeNovo = "Pode" + infere;
            //var infereDeNovo = "Não Pode" - infere;

			Console.WriteLine(valor1.GetType());
			Console.WriteLine(valor2.GetType());
			Console.WriteLine(infere.GetType());
			Console.WriteLine(infereDeNovo.GetType());
        }
    }
}
