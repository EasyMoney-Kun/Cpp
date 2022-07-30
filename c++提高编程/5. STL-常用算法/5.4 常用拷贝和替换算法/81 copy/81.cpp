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
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    for_each(v.begin(), v.end(), Print());
    cout << endl;
    vector<int> v1;
    // 记得提前开辟空间
    v1.resize(v.size());
    copy(v.begin(), v.end(), v1.begin());
    for_each(v1.begin(), v1.end(), Print());
    cout << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************

***********************************/