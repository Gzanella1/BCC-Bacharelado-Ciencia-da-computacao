package exercicio04;

import exercicio03.Porta;

public class Main {
    public static void main(String[] args) {
        Porta p1=new Porta(false,"branco",0.15,0.16,0.17);
        Porta p2=new Porta(false,"preto",1.0,2.6,0.17);
        Porta p3=new Porta(false,"amarelo",15.0,16.0,0.17);

        Casa casa=new Casa(p1,p2,p3,"verde");


        System.out.println("Primeira porta da casa: "+casa.getPorta1());
        System.out.println("Segunda porta da casa: "+casa.getPorta2());
        System.out.println("Terceira porta da casa: "+casa.getPorta3());
        System.out.println("Cor inicail da casa: "+casa.getCor());
        casa.pinta("Roxo");
        System.out.println("Alterando a cor da casa: "+casa.getCor());
        System.out.println("Número de portas abertas: "+ casa.quantasPortasEstaoAbertas());
        p1.abre();
        System.out.println("Número de portas abertas: "+ casa.quantasPortasEstaoAbertas());

    }
}
