import java.util.*;

public class HelloWorld {
	public static int output(String _operator, int _A, int _B) {
		if (_operator.equals("AND")) {
			if (_A == 0 || _B == 0) return 0;
			return 1;
		}
		else {
			if (_A == 1 || _B == 1) return 1;
			return 0;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int type, N, A, B;
		String operator;
		type = sc.nextInt();
		if (type == 1) {
			N = sc.nextInt();
			for (int i = 0; i < N; i++) {
				operator = sc.next();
				A = sc.nextInt();
				B = sc.nextInt();
				System.out.println(output(operator, A, B));
			}
		}
		else if (type == 2) {
			while (true) {
				operator = sc.next();
				if (operator.equals("0")) break;
				A = sc.nextInt();
				B = sc.nextInt();
				System.out.println(output(operator, A, B));
			}
		}
		else {
			while (sc.hasNext()) {
				operator = sc.next();
				A = sc.nextInt();
				B = sc.nextInt();
				System.out.println(output(operator, A, B));
			}
		}
	}
}