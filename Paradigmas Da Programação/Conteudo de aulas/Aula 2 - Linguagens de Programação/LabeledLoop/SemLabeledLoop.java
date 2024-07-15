class SemLabeledLoop {
	public static void main(String[] a) {
		int i, j;

		for(i = 1; i <= 10; i++) {
			System.out.println();

            for(j = 1; j <= 10; j++) {
				System.out.print(j + " ");

				if(j == 5) break;
            }
        }
	}
}
