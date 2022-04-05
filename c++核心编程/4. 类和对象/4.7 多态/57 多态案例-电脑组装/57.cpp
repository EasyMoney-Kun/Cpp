#include <iostream>
using namespace std;
// 抽象不同的零件类
// 抽象CPU类
class CPU
{
public:
    // 抽象的计算函数
    virtual void calculate() = 0;
};
// 抽象内存条类
class VideoCard
{
public:
    // 抽象的显示函数
    virtual void display() = 0;
};
// 抽象内存条类
class Memory
{
public:
    // 抽象存储函数
    virtual void storage() = 0;
};
// 电脑类
class Computer
{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    ~Computer()
    {
        // 释放cpu零件
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }
    // 提供工作的函数
    void work()
    {
        // 让零件工作起来，调用接口
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

private:
    CPU *m_cpu;      // CPU零件指针
    VideoCard *m_vc; // 显卡零件指针
    Memory *m_mem;   // 内存条零件指针
};
// 具体厂商
// intel厂商
class InterCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Inter的CPU开始计算了" << endl;
    }
};
class InterVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Inter的显卡开始显示了" << endl;
    }
};
class InterMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Inter的内存条开始存储了" << endl;
    }
};
// lenovo厂商
class lenovoCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "lenovo的CPU开始计算了" << endl;
    }
};
class lenovoVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "lenovo的显卡开始显示了" << endl;
    }
};
class lenovoMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "lenovo的内存条开始存储了" << endl;
    }
};
void test01()
{
    // 第一台电脑零件
    CPU *intelCpu = new InterCPU;
    VideoCard *videocard = new InterVideoCard;
    Memory *memory = new InterMemory;

    // 创建第一台电脑
    cout << "第一台电脑开始工作" << endl;
    Computer *computer = new Computer(intelCpu, videocard, memory);
    computer->work();
    delete computer;
    // 创建第二台电脑
    cout << "第二台电脑开始工作" << endl;
    Computer computer1(new lenovoCPU, new lenovoVideoCard, new lenovoMemory);
    computer1.work();
     // 创建第三台电脑
    cout << "第三台电脑开始工作" << endl;
    Computer computer2(new InterCPU, new lenovoVideoCard, new lenovoMemory);
    computer2.work();
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************

***********************************/