/*  
 * CS1020 (AY2012/3 Sem2)  
 * Lab #2 Ex3  
 * Author    :   
 * Matric no.:   
 * Description of program:   
 */ 

import java.util.*;

class SGTime {
	public int hour;
	public int minute;
	
	SGTime() {

	}
	
	public SGTime(int hour, int minute) {
		
	}
	
}

class Airline {
	private String from_city;
	private String to_city;
	private SGTime departure_time;
	private int arrival_day;
	private SGTime arrival_time;
	private int cost;
	
	public Airline() {
		
	}
	
	public Airline(String from_city, String to_city, SGTime departure_time, 
	               int arrival_day, SGTime arrival_time, int cost) {
		
	}
	
}

class ProcessQueries {
	private ArrayList <Airline> airlines;
	
	ProcessQueries() {
		
	}
	
	public void addAirline(Airline al){
		airlines.add(al);		
	}
	
	//Type1 Query
	public Airline getEarliestDeparture(String fromCity, String toCity, SGTime current_time){
		
	}
	
	//Type2 Query
	public Airline getEarliestArrival(String fromCity, String toCity, SGTime current_time){
		
	}
	
	//Type3 Query
	public Airline getShortestFlight(String fromCity, String toCity, SGTime current_time){
		
	}
	
	//Type4 Query
	public Airline getLowestCost(String fromCity, String toCity, SGTime current_time){
		
	}	
}

class AirlineMain {

	public static void main(String[] args) {
		// Declare a Scanner object to read input.

		// Declare the necessary variables.


		// Read in airline information.
		
		// Read in Queries and process them and output results accordingly.
	}

}

