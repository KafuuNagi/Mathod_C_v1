#include <stdio.h>
#include <stdlib.h> //引入伪随机rand()
#include <time.h>   //用时间戳初始化随机数种子，保证数字随机

int main(void)
{
    int first, second, third, fourth; // 四位随机数
    int num,a,b,c,d,i;
    int go_on = 1;                    // 判断程序是否继续进行

    while (go_on == 1)
    {
        // 初始化随机数种子
        srand(time(0));

        printf("程序已生成了一个四位数。每个数都在1-9之间，且四个数字互不相同。\n");
        printf("请尝试将其猜出。如果你猜的数中有数字相同但位置不同，记作1个B;\n");
        printf("如果数字相同且位置相同，记作1个A。");
        printf("你有十次猜测机会。下面请开始你的猜测：\n");

        do
        {
            first = 1 + rand() % 9;
            second = 1 + rand() % 9;
            third = 1 + rand() % 9;
            fourth = 1 + rand() % 9; // 保证数字在1-9之间
        } while (first == second || first == third || first == fourth ||
                 second == third || second == fourth || third == fourth);
        // 确保数字不同
        
        i = (scanf("%d",&num));
        a = num / 1000;
        b = (num / 100) % 10;
        c = (num / 10) % 10;
        d = num % 10;
        
        if(i != 1 || num < 1234 || num > 9876
        || a == b || a == c || a == d
        || b == c || b == d || c == d){
            printf("输入不正确！");
            go_on = 0;
            continue;
        }
    }
    return 0;
}  
