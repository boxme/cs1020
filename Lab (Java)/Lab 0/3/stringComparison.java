import java.lang.*;
import java.util.Scanner;

import sun.misc.Compare;

public class stringComparison {

	public static void main(String[] args) {
		String line1, line2;
		Scanner input1 = new Scanner(System.in);
		line1 = input1.next();
		Scanner input2 = new Scanner(System.in);
		line2 = input2.next();
		
		//Change to lowercase using .toLowerCase()
		line1 = line1.toLowerCase();
		line2 = line2.toLowerCase();
		
		if (line1.compareTo(line2) == 0) 
			System.out.printf("0\n");
		else if (line1.compareTo(line2) < 0)
			System.out.printf("1\n");
		else
			System.out.printf("2\n");
		
		//Using compareToIgnoreCase()
//		if (line1.compareToIgnoreCase(line2) == 0) 
//			System.out.printf("0\n");
//		else if (line1.compareToIgnoreCase(line2) < 0)
//			System.out.printf("1\n");
//		else
//			System.out.printf("2\n");
	}
}
