import java.lang.*;
import java.util.*;

class Digit {
	//Data Attributes
	private int digit;
	private Digit next;
	
	//Constructors
	public Digit() {
		digit=0;
		next=null;
	}
	
	public Digit(int digit, Digit next) {
		this.digit = digit;
		this.next = next;
	}
	
	//Methods
	public void setDigit(int digit) {this.digit = digit;}
	public void setNext(Digit next) {this.next = next;}
	
	//Accessors
	public int getDigit() {return digit;}
	public Digit getNext() {return next;}
}

class BigNumber {
	private Digit head = null;
	private int length = 0;
	
	//Constructors
	public BigNumber() {}
	
	public BigNumber(String number) {
		for (int i=0; i<number.length(); ++i) {
			Digit newDigit = new Digit(Character.getNumericValue(number.charAt(i)), null);
			
			if (length==0) head = newDigit;
			else {
				newDigit.setNext(head);
				head = newDigit;
			}
			length++;
		}
	}
	
	//Methods
	public static String addition(int shortest, BigNumber longNum, BigNumber shortNum) {
		Digit n1_head = longNum.getHead();
		Digit n2_head = shortNum.getHead();
		
		for (int i=0; i<shortest; ++i, n1_head = n1_head.getNext(), n2_head = n2_head.getNext()) 
			n1_head.setDigit(n1_head.getDigit() + n2_head.getDigit());
		
		n1_head = longNum.getHead();
		for (int i=0; i<longNum.getLength()-1; ++i, n1_head = n1_head.getNext()) {
			if (n1_head.getDigit() >= 10) {
				
				if (n1_head.getNext() == null) {
					Digit newDigit = new Digit();
					n1_head.setNext(newDigit);
				}
				n1_head.getNext().setDigit((n1_head.getDigit() / 10) + n1_head.getNext().getDigit());
				n1_head.setDigit(n1_head.getDigit() % 10);
			}
		}
		return longNum.toString();
	}
	
	public static String sum(BigNumber n1, BigNumber n2) {
		
		if (n1.length > n2.length) {return addition(n2.length, n1, n2);}
		else {return addition(n1.length, n2, n1);}
	}
	
	public String toString() {
		String output = new String();
		for (int i=0; i<length; ++i, head = head.getNext()) 
			output = (head.getDigit() + "") + output;
		
		if (output.startsWith("0") && output.length() != 1)
			return output.substring(1);
		return output;
	}
	
	//Accessors
	public Digit getHead() {return head;}
	public int getLength() {return length;}
}

class BigNumbers {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int numOperations = scanner.nextInt();
		
		while (numOperations > 0) {
			BigNumber n1 = new BigNumber(scanner.next());
			BigNumber n2 = new BigNumber(scanner.next());
			System.out.println(BigNumber.sum(n1, n2));
			numOperations--;
		}
	}

}
