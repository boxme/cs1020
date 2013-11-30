import java.lang.*;
import java.util.*;

class Airline {
	private String fromCity;
	private String toCity;
	private SGTime departureTime;
	private SGTime arrivalTime;
	private int arrivalDay;
	private int cost;
	
	/*Constructors*/
	public Airline(String fromCity, String toCity, SGTime departureTime, SGTime arrivalTime, int arrivalDay, int price) {
		this.fromCity = fromCity;
		this.toCity = toCity;
		this.departureTime = departureTime;
		this.arrivalTime = arrivalTime;
		this.arrivalDay = arrivalDay;
		this.cost = price;
	}
	
	/*Methods*/
	public int diffCompare() { //find time difference
		int diffHr = (arrivalTime.getHours() - departureTime.getHours()) + arrivalDay*24;
		int diffMins = arrivalTime.getMins() - departureTime.getMins();
		
		if (diffMins < 0) {
			diffHr--;
			diffMins += 60;
		}
		else if (diffMins >= 60) {
			diffHr++;
			diffMins -= 60;
		}
		int totalDiff = diffHr*60 + diffMins;
		return totalDiff;
	}
	
	public int waitTime(SGTime currentTime) { //waiting time
		int diffHr = departureTime.getHours() - currentTime.getHours();
		int diffMins = departureTime.getMins() - currentTime.getMins();
		
		if (diffHr < 0) diffHr += 24;
		if (diffMins < 0) {diffHr--; diffMins += 60;}
		else if (diffMins >= 60) {diffHr++; diffMins -= 60;}
		
		int totalWait = diffHr*60 + diffMins;
		
		if (totalWait < 60) totalWait += 24*60; //wait for 24 hours more if difference is less than 1 hr
		
		return totalWait;
	}
	
	/*Getters*/
	public String getFromCity() {return fromCity;}
	public String getToCity() {return toCity;}
	public SGTime getDepartureTime() {return departureTime;}
	public SGTime getArriveTime() {return arrivalTime;}
	public int getArrivalDay() {return arrivalDay;}
	public int getCost() {return cost;}
}
