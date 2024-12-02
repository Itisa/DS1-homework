#ifndef SEQSTACK_H
#define SEQSTACK_H
#include "Assistance.h"

// 顺序栈模板类
template<class ElemType>
class SeqStack {
protected:
    // 顺序栈的数据成员:
    int top1;										// 栈顶指针
    int top2;                                       // 另一栈顶端
    int maxSize;									// 栈的最大容量
    ElemType *elems;								// 元素存储空间
public:
    SeqStack(int size = DEFAULT_SIZE);
    ~SeqStack();
    Status push1(ElemType e);
    Status push2(ElemType e);
    Status pop1(ElemType &e);
    Status pop2(ElemType &e);
    void Traverse(void (*Visit)(const ElemType &)) const;
};

template<class ElemType>
SeqStack<ElemType>::SeqStack(int size) : top1(-1), top2(size), maxSize(size) {
    if(elems != nullptr) {
        delete [] elems;
    }
    elems = new ElemType[maxSize];
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack() {
    delete [] elems;
}

template<class ElemType>
Status SeqStack<ElemType>::push1(ElemType e) {
    if(top1+1 == top2) {
        return RANGE_ERROR;
    }
    elems[++top1] = e;
    return SUCCESS;
}

template<class ElemType>
Status SeqStack<ElemType>::push2(ElemType e) {
    if(top2-1 == top1) {
        return RANGE_ERROR;
    }
    elems[--top2] = e;
    return SUCCESS;
}

template<class ElemType>
Status SeqStack<ElemType>::pop1(ElemType &e) {
    if(top1 == -1) {
        return RANGE_ERROR;
    }
    e = elems[top1];
    top1--;
    return SUCCESS;
}

template<class ElemType>
Status SeqStack<ElemType>::pop2(ElemType &e) {
    if(top2 == maxSize) {
        return RANGE_ERROR;
    }
    e = elems[top2];
    top2++;
    return SUCCESS;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// 操作结果：从栈顶到栈底依次对栈的每个元素调用函数(*visit)访问
{
    for (int i = 0; i <= top1 ; i++)
        (*Visit)(elems[i]);
    for(int i = top2; i < maxSize ; i++) {
        (*Visit)(elems[i]);
    }
}







#endif //SEQSTACK_H
