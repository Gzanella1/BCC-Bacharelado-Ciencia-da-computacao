package exercicio01;

public class Gato implements Animal {
    @Override
    public void fazerSom() {
        System.out.println("O gato faz: Miau");
    }
    @Override
    public void comer() {
        System.out.println("O gato comeu");
    }
}