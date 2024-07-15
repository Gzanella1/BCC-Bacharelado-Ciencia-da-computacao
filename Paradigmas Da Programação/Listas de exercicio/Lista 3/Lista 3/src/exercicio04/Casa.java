package exercicio04;

import exercicio03.Porta;

import java.util.Arrays;
import java.util.List;

public class Casa {
    private Porta porta1;
    private Porta porta2;
    private Porta porta3;
    private String cor;

    public Casa(Porta porta1, Porta porta2, Porta porta3, String cor) {
        this.porta1 = porta1;
        this.porta2 = porta2;
        this.porta3 = porta3;
        this.cor = cor;
    }

    public void pinta(String cor){
        this.cor=cor;
    }
    public int quantasPortasEstaoAbertas(){
        // Gambiarra : se der errado fazer 3 if(getPorta1.isAberta) soma 1 na variavel n;
        int n = 0;
        Porta[] portas = {getPorta1(), getPorta2(), getPorta3()};

        for (Porta porta : portas) {
            if (porta.isAberta()) {
                n += 1;
            }
        }
        return n;
    }


    // ================
    // GETTER E SETTER
    // ================


    public Porta getPorta1() {
        return porta1;
    }

    public Porta getPorta2() {
        return porta2;
    }

    public Porta getPorta3() {
        return porta3;
    }


    public String getCor() {
        return cor;
    }

}
