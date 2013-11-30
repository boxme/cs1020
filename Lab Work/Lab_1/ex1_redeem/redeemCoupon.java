import java.lang.*;
import java.util.*;

class Coupon {
	// Data Attribute
	private String name;
	private double rate;
	
	// Constructors
	public Coupon() {}
	public Coupon(String name, double rate) {
		this.name = name;
		this.rate = rate;
	}
	
	// Accessors
	public String getName() {return name;}
	public double getRate() {return rate;}
	
	// Methods
	// The amount the user has to pay
	public double payment(double price) {
		if (rate <= 1) 
			return (1-rate) * price;
		else 
			return Math.abs(rate - price);
	}
}
public class redeemCoupon {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		double price, rate, pay=0.00, cost=1000000.0;
		int numCoupons;
		String nameCoupon, bestCoupon = "";
		
		price = scanner.nextDouble();
		numCoupons = scanner.nextInt();
		
		while (numCoupons > 0) {
			nameCoupon = scanner.next();
			rate = scanner.nextDouble();
			Coupon coupon = new Coupon(nameCoupon, rate);
			
			if (coupon.payment(price) < cost) {
				bestCoupon = nameCoupon;
				cost = coupon.payment(price);
				
				if (price > rate && rate != 1.0)
					pay = cost;
				else
					pay = 0.00;
			}
			--numCoupons;
		}
		
		System.out.printf("Best choice: %s\n", bestCoupon);
		System.out.printf("You need to pay $%.2f\n", pay);
	}

}
