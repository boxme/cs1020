import java.lang.*;
import java.util.Scanner;
import java.lang.Class;

public class lab_0_qn1 {
	public static boolean intToBool(int num) {
		return (num != 0);
	}
	
	public static int operation(String Op, int num1, int num2) {
		boolean a = intToBool(num1); //return true if 1, else false
		boolean b = intToBool(num2);
		
		if (Op.equals("AND")) {
			if (a && b) 
				return 1;
			else 
				return 0;
		}
		else {
			if (a || b) 
				return 1;
			else 
				return 0;
		}
			
	}
	
	public static void printResult(int[] results, int N) {
		for (int i=0; i<N; i++) {
			System.out.printf("%d\n", results[i]);
		}
	}
	
	public static void main(String[] args) {
		int[] results = new int[99];
		Scanner sc = new Scanner(System.in);
		
		switch (sc.nextInt()) {
		case 1: {
			int N = sc.nextInt();
			for (int i = 0; i < N; i++) {
				results[i] = operation(sc.next(), sc.nextInt(), sc.nextInt());
			}
			printResult(results, N);
			break;
		}
		case 2: {
			int i=0;
			while (true) {
				if (sc.hasNextInt()) break;
				else results[i] = operation(sc.next(), sc.nextInt(), sc.nextInt());
				++i;
			}
			printResult(results, i);
			break;
		}
		case 3: {
			int i=0;
			while(sc.hasNextLine()) {
				results[i]= operation(sc.next(), sc.nextInt(), sc.nextInt());
				++i;
			}			
			printResult(results,  i);
		}
		}
	}
}
