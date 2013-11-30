import java.util.*;
import java.lang.*;

public class SwingingMonkey {

	public static int count(int[] trees, int size) {
		int jump=0;
		Stack<Integer> stack = new Stack<Integer>();
		
		for (int i = 0; i < size; i++) {
			if (stack.empty()) 
				stack.push(trees[i]);
			else {
				//The order of the if loops matter
				while(!stack.empty() && stack.peek() < trees[i]) {
					jump++;
					stack.pop();
				}
				if (!stack.empty() && stack.peek() == trees[i]) {
					jump++;
					stack.pop();
				}
				if (!stack.empty() && stack.peek() > trees[i]) {
					jump++;
					stack.push(trees[i]);
				}
				if (stack.empty()) 
					stack.push(trees[i]);
			}
		}
		return jump;
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
 		int numTrees;
		numTrees = scanner.nextInt();
		
		int[] trees = new int[numTrees];
		for (int i = 0; i < trees.length; i++) {
			trees[i] = scanner.nextInt();
		}
		
		System.out.println(count(trees, numTrees));
		scanner.close();
	}

}
