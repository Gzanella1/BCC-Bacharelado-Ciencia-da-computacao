package exercicio06;

public class Main {
    public static void main(String[] args) {

        // video ensinando a trabalhar com data no java
        // https://www.youtube.com/watch?v=WnJUI-jMQGE


        // Construtor 1
        Data data1 = new Data(1222, 40, 30);
        if(data1.validaData()){
            data1.imprimirData(); // Deve imprimir: 1/4/1900
            data1.proximoDia();
            data1.imprimirData(); // Deve imprimir: 2/4/1900
            System.out.println("data valida");
        } else{
            System.out.println("data não é valida");
        }



        // Construtor 2
        Data dataAtual = new Data();
        if(dataAtual.validaData()){
            dataAtual.imprimirData(); // Deve imprimir a data atual do sistema
            dataAtual.proximoDia();
            dataAtual.imprimirData(); // Deve imprimir o dia seguinte à data atual do sistema
            System.out.println("data valida");

        }
        else{
            System.out.println("data atual não é valida");
        }

    }
}
