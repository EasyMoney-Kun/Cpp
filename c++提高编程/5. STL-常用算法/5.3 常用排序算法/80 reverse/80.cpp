#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Print
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), Print());
    cout << endl;
    reverse(v.begin()+1, v.end()-1);
    for_each(v.begin(), v.end(), Print());
    cout << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
将容器区间元素进行反转
***********************************/