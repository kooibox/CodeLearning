package BaseGammerLearning;
import java.util.Scanner;

public class Num {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int x;
        int y;
        int z;
        System.out.println("请输入三个数");
        x = in.nextInt();
        y = in.nextInt();
        z = in.nextInt();

        int max = 0;
        if(x>y)
        {
            if(x>z)
            {
                max = x;
            }
            else
            {
                max = z;
            }
        }
        else
        {
            if(y>z)
            {
                max = y;
            }
            else
            {
                max = z;
            }
        }
        System.out.println(max);
    }
}
