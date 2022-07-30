#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
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
    v.resize(10, 10);
    for_each(v.begin(), v.end(), Print());
    //后期填充
    fill(v.begin(), v.end(), 6);
    for_each(v.begin(), v.end(), Print());
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************

***********************************/