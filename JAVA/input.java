import java.util.Scanner;
public class input {
    public static void main(String[] args) {
        System.out.println("中文");
        Scanner in = new Scanner(System.in);
        System.out.println("echo:" + in.nextLine());
        // System.out.println("2+3="+2+3);

        int price;
        price = in.nextInt();
        System.out.println("100-"+price+"="+(100-price));
}
}
//变量定义的一般形式：<类型><名称>
//printlf(""+"") +号用来连接两个字符串，如果有运算的，要加上括号
 