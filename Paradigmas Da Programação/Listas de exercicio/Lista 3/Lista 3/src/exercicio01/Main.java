package exercicio01;

public class Main {
    public static void main(String[] args) {
        Animal cachorro = new Cachorro();
        cachorro.fazerSom();
        cachorro.comer();
        Animal gato = new Gato();
        gato.fazerSom();
        gato.comer();
    }
}