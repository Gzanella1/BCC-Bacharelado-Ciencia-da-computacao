public class EstudanteBolsista2 extends Estudante {

	private double remuneracao;

	public EstudanteBolsista2(int matricula, String nome, double remuneracao) {
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

	public void estudar(int tempo) {
		if (tempo > 0)
			System.out.println("Bolsista estudando.");
	}

	public void elaborarRelatorio() {
		System.out.println("Relatório elaborado.");
	}

}