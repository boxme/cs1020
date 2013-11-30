import java.lang.*;
import java.util.*;

public class KnapSack {

	public static int choose(int[] array, int index, int capacity) {
		if (index == array.length) {
			return 1;
		}
		else {
			if (array[index] <= capacity) {
				return choose(array, index+1, capacity) + choose(array, index+1, capacity-array[index]);
			}else {
				return choose(array, index+1, capacity);
			}
		}
	}
	public static void main(String[] args) {
		int index=0, capacity=6;
		int[] array = {3, 1, 6, 4, 5};
		System.out.println(choose(array, index, capacity));
	}

}
