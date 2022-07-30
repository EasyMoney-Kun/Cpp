#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
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
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), Print());
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());
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
sort(iterator beg,iterator end,_pred)
***********************************/