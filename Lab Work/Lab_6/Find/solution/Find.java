import java.util.*;

class Result {
	int N, K;
	int table[][];
	public Result(int N, int K) {
		this.N = N;
		this.K = K;
		table = new int[2][50000];
	}
	
	private int convert(char chr) {
		if (chr == 'A') return 1;
		if (chr == 'C') return 2;
		if (chr == 'G') return 3;
		return 4;
	}
	
	public void generate(String dna, int idx) {
		for (int i = 0; i < N; i++) {
			int hash = 0;
			if (i + K - 1 < N) {
				for (int j = 0; j < K; j++) {
					hash = hash * 5 + convert(dna.charAt(i + j));
				}
				table[idx][hash]++;
			}
		}
	}
	
	public int count(String substring, int idx) {
		int hash = 0;
		for (int i = 0; i < K; i++) {
			hash = hash * 5 + convert(substring.charAt(i));
		}
		return table[idx][hash];
	}
}

class Find {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, K, Q;
		String dna, substring, dna2;
		Result res;

		N = sc.nextInt();
		K = sc.nextInt();
		dna = sc.next();
		dna2 = sc.next();
		Q = sc.nextInt();
		res = new Result(N, K);
		res.generate(dna, 0);
		res.generate(dna2, 1);
		for (int i = 0; i < Q; i++) {
			substring = sc.next();
			if (res.count(substring, 0) > 0 && res.count(substring, 1) > 0) System.out.println(3);
			else if (res.count(substring, 0) > 0) System.out.println(1);
			else if (res.count(substring, 1) > 0) System.out.println(2);
			else System.out.println(0);
		}
	}
}