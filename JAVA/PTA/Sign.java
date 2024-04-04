import java.util.Scanner;
public class Sign {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("请输入一个整数：");
        int n = scan.nextInt();

        if(n < 0){
            System.out.println("负数");
        }else if(n == 0){
            System.out.println("零");
        }else if(n > 0){
            System.out.println("正数");
        }
    }
}
