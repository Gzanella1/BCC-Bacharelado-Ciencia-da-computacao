/* Classe estudante, pública */
public class Estudante {
	/* Atributos do estudante
	o sinal de "menos" no diagrama indica que os atributos são
	privados. Portanto, só podem ser acessados e manipulados no
	contexto da própria classe.
	*/
	private int matricula;
	private String nome;

	/* O construtor é um método especial responsável por
	inicializar o estado interno quando uma instância pra um
	objeto do tipo Estudante for criado. Quando não é definido,
	um construtor vazio é criado. Neste caso, criamos
	explicitamente um construtor vazio. */
	public Estudante() {}

	/* Métodos em java aceitam sobrecarga. 
	Desta forma, um método pode conter o mesmo nome que outro
	definido na mesma classe, mas a assinatura é diferente.
	Abaixo criamos um construtor diferente para Estudante. */
	public Estudante(String nome) {
		this.matricula = 10;
		this.nome = nome;
	}

	/* Aqui novamente sobrecarregamos o construtor. */
	public Estudante(int matricula, String nome) {
		this.matricula = matricula;
		this.nome = nome;
	}

	/* Os métodos da classe Estudante estão abaixo.
	Os métodos comumente são declarados contendo, na assinatura:
	- visibilidade
	- tipo de retorno
	- identificador
	- lista de parâmetros
	O sinal de "mais" no diagrama indica que os métodos são
	públios. Portanto, podem ser acessados de qualquer lugar. */
	public void estudar(int tempo) {
		if (tempo > 0)
			System.out.println("Estudando.");
	}

	public void apresentarTrabalho() {
		System.out.println("Apresentando.");
	}

	/* A criação de métodos getters e setters ajuda a padronizar
	a forma de criação e comunicação com os objetos, bem como esconder
	os detalhes de implementação da classe. Assim, sabemos que a forma
	de obter valores é por meio dos métodos get, e a forma de
	(re)definir os valores é por meio dos métodos set. Não conseguimos
	definir diretamente nos atributos porque eles são privados. Este
	princípio de esconder a estrutura interna e fornecer os métodos
	como interface de comunicação é conhecido como encapsulamento. */
	public void setMatricula(int matricula) {
		/* this é uma referência ao próprio objeto. Assim garantimos
		que não há ambiguidade entre o atributo do objeto
		(this.matricula) e o parâmetro do método */
		this.matricula = matricula;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getMatricula() {
		return this.matricula;
	}

	public String getNome() {
		return this.nome;
	}
}