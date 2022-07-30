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
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    for_each(v.begin(), v.end(), Print());
    cout << endl;
    replace(v.begin(), v.end(), 10, 6);
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
replace(iterator beg,iterator end,oldvalue,newvalue);
将区间内旧元素换成新元素
***********************************/