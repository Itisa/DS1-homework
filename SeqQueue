#include "SeqQueue.h"	// 循环队列类

int  main(void)
{
	char c = '1';
	//cout <<222 << endl;
    SeqQueue<int> qa(10);
    int x;
	//cout << 111 << endl;
    while (c != '0')
	{
        cout << endl << "1. creat queue.";
        cout << endl << "2. show queue.";
        cout << endl << "3. in queue.";
        cout << endl << "4. push queue.";
        cout << endl << "5. Get front.";
		cout << endl << "0. Break";
		cout << endl << "choose function(0~5):";
		cin >> c;
		switch (c) 
		{
			case '1':
                qa.Clear();
				cout << endl << "cin_e(when e = 0,break)";
				cin >> x;
				while (x != 0)	{
					qa.EnQueue(x);
					cin >> x;
				}
				break;
			case '2':
				cout << endl;
				qa.Traverse(Write<int>);
				break;
			case '3':
				cout << endl << "input element:";
				cin >> x;
				if (qa.EnQueue(x) == OVER_FLOW)
					cout << endl << "queue is full!";
				else
					cout << endl << "succese in queue.";
				break;
			case '4':
				qa.DelQueue(x);
				cout << endl << "the front element is" << x << " ." << endl;
				break;
			case '5':
				qa.GetHead(x);
				cout << endl << "the front element is" << x << " ." << endl;
				break;
		}
	}

	system("PAUSE"); 
	return 0;    

}
