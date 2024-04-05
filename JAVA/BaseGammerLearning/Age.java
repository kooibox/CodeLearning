package BaseGammerLearning;
import java.util.Scanner;

public class Age {
    public static void main(String[] args){  
        final int MINOR = 35;

        System.out.print("请输入你的年龄:");
        @SuppressWarnings("resource")
        Scanner in = new Scanner(System.in);

        int age = in.nextInt();

        System.out.print("你的年龄是"+age);

        if(age < MINOR)
        {
            System.out.println("年轻是美好的!");
        }else{
        System.out.println("年龄决定了你的精神世界，好好珍惜吧！");
    }
}
}
