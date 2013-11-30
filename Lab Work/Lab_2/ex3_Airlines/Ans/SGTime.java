import java.lang.*;
import java.util.*;

class SGTime {
	private int hr;
	private int min;
	
	/*Constructor*/
	public SGTime() {hr=0; min=0;}
	
	public SGTime(int hr, int min) {
		this.hr = hr;
		this.min = min;
	}
	
	/*Methods*/
	public int Compare(SGTime time) {
		if (hr > time.getHours()) return 1;
		if (hr < time.getHours()) return 0;
		if (min < time.getMins()) return 1;
		else return 0;
		
	}
	
	public int convertToMin() {
		return (hr*60 + min);
	}
	
	/*Getters*/
	public int getHours() {return hr;}
	public int getMins() {return min;}
}
