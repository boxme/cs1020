import java.lang.*;
import java.util.*;

import javax.management.OperationsException;

class Matrix {
	// Data Attributes
	public int size;
	public int[][] matrix;
	
	// Constructors
	public Matrix(int size) {
		this.size = size;
		this.matrix = new int[size][size];
	}
	
	// Methods
	private void rotate(int degree) {
		int numRotation = degree / 90;
		
		while (numRotation > 0) {
			for (int x=0; x<size/2; ++x) {
				for (int y=x; y<size-1-x; ++y) {
					int temp = matrix[x][y];
					matrix[x][y] = matrix[size-1-y][x];
					matrix[size-1-y][x] = matrix[size-1-x][size-1-y];
					matrix[size-1-x][size-1-y] = matrix[y][size-1-x];
					matrix[y][size-1-x] = temp;
				}
			}
			--numRotation;
		}
	}
	
	private void reflectX() {
		for (int i = 0, row = size-1; i < size/2; ++i, --row) {
			for (int j = 0; j < size; ++j) {
				int temp = matrix[row][j];
				matrix[row][j] = matrix[i][j];
				matrix[i][j] = temp;
			}
		}
	}
	
	private  void reflectY() {
		for (int i = 0; i < size; i++) {
			for (int j = 0, col = size-1; j < size/2; ++j, --col) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][col];
				matrix[i][col]= temp;
			}
		}
	}
	
	// To determine which operation to perform
	public void operate(String operation, String type) {
		int degree=0;
		
		if (type.length() > 1) {
			//change from string to int
			degree = Integer.parseInt(type);
			rotate(degree);
		}
		else if (type.equals("x")) 
			reflectX();
		else
			reflectY();
	}
	
	// String representation of matrix
	public String toString() {
		String output="";
		
		for (int i=0; i<size; ++i) {
			for (int j=0; j<size; ++j) {
				if (j>0) 
					output += " ";
				output += matrix[i][j];
			}
			output += "\n";
		}
		return output;
	}
}

public class Transform {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int size = scanner.nextInt();
		
		Matrix mat = new Matrix(size);
		
		for (int i=0; i<size; ++i) {
			for (int j = 0; j < size; ++j) 
				mat.matrix[i][j] = scanner.nextInt();
		}
		int numOperations = scanner.nextInt();
		
		while (numOperations > 0) {
			String operation = scanner.next();
			String type = scanner.next();
			mat.operate(operation, type);
			numOperations--;
		}
		
		System.out.printf("%s", mat.toString());
	}

}
