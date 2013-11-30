import java.util.*;

public class Matrix {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, M, index, sum;
		int[][] arr = new int[110][110];
		String type;
		N = sc.nextInt(); M = sc.nextInt();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		type = sc.next();
		index = sc.nextInt();
		sum = 0;
		index--;
		if (type.equals("ROW")) {
			for (int i = 0; i < M; i++) {
				sum += arr[index][i];
			}
		}
		else {
			for (int i = 0; i < N; i++) {
				sum += arr[i][index];
			}
		}
		System.out.println(sum);
	}
}