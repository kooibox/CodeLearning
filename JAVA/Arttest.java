public class Arttest {
    public static void main(String[] args) {
        int m = 12;
        int n = 5;
        System.out.println("m & n :" +(m & n));
        System.out.println("m | n :" +(m | n));
        System.out.println("m ^ n :" +(m ^ n));

        int num1 = 10;
        int num2 = 20;

        // 输出：num1 = 10 num2 = 20
        System.out.println("num1 = "+ num1 + " num2 = "+ num2);

        int temp = num1;
        // 交换num1和num2的值，num1现在等于20，num2现在等于10。
        num1 = num2;
        // 交换num1和num2的值，num1现在等于20，num2现在等于10。
        num2 = temp;
    }
}
