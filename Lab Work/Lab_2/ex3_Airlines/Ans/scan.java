import java.util.*;

public class scan {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String string;
		int i = 3;
		
		while (i>0) {
			string = scanner.nextLine();
			System.out.printf("%s\n", string);
			--i;
		}
	}

}
