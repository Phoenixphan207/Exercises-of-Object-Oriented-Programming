#include <iostream>
#include <vector>
#include <limits>

using namespace std;
#define ESP 1e-6
class cCandidate {
private: 
    unsigned int mssv;
    string ten;
    string ngay_thang_nam;
    double toan;
    double van;
    double anh;
public:
    cCandidate(unsigned int a , string t , string ntn , double dt, double dv,  double da) : 
        mssv(a) , ten(t) , ngay_thang_nam(ntn) , toan(dt) , van(dv), anh(da) {};
    cCandidate() : mssv(1)  , ten("") , ngay_thang_nam("") , toan(0), van(0), anh(0) {};

    void set_toan(double t) {
        toan = t;
    }
    double get_toan() {
        return toan;
    }

    void set_van(double v) {
        van = v;
    }
    double get_van(){
        return van;
    }

    void set_anh(double a) {
        anh = a;
    }
    double get_anh() {
        return anh;
    }

    double tong_diem() {
        return toan + van + anh;
    }


  void nhap_thi_sinh() {
        do {
            cout << "MSSV : ";
            cin >> mssv;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (mssv <= 0) {
                cout << "MSSV phai lon hon 0. Nhap lai!\n";
            }
        } while (mssv <= 0);

        cout << "Ten: ";
        getline(cin, ten);

        cout << "Ngay thang nam sinh: ";
        getline(cin, ngay_thang_nam);

        // Nhập điểm trong khoảng 0–10
        do {
            cout << "Nhap diem toan , van , anh (0–10): ";
            cin >> toan >> van >> anh;
            if (toan < 0 || toan > 10 || van < 0 || van > 10 || anh < 0 || anh > 10) {
                cout << "Tat ca diem phai trong khoang 0–10. Nhap lai!\n";
            }
        } while (toan < 0 || toan > 10 || van < 0 || van > 10 || anh < 0 || anh > 10);
    }


    void xuat_thi_sinh() {
        cout << endl;
        cout << "MSSV: " << mssv << '\n';
        cout << "Ten: " << ten << '\n';
        cout << "Ngay thang nam sinh: " << ngay_thang_nam << endl;
        cout << "Diem toan , van , anh: " << toan << " " << van << " " << anh << endl;
    }


};

class cListCandidate {
private: 
    vector<cCandidate> a;
public:
    cListCandidate(vector<cCandidate> res) : a(res) {};

    void nhap_danh_sach_cac_thi_sinh(int n) {
        for (int i = 0 ; i < n ; i++) {
            a[i].nhap_thi_sinh();
        }
    }

    void xuat_danh_sach() {
        for (int i = 0 ; i < a.size() ; i++) {
            a[i].xuat_thi_sinh();
        }
    }

    void tong_diem_lon_hon15() {
        for (int i = 0 ; i < a.size() ; i++) {
            if ((a[i].tong_diem() - 15.0) > ESP) { 
                a[i].xuat_thi_sinh();
            }
        }
    }

    cCandidate tong_diem_max() {
        cCandidate tmp = a[0];
        for (int i = 1 ; i < a.size() ; i++) {
            if (a[i].tong_diem() > tmp.tong_diem()) {
                tmp = a[i];
            }
        }
        return tmp;
    }

    void giam_dan_theo_tong_diem() {
        for (int i = 0 ; i < a.size() ; i++) {
            for (int j = i + 1 ; j < a.size() ; j++) {
                if (a[i].tong_diem() < a[j].tong_diem()) {
                    swap(a[i] , a[j]);
                }
            }
        }
    }
};

int main() {
    int n = 0;
   
    cout << "nhap n : " ;
    cin >> n;
    vector<cCandidate> res(n);


    cListCandidate a(res);
    
    a.nhap_danh_sach_cac_thi_sinh(n);

    cout << "________________KET QUA__________________" << endl;
    cout << "__Tong diem lon hon 15: __" << endl;
    a.tong_diem_lon_hon15();

    cCandidate tmp = a.tong_diem_max();
    cout << endl;
    cout << "__Tong diem max: __" ;
    tmp.xuat_thi_sinh();

    cout << endl;
    cout << "__Sap xep theo tong diem giam dan: __ ";
    a.giam_dan_theo_tong_diem();
    a.xuat_danh_sach();
}