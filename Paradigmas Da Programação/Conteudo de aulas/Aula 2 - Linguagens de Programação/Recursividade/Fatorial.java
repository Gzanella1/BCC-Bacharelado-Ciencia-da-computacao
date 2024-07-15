import java.util.Scanner;
public class Fatorial {
	public Fatorial() {
	}

	public int check(int n) {
		if (n < 0) System.exit(1);
		return n;
	}

	public int calculaFatorial(int n) {
		check(n);
		if (n == 0) {
			return 1;
		}
		return n * calculaFatorial(n-1);
	}

	public static void main(String[] a) {
		//int n = new Scanner(System.in).nextInt();
        int n = Integer.parseInt(a[0]);
        Fatorial f = new Fatorial();
		System.out.println(f.calculaFatorial(n));
    }
	
}
