package exercicio05;

public class TestaCalculadoras {
    public static void main(String[] args) {
        CalculadoraCientifica cc = new CalculadoraCientifica();

        System.out.println("Soma: "+cc.somar(10,50));
        System.out.println("Subitração:"+cc.subtrair(10,50));
        System.out.println("Multiplicação: "+cc.multiplicar(10,50));
        System.out.println("Divisão: "+cc.dividir(50,10));
        System.out.println("Potencia: "+cc.potencia(10,2));

    }
}
