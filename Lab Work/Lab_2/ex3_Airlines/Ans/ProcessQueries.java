import java.lang.*;
import java.util.*;

public class ProcessQueries {

	public static String convertString(int Hrs, int Mins) {
		if (Mins < 10) 
			return (Hrs + "" + ":0" + Mins + "");
		return (Hrs + "" + ":" + Mins);
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int N=0, Q=0, arriveDay=0, price=0;
		String fromCity = new String();
		String toCity = new String();
		
		Query airLineList = new Query();
		
		String depTime = new String();
		String arrTime = new String();
		
		int depHrs=0, depMins=0, arrHrs=0, arrMins=0;
		
		N = scanner.nextInt();
		
		while (N > 0) {
			fromCity = scanner.next();
			depTime = scanner.next();
			arriveDay = scanner.nextInt();
			arrTime = scanner.next();
			price = scanner.nextInt();
			
			//Setting the time to integers
			--N;
		}
	}

}
