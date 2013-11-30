import java.lang.*;
import java.util.*;

public class AlternateList {
	
	public static void move(List<Integer> linkList, int index, int size) {
		List<Integer> tempList = new LinkedList<Integer>();
		
		for (int i = 0; i < size; ++i) {
			tempList.add(linkList.get(index-1));
			linkList.remove(index-1);
		}
		linkList.addAll(tempList);
	}
	
	public static void rm(List<Integer> linkList, int index, int size) {
		for (int i = 0; i < size; ++i)
			linkList.remove(index-1);
	}
	
	public static void addValue(List<Integer> linkList, int index, int size, int value) {
		List<Integer> tempList = new LinkedList<Integer>();
		
		for (int i = 0; i < size; ++i) {
			tempList.add(linkList.get(index-1) + value);
			linkList.remove(index-1);
		}
		linkList.addAll(index-1, tempList);
	}
	
	public static boolean isAlternate(List<Integer> linkList) {
		if (linkList.size() == 1 || linkList.isEmpty()) return true;
		
		for (int i=0; i < linkList.size()-1; ++i) {
			if (linkList.get(i) > 0 && linkList.get(i+1) > 0) return false;
			else if (linkList.get(i) < 0 && linkList.get(i+1) < 0) return false;
		}
		return true;
	}
	
	public static void print(List<Integer> linkList) {
		for (int i=0; i<linkList.size(); ++i) 
			System.out.printf("%d ", linkList.get(i));
		System.out.println();
	}
	
	public static void main(String[] args) {
//		List<Integer> linkList = new LinkedList<Integer>(Arrays.asList(1, -3, -5, 6, 10));
		Scanner scanner = new Scanner(System.in);
		
		List<Integer> linkList = new LinkedList<Integer>();
		int N, Q;
		N = scanner.nextInt();
		Q = scanner.nextInt();
		
		for (int i=0; i<N; ++i)
			linkList.add(scanner.nextInt());
		
		String operation = new String();
		int index, size, value;
		
		while (Q>0) {
			operation = scanner.next();
			switch (operation) {
			case "M": 
				index = scanner.nextInt();
				size = scanner.nextInt();
				move(linkList, index, size);
				if (isAlternate(linkList)) System.out.println("YES");
				else System.out.println("NO");
				break;

			case "R":
				index = scanner.nextInt();
				size = scanner.nextInt();
				rm(linkList, index, size);
				if (isAlternate(linkList)) System.out.println("YES");
				else System.out.println("NO");
				break;
			
			case "A":
				index = scanner.nextInt();
				size = scanner.nextInt();
				value = scanner.nextInt();
				addValue(linkList, index, size, value);
				if (isAlternate(linkList)) System.out.println("YES");
				else System.out.println("NO");
				break;
			}
			--Q;
		}
		
	}

}
