import java.util.*;
import java.lang.*;

//This class represents all orders of customers
class ListOrder {
    
    int numDishes;
    //each dish has a queue of customers who ordered this dish
    private ArrayList<Queue<Integer>> listQueue;
    
    //constructor
    public ListOrder(int numDish) {
    	this.numDishes = numDish;
        listQueue = new ArrayList<Queue<Integer>>();
        
        for (int i = 0; i < numDish; i++) {
        	//Instantiate the Queue object
			listQueue.add(new LinkedList<Integer>());
        }
    }
    
    //add new order to the list
    public void addNewOrder(int tagNum, int dishNum) {
        listQueue.get(dishNum-1).offer(tagNum);
    }
    
    //process food when it is ready
    public int processReadyFood(int dishNum) {
    	if (listQueue.get(dishNum-1).size() == 0) 
    		return 0;
        return listQueue.get(dishNum-1).poll();
    }
}

class QuickEat {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int numDish, numInstructions;
		numDish = scanner.nextInt();
		
		String[] menu = new String[numDish];
		ListOrder list = new ListOrder(numDish);
		
		scanner.nextLine();
		for (int i=0; i<numDish; ++i) {
			menu[i] = scanner.nextLine();
		}
		
		numInstructions = scanner.nextInt();
		
		String operation = new String();
		int tagNum, numOrder, dishNum;
		
		while (numInstructions > 0) {
			operation = scanner.next();
			
			switch (operation) {
			case "Order":
				tagNum = scanner.nextInt();
				numOrder = scanner.nextInt();
				for (int i = 0; i < numOrder; i++) {
					dishNum = scanner.nextInt();
					list.addNewOrder(tagNum, dishNum);
				}
				break;

			case "Ready":
				dishNum = scanner.nextInt();
				int dish = list.processReadyFood(dishNum);
				
				if (dish == 0)
					System.out.println("Throw away " + menu[dishNum-1]);
				else
					System.out.println(menu[dishNum-1] + " ready to be served to Tag "+ dish);
				break;
			}
			numInstructions--;
		}
	}

}
