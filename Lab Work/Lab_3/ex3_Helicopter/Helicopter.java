import java.lang.*;
import java.util.*;

class Helipad {
	private String heliName;
	private int padNum;
	private Helipad next;
	
	/*Constructor*/
	public Helipad(int padNum, Helipad next) {
		heliName = "empty";
		this.padNum = padNum;
		this.next = next;
	}
	
	public Helipad(int padNum) {
		heliName = "empty";
		this.padNum = padNum;
	}
	
	/*Methods*/
	public void arrive(String heliName) {
		this.heliName = heliName;
	}
	
	public void depart() {
		heliName = "empty";
	}
	
	public void setNext(Helipad next) {this.next = next;}
	
	/*Getters*/
	public boolean isAval() {return heliName.equals("empty");}
	public int getPadNum() {return padNum;}
	public Helipad getNext() {return next;}
	public String getHeliName() {return heliName;}
}

class Field {
	private Helipad head = null;
	private int numPad = 0;
	
	/*Constructor*/
	public Field() {}
	
	public Field(int numPad) {
		this.numPad = numPad;
		
		for (int i = 0; i < numPad; i++) {
			if (head==null) {
				Helipad newPad = new Helipad(i);
				head = newPad;
				newPad.setNext(head);
			}
			else {
				Helipad newPad = new Helipad(i, head.getNext());
				head.setNext(newPad);
				head = newPad;
			}
		}
	}
	
	/*Methods*/
	public void search(int padNum) {
		while (true) {
			if (head.getPadNum() == padNum)
				break;
			head = head.getNext();
		}
	}
	
	public void searchAval(String heliName, int padNum) {
		search(padNum);
		if (head.isAval()) head.arrive(heliName);
		else {
			for (int i = 0; i < numPad; i++) {
				head = head.getNext();
				if (head.isAval()) {
					head.arrive(heliName);
					break;
				}
			}
		}
		return;
	}
	
	public void departure(int padNum) {
		search(padNum);
		head.depart();
	}
	
	public void print() {
		search(0);
		for (int i = 0; i < numPad; i++, head = head.getNext()) {
			if (head.isAval()) 
				System.out.println("Field " + head.getPadNum() + ": " + head.getHeliName());
			else 
				System.out.println("Field " + head.getPadNum() + ": occupied by helicopter: " + head.getHeliName());
		}
	}
	
	/*Getters*/
	public int getNumPad() {return numPad;}
	public Helipad getHead() {return head;}
	
}
public class Helicopter {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int N = scanner.nextInt();
		Field airField = new Field(N);
		String operation, heliName;
		int padNum;
		
		while (true) {
			operation = scanner.next();
			
			if (operation.equals("END")) break;
			else if (operation.equals("Incoming")) {
				heliName = scanner.next();
				padNum = scanner.nextInt();
				airField.searchAval(heliName, padNum);
			}
			else {
				padNum = scanner.nextInt();
				airField.departure(padNum);
			}
		}
		airField.print();
	}

}
