/* Importa a classe DecimalFormat. */
import java.text.DecimalFormat;
/* Classe de teste, onde os objetos serão criados e interagirão. */
public class TestaEstudante2 {

	/* Função estática, ponto de partida do programa. */
	public static void main(String[] a) {

		/* Criação de três referências de tipo EstudanteBolsista. */
		EstudanteBolsista aluno1, aluno2, aluno3;

		/* Instanciação de três referências a objetos do tipo
		Estudante. A terceira referência aponta para a segunda. */
		aluno1 = new EstudanteBolsista(99, "José", 500);
		aluno2 = new EstudanteBolsista(109443, "Ricardo", 200);
		aluno3 = aluno2;

		/* Redefinição do nome do objeto por meio do método setNome. */
		aluno3.setNome("João");

		/* Formata a saída para delimitar as casas decimais. */
		DecimalFormat formatoMoeda = new DecimalFormat("#.00");

		/* Escreve os dados do objeto aluno2, do tipo Estudante. */
		System.out.println("O(A) aluno(a) de matrícula "
			+ aluno2.getMatricula() + " se chama "
			+ aluno2.getNome() + " e recebe uma bolsa de "
			+ formatoMoeda.format(aluno2.getRemuneracao()) + " reais.");

	}
}