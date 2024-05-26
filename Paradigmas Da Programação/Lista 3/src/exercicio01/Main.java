package exercicio01;

import exercicio02.Senha;

public class Main {
    public static void main(String[] args) {

        Senha senha = new Senha("minhasenha");

        // Tentando autenticação com senha correta
        senha.entraSenha("minhasenha"); // Saída: Senha correta.

        // Tentando autenticação com senha incorreta
        senha.entraSenha("senhaerrada"); // Saída: Senha incorreta. Tentativas restantes: 2
        senha.entraSenha("senhaerrada"); // Saída: Senha incorreta. Tentativas restantes: 1
        senha.entraSenha("senhaerrada"); // Saída: Senha incorreta. Tentativas restantes: 0
        // Saída: Senha bloqueada.

        // Tentando trocar senha com senha bloqueada
      //  senha.trocarSenha("minhasenha", "novasenha"); // Saída: Senha bloqueada. Não é possível trocar a senha.

        // Desbloqueando senha e trocando-a com sucesso
        senha.entraSenha("minhasenha"); // Saída: Senha correta.
        //senha.trocarSenha("minhasenha", "novasenha"); // Saída: Senha alterada com sucesso.
    }
}