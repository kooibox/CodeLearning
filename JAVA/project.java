package Tang;

import java.util.Random;
import java.util.Scanner;

class Person {
    private String name;
    private int score;
    public Person(String name){
        this.name = name;
    }
    public String Person(){
        return name;
    }
    public void setName(String name)
    {
        this.name = name;
    }
    public int getScore()
    {
        return score;
    }
    public void setScore(int score)
    {
        this.score = score;
    }
    public int showFirst(){
        System.out.println("请输入数字(1-3):1.石头 2.剪刀 3.布 >>:");
        Scanner sc = nwe Scanner(System.in);
        int a = sc.nextInt();
        switch (a) {
            case 1:
                System.out.println(name+"自信出: 石头");
                break;
            case 2:
                System.out.println(name+"自信出：剪刀");
                break;
            case 3:
                System.out.println(name+"自信出： 布");
                break;
            default:
                System.out.println(name+"自信出了一个奇怪的手势！！");
                break;
        }
        return a;
    }

    class Ipad{
        private String name;
        private int score;
        private int b=0;
        public Ipad(String name) {
            this.name = name;
        }
        public Ipad(){
            
        }
        public String getName() {
               return name;
           }
           public void setName(String name) {
               this.name = name;
           }
           public int getScore() {
               return score;
           }
           public void setScore(int score) {
               this.score = score;
           }
        public  int showFirst() {
           Random rand = new Random();
           b=rand.nextInt(3)+1;
            switch (b) {
               case 1:
                   System.out.println(name + "自信出：石头");
                   break;
               case 2:
                   System.out.println(name + "自信出：剪刀");
                   break;
               case 3:
                   System.out.println(name + "自信出：布");
                   break;
               default:
                   System.out.println(name + "自信出了一个奇怪的手势！！！");
                   break;
               }
           return b;
       }
   }
   class Ruler{
       private Person person;
       private Ipad pad ;
       private int count;
       public void init() {
           person=new Person("伟哥");
           pad =new Ipad("人机");
           System.out.println("<<---------------欢迎来到伟哥游戏社区--------------->>");
           System.out.println("*****************猜拳游戏：伟哥VS人机****************");
           int index=0;
           System.out.print("loading.");
           while(index<40) {
               System.out.print(".");
               try {
                   Thread.sleep(500);
               }catch (InterruptedException e) {
                   e.printStackTrace();
               }
               
               index++;
           }
           System.out.println("\n加载完毕！！！");
           playGame();
       }
       public void playGame() {
           Scanner sc=new Scanner(System.in);
           int pf,ipf;
           pf=person.showFirst();
           ipf=pad.showFirst();
           
           if(pf==1&&ipf==2 || pf==2&&ipf==3 ||pf==3&&ipf==1) {
               person.setScore(person.getScore()+1);
               System.out.println("奇迹：伟哥吊打人机！！！！！");
           }else if(pf==ipf) {
               System.out.println("平局：一胜一负，经济稳固~~~~~");
           }else {
               pad.setScore(pad.getScore()+1);
               System.out.println("惨败：伟哥智力堪忧，竟然打不过人机^··^");
           }
           count++;
           System.out.print("是否继续看伟哥被人机暴捶(Y|N):");
           String ch=sc.nextLine();
           if("Y".equalsIgnoreCase(ch)) {
               playGame();
           }else {
               showResult();
           }
       }
       public int calResult() {
           if(person.getScore()>pad.getScore()) {
               return 1;
           }else if(person.getScore()==pad.getScore()) {
               return 2;
           }else {
               return 3;
           }
       }
       public void showResult() {
           int t=calResult();
           if(t==1)  System.out.println("^-^:伟哥最终取得了胜利");
           else if(t==2)  System.out.println("伟哥最终竟然和人机打成了：平局！！！！");
           else System.out.println("果然，伟哥还是打不过人机~^-^~");
           System.out.println("伟哥最终得分："+person.getScore()+"(单位：伟) ::人机最终得分："+pad.getScore()+"(单位：伟)");
       }
   }
   public class Test {
       public static void main(String[] args) {
        Ruler rl=new Ruler();
        rl.init();
       }
    }