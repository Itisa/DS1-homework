#include "polynomial.h"

int main() {
    poly p;
    cout << "创建多项式" << endl;
    cout << "输入系数和指数（输入0 0结束）：" << endl;
    double n, m;
    while (1) {
        cin >> n >> m;
        if (n != 0 || m != 0) {
            p.insert(n, m);
        }
        else { break; }
    }
    p.display();
    double x;
    cout << "请输入x的值:";
    cin >> x;
    cout << "多项式的结果为：" << p.calc(x) << endl;
    return 0;
}