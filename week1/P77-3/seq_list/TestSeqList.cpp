#include "SeqList.h"	// 顺序表类
#include <iostream>
using namespace std;
template<class T>
void Merge_List(const SeqList<T>& la, const SeqList<T>& lb, SeqList<T>& lc) {
    int i = 1, j = 1;
    int counter = 0;
	int lena = la.GetLength(), lenb = lb.GetLength();
    // 合并两个有序表
    while (i <= lena && j <= lenb) {
        T e1, e2;
        la.GetElem(i, e1);  // 获取la中的元素
        lb.GetElem(j, e2);  // 获取lb中的元素
        // 比较两个表当前元素的大小
        if (e1 <= e2) {
            lc.InsertElem(counter, e1);
            ++i;
        } else {
            lc.InsertElem(counter, e2);
            ++j;
        }
        ++counter;
    }
    // 如果la还有剩余元素，直接插入到lc中
    while (i<=lena) {
        T e1;
        la.GetElem(i, e1);
        lc.InsertElem(counter, e1);
        ++i;
        ++counter;
    }
    // 如果lb还有剩余元素，直接插入到lc中
    while (j<=lenb) {
        T e2;
        lb.GetElem(j, e2);
        lc.InsertElem(counter, e2);
        ++j;
        ++counter;
    }
}
int main(void)
{
	char c = '*';
    SeqList<int> la(20),lb(20),lc(20);
    int e, i;
    Status sta;
	while (c != '0')
	{
        cout << endl << "1. 生成线性表.";
        cout << endl << "2. 显示线性表.";
        cout << endl << "3. 取指定元素.";
        cout << endl << "4. 设置元素值.";
        cout << endl << "5. 删除元素.";
        cout << endl << "6. 插入元素.";
        cout << endl << "7. 元素定位.";
        cout << endl << "8. 求线性表长度.";
		cout << endl << "9. 逆置线性表.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~9):";
		cin >> c;
		switch (c) 	{
			case '1':
			    la.Clear();
			    sta = SUCCESS;
				cout << endl << "输入e(e = 0时退出):";
				cin >> e;
				while (e != 0 && sta != OVER_FLOW)	{
					sta = la.InsertElem(e);
					if (sta == OVER_FLOW) 
						cout << "线性表已满." << endl;
					else
						cin >> e;
				}
				break;
			case '2':
			    la.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "输入元素位置:";
			    cin >> i;
			    if (la.GetElem(i, e) == NOT_PRESENT) 
					cout << "元素不存储." << endl;
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
			    sta = la.InsertElem(i, e);
			    
			    if (sta == RANGE_ERROR) 
					cout << "位置范围错." << endl;
				else if (sta == OVER_FLOW) 
					cout << "线性表已满." << endl;
				else
					cout << "插入成功." << endl;	
			    break;
			case '7':
			    cout << endl << "输入元素值:";
			    cin >> e;
			    i = la.LocateElem(e); 
			    if (i != 0) 
					cout << "元素" << e << "的序号为：" << i << endl;
				else

					cout << "元素" << e << "不存在。"  << endl;
			    break;
			case '8':
			    cout << endl << "线性表的长度为:" << la.GetLength() << endl; 
			    break;
			// case '9':
			// 	la.RemoveRep();
			// 	break;
			// 
			// case '9':
			// 	int s,t;
			// 	cout << "请输入s："<<'\n';
			// 	cin >> s;
			// 	cout << "请输入t:" <<'\n';
			// 	cin >> t;
			// 	la.RemoveStT(s,t);
			case '9':
				la.Reverse();
				break;
			// case '9':
			// 	int a[6] = {1,6,7,9,10,30},b[4] = {3,4,8,9};
			// 	SeqList<int>list1(a,6,10),list2(b,4,10),list3;
			// 	// list2.Traverse(Write<int>);
			// 	Merge_List(list1,list2,list3);
				
       	}
	}
   	system("PAUSE");        		// 调用库函数system()，暂停程序运行 
   	return 0;               		// 返回操作系统
}


