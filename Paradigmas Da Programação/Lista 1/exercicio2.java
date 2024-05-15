/**
 * Exercício 2: Se você precisa rotular um loop,
 * provavelmente está lidando com loops aninhados (um loop dentro de outro),
 * o que já torna o código mais complexo. No entanto, a situação piora quando
 * você precisa executar um `break` no loop externo a partir do loop interno.
 * Para lidar com esse caso, você usaria loops rotulados (labeled loops) em Java.
 */
public class exercicio2 {
    public static void main(String[] args) {
        // Cria uma matriz de 3x4
        int[][] matrix = new int[10][10];

        // Preenche a matriz com valores
        fillMatrix(matrix);

        // Imprime a matriz
        printMatrix(matrix);
    }

    public static void fillMatrix(int[][] matrix) {
        linhaMatriz:
        for (int i = 0; i < matrix.length; i++) {
            ColunaMatriz:
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j] = i;
            }
        }
    }

    public static void printMatrix(int[][] matrix) {
        linhaMatriz:
        for (int i = 0; i < matrix.length; i++) {
            ColunaMatriz:
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
                if (i == 5) break linhaMatriz;

            }
            System.out.println();
        }
    }

}


/**
 *
 * Questão 5:
 * Acredito que um programa confiavel seja aquele que realiza com exelecia tudo o que é esperado,
 * entregando os resultados de forma rapida e segura, armazenando os dados de forma sigilosa,
 * além de tudo, aquele que tenha verificações contra entradas de usuarios com más intenções, no geral
 * seria fazer as verificações de entrada e saida ao o usuario, ter todos os tratamentos de erro, e acima de tudo
 * sigilo das iformações.
 * Gosto muito de citar o livro "clean code", pois ele nos mostra como programadores podem implementar
 * programas que geram confiabilidade ao usuario.
 */