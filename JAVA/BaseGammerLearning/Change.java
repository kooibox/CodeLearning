package BaseGammerLearning;
import java.util.Scanner;

public class Change {
    public static void main(String[] args){
        //初始化
        Scanner in = new Scanner(System.in);
        int amount = in.nextInt();

        System.out.println("**********");
        System.out.println("Java城际铁路专线");
        System.out.println("*   无指定座位票   *");
        System.out.println("*   票价:   10元   *");
        System.out.println("**********");

        System.out.println("找零："+(amount-10));

        
        System.out.print("请投币：");
        
    }
}
