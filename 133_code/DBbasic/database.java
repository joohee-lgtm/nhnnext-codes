
class database {
	
	public static void main(String[] args){
		reculsive(9);
	}

	private static void reculsive(long i) {
		
		long n = 0;
		long n_1 = 0;
		long n_2 = 0;
		
		for (int j=1; j<=i ; j++){
			if (j==1){
				n_2 = 2;
			}
			else if(j == 2){
				n_1 = 3;
			}
			else {
				n = n_1 * n_2;
				n_2 = n_1;
				n_1 = n;
			}
		}
		
		System.out.println(n);
	}
	
}
