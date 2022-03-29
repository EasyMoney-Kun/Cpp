#include <iostream>
using namespace std;
int main()
{
    int a, b; // a,b分别表示为数字的个位或十位
    for (int i = 1; i < 100; i++)
    {
        a = i % 10;
        b = i / 10;

        if (a==7||b==7||i%7==0)
        {
            cout << "逢" << i << "过" << endl;
            continue;
        }
        cout << i << endl;
    }

    system("pause");
    return 0;
}
/*******************************
案例描述：从1到100的数字，数字含7或者是7的倍数就过
********************************/