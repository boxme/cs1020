import java.lang.*;
import java.util.Scanner;

import javax.management.OperationsException;

public class matrix {

	public static int operation(String query, int[][]matrix, int lineNum, int N, int M) {
		int output = 0;
		if (query.equals("ROW")) {
			for (int i = 0; i < M; ++i) 
				output += matrix[lineNum-1][i];
		}
		else {
			for (int i = 0; i < N; i++) 
				output += matrix[i][lineNum-1];
		}
		return output;
	}
	
	public static void main(String[] args) {
		int N,M;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); M = sc.nextInt();
		
		int[][] matrix = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			Scanner scInput = new Scanner(System.in);
			for (int j = 0; j < M; j++) {	
				matrix[i][j] = scInput.nextInt();
			}
		}
		
		String query;
		int lineNum, output;
		Scanner queryScan = new Scanner(System.in);
		query = queryScan.next();
		lineNum = queryScan.nextInt();
		
		output = operation(query, matrix, lineNum, N, M);
		
		System.out.printf("%d\n", output);
	}
}
