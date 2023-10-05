import java.util.Scanner;
class Calculator
{
    public static void main(String args[])
{ 
    System.out.print("Enter the First Number: ");
    Scanner sc= new Scanner(System.in);
    int F= sc.nextInt();
    System.out.print("\nEnter the Second Number: ");
    int S= sc.nextInt();
    System.out.print(" Type 1 for plus '+'\n Type 2 for minus'-'\n Type 3 for multiply'*'\n Type 4 for Divide'/'\n ");
    int t= sc.nextInt();
    
   switch(t)
{              
      case 1:
                System.out.print("The sum of given numbers is: " + (F+S));
                break;
      case 2:
                 System.out.print("The Subtraction of given numbers is: " + (F-S));
                 break;
      case 3:
                  System.out.print("The multiplication of given numbers is: " + (F*S));
                  break;
      case 4:
                  System.out.print("The Division of given numbers is: " + (F/S));
                  break;
      default:
                 System.out.print("You entered invalid number");
                 break;
}
}
}
                 
                