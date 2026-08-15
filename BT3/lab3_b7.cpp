#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class NgayThangNam {
private:
    int ngay;
    int thang;
    int nam;

    bool laNamNhuan() {
        return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
    }
    bool valid_info() {
        if (ngay * thang * nam <= 0 || ngay > 31 || thang > 12)
            return false;
        if (thang == 2 && ngay > 29) 
            return false;
        if (thang == 4|| thang == 6 || thang == 9 || thang == 11) {
            if (ngay > 30) return false;
        }
        if (!laNamNhuan() && ngay == 29 && thang == 2) return false;

        return true;
    }
public:
    NgayThangNam() : ngay(1) , thang(1), nam(1) {};

    void set_ngay(int n) {
        ngay = n;
    }
    int get_ngay() {
        return ngay;
    }

    void set_thang(int t) {
        thang = t;
    }
    int get_thang() {
        return thang;
    }

    void set_nam(int n ) {
        nam = n;
    }
    int get_nam() {
        return nam;
    }
   
    void Nhap() {
        cout << "Nhap ngay, thang ,nam: ";
        cin >> ngay >> thang >> nam;
        while (!valid_info()) {
            cout << "Nhap lai ngay thang nam hop le: ";
            cin >> ngay >> thang >> nam;
        }
    }

    void Xuat() {
        cout << ngay << "/" << thang << "/" << nam;
    }

    bool lonHon(const NgayThangNam &b) {
        // trả về true nếu a già hơn b
        if (nam < b.nam) return true;
        if (nam > b.nam) return false;

        if (thang < b.thang) return true;
        if (thang > b.thang) return false;

        if (ngay < b.ngay) return true;
        return false;
    }

};


class cNhanVien {
private: 
    string ten;
    unsigned int ms;
    NgayThangNam ngay_thang_nam;
    double luong;
public:
    cNhanVien() : ten("") , ms(0), luong(0) {
        NgayThangNam new_ntn;
        ngay_thang_nam = new_ntn;
    }

    cNhanVien(string t , unsigned int mssv , NgayThangNam ntn , double l ) : ten(t) , ms(mssv) , ngay_thang_nam(ntn) , luong(l) {};
    
    void set_ntn(NgayThangNam tmp) {
        ngay_thang_nam = tmp;
    }
    NgayThangNam get_ntn() {
        return ngay_thang_nam;
    }

    void set_luong(double l) {
        luong = l;
    }
    double get_luong() {
        return luong;
    }

   void nhap_nhan_vien() {
        cout << "Nhap ten: ";
        getline(cin , ten);

        cout << "Ma so nhan vien: ";
        cin >> ms;
        while (ms < 0) {
            cout << "Nhap lai ms: ";
            cin >> ms;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ hết newline
        
        //Nhap ngay thang nam sinh: 
        ngay_thang_nam.Nhap();

        cout << "Nhap luong: ";
        cin >> luong;
        while (luong < 0) {
            cout << "Nhap lai luong: ";
            cin >> luong;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ hết newline trước khi quay lại vòng lặp
    }

   void xuat_nhan_vien() {
        cout << "Ten: " << ten << endl;
        cout << "Ma so NV: " << ms << endl;
        cout << "Ngay sinh: ";
        ngay_thang_nam.Xuat();
        cout << endl;
        cout << "Luong: " << luong << endl;
    }

};

class cNhanVienVP {
private: 
    vector<cNhanVien> a;

public:
    cNhanVienVP() {
        vector<cNhanVien> res;
        a = res;
    }

    void nhap_danh_sach_nhan_vien(int n) {
        for (int i = 0 ; i < n ; i++) {
            cNhanVien tmp;
            tmp.nhap_nhan_vien();
            a.push_back(tmp);
        }
    }   

    cNhanVien nhan_vien_luong_max(int n ) {

        cNhanVien tmp = a[0];

        for (int i = 1 ; i < n ; i++) {
            if (a[i].get_luong() > tmp.get_luong()) {
                tmp = a[i];
            }
        }

        return tmp;
    }

    double tong_luong(int n ) {
        double res = 0;
        for (int i = 0 ; i < n ; i++) {
            res += a[i].get_luong();
        }
        return res;
    }

    void tang_dan_theo_luong(int n ) {
        for (int i = 0 ; i < n ; i++) {
            for(int j = i +  1; j < n ; j ++) {
                if (a[i].get_luong() > a[j].get_luong()) {
                    swap(a[i], a[j]);
                }
            }
        }
    }

    void xuat_danh_sach_nhan_vien(int n) {
        cout << "\n===== DANH SACH NHAN VIEN =====\n";
        for (int i = 0; i < n; i++) {
            cout << "\nNhan vien " << i + 1 << ":\n";
            cout << "-----------------------------\n";
            a[i].xuat_nhan_vien();
        }
        cout << "\n===============================\n";
    }

    cNhanVien tuoi_max(int n) {
        cNhanVien old = a[0];
        for (int i = 1 ; i < n ; i++) {
            if (a[i].get_ntn().lonHon(old.get_ntn())) {
                old = a[i];
            }
        }

        return old;
    }
};

int main() {    
    int n = 0;
    cout << "Nhap so nhan vien: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline

    cNhanVienVP ds;
    ds.nhap_danh_sach_nhan_vien(n);

    // 1. Xuất danh sách nhân viên
    ds.xuat_danh_sach_nhan_vien(n);

    // 2. Nhân viên có lương cao nhất
    cout << "\n===== Nhan vien co luong cao nhat =====\n";
    cNhanVien nvLuongMax = ds.nhan_vien_luong_max(n);
    nvLuongMax.xuat_nhan_vien();

    // 3. Tổng lương công ty phải trả
    cout << "\n===== Tong luong cong ty phai tra =====\n";
    double tongLuong = ds.tong_luong(n);
    cout << "Tong luong: " << tongLuong << endl;

    // 4. Nhân viên có tuổi cao nhất
    cout << "\n===== Nhan vien co tuoi cao nhat =====\n";
    cNhanVien nvTuoiMax = ds.tuoi_max(n);
    nvTuoiMax.xuat_nhan_vien();

    // 5. Sắp xếp danh sách tăng dần theo lương
    cout << "\n===== Danh sach sap xep theo luong tang dan =====\n";
    ds.tang_dan_theo_luong(n);
    ds.xuat_danh_sach_nhan_vien(n);

    return 0;
}
