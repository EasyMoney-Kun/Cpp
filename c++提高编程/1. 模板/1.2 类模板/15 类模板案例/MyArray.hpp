#pragma once
#include <iostream>
using namespace std;
template <class T>
class MyArray
{
public:
    // 有参构造
    MyArray(int Capacity)
    {
        this->m_Capacity = Capacity;
        this->m_Szie = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        this->m_Capacity = arr.m_Capacity;
        this->m_Szie = arr.m_Szie;
        // 深拷贝
        this->pAddress = new T[arr.m_Capacity];
        // 将arr中的数据拷贝过来
        for (int i = 0; i < this->m_Szie; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    // operator= 防止浅拷贝问题
    MyArray &operator=(const MyArray &arr)
    {
        // 先判断原来堆区是否有数据，如果有先释放
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Szie = 0;
        }
        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Szie = arr.m_Szie;
        this->pAddress = new T[arr.m_Capacity];
        // 将arr中的数据拷贝过来
        for (int i = 0; i < this->m_Szie; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    // 尾插法
    void Push_Back(const T &val)
    {
        // 判断容量是否等于大小
        if (this->m_Capacity == this->m_Szie)
        {
            return;
        }
        this->pAddress[this->m_Szie] = val; // 在数组末尾插入数据
        this->m_Szie++;                     // 更新数组大小
    }
    // 尾删法
    void Pop_Back()
    {
        // 判断容量是否为空
        if (this->m_Szie== 0)
        {
            return;
        }
        this->m_Szie--;
    }
    // 通过下标访问数组中的元素
    T &operator[](int index)
    {
        return this->pAddress[index];
    }
    // 返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }
    // 返回数组大小
    int getSize()
    {
        return this->m_Szie;
    }
    // 析构函数
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress;    // 指针指向堆区开辟的真实数组
    int m_Capacity; // 数组容量
    int m_Szie;     // 数组大小
};
