import java.lang.*;
import java.util.*;

class Schedule {
	private String day;
	private int startTime;
	private int endTime;
	
	/*Constructor*/
	public Schedule(String day, int startTime, int endTime) {
		this.day = day;
		this.startTime = startTime;
		this.endTime = endTime;
	}
	
	/*Method*/
	public boolean clashed(Schedule newSchedule) {
		if (startTime >= newSchedule.getEndTime() || newSchedule.getStartTime() >= endTime)
			return false;
		else return true;
	}
	
	/*Getter*/
	public String getDay() {return day;}
	public int getStartTime() {return startTime;}
	public int getEndTime() {return endTime;}
}

class Module {
	private String code;
	private Schedule lecture;
	private Schedule tutorial;
	private Schedule lab;
	
	/*Constructor*/
	public Module(String code) {this.code = code;}
	
	/*Methods*/
	public void upDateModule(String lessonType, String day, int startTime, int endTime) {
		Schedule newSchedule = new Schedule(day, startTime, endTime);
		
		if (lessonType.equals("lecture")) this.lecture = newSchedule;
		else if (lessonType.equals("tutorial")) this.tutorial = newSchedule;
		else this.lab = newSchedule;
	}
	
	public boolean gotClashed(Module newModule) {
		int i=3;
		while (i>0) {
			//check lecture clashes
			if (lecture.getDay().equals(newModule.getLect().getDay())) 
				if (lecture.clashed(newModule.getLect())) return true;
			if (lecture.getDay().equals(newModule.getTut().getDay()))
				if (lecture.clashed(newModule.getTut())) return true; 
			if (lecture.getDay().equals(newModule.getLab().getDay()))
				if (lecture.clashed(newModule.getLab())) return true; 
			//check tutorial clashes
			if (tutorial.getDay().equals(newModule.getLect().getDay()))
				if (tutorial.clashed(newModule.getLect())) return true; 
			if (tutorial.getDay().equals(newModule.getTut().getDay()))
				if (tutorial.clashed(newModule.getTut())) return true; 
			if (tutorial.getDay().equals(newModule.getLab()))
				if (tutorial.clashed(newModule.getLab())) return true; 
			//check lab clashes
			if (lab.getDay().equals(newModule.getLect().getDay()))
				if (lab.clashed(newModule.getLect())) return true; 
			if (lab.getDay().equals(newModule.getTut().getDay()))
				if (lab.clashed(newModule.getTut())) return true;
			if (lab.getDay().equals(newModule.getLab().getDay()))
				if (lab.clashed(newModule.getLab())) return true; 
			--i;
		}
		return false;
	}
	
	/*Getters*/
	public String getCode() {return code;}
	public Schedule getLect() {return lecture;}
	public Schedule getTut() {return tutorial;}
	public Schedule getLab() {return lab;}
}

class TimeTable {
	private List<Module> listOfModules;
	
	/*Constructor*/
	public TimeTable() {listOfModules = new ArrayList<Module>();}
	
	/*Methods*/
	public String updateTimeTable(Module newModule) {
		if (listOfModules.isEmpty()) {
			listOfModules.add(newModule);
			return "Added";
		}
		else {
			for (int i = 0; i < listOfModules.size(); i++) {
				Module temp = listOfModules.get(i);
				if (temp.gotClashed(newModule)) return "Clashed";
			}
			listOfModules.add(newModule);
			return "Added";
		}
	}
	public int countClasses(String day) {
		int numClasses = 0;
		for (int i = 0; i < listOfModules.size(); i++) {
			Module temp = listOfModules.get(i);
			if (temp.getLect().getDay().equals(day)) ++numClasses;
			if (temp.getTut().getDay().equals(day)) ++numClasses;
			if (temp.getLab().getDay().equals(day)) ++numClasses;
		}
		return numClasses;
	}
}

public class Register {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int K, startTime, endTime;
		String operation, code, day;
		TimeTable aList = new TimeTable();
		
		K = scanner.nextInt();
		
		while (K>0) {
			int i=3;
			operation = scanner.next();
			
			if (operation.equals("MODULE")) {
				code = scanner.next();
				Module newModule = new Module(code);

				while (i>0) {
					day = scanner.next();
					startTime = scanner.nextInt();
					endTime = scanner.nextInt();
					if (i==3) newModule.upDateModule("lecture", day, startTime, endTime);
					else if (i==2) newModule.upDateModule("tutorial", day, startTime, endTime);
					else newModule.upDateModule("lab", day, startTime, endTime);
					--i;
				}
				System.out.println(aList.updateTimeTable(newModule));
			}
			else {
				day = scanner.next();
				System.out.println(aList.countClasses(day));
			}
			--K;
		}
	}

}
