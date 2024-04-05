package BaseGammerLearning;
import java.util.Scanner;
/**
 * @author:禅意剑心相思骨 
 * */
public class IfElse {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("请输入你的姓名：");
        String name = scan.nextLine();
        System.out.println(name);
         
        System.out.println("请输入你的年龄");
        int age = scan.nextInt();
        System.out.println(age);

        System.out.println("请输入你的体重：");
        double weight = scan.nextDouble();
        System.out.println(weight);
        
        System.out.println("你是否相中我了呢？(true/false)");
        boolean love = scan.nextBoolean();
        System.out.println(love);

        System.out.println("请输入你的性别：");
        String gender = scan.next();
        System.out.println(gender);

    }
}
