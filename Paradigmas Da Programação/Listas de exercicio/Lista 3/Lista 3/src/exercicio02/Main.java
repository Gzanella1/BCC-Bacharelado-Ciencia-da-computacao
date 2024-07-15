package exercicio02;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Senha senha = new Senha("teste159Giovani");

        int opcao;
        do {
            exibirMenu();
            opcao = in.nextInt();
            in.nextLine();

            switch (opcao) {
                case 1:
                    System.out.print("Digite a sua senha: ");
                    String senhaDigitada = in.nextLine();
                    senha.entraSenha(senhaDigitada);
                    break;
                case 2:
                    System.out.print("Digite a sua senha: ");
                    String senhaAntiga = in.nextLine();

                    System.out.print("Digite a nova senha: ");
                    String novaSenha = in.nextLine();

                    senha.trocarSenha(senhaAntiga,novaSenha);
                    break;
                case 3:
                    System.out.println("Saindo do programa...");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        } while (opcao != 3);

        in.close();
    }

    private static void exibirMenu() {
        System.out.println("\nMenu:");
        System.out.println("1. Autenticar");
        System.out.println("2. Trocar senha");
        System.out.println("3. Sair");
        System.out.print("Escolha uma opção: ");
    }

}