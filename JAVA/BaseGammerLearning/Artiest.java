package BaseGammerLearning;
public class Artiest {
    public static void main(String[] args) {
        //定义一个布尔变量b1，值为true
        boolean b1 = true;
        //将b1的值改为false
        b1 = false;
        //定义一个整型变量num1，值为10
        int num1 = 10;
        //如果b1的值为true，并且num1的值大于0，则输出我现在在北京
        if(b1 & (num1++>0)){
            System.out.println("我现在在北京");
        }else{
            System.out.println("我现在在南京");
        }
        //输出num1的值，结果为11
        System.out.println("num1 = " + num1);//11

        //定义一个Boolean类型的变量b2，值为true
        Boolean b2 = true;
        //将b2的值改为false
        b2 = false;
        //定义一个整型变量num2，值为10
        int num2 = 10;
        //如果b2的值为true，并且num2的值大于0，则输出我现在在北京
        if(b2 && (num2++>0)){
            System.out.println("我现在在北京");
        }else{
            System.out.println("我现在在南京");
        }
        //输出num2的值
        System.out.println("num2 = " + num2);

    } 
}
