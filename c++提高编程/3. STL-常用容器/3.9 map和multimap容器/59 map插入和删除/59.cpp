#include <iostream>
using namespace std;
#include <map>
void printMap(const map<int, int> &m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key=" << (*it).first << " value=" << (*it).second << endl;
    }
}
void test01()
{
    map<int, int> m;
    //插入方式
    //第一种
    m.insert(pair<int, int>(1, 10));
    //第二种
    m.insert(make_pair(4, 30));
    //第三种
    m.insert(map<int, int>::value_type(3, 40));
    //第四种
    m[2] = 20;            //不建议插入会覆盖 相同key值的value 普通插入不会覆盖原数据的value
    cout << m[5] << endl; //如果访问的key值不存在 会创造出value值为0的 
                          //可以用此方法去访问容器
    printMap(m);

    m.erase(m.begin());
    cout << "------------" << endl;
    printMap(m);

    m.erase(m.begin(), --m.end());
    cout << "------------" << endl;
    printMap(m);

    m.clear();
    cout << "------------" << endl;
    printMap(m);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
insert(elem);
clear();
erase(pos);
erase(beg,end);
erase(key); //删除容器中值为key的元素
***********************************/