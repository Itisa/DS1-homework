#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;          // 节点存储的数据
    Node* next;      // 指向下一个节点的指针

    Node(T data) : data(data), next(nullptr) {}  // 构造函数初始化节点数据和next指针
};

#endif // NODE_H
