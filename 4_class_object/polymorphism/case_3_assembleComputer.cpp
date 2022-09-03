#include <iostream>
using namespace std;

class CPU
{
public:
    virtual void calculate() = 0;
    virtual ~CPU(){
        cout << "CPU virtual destructor" << endl;
    };
};
class VideoCard
{
public:
    virtual void display() = 0;
    virtual ~VideoCard(){};
};
class Memory
{
public:
    virtual void storage() = 0;
    virtual ~Memory(){};
};

// Inter
class InterCPU : public CPU
{
public:
    void calculate()
    {
        cout << "Inter CPU" << endl;
    }
};
class InterVideoCard : public VideoCard
{
public:
    void display()
    {
        cout << "Inter Videoplay" << endl;
    }
};
class InterMemory : public Memory
{
public:
    void storage()
    {
        cout << "Inter Memory" << endl;
    }
};
// Mac
class MacCPU : public CPU
{
public:
    void calculate()
    {
        cout << "Mac CPU" << endl;
    }
};
class MacVideoCard : public VideoCard
{
public:
    void display()
    {
        cout << "Mac Videoplay" << endl;
    }
};
class MacMemory : public Memory
{
public:
    void storage()
    {
        cout << "Mac Memory" << endl;
    }
};

class Computer
{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *memory)
    {
        this->cpu = cpu;
        this->vc = vc;
        this->memory = memory;
    }
    void work()
    {
        cpu->calculate();
        vc->display();
        memory->storage();
    }
    ~Computer()
    {
        if(cpu != NULL)
        {
            delete cpu;
            cpu = NULL;
        }
        if(vc != NULL)
        {
            delete vc;
            vc = NULL;
        }
        if(memory != NULL)
        {
            delete memory;
            memory = NULL;
        }
    }

private:
    CPU *cpu;
    VideoCard *vc;
    Memory *memory;
};

void test()
{
    CPU *cpu = new InterCPU;
    VideoCard *vc = new InterVideoCard;
    Memory *memory = new MacMemory;
    Computer *InterMac = new Computer(cpu, vc, memory);
    InterMac->work();
    delete InterMac;

    cout << "----------------" << endl;

    Computer *InterCom = new Computer(new InterCPU,new InterVideoCard, new InterMemory);
    InterCom->work();
    delete InterCom;
}

int main(int argc, const char *argv[])
{
    test();
    return 0;
}