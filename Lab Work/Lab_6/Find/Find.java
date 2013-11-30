import java.util.*;

class HashTable {
	private final int SIZE = 1009;
	private String[] table;
	
	/*Constructor*/
	public HashTable() {
		table = new String[SIZE];
	}
	
	/*Methods*/
	public int hashFunction(String data) {
		int sum = 0;
		for (int i = 0; i < data.length(); i++) {
			sum = sum*31 + data.charAt(i);
			sum %= SIZE;
		}
		return sum % SIZE;
	}
	
	public void insert(String data, int subStringLength) {
		for (int i = 0; i < data.length() - (subStringLength-1); i++) {
			String subString = data.substring(i, i+subStringLength);
			int key = hashFunction(subString);
			int j = 1;
			while (table[key] != null && !table[key].equals(subString)) {
				key = (key + (2*j-1)) % SIZE;
				++j;
			}
			table[key] = subString;
		}
	}
	
	public boolean query(String subString) {
		int key = hashFunction(subString);
		if (table[key] != null && table[key].equals(subString))
			return true;
		
		int j = 1;
		while (table[key] != null) {
			key = (key + (2*j-1)) % SIZE;
			++j;
			if (table[key].equals(subString)) 
				return true;
		}
		return false;
	}
	
}
public class Find {

	public static void main(String[] args) {
		HashTable hashTable_1 = new HashTable();
		HashTable hashTable_2 = new HashTable();
		int dataLength, subStringLength, Q;
		String data_1, data_2, subString;
		Scanner scanner = new Scanner(System.in);
		
		dataLength = scanner.nextInt();
		subStringLength = scanner.nextInt();
		data_1 = scanner.next();
		data_2 = scanner.next();
		Q = scanner.nextInt();
		
		/*Insert into hashtable*/
		hashTable_1.insert(data_1, subStringLength);
		hashTable_2.insert(data_2, subStringLength);
		
		/*Query*/
		while (Q>0) {
			subString = scanner.next();
			int output = 0;
			
			if (hashTable_1.query(subString)) 
				output += 1;
			if (hashTable_2.query(subString))
				output += 2;
			
			System.out.println(output);
			--Q;
		}
		
		scanner.close();
	}

}
