#include <iostream>
#include <vector>
#include <cmath>
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
    PhanSo(): tu_so(0) , mau_so(1) {};
    PhanSo(int a , int b) {
        tu_so = a;
        if (b == 0) {
            cout << "ERROR , auto format mau_so = 1";
            mau_so = 1;
        }
        else mau_so = b;
    }

    void rut_gon() {
        int a = gcd();
        tu_so /= a;
        mau_so /= a;

        if (mau_so < 0) {
            tu_so = - tu_so;
            mau_so = - mau_so;
        }
    }
    void setTu(int tu) {
        tu_so = tu;
    }
    int getTu() {
        return tu_so;
    }
    void setMau(int mau) {
        mau_so = mau;
    }
    int getmau() {
        return mau_so;
    }

    void tong_2_pso(PhanSo a2) {
        tu_so = tu_so * a2.mau_so + a2.tu_so * mau_so;
        mau_so = mau_so * a2.mau_so;
    }

    PhanSo hieu_2_pso( PhanSo a2) {
        tu_so = tu_so * a2.mau_so - mau_so * a2.tu_so;
        mau_so = mau_so * a2.mau_so;

        return {tu_so , mau_so};
    }
    void nhap_ps() {
        cout << "Nhap tu: ";
        cin >> tu_so;
        cout << "Nhap mau: ";
        cin >> mau_so;

        while (mau_so == 0) {
            cout << "Nhap lai mau: ";
            cin >> mau_so;
        }
    }

    void xuat_ps() {
        rut_gon();
        if (mau_so < 0) {
            tu_so = -tu_so;
            mau_so = -mau_so;
        }
        if (mau_so == 1 ) cout << tu_so;
        else  cout << tu_so << "/" << mau_so << endl;
    }

    bool nho_hon(PhanSo a2) {
        return (tu_so * a2.mau_so - mau_so * a2.tu_so) > 0;
    }   
    
    bool tu_is_prime() {
        rut_gon(); 
        
        if (tu_so < 2) return false;
        for (int i = 2; i * i <= tu_so; i++) {
            if (tu_so % i == 0) return false;
        }
        return true;
    }
};

class cDSPhanSo{
private:
    vector<PhanSo> a;

    int min_arr(const vector<int> a) {
        int ans = a[0];
        for (int i = 1 ; i < a.size() ; i++){
            if (a[i] < ans) {
                ans = a[i];
            }
        }
        return ans;
    }
public:
    cDSPhanSo(vector<PhanSo> res) : a(res) {};

    PhanSo tong_pso() {
        PhanSo tong(0,1);
        for (int i = 0 ; i < a.size() ; i++) {
            tong.tong_2_pso(a[i]);
        }
        return tong;
    }

    PhanSo max() {
        if (a.empty()) return {0,1};

        PhanSo max_ans = a[0];
        for (int i = 1 ; i < a.size() ; i++) {
            PhanSo tmp = a[i];
            PhanSo hieu = tmp.hieu_2_pso(max_ans);

            if (hieu.getTu() > 0) max_ans = a[i]; 
        }
        return max_ans;
    }
    PhanSo min() {
        if (a.empty()) return {0,1};

        PhanSo min_ans = a[0];
        for (int i = 1 ; i < a.size() ; i++) {
            PhanSo tmp = a[i];
            PhanSo hieu = tmp.hieu_2_pso(min_ans);

            if (hieu.getTu() < 0) min_ans = a[i]; 
        }
        return min_ans;
    }

    void decreasing() {
        for (int i = 0 ; i < a.size() ; i++) 
        {
            for (int j = i + 1 ; j < a.size() ; j++) {
                if (a[i].nho_hon(a[j])) 
                    swap(a[i] , a[j]);
            }
        }
    }
    void increasing() {
        for (int i = 0 ; i < a.size() ; i++) {
            for (int j = i+1 ; j < a.size() ; j++) {
                if (!a[i].nho_hon(a[j])) 
                    swap(a[i] , a[j]);
            }
        }
    }

    PhanSo max_tu_is_prime() {
        PhanSo max_ps(0, 1);
        int max_prime = -1;

        for (int i = 0; i < a.size(); i++) {
            if (a[i].tu_is_prime()) {
                if (a[i].getTu() > max_prime) {
                    max_prime = a[i].getTu();
                    max_ps = a[i];
                }
            }
        }
        
        if (max_prime == -1) {
            cout << "Khong co phan so nao co tu la so nguyen to!\n";
        }
        
        return max_ps;
    }
    void xuat_day() {
        for (int i = 0 ; i < a.size() ; i++) {
            a[i].xuat_ps();
        }
    }

};


int main() {
    vector<PhanSo> a;
    a.push_back(PhanSo(1,2));
    a.push_back(PhanSo(2,5));
    a.push_back(PhanSo(3,4));
    a.push_back(PhanSo(6,8));
    a.push_back(PhanSo(5,9));
    a.push_back(PhanSo(1,1));
    cDSPhanSo res(a);
    // PhanSo temp = res.tong_pso();
    // temp.xuat_ps();

    // PhanSo phat = res.max();
    // PhanSo phat2 = res.min();
    // phat.xuat_ps(); 
    // cout << endl;
    // phat2.xuat_ps();s
    // cout << "Tang: " << endl;
    // res.increasing();
    // res.xuat_day();
    PhanSo tmp = res.max_tu_is_prime();
    tmp.xuat_ps();
}