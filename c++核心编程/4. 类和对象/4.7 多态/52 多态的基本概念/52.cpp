#include <iostream>
using namespace std;
// 多态

// 动物类
class Animal
{
public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};
// 猫类
class Cat : public Animal
{
public:
    // 重写 ： 函数返回值类型 函数名 函数列表 完全一致成为重写
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};
// 狗类
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "狗叫" << endl;
    }
};
// 执行说话的函数
// 地址早绑定 在编译阶段确定函数地址
// 如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

// 动态多态满足条件
// 1、有继承关系
// 2、子类重写父类的虚函数
// 动态多态使用
// 父类的指针或则引用 执行子类对象
void doSpeak(Animal &animal) // 父类的引用指向子类的对象  Animal &animal = cat
{
    animal.speak();
}
void test01()
{
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}
void test02()
{
    cout << "sizeof(animal)=" << sizeof(Animal) << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
多态是c++面向对象的三大特性之一
多态分为两类
    静态多态：函数重载和运算符重载属于静态多态，复用函数名
    动态多态：派生类和虚函数实现运行时多态
静态多态和动态多态
    静态多态的函数地址早绑定 - 编译阶段确定函数地址
    动态多态的函数地址晚绑定 - 运行阶段确定函数地址

Animal类内部结构
vfptr；虚函数指针
v-virtual
f-function
ptr-pointer
vftable：表内记录虚函数的地址
&Animal::speak
Cat类内部结构
当函数重写时
&Cat::speak 覆盖从父类继承的 &Animal::speak

当父类的指针或者引用指向子类对象时候，发生多态
Animal& animal=cat；
animal.speak();
***********************************/