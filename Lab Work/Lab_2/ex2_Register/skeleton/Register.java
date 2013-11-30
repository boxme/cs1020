/*  
 * CS1020 (AY2012/3 Sem2)  
 * Lab #2 Ex2  
 * Author    :   
 * Matric no.:   
 * Description of program:   
 */ 

import java.util.*;

class Schedule {
	// declare the attributes

	// declare the constructor

	/* clashWith: to check whether this schedule clash with a Schedule called otherSchedule
	 * Pre-cond:
	 * Post-cond:
	 */
	public boolean clashWith(Schedule otherSchedule) {
		// implementation
		return true;
	}
}

class Module {
	// declare the attributes

	// declare the constructor

	/* count: to count number of classes(lecture, tutorial, and lab of only this Module) on day.
	 * 	      For example: when day = "Monday", lecture is on Monday, tutorial is on Monday
	 *        but lab is on Tuesday, then return 2. (lecture and tutorial are on Monday).
	 * Pre-cond:
	 * Post-cond:
	 */
	public int count(String day) {
		// implementation
		return 0;
	}

	/* clashWith: to check whether this module clash with a Module called otherModule
	 * Pre-cond:
	 * Post-cond:
	 */
	public boolean clashWith(Module otherModule) {
		// implementation
		return true;
	}
}

class Timetable {
	// declare the attributes

	// declare the constructor

	/* checkClash: to check whether otherModule clash with one of 
	 * 			   the modules in our timetable list.
	 * Pre-cond:
	 * Post-cond:
	 */
	public boolean checkClash(Module otherModule) {
		// implementation
		return true;
	}

	/* add: to add a new module to the timetable list.
	 * Pre-cond:
	 * Post-cond:
	 */
	public void add(Module module) {
		// implementation
		return;
	}

	/* count: to count number of classes on day.
	 * Pre-cond:
	 * Post-cond:
	 */
	public int count(String day) {
		// implementation
		return 0;
	}
}

class Register {

	public static void main(String[] args) {
		// declare the necessary variables

		// declare a Scanner object to read input

		// read input and process them accordingly

		// simulate the problem

		// output the result
	}
}
