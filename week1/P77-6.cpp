#include <iostream>
#include <cassert>
using namespace std;
template <typename T>
class sorted_Linklist_with_head{
public:
	sorted_Linklist_with_head(){
		head = new node();
	}
	~sorted_Linklist_with_head(){
		node* now = head;
		while(now != NULL){
			node* nxt = now -> nxt;
			delete now;
			now = nxt;
		}
	}
	void push(const T& _val){
		node* now = head;
		while(now -> nxt != NULL){
			if (_val < now -> nxt -> val){
				now -> nxt = new node(_val,now -> nxt);
				return ;
			}
			now = now -> nxt;
		}
		now -> nxt = new node(_val);
	}
	void append(const T& _val) {push_back(_val);}
	void pop(){
		assert(head -> nxt != NULL);
		node* now = head;
		while(now -> nxt -> nxt != NULL){
			now = now -> nxt;
		}
		delete now -> nxt;
		now -> nxt = NULL;
	}

	int erase_all(const T& _val) {
		int erase_cnt = 0;
		node* now = head;
		while(now -> nxt != NULL){
			if (_val == now -> nxt -> val){
				node* del = now -> nxt;
				now -> nxt = now -> nxt -> nxt;
				delete del;
				erase_cnt++;
			} else {
				now = now -> nxt;
			}
		}
		return erase_cnt;
	}

	T at(const int& x) const {
		node* now = head;
		for (int i = -1; i < x; ++i){
			now = now -> nxt;
			assert(now != NULL);
		}
		return (*now).val;
	}
	T operator [](const int& x) const {
		return at(x);
	}
	void print_all() const {
		node* now = head -> nxt;
		while(now != NULL){
			cout << now -> val << endl;
			now = now -> nxt;
		}
	}
private:
	struct node{
		node(const T& _val = T{},node* _nxt = NULL):val(_val),nxt(_nxt){}
		T val;
		node* nxt;
	};
	node* head;
};

int main(){
	sorted_Linklist_with_head<int> tmp;
	int a[] = {4,2,6,2,4,71,8,23,0,-2};
	int siz = sizeof(a)/sizeof(int);
	for (int i = 0; i < siz; i++){
		tmp.push(a[i]);
	}
	cout << "print_all" << endl;
	tmp.print_all();
	cout << "erase_cnt: 2" << endl;
	cout << tmp.erase_all(2) << endl;
	cout << "print_all" << endl;
	tmp.print_all();
	cout << "erase_cnt: 3" << endl;
	cout << tmp.erase_all(3) << endl;
	cout << "print_all" << endl;
	tmp.print_all();

	return 0;
}