/*
 * author		: [Phan Shi Yu]
 * matric no.	: [A0091024U]
 */
 
import java.util.*;

class RunaroundNumbers {
	/**
	 * isRunAroundNumbers: check if input is a runaroundnumber.
	 */
	public static boolean isRunAroundNumbers(int input) {
        //Convert input into string to act as an array of digits//
        String num = Integer.toString(input);

        int length = num.length(); //Number of digits in input//

        //Preliminary check: All digits are unique and does not contain zero//
        if (num.charAt(0) == '0')
            return false;
            
        for (int i=0; i<(length) ; ++i)
        {
            for (int j=(i+1) ; j<length ; ++j)
            {
                if ((num.charAt(j) == '0') || (num.charAt(i) == num.charAt(j)))
                    return false;
            }
        }

        //Primary check: Runaround property//
        int count = 0; //Count of unique digits touched//
        int pos = 0; //Position of digit that will be used as the new digit//
        int digit = 0; //Digit that is currently touched//
        boolean[] isUsed = new boolean[length]; //Array to marked out digits that were touched//

        while (count < length)
        {
            if (isUsed[pos])
                return false;
            else
                isUsed[pos] = true; //Mark the digit that is touched//
            
            digit = num.charAt(pos) - '0';

            pos = (pos + digit) % length;

            ++count;
        }

        if (pos == 0)
            return true;
        else
            return false;
	}

	/**
	 * solve: return a runaroundnumber greater than input.
	 */
	public static int solve(int input) {
		do
        {
            input++;
        }
        while (!isRunAroundNumbers(input));

		return input;
	}

	public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    System.out.println(solve(sc.nextInt()));
	}
}
