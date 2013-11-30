import java.lang.*;
import java.util.*;

public class AreaOfTriangle {
	
	public static Double area(Double[] array) {
		Double a = array[0], b = array[1], c = array[2];
		Double p = (a+b+c) / 2;
		Double AreaOfTriangle = Math.sqrt(p * (p-a) * (p-b) * (p-c));
		
		return AreaOfTriangle;
	}
	
	public static Boolean validTriangle(Double[] array) {
		if (array[0] < array[1] + array[2] ) 
			return true;
		else
			return false;
	}

	public static void main(String[] args) {
		Double[] array = new Double[3];
		Scanner scanner = new Scanner(System.in);
		
		for (int i = 0; i < array.length; ++i) {
			Double length = scanner.nextDouble();
			array[i] = length;
		}
		Arrays.sort(array, Collections.reverseOrder()); 
		
		if (validTriangle(array)) 
			System.out.printf("Area = %.2f\n", area(array));
		else
			System.out.printf("Invalid Triangle!\n");
	}

}
