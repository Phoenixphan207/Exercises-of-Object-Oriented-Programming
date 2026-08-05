#include <iostream>

using namespace std;

class PhanSo{
private:
    int tu_so;
    int mau_so;

    int gcd() {
        int a = abs(tu_so);
        int b = abs(mau_so);

        while (b != 0) {
            int temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
public:
    PhanSo() : tu_so(0) , mau_so(1) {};
    PhanSo(int a, int b) { 
        tu_so = a;
        if (b == 0) {
            cout << "ERROR , auto format mau_so = 1 ";
            mau_so = 1;
        }
        else mau_so = b;
    }

    void nhap_pso() {
        cout << "Nhap tu so: " ;
        cin >> tu_so;
        
        cout << "Nhap mau so : ";
        cin >> mau_so;
        while (mau_so == 0) {
            cout << "Nhap lai mau so != 0: " ;
            cin >> mau_so;
        }
    }

    
    void rut_gon() {
        int c = gcd();

        tu_so /= c;
        mau_so /= c;

        if (mau_so < 0) {
            tu_so = -tu_so;
            mau_so = -mau_so;
        }
    }

    void xuat_kq() {
        if (mau_so == 1) cout << tu_so;
        else cout << tu_so << "/" << mau_so;
    }
};

int main() {
    PhanSo a(1 , 0);
    a.nhap_pso();
    a.rut_gon();
    a.xuat_kq();

    return 0;
}