import java.util.Scanner;

class KvCost {
public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    double cost = scan.nextDouble();
    double b;
    if(cost < 0){
        System.out.println("Invalid cost!");
    }else if(cost <= 50){
        b = cost * 0.53;
        System.out.println("The cost is "+b+" yuan.");
    }else if(cost > 100){
        b = (cost - 50) * 0.58 + 50 * 0.53;
        System.out.println("The cost is "+b+" yuan.");
    }
    }
}