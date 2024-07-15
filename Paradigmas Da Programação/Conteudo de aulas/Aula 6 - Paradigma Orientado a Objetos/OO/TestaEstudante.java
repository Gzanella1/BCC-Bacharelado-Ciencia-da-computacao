/* Classe de teste, onde os objetos serão criados e interagirão. */
public class TestaEstudante {

	/* Função estática, ponto de partida do programa. */
	public static void main(String[] a) {

		/* Criação de três referências de tipo Estudante. */
		Estudante aluno1,
				  aluno2,
				  aluno3;

		/* Instanciação de três referências a objetos do tipo
		Estudante. A terceira referência aponta para a segunda. */
		aluno1 = new Estudante();
		aluno2 = new Estudante(109443, "Ricardo");
		aluno3 = aluno2;

		/* Redefinição do nome do objeto por meio do método setNome. */
		aluno3.setNome("João");

		/* Escreve os dados do objeto aluno2, do tipo Estudante. */
		System.out.println("O(A) aluno(a) de matrícula "
			+ aluno2.getMatricula() + " se chama "
			+ aluno2.getNome() + ".");

	}
}