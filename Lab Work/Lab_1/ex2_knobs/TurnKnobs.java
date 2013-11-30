import java.lang.*;
import java.util.*;

class Knob {
	// Data Attributes
	private boolean isOn;
	String currPos;
	String targetPos;
	
	// Constructor
	public Knob(boolean state, String currPos, String targetPos) {
		isOn = state;
		this.currPos = currPos;
		this.targetPos = targetPos;
	}
	
	// Determine whether the device is on or off after num moves
	public boolean deviceIsOn(int num) {
		if (num % 2 == 0)
			return isOn;
		else
			return !isOn;
	}
	
	// Compute the least moves to turn the knob
	public int ChangePos() {
		int num=0;
		ArrayList<String> pos = new ArrayList<String>();
		pos.add("up"); pos.add("right"); pos.add("down"); pos.add("left");
		
		if (currPos.equals(targetPos)) 
			return 4;
		else {
			num = pos.indexOf(targetPos) - pos.indexOf(currPos);
			if (num < 0)
				num += 4;
		}
		return num;
	}
}
public class TurnKnobs {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		ArrayList<Knob> knobs = new ArrayList<Knob>();
		
		int numKnobs=scanner.nextInt();
		String state = "";
		
		while (numKnobs > 0) {
//			input = scanner.nextLine();
//			String[] inputArray = input.split(" ");
			state = scanner.next();
			
			if (state.equals("on")) {
				Knob knob = new Knob(true, scanner.next(), scanner.next());
				knobs.add(knob);
			}
			else {
				Knob knob = new Knob(false, state, scanner.next());
				knobs.add(knob);
			}
			--numKnobs;
		}
		int move=0;
		for (int i = 0; i < knobs.size(); ++i) {
			int num=0;
			num = knobs.get(i).ChangePos();
			
			if (knobs.get(i).deviceIsOn(num))
				System.out.println("on");
			else
				System.out.println("off");
			move += num;
		}
		System.out.printf("Total stops(s) %d\n", move);
	}

}
