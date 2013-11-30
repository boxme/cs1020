import java.lang.*;
import java.util.*;

public class Stick {

	public static int minSticks(int[] sticks, int length, int index, int numSticks) {
		if (index == sticks.length ) {
			if (length == 0) return numSticks;
			else return -1;
		} else {
			int num1 = -1;
			int num2 = -1;
			if (sticks[index] <= length) {
				num1 = minSticks(sticks, length-sticks[index], index+1, numSticks+1);
				num2 = minSticks(sticks, length, index+1, numSticks);
			}else {
				num1 = minSticks(sticks, length, index+1, numSticks);
			}
			
			if (num1 == num2) return num1;
			else if (num1 < 0) return num2;
			else if (num2 < 0) return num1;
			else return Math.min(num1, num2);
		}
		
	}
	public static void main(String[] args) {
		int[] sticks = {1, 1, 1, 1, 1, 3};
		System.out.println(minSticks(sticks, 5, 0, 0));
	}

}
