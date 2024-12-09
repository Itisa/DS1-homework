#include<iostream>
using namespace std;
template<class ElemType>
class SeqQueue
{
private:
    int front;
    int rear;
    int maxSize;
    ElemType *queue;
public:
    SeqQueue(int size);
    virtual~SeqQueue();
    bool isEmpty();//判空*
    bool isFull();//判满*
    void enQueue(ElemType x);//入队
    void deQueue();//出队*
    ElemType get_Front();//取队头
    void printQueue();//打印
};

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
{
    maxSize=size;
    queue=new ElemType[maxSize];//给队列元素分配空间
    front=rear=0;
}
template<class ElemType>
SeqQueue<ElemType>::~SeqQueue()
{
    delete []queue;
}

template<class ElemType>
bool SeqQueue<ElemType>::isEmpty()
{
    if(front==rear)
        return true;
    else
        return false;
}

template<class ElemType>
bool SeqQueue<ElemType>::isFull()
{
    if((rear+1)%maxSize==front)
        return true;
    else
        return false;
}

template<class ElemType>
void SeqQueue<ElemType>::enQueue(const ElemType x)//入队
{
    if(isFull())
        cout<<"Queue is full"<<endl;//判满则无法添加
    else
    {
        queue[rear]=x;
        rear=(rear+1)%maxSize;
    }
}

template<class ElemType>
void SeqQueue<ElemType>::deQueue()//队头出队
{
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;//判空则无法删除
        return;
    }
    front=(front+1)%maxSize;


}

// template<class ElemType>
// ElemType SeqQueue<ElemType>::get_Front()//取队头
// {
//     if(isEmpty())
//         cout<<"Queue is empty"<<endl;
        
//     else
//         return queue[front];
// }

template<class ElemType>
void SeqQueue<ElemType>::printQueue()//打印
{
    if(isEmpty())
        cout<<"Queue is empty"<<endl;
    else
    {
        for(int i=front;i!=rear;i=(i+1)%maxSize)
        cout<<queue[i]<<endl;
    }
}

int main()
{
    SeqQueue<int> q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.printQueue();
    q.deQueue();
    q.printQueue();
    //cout<<q.get_Front()<<endl;
    system("pause");
    return 0;
}
