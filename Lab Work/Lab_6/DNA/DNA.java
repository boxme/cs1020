import java.util.*;

class HashTable {
	private final int SIZE = 1009;
	private int[] table;
	private double loadFactor;
	
	/*Constructor*/
	public HashTable() {
		table = new int[SIZE];
		loadFactor = 0.0;
	}
	
	/*Methods*/
	public int hashFunction(String data) {
		int sum = 0;
		for (int i = 0; i < data.length(); i++) {
			sum = sum*31 + data.charAt(i);
		}
		return sum % SIZE;
	}
	
	public void insert(String data, int subStringLength) {
		for (int i = 0; i < data.length()-(subStringLength-1); i++) {
			String subString = data.substring(i, i+subStringLength);
			int key = hashFunction(subString);
			table[key] += 1;
			++loadFactor;
		}
	}
	
	public int query(String dna) {
		int key = hashFunction(dna);
		return table[key];
	}
	
	/**/
	public double getLoadFactor() {
		return loadFactor / SIZE;
	}
}
public class DNA {
	
	public static void main(String[] args) {
		HashTable hashTable = new HashTable();
		int dataLength, subStringLength, Q;
		String data, dna;
		Scanner scanner = new Scanner(System.in);
		
		dataLength = scanner.nextInt();
		subStringLength = scanner.nextInt();
		data = scanner.next();
		Q = scanner.nextInt();
		
		/*Insert into the hashtable*/
		hashTable.insert(data, subStringLength);
		
		/*Search the hashtable*/
		while (Q>0) {
			dna = scanner.next();
			System.out.println(hashTable.query(dna));
			--Q;
		}
		scanner.close();
	}

}
