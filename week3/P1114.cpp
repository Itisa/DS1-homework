#include <bits/stdc++.h>

using namespace std;

struct node {
	int id;
	node* lson;
	node* rson;
	node(int _id) : id(_id),lson(NULL),rson(NULL){}
};

vector<int> P11(node* root){
	vector<int> result;
	stack<node*> stack;
	node* current = root;

	while (current != NULL || !stack.empty()) {
		while (current != NULL) {
			stack.push(current);
			current = current->lson;
		}

		current = stack.top();
		stack.pop();
		result.push_back(current->id);

		current = current->rson;
	}

	return result;
}

int P14(node* root){
	if (root -> lson == NULL && root -> rson == NULL){
		return 1;
	} else {
		int cnt = 0;
		if (root -> lson != NULL){
			cnt += P14(root -> lson);
		}
		if (root -> rson != NULL){
			cnt += P14(root -> rson);
		}
		return cnt;
	}
}

int main(){
	node* root = new node(1);
    root->rson = new node(2);
    root->rson->lson = new node(3);
    vector<int> mid = P11(root);
    int cnt = P14(root);
    for (int i = 0; i < mid.size(); i++){
    	cout << mid[i] << " ";
    }
    cout << "\n";
    cout << cnt << "\n";
    

	return 0;
}