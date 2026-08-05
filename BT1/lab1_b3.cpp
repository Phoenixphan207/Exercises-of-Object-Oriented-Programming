#include <iostream>

using namespace std;

class PhanSo {
private:
    int tu_so;
    int mau_so;

    int gcd() {
        int a = abs(tu_so);
        int b = abs(mau_so);

        while (b != 0) {
            int temp  = a%b;
            a = b;
            b = temp;
        }
        return a;
    }

public:
    PhanSo(int a , int b) {
        tu_so = a;

        if (b == 0) {
            cout << "ERROR , auto format mau_so == 1";
            mau_so = 0;
        }
        else mau_so = b;
    }

    void nhap_pso() {
        cout << "Nhap tu: ";
        cin >> tu_so;

        cout << "Nhap mau: ";
        cin >> mau_so;
        while (mau_so == 0) {
            cout << "ERROR, nhap lai: ";
            cin >> mau_so;
        }
    }

    PhanSo tong_2_pso(PhanSo a1, PhanSo a2) {
        a1.tu_so = a1.tu_so * a2.mau_so + a1.mau_so * a2.tu_so;
        a1.mau_so = a1.mau_so * a2.mau_so;
        return a1;
    }
    PhanSo hieu_2_pso(PhanSo a1, PhanSo a2) {
        a1.tu_so = a1.tu_so * a2.mau_so - a1.mau_so * a2.tu_so;
        a1.mau_so = a1.mau_so * a2.mau_so;

        return a1;
    }
    PhanSo tich_2_pso(PhanSo a1, PhanSo a2) {
        a1.tu_so *= a2.tu_so;
        a1.mau_so *= a2.mau_so;
        return a1;
    }
    PhanSo chia_2_pso(PhanSo a1, PhanSo a2) {
        if (a2.tu_so == 0) {
            cout << "ERROR";
            return {0,1};
        }
        
        a1.tu_so *= a2.mau_so;
        a1.mau_so *= a2.tu_so;
        return a1;
    }

        
    void rut_gon() {
        int a = gcd();

        tu_so /= a;
        mau_so /= a;

        if (mau_so < 0) {
            tu_so = -tu_so;
            mau_so = -mau_so;
        }
    }
    void output() {
        if (mau_so == 1) cout << tu_so;
        else cout << tu_so << "/" << mau_so;
    }
};

int main() {
    PhanSo a1(1,1);
    PhanSo a2(1,1);

    a1.nhap_pso();
    a2.nhap_pso();

    char s;
    cout << "Nhap cach tinh" ;
    cin >> s;
    
    PhanSo res(1,1);
    if (s == '+') {
        res = res.tong_2_pso(a1, a2);
    }
    else if (s == '-') {
        res = res.hieu_2_pso(a1 , a2);
    }
    else if (s == '*') {
        res = res.tich_2_pso(a1, a2);
    }
    else if (s == '/') {
        res = res.chia_2_pso(a1 ,a2);
    }
    res.rut_gon();
    res.output();
}