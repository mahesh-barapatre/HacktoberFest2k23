import java.util.Scanner;
public class CelciusToFarenhiet{
	public static void main(String[] args) {
		  System.out.print("Enter the temperature to convert it into Farenhiet : ");
		  
		   // Farenhiet(F) = (Celcius(C) × 9/5) + 32
		   Scanner sc= new Scanner(System.in);
		   float temp= sc.nextFloat();
		   float F = (temp * 9/5)+32; // conversion to Farenhiet 
		   System.out.print("\n Temperature " + temp + " celcius to farenhiet is " + F);
		   
	}
}