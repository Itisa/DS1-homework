#include "LinkList.h"		// ��������

int main(void)
{
	int a[5] = {1,2,3,45,11};
	int b[4] = {6,7,8,9};
	LinkList<int> list1(a,5);
	LinkList<int> list2(b,4);
	LinkList<int> list3;
	list3.MergeAndSort(list1,list2);
	list3.printList();
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
