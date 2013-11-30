/*  
 * CS1020 (AY2012/3 Sem2)  
 * Lab #3 Ex3  
 * Author    :   
 * Matric no.:   
 * Description of program: (fill in the description below)  
 */ 
import java.util.*;

class ListNode {
	private int id; //id of field
	private String helicopterName; //name of parking helicopter
	private ListNode next; //next field
					
	//constructors
	public ListNode() {}	
	public ListNode(int id) { 
		this.id = id;
		this.helicopterName = "";
	}
							
	public ListNode(int id, String planeName){
		this.id = id;
		this.helicopterName = planeName;
	}
								
	
	// add getters and setters 
	
	// feel free to add other private/public methods if appropriate
}

class ControlTower {
	private int numFields; //the number of fields 
	private ListNode[] fields; //a list of all field objects
				
	// constructors
	ControlTower() {}
	ControlTower(int num) {
	}
						
	//PRE-CONDITION:
	//POST-CONDITION:
	public void helicopterOutgoing(int idx) {
	}
							
	//PRE-CONDITION:
	//POST-CONDITION:
	public void helicopterIncoming(String helicopterId, int dest) {
	}
	
	//Feel free to add in other public/private methods if appropriate
}

class Helicopter {
		
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	}

}

