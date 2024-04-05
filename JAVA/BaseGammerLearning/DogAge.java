package BaseGammerLearning;
import java.util.Scanner;
public class DogAge {
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);

        System.out.print("请输入狗的年龄：");
        int dogAge = scan.nextInt();
        int humanAge;
        if(dogAge < 0){
            System.out.println("请输入正确的年龄！");
        }else if(dogAge <= 2){
            humanAge = (int) (dogAge * 10.5);
            System.out.println("相当于人类年龄：" + humanAge);
        }else{
            humanAge = (dogAge-2)*4+21;
            System.out.println("相当于人类年龄：" + humanAge);
        }
    }
}