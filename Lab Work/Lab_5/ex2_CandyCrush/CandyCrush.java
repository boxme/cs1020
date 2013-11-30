import java.util.*;

class Level {
	private int target;
	private int numRows;
	private int numCols;
	private char[][] map;
	
	//Constructor
	public Level(int numRows, int numCols, int target, char[][] map) {
		this.numRows = numRows;
		this.numCols = numCols;
		this.target = target;
		this.map = new char[numRows][numCols];
		
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) 
				this.map[i][j] = map[i][j];
		}
	}
	
	//Methods
	//Swap
	public void swapCandy(int row1, int col1, int row2, int col2) {
		char temp = map[row1][col1];
		map[row1][col1] = map[row2][col2];
		map[row2][col2] = temp;
	}
	
	//Scan the map for the same type of candies in 3 or more in sequence
	public void scanMap() {
		Boolean exit = true;
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (map[i][j] != '0' && map[i][j] != '-' && (horiCheck(i, j) || VertiCheck(i, j))) {
					markCandy(i, j);
					exit = false;
				}
			}
		}
		removeCrushedCandy();
		
		if (exit) return;
		else scanMap();
	}
	
	//Mark candies of the same type in 3 or more in sequence
	public void markCandy(int row, int col) {
		//Mark in the row
		if (horiCheck(row, col)) {
			//On the left
			if (col >= 1 && map[row][col-1] == map[row][col])
				markLeft(row, col-1);
			//On the right
			if (col <= numCols-2 && map[row][col+1] == map[row][col])
				markRight(row, col+1);
		}
		//Mark in the col
		if (VertiCheck(row, col)) {
			//On the top
			if (row >= 1 && map[row-1][col] == map[row][col]) 
				markTop(row, col);
			//On the bottom
			if (row <= numRows-2 && map[row+1][col] == map[row][col])
				markBottom(row, col);
		}
		map[row][col] = '0';
	}
	
	//Check for any candies of the same type in 3 or more in a row
	public boolean horiCheck(int row, int col) {
		//2 on left
		if (col >= 2 && map[row][col-1] == map[row][col] && map[row][col-2] == map[row][col])
			return true;
		//2 on right
		else if(col <= numCols-3 && map[row][col+1] == map[row][col] && map[row][col+2] == map[row][col])
			return true;
		//1 each on left and right
		else if(col >= 1 && col <= numCols-2 && map[row][col+1] == map[row][col] && map[row][col-1] == map[row][col])
			return true;
		else
			return false;
	}
	
	//Check for any candies of the same type in 3 or more in a col
	public boolean VertiCheck(int row, int col) {
		//2 on top
		if (row >= 2 && map[row-1][col] == map[row][col] && map[row-2][col] == map[row][col])
			return true;
		//2 on bottom
		else if(row <= numRows-3 && map[row+1][col] == map[row][col] && map[row+2][col] == map[row][col])
			return true;
		//1 each on top and bottom
		else if(row >= 1 && row <= numRows-2 && map[row+1][col] == map[row][col] && map[row-1][col] == map[row][col])
			return true;
		else
			return false;
	}
	
	//Recursively mark the same candy type if they are 3 or more in a row to the left
	public void markLeft(int row, int col) {
		if (col==0 || map[row][col-1] != map[row][col]) {
			map[row][col] = '0';
			return;
		}
		else {
			map[row][col]= '0';
			markLeft(row, col-1);
		}
	}
	
	//Recursively mark the same candy type if they are 3 or more in a row to the right
	public void markRight(int row, int col) {
		if (col==numCols-1 || map[row][col+1] != map[row][col]) {
			map[row][col] = '0';
			return;
		}
		else {
			map[row][col]= '0';
			markRight(row, col+1);
		}
	}
	
	//Recursively mark the same candy type if they are 3 or more in a row to the top
	public void markTop(int row, int col) {
		if (row==0 || map[row-1][col] != map[row][col]) {
			map[row][col] = '0';
			return;
		}
		else {
			map[row][col]= '0';
			markTop(row-1, col);
		}
	}
	
	//Recursively mark the same candy type if they are 3 or more in a row to the bottom
	public void markBottom(int row, int col) {
		if (row==numRows-1 || map[row+1][col] != map[row][col]) {
			map[row][col] = '0';
			return;
		}
		else {
			map[row][col]= '0';
			markBottom(row+1, col);
		}
	}
	
	//Crash candies which are marked
	public void removeCrushedCandy() {
		int numCrushed = 0;
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (map[i][j] == '0') {
					moveRow(i, j);
					numCrushed++;
				}
			}
		}
		target -= numCrushed;
	}
	
	//Move the affected row down if candies are crashed
	public void moveRow(int row, int col) {
		for (int i = row; i > 0; i--) {
			if (map[i][col] == '-')
				break;
			map[i][col] = map[i-1][col];
		}
		map[0][col] = '-';
	}
	
	//Print current map
	public void printMap() {
    	for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) 
				System.out.print(map[i][j]);
	    	System.out.println();
		}
    }
	
	//Getter
	public int getTarget() {return target;}
}

public class CandyCrush {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numRows, numCols, target, numMoves;
		int row1, col1, row2, col2;
		String input;
		
		numRows = scanner.nextInt();
		numCols = scanner.nextInt();
		
		char[][]map = new char[numRows][numCols];
		for (int i = 0; i < numRows; i++) {
			input = scanner.next();
			for (int j = 0; j < numCols; j++) {
				map[i][j] = input.charAt(j);
			}
		}
		
		target = scanner.nextInt();
		numMoves = scanner.nextInt();
		Level level1020 = new Level(numRows, numCols, target, map);

		while (numMoves > 0) {
			row1 = scanner.nextInt();
			col1 = scanner.nextInt();
			row2 = scanner.nextInt();
			col2 = scanner.nextInt();
			
			level1020.swapCandy(row1, col1, row2, col2);
			level1020.scanMap();
			--numMoves;
		}
		
		level1020.printMap();
		if (level1020.getTarget() <= 0) 
			System.out.println("Level 1020 Cleared!");
		else
			System.out.println("Level 1020 Not Cleared!");
	}

}
