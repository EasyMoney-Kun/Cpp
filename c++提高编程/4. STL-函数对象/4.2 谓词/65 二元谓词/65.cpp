#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Compare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), Compare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
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