import java.util.Scanner;

public class SimpleCalculator {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.printf("请输入表达式: ");
        int a = scan.nextInt();
        char op = scan.next().charAt(0);
        int b = scan.nextInt();

        switch (op) {
            case '+':
                System.out.println(a + b);
                break;
            case '-':
                System.out.println(a - b);
                break;
            case '*':
                System.out.println(a * b);
                break;
            case '/':
                System.out.println(a / b);
                break;
            default:
                System.out.println("输入有误，请重新输入");
        }
    }
}

