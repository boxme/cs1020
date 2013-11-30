/*  
 * CS1020 (AY2012/3 Sem2)  
 * Lab #5 Ex2  
 * Author    : 
 * Matric no.:  
 * Description of program: (fill in the description below)
 *
 */
import java.util.*;

public class CandyCrush {

    public static void main(String[] args) {
	
		//scan in the candy map and create a map with the input number of rows, columns and target
        			
	
		// take in the number of moves as well as initialise variables for the moves
        int numMoves = sc.nextInt();
        int row1;
        int col1;
        int row2;
        int col2;
		
		//performs the moves and calls on the appropriate methods to update the map
        for (int i = 0; i < numMoves; i++) {
            row1 = sc.nextInt();
            col1 = sc.nextInt();
            row2 = sc.nextInt();
            col2 = sc.nextInt();
            ccl.swapTwoCandies(row1, col1, row2, col2);            
            if(ccl.horiThreeInARow(row1, col1) || ccl.vertThreeInARow(row1, col1)) {                
                ccl.markCrushedCandies(row1, col1);
            }
            if(ccl.horiThreeInARow(row2, col2) || ccl.vertThreeInARow(row2, col2)) {                
                ccl.markCrushedCandies(row2, col2);
            }
            int numCrushed = ccl.removeCrushedCandies();
            while (numCrushed != 0) {
                ccl.scanMap();
                numCrushed = ccl.removeCrushedCandies();
            }
        }
		
		//print your output here
        
    }
   
}

class CandyCrushLevel {

    private int target;
    private int numRows;
    private int numCols;
    private char[][] map;

    //constructors
    public CandyCrushLevel() {};
    
    
    public CandyCrushLevel(int numRows, int numCols, char[][] map, int target) {
        this.map = new char[numRows][numCols];
        this.numRows = numRows;
        this.numCols = numCols;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                this.map[i][j] = map[i][j];
            }
        }
        this.target = target;
    }

    //method that swaps the position of two candies: candy at row1, col1 and candy at row2, col2
    public void swapTwoCandies(int row1, int col1, int row2, int col2) {
        char temp = map[row1][col1];
        map[row1][col1] = map[row2][col2];
        map[row2][col2] = temp;
    }

    //this method scans the map of candies calls upon the markCrushedCandies method to mark candies which are in a row of 3 or more if there are any
    public void scanMap() {
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (map[i][j] != '0' && map[i][j] != '-' && (horiThreeInARow(i, j) || vertThreeInARow(i, j))) {
                    markCrushedCandies(i, j);
                }
            }
        }
    }

    //this method takes in the position of a single candy that belongs in a row of 3 or more and calls upon other methods to mark the candies in the same row
    // of 3 or more as '0'
    //pre-cond: position of candy that is passed in MUST belong in a row of 3 or more
    public void markCrushedCandies(int row, int col) {

        if (horiThreeInARow(row, col)) {
            //case 1: candy on left side is the same        
            if (col > 0 && map[row][col - 1] == map[row][col]) {                
                markLeftCandies(row, col - 1);
            }
            //case 2: candy on right side is the same
            if (col < numCols - 1 && map[row][col + 1] == map[row][col]) {                
                markRightCandies(row, col + 1);
            }
        }
        if (vertThreeInARow(row, col)) {
            //case 3: candy on top is the same
            if (row > 0 && map[row - 1][col] == map[row][col]) {                
                markTopCandies(row - 1, col);
            }
            //case 4: candy below is the same
            if (row < numRows - 1 && map[row + 1][col] == map[row][col]) {                
                markBottomCandies(row + 1, col);
            }
        }

        map[row][col] = '0';
    }    

   //this method recursively searches to the left of a candy for candies that belong to the same row of 3 or more and marks them as '0'
    public void markLeftCandies(int row, int col) {
        //fill in your method here
    }

    //this method recursively searches to the right of a candy for candies that belong to the same row of 3 or more and marks them as '0'
    public void markRightCandies(int row, int col) {
        //fill in your method here
    }

    //this method recursively searches to the top of a candy for candies that belong to the same row of 3 or more and marks them as '0'
    public void markTopCandies(int row, int col) {
        //fill in your method here
    }

    //this method recursively searches to the bottom of a candy for candies that belong to the same row of 3 or more and marks them as '0'
    public void markBottomCandies(int row, int col) {
		//fill in your method here
    }

    //this method takes in the position of a candy and returns true if the candy belongs in a horizontal row of 3 or more candies which are the same
    public boolean horiThreeInARow(int row, int col) {
        //case1: 2 of the same candies to the left
        if (col >= 2 && map[row][col] == map[row][col - 1] && map[row][col] == map[row][col - 2]) {
            return true;
        } //case2: 2 of the same candies to the right
        else if (col <= numCols - 3 && map[row][col] == map[row][col + 1] && map[row][col] == map[row][col + 2]) {
            return true;
        } //case 3: at least 1 each of the same candies to the right and left
        else if (col >= 1 && col <= numCols - 2 && map[row][col] == map[row][col - 1] && map[row][col] == map[row][col + 1]) {
            return true;
        }

        return false;
    }

    //this method takes in the position of a candy and returns true if the candy belongs in a vertical row of 3 or more candies which are the same
    public boolean vertThreeInARow(int row, int col) {
        //case1: 2 of the same candies to the top
        if (row >= 2 && map[row][col] == map[row - 1][col] && map[row][col] == map[row - 2][col]) {
            return true;
        } //case2: 2 of the same candies to the bottom
        else if (row <= numRows - 3 && map[row][col] == map[row + 1][col] && map[row][col] == map[row + 2][col]) {
            return true;
        } //case 3: at least 1 each of the same candies to the top and bottom
        else if (row >= 1 && row <= numRows - 2 && map[row][col] == map[row - 1][col] && map[row][col] == map[row + 1][col]) {
            return true;
        }

        return false;
    }

    //this method removes all candies that are marked as '0', meaning they are crushed and calls upon the shiftCandiesDown method
    //to shift the candies that were unaffected down.
    public int removeCrushedCandies() {
        int numCrushed = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (map[i][j] == '0') {                                        
                    this.shiftCandiesDown(i, j);                                        
                    numCrushed++;
                }
            }
        }        
        target = target - numCrushed;
        return numCrushed;
    }

    //shifts the candies in a column down, removing the candy that was crushed, empty spaces are denoted by a '-'
    public void shiftCandiesDown(int row, int col) {
        for (int i = row; i > 0; i--) {
            if (map[i][col] == '-') {                
                break;
            }            
            map[i][col] = map[i - 1][col];            
        }
        map[0][col] = '-';        
    }

    //prints the current state of the candy crush map
    public void printMap() {
	//this is a stub
    }

}
