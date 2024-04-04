/**
 * @author:123
 */

import java.util.Scanner;

public class IfElse1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);  

        System.out.println("请输入成绩：(0-100)");
        int score = scan.nextInt();

        if(score == 100){
            System.out.println("奖励一辆宝马BWM");
        }else if(score >= 80 && score <= 99){
            System.out.println("奖励一台iPhone 13 Pro Max 1TB");
        }else if(score >= 60 && score <= 79){
            System.out.println("奖励一台iPad Pro 1TB");
        }else if(score >= 40 && score <= 59){
            System.out.println("奖励一台iPhone 13 128G");
        }else{
            System.out.println("奖励一本参考书");
        }
    }
}
