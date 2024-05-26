package exercicio02;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Senha senha = new Senha("teste159Giovani");

        int i=0;
        while (i <= 3) {
            if (senha.isBloqueado()) {
                System.out.println("A senha está bloqueada. Não é possível efetuar a autenticação.");
                break;
            }

            System.out.print("Digite a sua senha: ");
            String senhaDigitada = scanner.nextLine();
            senha.entraSenha(senhaDigitada);
            i++;
        }

        // nesse caso eu acho errado passa a senha autal como parametro
        // poderia simplismente acessar a variavel senha.torcarSenha(novaSenha);
        // como ex pede com dois parametros achei melhor colocar o atributo da forma static
        // pa ai eu acesso direto da classe
        System.out.println("trocando de senha: ");
        Senha.trocarSenha(senha, "senha");




        scanner.close();
    }
}