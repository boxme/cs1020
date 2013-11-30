import java.lang.*;
import java.util.*;

class Coordinate {
	private int row, col;
	
	//Constructor
	public Coordinate() {}
	
	public Coordinate(int row, int col) {
		this.row = row;
		this.col = col;
	}
	
	//Getters
	public int getRow() {return row;}
	public int getCol() {return col;}
}

class Maze {
	private int[][] map;
	private int numSteps;
	private int size;
	private Stack<Coordinate> stack;
	private Queue<Coordinate> path;
	
	//Constructor
	public Maze(int size, int[][] map) {
		this.size = size;
		this.map = new int[size][size];
		this.map = map;
		numSteps = 400;
		stack = new Stack<Coordinate>();
		path = new LinkedList<Coordinate>();
		
		stack.push(new Coordinate(1, 0));
	}
	
	//Methods
	//Find the shortest path to the exit
	public void findExit(int steps) {
		int i = stack.peek().getRow();
		int j = stack.peek().getCol();
		map[i][j] = 1;
		
		if (!bottom(i, j) && !right(i, j) && !up(i, j) && !left(i, j)) {
			if (exitFound()) {
				if (steps < numSteps) {
					numSteps = steps;
					copyPath();
				}
			}
			stack.pop();
			return;
		}

		if (exitFound()) {
			if (steps < numSteps) {
				numSteps = steps;
				copyPath();
			}
			stack.pop();
			return;
		}
		else {
			//Go down
			if (bottom(i, j)) {
				stack.push(new Coordinate(i+1, j));
				findExit(steps+1);
			}
			//Go right
			if (right(i, j)) {
				stack.push(new Coordinate(i, j+1));
				findExit(steps+1);
			}
			//Go up
			if (up(i, j)) {
				stack.push(new Coordinate(i-1, j));
				findExit(steps+1);
			}
			//Go left
			if (left(i, j)) {
				stack.push(new Coordinate(i, j-1));
				findExit(steps+1);
			}
			
			//Explored all the possible directions
			stack.pop();
		}
		
		if (stack.empty()) return;
	}
	
	//Remember the shortest path
	public void copyPath() {
		Iterator<Coordinate> iter = stack.iterator();

		if (!path.isEmpty())
			path.clear();
		
		while (iter.hasNext())
			path.offer(iter.next());
	}
	
	//Found exit return true 
	public boolean exitFound() {
		if (stack.peek().getCol() == size-1 || stack.peek().getRow() == 0 || stack.peek().getRow() == size-1)
			return true;
		return false;
	}
	
	//Check bottom for path
	public boolean bottom(int row, int col) {
		if (row == size-1 || map[row+1][col] != 0) 
			return false;
		return true;
	}
	
	//Check right for path
	public boolean right(int row, int col) {
		if (col == size-1 || map[row][col+1] != 0) 
			return false;
		return true;
	}
	
	//Check up for path
	public boolean up(int row, int col) {
		if (row == 0 || map[row-1][col] != 0) 
			return false;
		return true;
	}
	
	//Check left for path
	public boolean left(int row, int col) {
		if (col == 0 || map[row][col-1] != 0) 
			return false;
		return true;
	}
	
	//Getters
	public int getSteps() {return numSteps;}
	public void getPath() {
		Iterator<Coordinate> iter = path.iterator();
		
		while (iter.hasNext()) {
			Coordinate temp = iter.next();
			System.out.println("(" + temp.getRow() + ", " + temp.getCol() + ")");
		}
	}
}
public class ShortestPath {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int size = scanner.nextInt();
		int[][] map = new int[size][size];
		
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) 
				map[i][j] = scanner.nextInt();
		}
		
		Maze maze = new Maze(size, map);
		maze.findExit(1);
		
		System.out.println("The shortest path is " + maze.getSteps() + " steps:");
		maze.getPath();
	}

}
