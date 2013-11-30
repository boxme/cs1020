import java.lang.*;
import java.util.*;

class Ruler {
	int[] pos;
	int numSegs;
	int[] contains;
	
	public Ruler(int rulerLength, int N, int[] mark) {
		Arrays.sort(mark);
		numSegs = N+1;
		pos = new int[numSegs+1];
		contains = new int[numSegs];
		
		for (int i = 0; i < pos.length; i++) {
			if (i == 0) pos[i] = 0;
			else if (i == pos.length - 1) pos[i]= rulerLength;
			else pos[i] = mark[i-1]; 
		}
		
		for (int i = 0; i < contains.length; ++i)
			contains[i] = 1;
	}
	
	public int newMarking(int numNewMarks) {
		int longestSegment;
		double longestLength;
		
		while (numNewMarks > 0) {
			longestLength=0.0; longestSegment=0;
			
			for (int i = 1; i < pos.length; i++) {
				if ((((double) pos[i] - (double) pos[i-1]) / (double) contains[i-1]) > longestLength) {
					longestLength = ((double) pos[i] - (double) pos[i-1]) / contains[i-1] ;
					longestSegment = i-1;
				}		
			}
			contains[longestSegment] += 1;
			--numNewMarks;
		}
		longestLength = 0.0;
		for (int i = 1; i < pos.length; i++) {
			if ((((double) pos[i] - (double) pos[i-1]) / contains[i-1]) > longestLength) 
				longestLength = ((double) pos[i] - (double) pos[i-1]) / contains[i-1];
		}
		
		//Round up to the nearest whole number
		longestLength = Math.round(longestLength);
		return (int)longestLength; //type casting
	}
	
}
public class MakerRuler {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rulerLength, N, numNewMarks, longestLength;
		int[] mark;
		
		rulerLength = scanner.nextInt();
		N = scanner.nextInt();
		mark = new int[N];
		
		for (int i = 0; i < mark.length; i++) 
			mark[i]= scanner.nextInt(); 
		
		Ruler ruler = new Ruler(rulerLength, N, mark);
		numNewMarks = scanner.nextInt();
		
		longestLength = ruler.newMarking(numNewMarks);
		System.out.printf("%d\n", longestLength);
		scanner.close();
	}

}
