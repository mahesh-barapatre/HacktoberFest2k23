import java.util.Scanner;
public class Factorial {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter the number to calculate factorial: ");
		int number= sc.nextInt();
		int fact = 1;
		for (int i= number; i>=1;i--)
		{
			fact *= i;
		}
		System.out.println("The factorial of  given number " + number + " is " + fact);
			
		
	}
}