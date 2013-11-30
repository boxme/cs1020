/*  
 * CS1020 (AY2012/3 Sem2)  
 * Lab #3 Ex2  
 * Author    :   
 * Matric no.:   
 * Description of program: (fill in the description below)  
 */ 
import java.util.*;

class Digit {

	// Data attributes
	private int digit;
	private Digit next;

	// Constructors
	// This default constructor has an empty body
	public Digit(){    
	}

	public Digit(int digit, Digit next) {
		this.digit = digit;
		this.next = next;
	}

	// Accessors
	public int getDigit() {
		return digit;
	}

	public Digit getNext() {
		return next;
	}
	
	public void setDigit(int digit) {
		this.digit = digit;
	}
	
	public void setNext(Digit next) {
		this.next = next;
	}
}

class BigNumber {
	private Digit head = null;
	private int length = 0;

	// Constructors
	// This default constructor has an empty body	
	public BigNumber() {
	}

	// Build a linked list of digits
	public BigNumber(String number) {
		// Fill in

	}
	
	// Accessors
	public Digit getHead() {
		return head;
	}

	public int getLength() {
		return length;
	}

	// Append a digit to the linked list
	public void add(int digit) {
		// Fill in

	}
	
	// Sum two big numbers and return its sum
	public static String sum(BigNumber n1, BigNumber n2) {
		// Fill in

		return ""; // this is a stub
	}
	
	public String toString() {
		// Fill in

		return ""; // this is a stub
	}

	// You may add in other method(s) if you wish

}

// This is the driver class
class BigNumbers {

	public static void main(String[] args) {
		// Declare a Scanner object to read input

		// Declare the necessary variables

		// Read input and process them accordingly

		// Output the result
		// Ensure your output is in the right format
	}
}
