package exercicio01;

public class Senha {
    private String senha;
    private int tentativas = 3;
    private boolean bloqueada = false;

    public Senha(String senha) {
        this.senha = senha;
    }

    public void entraSenha(String senhaInserida) {
        if (bloqueada) {
            System.out.println("Senha bloqueada. Não é possível efetuar a autenticação.");
        } else {
            if (senhaInserida.equals(senha)) {
                System.out.println("Senha correta.");
                tentativas = 3;
            } else {
                tentativas--;
                System.out.println("Senha incorreta. Tentativas restantes: " + tentativas);
                if (tentativas == 0) {
                    bloqueada = true;
                    System.out.println("Senha bloqueada.");
                }
            }
        }
    }

    public void trocarSenha(String senhaAntiga, String senhaNova) {
        if (bloqueada) {
            System.out.println("Senha bloqueada. Não é possível trocar a senha.");
        } else {
            if (senhaAntiga.equals(senha)) {
                senha = senhaNova;
                tentativas = 3;
                System.out.println("Senha alterada com sucesso.");
            } else {
                tentativas--;
                System.out.println("Senha antiga incorreta. Tentativas restantes: " + tentativas);
                if (tentativas == 0) {
                    bloqueada = true;
                    System.out.println("Senha bloqueada.");
                }
            }
        }
    }
}