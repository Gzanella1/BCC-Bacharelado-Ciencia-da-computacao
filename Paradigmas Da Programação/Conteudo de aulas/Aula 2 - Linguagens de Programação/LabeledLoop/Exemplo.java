public class Exemplo {
	public static void main(String[] args) {
		int i = 0;
		externo: for (; true;) {
            interno: for (; i < 10; i++) {
               	System.out.println("i = " + i);
               	if (i == 2) {
            		System.out.println("continue");
            		continue;
               	}
               	if (i == 3) {
                    System.out.println("break");
                   	i++;
                   	break;
                }
                if (i == 7) {
                    System.out.println("Continua no externo");
                   	i++;
                   	continue externo;
                }
                if (i == 8) {
                	System.out.println("break externo");
                    break externo;
                }
                for (int k = 0; k < 5; k++) {
                	if (k == 3) {
                  		System.out.println("Continua no interno");
                   		continue interno;
                	}
                }
            }
        }
    }
}