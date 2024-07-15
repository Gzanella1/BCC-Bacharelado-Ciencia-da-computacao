/*
Em Java, todo objeto que deixa de ser referenciado é considerado "lixo".
Para coletar este lixo deliberadamente, invocamos o garbage collector.
O método finalize() é chamado quando um objeto é coletado.

Um objeto deixa de ser referenciado quando:
a) recebe uma referência nula;
b) recebe a referência a outro objeto; ou
c) cria um objeto de forma anônima.
*/
public class Coletor { 

	static int lixoColetado = 0;
 
	public void finalize(){
		System.out.println("O lixo está sendo coletado.");
		lixoColetado++;
	}  

	public static void main(String a[]) {  

		Coletor c1 = new Coletor();
		Coletor c2 = new Coletor();
		c1 = null;
		c2 = c1; // c1 = null; 
		
		for (int i = 0; i < 100; i++) {
			new Coletor();
			System.gc();
		}

		System.out.println("O coletor de lixo foi chamado " + lixoColetado + " vezes.");
	}
}