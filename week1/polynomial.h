#include<iostream>
#include<cmath>
using namespace std;

class Node {
public:
	double coefficient;//ϵ��
	int exponent;//ָ��
	Node* next;

	//���캯��
	Node(double coe, int exp, Node* n = nullptr) :coefficient(coe), exponent(exp), next(n) {};
};

class poly {
private:
	Node* head;

public:
	poly() :head(nullptr) {};

	//���������ͷ�
	~poly() {
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	//����β��
	void insert(double coe,int exp) {
		Node* newNode = new Node(coe, exp);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	double calc(double x);
};


double poly::calc(double x) {
	double result = 0.0;
	Node* current = head;
	while (current != nullptr) {
		result += (current->coefficient * pow(x, current->exponent));
		current = current->next;
	}
	return result;
}

