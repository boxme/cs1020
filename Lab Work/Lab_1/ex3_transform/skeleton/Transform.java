/*
 * CS1020 (AY2012/3 Sem2)
 * Lab #1 Ex3
 * Author    : 
 * Matric no.: 
 * Description of program: 
 */
import java.util.*;

class Matrix {

	// Data attributes
	int size;
	int matrix[][];

	// Constructors
	// Default constructor creates a 1x1 matrix
	public Matrix() {
		this(1);
	}

	public Matrix(int size) {
		this.size = size;
		this.matrix = new int[size][size];
	}
	
	// Write a description for this method
	private void rotate(int degree) {

	}
	
	// Write a description for this method
	private void reflectX() {

	}
	
	// Write a description for this method
	private void reflectY() {

	}
	
	// To determine which operation to perform  based on the operation and type parameters
	public void operate(String operation, String type) {

	}

	// String representation of matric
	public String toString() {
		String output = "";

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (j > 0)
					output += " ";
				output += matrix[i][j];
			}
			output += "\n";
		}
		return output;
	}
}

class Transform {

	public static void main(String[] args) {
		// Declare a Scanner object to read input


		// Declare the necessary variables
		Matrix result = ...


		// Read input and process them accordingly


		// Output the result
		// Stick to this statement to ensure that your output is 
		// in the right format; the following call makes use of
		// the toString() method of Matrix class implicitly
		System.out.print(result);
	}
}

