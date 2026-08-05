#include <iostream>

using namespace std;

class HocSinh {
private:
    string ten;
    double toan;
    double van;

    double diem_trung_binh() {
        return (toan + van) / 2.0;
    }
public:
    HocSinh(): ten("") , toan(0) , van(0) {};
    HocSinh(string s , double a , double b) {
        ten = s;
        if (a < 0) {
            cout << "ERROR , auto format math score == 0";
            toan = 0.0f;
        }
        else toan = a;

        if (b < 0) {
            cout << "ERROR, auto format literature == 0" ;
            van = 0.0f;
        }
        else van = b;
    }

    void nhap_tt() {
        cout << "Ten: ";
        getline(cin , ten);
        cout << "Diem toan: " ;
        cin >> toan;
        while (toan < 0 || toan > 10) {
            cout << "Nhap diem toan hop le: ";
            cin >> toan;
        }

        cout << "Diem van: ";
        cin >> van;
        while (van < 0 || van > 10) {
            cout << "Nhap diem van > 0: ";
            cin >> van;
        }
    }


    void output() {
        cout << ten << " co diem trung binh: " << diem_trung_binh();
    }
};

int main() {
    HocSinh a;
    a.nhap_tt();
    a.output();
}