#include "polynomial.h"

int main() {
    poly p;
    cout << "��������ʽ" << endl;
    cout << "����ϵ����ָ��������0 0��������" << endl;
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
    cout << "������x��ֵ:";
    cin >> x;
    cout << "����ʽ�Ľ��Ϊ��" << p.calc(x) << endl;
    return 0;
}