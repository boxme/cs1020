/*  
 * CS1020 (AY2012/3 Sem2)  
 * Lab #5 Ex1  
 * Author    : 
 * Matric no.:  
 * Description of program: (fill in the description below)
 *
 */
import java.util.*;
import java.awt.Point;

class ShortestPath {
	public static void main(String[] args) {
		int[][] maze;
		Scanner sc = new Scanner(System.in);
		
		//Take in inputs
		int N = sc.nextInt();
		maze = new int[N][N];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maze[i][j] = sc.nextInt();
			}
		}

		// Starting location is at maze[1][0];
		Stack<Point> shortestPath = pathfinder(/*Fill in parameters*/);

		System.out.println("The shortest path is " + shortestPath.size() + " steps:");

		// Print out the path
		System.out.println(); // This is a stub
	}
	
	//Recursive function
	public static Stack<Point> pathfinder(/*Fill in parameters*/) {

		//Declare variables
		Stack<Point> shortestPath = new Stack<Point>();

		// Mark Step as Visited
		/* Fill in code */

		// Add step to Path
		/* Fill in code */

		// Base Case: Reached Maze's Exit
		/* Fill in code */

		// Case 1: Move UP
		/* Fill in code */

		// Case 2: Move RIGHT
		/* Fill in code */

		// Case 3: Move DOWN
		/* Fill in code */

		// Case 4: Move LEFT
		/* Fill in code */

		return null; // This is a stub
	}
}
