 //1.售货机
 //------------


#include<stdio.h>
#include<stdlib.h>
int main()
{
int menuid;
int count = 0,i;
printf("[1]Selsect crisps\n\
 [2]Selsect popcorn\n\
 [3]Selsect chocolate\n\
 [4]Selsect cola\n\
 [0]Exit\n\
 ");
 scanf("%d",&menuid);
 for(i = 0;i<5;i++){
    switch (menuid)
    {
    case 0:
        Exit(0);
        printf("%f\n",Selcetcrisps);/* code */
        break;
    case 1:
        printf("2.5\n");
        break;
    case 2:
        printf("4.0\n");
        break;
    case 3:
        printf("3.5\n");
        break;
    case 4:
        printf("0\n");
        break;
    default:
        Exit(0);
        break;
    }
 }
 return 0;
}


//  //2.四则运算
//  //------------
// #include<stdio.h>

// int main()
// {
//     double op1,op2,result;
//     char s;

//     scanf("%lf%c%lf",&op1,&s,&op2);
//     switch (s)
//     {
//     case '+':/* constant-expression */
//         result = op1 + op2;/* code */
//         break;
//     case '-':
//         result = op1 - op2;
//         break;
//     case '*':
//         result = op1 * op2;
//         break;
//     case '/':
//         result = op1 / op2;
//         break;
//     }
//     printf("result = %lf",result);
// }
 //------------

//  //3.统计字符和数字个数 123456 78 9a
//  //------------
// #include<stdio.h>

// int main()
// {
//     int c_num =0,d_num=0,o_num=0;
//     char temp;
//     int i = 0;

//     for(;i<10;i++){
//         temp = getchar();
//         switch (temp){
//             case'1':
//             case'2':
//             case'3':
//             case'4':
//             case'5':
//             case'6':
//             case'7':
//             case'8':
//             case'9':
//             case'0':
//                 d_num++;
//                 break;
//         }
//         return 0;

//     }
// }
//  //------------
 

 //4.奇偶性
//-------------
// #include<stdio.h>
// int main()
// {
//     int num;
//     scanf("%d",&num);
//     if(num %2 == 0){
//         printf("偶数");
//     }else{
//         printf("奇数");/* code */
//     }
//     return 0;
// }
//-------------
 //5.绝对值
//-------------
// #include<stdio.h>9

// int main()
// {
//     int num;
//     scanf("%d",&num);

//     if(num < 0){
//         num = -num;
//     }
//     printf("%d",num);

//     return 0;
// }

//-------------