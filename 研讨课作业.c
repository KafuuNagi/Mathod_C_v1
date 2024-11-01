#include <stdio.h>
#include <stdlib.h> //引入伪随机rand()
#include <time.h>   //用时间戳初始化随机数种子，保证数字随机

int main(void)
{
    int first, second, third, fourth; // 四位随机数
    int num, a, b, c, d, i;//处理输入量相关
    int turns;//循环次数，控制10次后游戏结束
    int go_on = 1;                    // 判断程序是否继续
    int right_A = 0, right_B = 0;//A和B的个数

    srand(time(0));// 初始化随机数种子

    while (go_on == 1)
    {
        printf("程序已生成了一个四位数。每位数都在1-9之间，且四个数字互不相同。\n");
        printf("请尝试将其猜出。如果你猜的数中有数字相同但位置不同，记作1个B;\n");
        printf("如果数字相同且位置相同，记作1个A。");
        printf("你有十次猜测机会。下面请开始你的猜测：\n");

        /*do while出口条件循环，在检测条件时至少已循环一次*/
        do
        {
            first = 1 + rand() % 9;
            second = 1 + rand() % 9;
            third = 1 + rand() % 9;
            fourth = 1 + rand() % 9; // 保证数字在1-9之间
        } while (first == second || first == third || first == fourth ||
            second == third || second == fourth || third == fourth);
        // 确保数字不同

        for (turns = 1; turns <= 10; turns++) {
            right_A = 0, right_B = 0;
            i = (scanf("%d", &num));
            a = num / 1000;
            b = (num / 100) % 10;
            c = (num / 10) % 10;
            d = num % 10;//拆分输入的四位数

            if (i != 1 || num < 1234 || num > 9876
                || a == b || a == c || a == d
                || b == c || b == d || c == d
                || b == 0 || c == 0 || d == 0)) {
                printf("输入不正确，请重新输入！\n");
                turns--;
                while (getchar() != '\n');//清空输入缓存区
                continue;
            }//判断输入是否合规，若不合规则该次重来

            if (a == first) right_A++;
            if (b == second) right_A++;
            if (c == third) right_A++;
            if (d == fourth) right_A++;//统计A

            if (a == second || a == third || a == fourth) right_B++;
            if (b == first || b == third || b == fourth) right_B++;
            if (c == first || c == second || c == fourth) right_B++;
            if (d == first || d == second || d == third) right_B++;//统计B

            printf("本轮结果为%dA%dB\n", right_A, right_B);
            if (turns == 10) {
                printf("你已用光所有机会，游戏结束！\n");//到达十次，结束游戏
                printf("正确的数字为%d%d%d%d\n", first, second, third, fourth);
            }
            if (right_A == 4) {
                printf("恭喜，你猜对了！\n");
                break;
            }
        }
        printf("你还要继续游戏吗？输入1再来一轮，输入其它字符结束游戏：");
        i = scanf("%d", &go_on);
        if (i != 1)
            break;
    }
    return 0;
}
