#include <iostream>
using namespace std;
int main()
{
    int num = 100;
    int a, b, c; // a,b,c分别为个位，十位，百位上的数
    do
    {
        a = num % 10;
        b = num / 10 % 10;
        c = num / 100;
        if (a * a * a + b * b * b + c * c * c == num)
        {
            cout << num << endl;
        }
        num++;
    }while(num<1000);
    system("pause");
    return 0;
}
/*******************************
案例描述：水仙花数是指一个三位数，他的每个位上的数字三次幂之和等于它本身
例如：1^3+3^3+5^3=153
********************************/