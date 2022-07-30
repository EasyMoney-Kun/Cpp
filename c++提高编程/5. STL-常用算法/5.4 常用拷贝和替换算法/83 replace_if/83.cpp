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
class myprint
{
public:
    bool operator()(int val)
    {
        return val == 10;
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
    replace_if(v.begin(), v.end(), myprint(), 6);
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
replace_if(iterator beg,iterator end,_pred,newvalue)
按条件替换元素
***********************************/