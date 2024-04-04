import java.util.Scanner;

class FxFunc {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("请输入一个实数x：");
        double x = scan.nextDouble();
        
        if(x != 10){
            System.out.println("x = " + x + " f(x) = " + (x * x * x));
        }else{
            System.out.println("x = " + x + " f(x) = " + 294);
        }
    }
}