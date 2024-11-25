#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"
#include <iostream>

template <typename T>
class LinkList {
protected:
	Node<T>* head;
	int length;

public:
	LinkList() : head(nullptr) {}

	// 通过数组构造链表
	LinkList(T* arr, int size) : head(nullptr) {
		for (int i = 0; i < size; ++i) {
			insertTail(arr[i]);
		}
	}

	~LinkList() { clear(); }

	// 插入新节点到链表头部
	void insertHead(T data) {
		Node<T>* newNode = new Node<T>(data);
		newNode->next = head;
		head = newNode;
		length++;
	}

	// 插入新节点到链表尾部
	void insertTail(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	// 删除链表头部的节点
	void deleteHead() {
		if (head == nullptr) return;
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}

	// 清空链表
	void clear() {
		while (head != nullptr) {
			deleteHead();
		}
	}

	// 打印链表
	void printList() const {
		Node<T>* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	// 自定义赋值操作符
	LinkList& operator=(const LinkList& other) {
		if (this != &other) {
			clear();
			Node<T>* temp = other.head;
			while (temp != nullptr) {
				insertTail(temp->data);
				temp = temp->next;
			}
		}
		return *this;
	}

	void MergeAndSort(LinkList<int>&ls1,LinkList<int>&ls2){
		Node<int>*p1 = ls1.head;
		Node<int>*p2 = ls2.head;
		while(p1!=nullptr && p2!=nullptr){
			int e1 = p1->data, e2 = p2->data;
			if(e1<=e2) {
				this->insertHead(e1);
				p1 = p1->next;
			}else{
				this->insertHead(e2);
				p2 = p2->next;
			}
		}
		while(p1!=nullptr){
			int e1 = p1->data;
			this->insertHead(e1);
			p1 = p1->next;
		}
		while(p2!=nullptr){
			int e2 = p2->data;
			this->insertHead(e2);
			p2 = p2->next;
		}
	}
	 // 合并两个链表并排序
	 // void MergeAndSort(LinkList& list1, LinkList& list2) {
	 // 	LinkList result;
	 // 	Node<T>* ptr1 = list1.head;
	 // 	Node<T>* ptr2 = list2.head;
	 // 	while (ptr1 != nullptr) {
	 // 		result.insertTail(ptr1->data);
	 // 		ptr1 = ptr1->next;
	 // 	}
	 // 	while (ptr2 != nullptr) {
	 // 		result.insertTail(ptr2->data);
	 // 		ptr2 = ptr2->next;
	 // 	}
	 // 	*this = result;
	 //
	 // 	if (head == nullptr || head->next == nullptr) return;
	 // 	Node<T>* sorted = nullptr;
	 // 	Node<T>* current = head;
	 // 	while (current != nullptr) {
	 // 		Node<T>* next = current->next;
	 // 		if (sorted == nullptr || sorted->data <= current->data) {
	 // 			current->next = sorted;
	 // 			sorted = current;
	 // 		} else {
	 // 			Node<T>* temp = sorted;
	 // 			while (temp->next != nullptr && temp->next->data > current->data) {
	 // 				temp = temp->next;
	 // 			}
	 // 			current->next = temp->next;
	 // 			temp->next = current;
	 // 		}
	 // 		current = next;
	 // 	}
	 // 	head = sorted;
	// }
};

#endif // LINKLIST_H
