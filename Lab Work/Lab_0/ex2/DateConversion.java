import java.lang.*;
import java.util.*;

public class DateConversion {
	
	public static boolean isLeapYear(int year) {
		if (year % 400 == 0) 
			return true;
		else if (year % 4 == 0 && year % 100 > 0) 
			return true;
		else
			return false;
			
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.printf("Enter date in the UK format: ");
		String month = scanner.next();
		String dateString = scanner.next();
		int year = scanner.nextInt();
		
		//removing the commas from the end of this string
		dateString = dateString.substring(0, dateString.length()-1);
		
		//convert String to int 
		int date = Integer.parseInt(dateString);
		
		//American Date format
		System.out.printf("Date in American format: %d %s %d\n", date, month, year);
		
		//Leapyear?
		if (isLeapYear(year))
			System.out.printf("%d is a leap year.\n", year);
		else
			System.out.printf("%d is not a leap year.\n", year);
	}

}
