#include "LinkList.h"		// 单链表类
#include "windows.h"
void merge(LinkList<int>&ls1,LinkList<int>&ls2,LinkList<int>&ls3){
	Node<int>*p1 = ls1.head->next;
	Node<int>*p2 = ls2.head->next;
	int counter = 1;
	while(p1!=NULL && p2!=NULL){
		int e1 = p1->data, e2 = p2->data;
		if(e1<=e2) {
			ls3.InsertElem(counter,e1);
			++counter;
			p1 = p1->next;
		}else{
			ls3.InsertElem(counter,e2);
			++counter;
			p2 = p2->next;
		}
	}
	while(p1!=NULL){
		int e1 = p1->data;
		ls3.InsertElem(counter,e1);
		++counter,p1 = p1->next;
	}
	while(p2!=NULL){
		int e2 = p2->data;
		ls3.InsertElem(counter,e2);
		++counter,p2 = p2->next;
	}
	ls3.Reverse();
}
void init(LinkList<int>&la){
	la.Clear();
	int e;
	cout << endl << "输入e(e = 0时退出):";
	cin >> e;
	while (e != 0){
		la.InsertElem(e);
		cin >> e;
	}
}
int main(void)
{
	// SetConsoleOutputCP(CP_UTF8);
	char c = '*';
    LinkList<int> la,lb,lc;
    int e;
	int i;

    while (c != '0')
	{
        cout << endl << "1. 生成单链表.";
        cout << endl << "2. 显示单链表.";
        cout << endl << "3. 取指定位置的元素.";
        cout << endl << "4. 设置元素值.";
        cout << endl << "5. 删除元素.";
        cout << endl << "6. 插入元素.";
		cout << endl << "7. 元素定位";
		cout << endl << "8. 取单链表长度";
		cout << endl << "9. 逆置单向链表";
  		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~9):";
		cin >> c;
		switch (c) 
		{
			case '1':
			    la.Clear();
				cout << endl << "输入e(e = 0时退出):";
				cin >> e;
				while (e != 0)   {
					la.InsertElem(e);
					cin >> e;
				}
				break;
			case '2':
			    la.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "输入元素位置:";
			    cin >> i;
			    if (la.GetElem(i, e) == RANGE_ERROR) 
					cout << "元素不存在." << endl;
				else
					cout << "元素:" << e << endl;
			    break;
			case '4':
			    cout << endl << "输入位置:";
			    cin >> i;
			    cout << endl << "输入元素值:";
			    cin >> e;
				if (la.SetElem(i, e) == RANGE_ERROR)
					cout << "位置范围错." << endl;
				else
					cout << "设置成功." << endl;
			    break;
			case '5':
			    cout << endl << "输入位置:";
			    cin >> i;
			    if (la.DeleteElem(i, e) == RANGE_ERROR) 
					cout << "位置范围错." << endl;
				else
					cout << "被删除元素值:" << e << endl;
			    break;
			case '6':
			    cout << endl << "输入位置:";
			    cin >> i;
			    cout << endl << "输入元素值:";
			    cin >> e;
			    if (la.InsertElem(i, e) == RANGE_ERROR) 
					cout << "位置范围错." << endl;
				else
					cout << "成功:" << e << endl;
			    break;
			case '7':
			    cout << endl << "输入元素的值:";
			    cin >> e;
			    i = la.LocateElem(e);
			    if (i == 0) 
					cout << "元素不存在." << endl;
				else
					cout << "元素" << e << "的序号为：" << i << endl;
			    break;
			case '8':
			    cout << endl << "单链表的长度为:" << la.GetLength()  << endl;
			    break;
		//  case '9':
		//  	la.RemoveRep();
		// 	break;
		 	case '9':
		 		la.Reverse();
				break;
			// case '9':
			// 	cout << "请输入需要删除的元素值："<<'\n';
			// 	int el;
			// 	cin >> el;
			// 	la.Deleval(el);
			// 	break;
			// case '9':
			// 	init(la),init(lb);
			// 	merge(la,lb,lc);
			// 	lc.Traverse(Write<int>);
		}
	}
	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统1
}
