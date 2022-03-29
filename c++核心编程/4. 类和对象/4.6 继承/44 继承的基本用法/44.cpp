#include <iostream>
using namespace std;
// // 普通实现页面
// // java页面
// class Java
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册.....（公共头部）" << endl;
//     }
//     void footor()
//     {
//         cout << "帮助中心、交流合作、站内地图.....（公共底部）" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++.....(公共分类列表)" << endl;
//     }
//     void content()
//     {
//         cout << "Java学科视频" << endl;
//     }
// };
// // Python页面
// class Python
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册.....（公共头部）" << endl;
//     }
//     void footor()
//     {
//         cout << "帮助中心、交流合作、站内地图.....（公共底部）" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++.....(公共分类列表)" << endl;
//     }
//     void content()
//     {
//         cout << "Python学科视频" << endl;
//     }
// };
// // Cpp页面
// class Cpp
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册.....（公共头部）" << endl;
//     }
//     void footor()
//     {
//         cout << "帮助中心、交流合作、站内地图.....（公共底部）" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++.....(公共分类列表)" << endl;
//     }
//     void content()
//     {
//         cout << "C++学科视频" << endl;
//     }
// };
// 继承实现页面
// 公共页面类
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册.....（公共头部）" << endl;
    }
    void footor()
    {
        cout << "帮助中心、交流合作、站内地图.....（公共底部）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++.....(公共分类列表)" << endl;
    }
};
class Java : public BasePage
{
public:
    void content()
    {
        cout << "Java学科视频" << endl;
    }
};
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python学科视频" << endl;
    }
};
class Cpp : public BasePage
{
public:
    void content()
    {
        cout << "C++学科视频" << endl;
    }
};
void test01()
{
    cout << "Java下载视频页面如下：" << endl;
    Java ja;
    ja.header();
    ja.left();
    ja.content();
    ja.footor();

    cout << "----------------------" << endl;
    cout << "Python下载视频页面如下：" << endl;
    Python py;
    py.header();
    py.left();
    py.content();
    py.footor();

    cout << "----------------------" << endl;
    cout << "Cpp下载视频页面如下：" << endl;
    Cpp cp;
    cp.header();
    cp.left();
    cp.content();
    cp.footor();
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
继承是面向对象三大特性之一
定义某些类时，下级别的成员除了拥有上一级的共性，还有自己的特性
这时候考虑用继承的技术，减少重复代码
继承的好处：减少重复代码
语法；class 子类 ：继承方式 父类
子类 也称为 派生类
父类 也称为 基类
***********************************/