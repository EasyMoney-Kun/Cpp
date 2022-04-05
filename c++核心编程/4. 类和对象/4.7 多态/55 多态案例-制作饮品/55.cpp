#include <iostream>
using namespace std;
class AbstractDrinking
{
public:
    //煮水
    virtual void
    Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加入辅料
    virtual void PutSth() = 0;
    //制作饮品
    void makeDrink()
    {

        Boil();
        Brew();
        PourInCup();
        PutSth();
    }
};
//制作咖啡
class MakeCoffee : public AbstractDrinking
{
    //煮水
    virtual void Boil()
    {
        cout << "煮矿泉水" << endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    //倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    //加入辅料
    virtual void PutSth()
    {
        cout << "加入糖和牛奶" << endl;
    }
};
class MakeTea : public AbstractDrinking
{
    //煮水
    virtual void Boil()
    {
        cout << "煮井水" << endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }
    //倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    //加入辅料
    virtual void PutSth()
    {
        cout << "加入枸杞" << endl;
    }
};
void doWork(AbstractDrinking *abs)
{
    abs->makeDrink();
    delete abs; // 释放
}
void test01()
{
    doWork(new MakeCoffee);
    cout << "------------" << endl;
    doWork(new MakeTea);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************

***********************************/