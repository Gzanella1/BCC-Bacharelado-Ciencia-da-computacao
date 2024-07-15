/* A palavra extends diz que EstudanteBolsista herda Estudante. */
public class EstudanteBolsista extends Estudante {

	private double remuneracao;

	public EstudanteBolsista(int matricula, String nome, double remuneracao) {
		/* A chamada ao construtor da classe mãe precisa ser a primeira
		instrução do construtor da classe filha. */
		super(matricula, nome);
		this.remuneracao = remuneracao;
	}

	public void setRemuneracao(double remuneracao) {
		if (remuneracao > 0)
			this.remuneracao = remuneracao;
	}

	public double getRemuneracao() {
		return this.remuneracao;
	}

	public void elaborarRelatorio() {
		System.out.println("Relatório elaborado.");
	}

}