import java.lang.*;
import java.util.*;

public class NChooseK {

	public static void chooseK(int K, String original, String substring) {
		if (original.length() == K) {
			System.out.println(substring + original);
		} 
		else if (K == 0) {
			System.out.println(substring);
		}
		else {
			chooseK(K-1, original.substring(1), substring+original.charAt(0));
			chooseK(K, original.substring(1), substring);
		}
	}
	public static void main(String[] args) {
		chooseK(1,"abcd", "");
	}

}
