#include<iostream>
#include<cmath>
#include<stdexcept>
using namespace std;

class Node {
public:
	double coefficient;//ϵ��
	double exponent;//ָ��
	Node* next;

	//���캯��
	Node(double coe, double exp, Node* n = nullptr) :coefficient(coe), exponent(exp), next(n) {};
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
	void insert(double coe,double exp) {
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

	//չʾ
	void display() {
		Node* temp = head;
		if (temp->coefficient == 1) {
			cout << "x" << "^" << temp->exponent;
		}
		else if (temp->coefficient == -1) {
			cout << "-x" << "^" << temp->exponent;
		}
		else cout << temp->coefficient << "x" << "^" << temp->exponent;
		
		temp = temp->next;
		while (temp != nullptr) {
			if (temp->coefficient < 0&& temp->coefficient != -1) {
				cout << "-" << abs(temp->coefficient) << "x" << "^" << temp->exponent;
			}
			else if (temp->coefficient == -1) {
				cout << "-" << "x" << "^" << temp->exponent;
			}
			else if(temp->coefficient > 0 && temp->coefficient != 1){
				cout << "+" << temp->coefficient << "x" << "^" << temp->exponent;
			}
			else if (temp->coefficient == 1) {
				cout << "+" << "x" << "^" << temp->exponent;
			}
			temp = temp->next;
		}
		cout << endl;
	}

	double calc(double x);
};


double poly::calc(double x) {
	if (x < 0) {
		Node* temp = head;
		while (temp != nullptr) {
			if (floor(temp->exponent) != temp->exponent) { // ���ָ���Ƿ�Ϊ������
				cout << "������������ֹͣ���㡣" << endl;
				exit(EXIT_FAILURE);
			}
			temp = temp->next;
		}
	}
	if (x == 0) {
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->exponent < 0) { // ����Ƿ����x�ڷ�ĸʱΪ0�����
				cout << "��ĸ����Ϊ0��ֹͣ���㡣" << endl;
				exit(EXIT_FAILURE);
			}
			temp = temp->next;
		}
	}
	double result = 0.0;
	Node* current = head;
	while (current != nullptr) {
		result += (current->coefficient * pow(x, current->exponent));
		current = current->next;
	}
	return result;
}

