public class TiposZoados {
	public static void main(String[] args) {
		/*
		Olhando a documentação do método Integer.valueOf()
		(https://docs.oracle.com/javase/7/docs/api/java/lang/Integer.html#valueOf(int)),
		podemos ver que se o valor passado for maior que IntegerCache.low
		e menor que IntegerCache.high, então o método retorna objetos Integer de IntegerCache.

		Os valores padrão para IntegerCache.low e IntegerCache.high são -128 e 127, respectivamente.
		Portanto, em vez de criar e retornar novos objetos inteiros, o método Integer.valueOf()
		retorna objetos Integer de um IntegerCache interno se o valor passado for maior que -128
		e menor que 127.
		*/
		System.out.println(Integer.valueOf(6) == Integer.valueOf(6));
		System.out.println(Integer.valueOf(1000) == Integer.valueOf(1000));

		/* Aqui sim daria true! */
		System.out.println(Integer.valueOf(1000).equals(Integer.valueOf(1000)));

		/* Um não funciona e o outro funciona. Por quê? */
		//System.out.println((byte) + (char) - (int) + (long));
		System.out.println((byte) + (char) - (int) + (long) - 1);
		
		/*
		Sistemas de representação numérica diferentes
		podem ser usados numa mesma expressão!
		*/
		System.out.println(022 - 2);
	}
}