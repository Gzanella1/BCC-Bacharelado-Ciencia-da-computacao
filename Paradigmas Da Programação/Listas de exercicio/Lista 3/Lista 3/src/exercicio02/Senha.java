package exercicio02;

public class Senha {
    private String senha;
    private int tentativas;
    private boolean bloqueado;

    public Senha(String senha) {
        this.senha = senha;
        this.tentativas = 3;
        this.bloqueado = false;
    }

    public boolean entraSenha(String s) {
        // Verifica se está bloqueado
        if (isBloqueado()) {
            System.out.println("A senha está bloqueada. Não é possível efetuar a autenticação.");
        } else {
            // Se a senha não estiver correta, remova uma tentativa
            if (!getSenha().equals(s)) {
                setTentativas(getTentativas() - 1);
                // Verifica se ainda tem tentativas
                if (getTentativas() == 0) {
                    setBloqueado(true);
                    System.out.println("A senha foi bloqueada devido a várias tentativas incorretas.");
                } else {
                    System.out.println("Senha incorreta. Número de tentativas restantes: " + getTentativas());
                }
                return false;
            } else {
                // Senha correta, renova as tentativas para 3
                setTentativas(3);
                System.out.println("Senha correta. Número de tentativas : " + getTentativas());
                return true;
            }
        }
        return false;
    }

    public void trocarSenha(String senhaAntiga, String novaSenha) {
        // se a esta bloqueada
        if (isBloqueado()) {
            System.out.println("A senha está bloqueada. Não é possível efetuar a alteração da senha.");
        } else {
            if(entraSenha(senhaAntiga)){
                setSenha(novaSenha);
                setTentativas(3);
                System.out.println("senha foi torcada para :" + getSenha());
            }
        }
    }






    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public int getTentativas() {
        return tentativas;
    }

    public void setTentativas(int tentativas) {
        this.tentativas = tentativas;
    }

    public boolean isBloqueado() {
        return bloqueado;
    }

    public void setBloqueado(boolean bloqueado) {
        this.bloqueado = bloqueado;
    }
}