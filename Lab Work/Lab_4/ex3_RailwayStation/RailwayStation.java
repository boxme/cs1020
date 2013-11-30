import java.util.*;
import java.lang.*;

class TrainStation{
	private Stack<Integer> S;
	
	public TrainStation(){
		S = new Stack<Integer>();
	}

	//do input and output
	public void solve(Scanner sc, int numCoaches){
		Queue<Integer> A = new LinkedList<Integer>();
		Queue<Integer> B = new LinkedList<Integer>();
		int perm = sc.nextInt();
		
		while (perm > 0) {
			A.clear(); B.clear(); S.clear();
			
			for (int i = 1; i <= numCoaches; i++) {
				A.offer(i); B.offer(sc.nextInt());
			}
			
			if (check(A, B)) System.out.println("Yes");
			else System.out.println("No");
			perm--;
		}
	}

	//to check whether the permutation is possible
	public boolean check(Queue<Integer> A, Queue<Integer> B){
		while (!A.isEmpty()) {
			
			if (S.empty()) {S.push(A.poll());}
			
			while (!S.empty() && S.peek() != B.peek()) {
				S.push(A.poll());
			}
			
			while (!S.empty() && S.peek() == B.peek()) {
				S.pop(); B.poll();
			}
		}
		if (!S.empty()) 
			return false;
		return true;
	}
}

class RailwayStation{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		TrainStation station = new TrainStation();
		
		int numCoaches = sc.nextInt();
		
		while (numCoaches != 0) {
			station.solve(sc, numCoaches);
			numCoaches = sc.nextInt();
		}
	}
}