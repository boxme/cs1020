import java.util.*;

class Incantation {
	private String word;
	private int occurrence;
	
	/*Constructor*/
	public Incantation(String word) {
		this.word = word;
		occurrence = 1;
	}
	
	/*Methods*/
	public void increaseOccurrence() {
		++occurrence;
	}
	
	public void decreaseOccurrence() {
		--occurrence;
	}
	
	public boolean equals(String word) {
		return this.word.equals(word);
	}
	
	/*Getters*/
	public String getWord() {return word;}
	public int getOccurrence() {return occurrence;}
}

class HashTable {
	private final int SIZE = 2011;
	private Incantation[] table;
	
	/*Constructor*/
	public HashTable() {
		table = new Incantation[SIZE];
	}
	
	/*Methods*/
	public int hashFunction1(String word) {
		int sum = 0;
		for (int i = 0; i < word.length(); i++) {
			sum = sum*31 + word.charAt(i);
			sum %= SIZE;
		}
		return sum % SIZE;
	}
	
	public int hashFunction2(int key) {
		int s = SIZE-1;
		return (key % s) + 1;
	}
	
	public void insert(String word) {
		int key = hashFunction1(word);
		int key2 = hashFunction2(key);
		Incantation newWord = new Incantation(word);
		
		while (table[key] != null) {
			
			if (table[key].equals(word)) {
				table[key].increaseOccurrence();
				return;
			}
			key = (key + key2) % SIZE;
		}
		
		table[key] = newWord;
	}
	
	public int search(String word) {
		int key = hashFunction1(word);
		int key2 = hashFunction2(key);
		
		while (table[key] != null && !table[key].equals(word)) {
			key = (key + key2) % SIZE;
		}
		return table[key].getOccurrence();
	}
	
	public void remove(String word) {
		int key = hashFunction1(word);
		int key2 = hashFunction2(key);
		
		while (table[key] != null && !table[key].equals(word)) {
			key = (key + key2) % SIZE;
		}
		
		table[key].decreaseOccurrence();
	}
}

public class Incantations {
	
	public static int removeFront(LinkedList<String> list, int totalLength, 
								  HashTable table) {
		while (!list.isEmpty() && table.search(list.getFirst()) > 1) {
			table.remove(list.getFirst());
			totalLength -= list.removeFirst().length();
		}
		return totalLength;
	}
	
	public static int removeBack(LinkedList<String> list, int totalLength, 
								 HashTable table) {
		while (!list.isEmpty() && table.search(list.getLast()) > 1) {
			table.remove(list.getLast());
			totalLength -= list.removeLast().length();
		}
		return totalLength;
	}
	
	public static int getMinLength(LinkedList<String> list_1, LinkedList<String> list_2,
								   int totalLength, HashTable table1, HashTable table2) {
		int minLength_1 = totalLength;
		int minLength_2 = totalLength;
		
		/*Remove head first*/
		minLength_1 = removeFront(list_1, minLength_1, table1);
		minLength_1 = removeBack(list_1, minLength_1, table1);
		
		/*Remove back first*/
		minLength_2 = removeBack(list_2, minLength_2, table2);
		minLength_2 = removeFront(list_2, minLength_2, table2);
		
		return Math.min(minLength_1, minLength_2);
	}
	public static void main(String[] args) {
		LinkedList<String> list_1 = new LinkedList<String>();
		LinkedList<String> list_2 = new LinkedList<String>();
		HashTable table1 = new HashTable();
		HashTable table2 = new HashTable();
		int N=0, totalLength = 0;
		Scanner scanner = new Scanner(System.in);
		
		N = scanner.nextInt();
		while (N>0) {
			String word = scanner.next();
			list_1.add(word);
			list_2.add(word);
			table1.insert(word);
			table2.insert(word);
			totalLength += word.length();
			--N;
		}
		
		System.out.println(getMinLength(list_1, list_2, totalLength, table1, table2));
		scanner.close();
	}

}
