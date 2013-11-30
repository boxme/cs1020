import java.lang.*;
import java.util.*;

class Query {
	private Vector<Airline> listAirline;
	
	/*Constructor*/
	public Query() {listAirline = new Vector<Airline>();}
	
	/*Methods*/
	//Add airline info
	public void addAirline(Airline newEntry) {listAirline.add(newEntry);}
	
	//Find the earliest departure time
	public Vector<Airline> earliestDepart(String fromCity, String toCity, SGTime currentTime) {
		Vector<Airline> infoList = new Vector<Airline>();
		Vector<Airline> earliest = new Vector<Airline>();
		
		for (int i = 0; i < listAirline.size(); ++i) {
			if (listAirline.get(i).getFromCity().equals(fromCity) && listAirline.get(i).getToCity().equals(toCity))
				infoList.add(listAirline.get(i));
		}
		
		for (int i=0; i < infoList.size(); ++i) {
			if (earliest.isEmpty()) 
				earliest.add(infoList.get(i));			
			else if (earliest.get(0).waitTime(currentTime) > infoList.get(i).waitTime(currentTime)) {
				earliest.clear();
				earliest.add(infoList.get(i));
			}		
		}
		return earliest;
	}
	
	//Find earliest arrival time
	public Vector<Airline> earliestArrive(String fromCity, String toCity, SGTime currentTime) {
		Vector<Airline> infoList = new Vector<Airline>();
		Vector<Airline> earliest = new Vector<Airline>();
		
		for (int i = 0; i < listAirline.size(); ++i) {
			if (listAirline.get(i).getFromCity().equals(fromCity) && listAirline.get(i).getToCity().equals(toCity))
				infoList.add(listAirline.get(i));
		}
		
		for (int i = 0; i < infoList.size(); i++) {
			if (earliest.isEmpty()) earliest.add(infoList.get(i));
			
			int totalTime_1 = earliest.get(0).diffCompare() + earliest.get(0).waitTime(currentTime);
			int totalTime_2 = infoList.get(i).diffCompare() + infoList.get(i).waitTime(currentTime);
			
			if (totalTime_1 > totalTime_2) {
				earliest.clear();
				earliest.add(infoList.get(i));
			}
		}
		return earliest;
	}
	
	//Find shortest flight
	public Vector<Airline> shortFlight(String fromCity, String toCity, SGTime currentTime) {
		Vector<Airline> infoList = new Vector<Airline>();
		Vector<Airline> earliest = new Vector<Airline>();
		
		for (int i = 0; i < listAirline.size(); ++i) {
			if (listAirline.get(i).getFromCity().equals(fromCity) && listAirline.get(i).getToCity().equals(toCity))
				infoList.add(listAirline.get(i));
		}
		
		for (int i = 0; i < infoList.size(); ++i) {
			if (earliest.isEmpty()) earliest.add(infoList.get(i));
			else if (earliest.get(0).diffCompare() > infoList.get(i).diffCompare()) {
				earliest.clear();
				earliest.add(infoList.get(i));
			}
		}
		return earliest;
	}
	
	//Find cheapest flight
	public Vector<Airline> cheapest(String fromCity, String toCity, SGTime currentTime) {
		Vector<Airline> infoList = new Vector<Airline>();
		Vector<Airline> cheap = new Vector<Airline>();
		
		for (int i = 0; i < listAirline.size(); ++i) {
			if (listAirline.get(i).getFromCity().equals(fromCity) && listAirline.get(i).getToCity().equals(toCity)) 
				infoList.add(listAirline.get(i));
		}
		
		for (int i = 0; i < infoList.size(); ++i) {
			if (cheap.isEmpty()) 
				cheap.add(infoList.get(i));
			else if (cheap.get(0).getCost() > infoList.get(i).getCost()) {
				cheap.clear();
				cheap.add(infoList.get(i));
			}
		}
		return cheap;
	}
}
