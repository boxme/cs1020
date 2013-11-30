/**
 * name	     :
 * matric no.:
 */
import java.util.*;

class Application {

    // declare the member field

    // declare the constructor

	// declare other necessary methods
}

class Storage {

    // declare the member field

    // declare the constructor

	/**
	 *	   add				: to add a new Application to this storage
	 *	   Pre-condition 	:
	 *	   Post-condition	:
	 */
	public void add(Application app) {
		// implementation
		return;
	}

	/**
	 *	   get				: to get an Application at index <index>
	 *	   Pre-condition 	:
	 *	   Post-condition	:
	 */
	public Application get(int index) {
		// implementation
		return null;
	}

	/**
	 *	   getNumberOfApps	: to get the number of apps in this storage
	 *	   Pre-condition 	:
	 *	   Post-condition	:
	 */
	public int getNumberOfApps() {
		// implementation
		return 0;
	}

	/**
	 *	   getRemainingSize	: to get the remaining size of this storage (initial size - total size of
	 *						  installed applications in this storage)
	 *	   Pre-condition 	:
	 *	   Post-condition	:
	 */
	public int getRemainingSize() {
		// implementation
		return 0;
	}
}

class Phone {
    // declare the member field

    // declare the constructor

	/**
	 *	   add				: to add a new Application to this phone, return "Failed to be added" if app
	 *						  cannot be added to any storages, else return "Added to storage x", where x is 
	 *						  the number of a storage
	 *	   Pre-condition 	:
	 *	   Post-condition	:
	 */
	public String add(Application app) {
		// implementation
		return "";
	}
	
	/**
	 *	   getLargestApp	: to retrieve the largest Application in this phone
	 *	   Pre-condition 	:
	 *	   Post-condition	:
	 */
	public Application getLargestApp() {
		// implementation
		return null;
	}

	/**
	 *	   getSmallestApp	: to retrieve the smallest Application in this phone
	 *	   Pre-condition 	:
	 *	   Post-condition	:
	 */	
	public Application getSmallestApp() {
		// implementation
		return null;
	}

	/**
	 *	   getStorages		: to get all storages in this phone
	 *	   Pre-condition 	:
	 *	   Post-condition	:
	 */	
	public Vector<Storage> getStorages() {
		// implementation
		return null;
	}
}

class Main {
	public static void main(String[] args) {
		// declare the necessary variables

		// declare a Scanner object to read input

		// read input and process them accordingly
	}
}