package exercicio01;

public class Cachorro implements Animal {
    @Override
    public void fazerSom() {
        System.out.println("O cachorro faz: Au Au");
    }
    @Override
    public void comer() {
        System.out.println("O cachorro comeu");
    }
}