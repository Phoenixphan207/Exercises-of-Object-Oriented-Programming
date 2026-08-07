#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

class Dinh {
private:
    double a;
    double b;
public:
    Dinh() : a(0) , b(0) {};
    Dinh(double t , double v) : a(t) , b(v) {};

    void set_dinh_a(double a1) {
        a = a1;
    }
    double t1(){
        return a;
    }
    void set_dinh_b(double b1) {
        b =b1;
    }
    double t2() {
        return b;
    }

    void nhap_dinh() {
        cin >> a >> b;
    }
    void xuat_dinh() {
        cout << a << " " << b;
    }

    // TỊNH TIẾN 
    void tinh_tien(double dx, double dy) {
        a += dx;
        b += dy;
    }

    void phong_to_thu_nho(double k) {
        a *= k;
        b *= k;
    }

    void quay(double rad) {
        double a_old = a;
        double b_old = b;
        a = a_old * cos(rad) - b_old * sin(rad);
        b = a_old * sin(rad) + b_old * cos(rad);
    }
};


class cTamGiac {
private: 
    Dinh A;
    Dinh B;
    Dinh C;

    // Hàm phụ trợ so sánh số thực tránh sai số
    bool bang_nhau(double x, double y) {
        return abs(x - y) < EPS;
    }
    
    double ab() {
        double dx = A.t1() - B.t1();
        double dy = A.t2() - B.t2();
        double c = dx*dx + dy*dy;
        // c is the squared distance between A and B
        return sqrt(c);
    }
    double ac() {
        double dx = A.t1() - C.t1();
        double dy = A.t2() - C.t2();
        double c = dx*dx + dy*dy;
        // c is the squared distance between A and C
        return sqrt(c);
    }
    double bc() {
        double dx = C.t1() - B.t1();
        double dy = C.t2() - B.t2();
        double c = dx*dx + dy*dy;
        // c is the squared distance between A and B
        return sqrt(c);
    }
    bool valid_info() {
        double a = ab();
        double b = bc();
        double c = ac();

        return (a + b > c + EPS) && (a + c > b + EPS) && (b + c > a + EPS);
    }
public:
    cTamGiac() : A(0,0) , B(0,0), C(0,0) {};
    cTamGiac(Dinh a1 , Dinh a2, Dinh a3) : A(a1) , B(a2) , C(a3) {};

    void Nhap() {
        cout << "Nhap dinh A: " ;
        A.nhap_dinh();
        cout << "Nhap dinh B: ";
        B.nhap_dinh();
        cout << "Nhap dinh C: ";
        C.nhap_dinh();

        while (!valid_info()) {
            cout << "Nhap lai dinh A: " ;
            A.nhap_dinh();
            cout << "Nhap lai dinh B: ";
            B.nhap_dinh();
            cout << "Nhap lai dinh C: ";
            C.nhap_dinh();
        }
        
    }

   void check_loai() {
        double c1 = ab(), c2 = bc(), c3 = ac();

        bool vuong = bang_nhau(c1*c1 + c2*c2, c3*c3) ||
                     bang_nhau(c1*c1 + c3*c3, c2*c2) ||
                     bang_nhau(c2*c2 + c3*c3, c1*c1);

        bool deu = bang_nhau(c1, c2) && bang_nhau(c2, c3);
        bool can = bang_nhau(c1, c2) || bang_nhau(c2, c3) || bang_nhau(c1, c3);

        if (deu) {
            cout << "Tam giac deu";
        } else if (can) {
            if (vuong) cout << "Tam giac vuong can";
            else cout << "Tam giac can";
        } else {
            if (vuong) cout << "Tam giac vuong";
            else cout << "Tam giac thuong";
        }
    }


    double chu_vi(){
        return ab() + bc() + ac();
    }

    double dien_tich() {
        return 0.5 * abs(A.t1() * (B.t2() - C.t2()) + B.t1() * (C.t2() - A.t2()) + C.t1() * (A.t2() - B.t2()));
    }

    void Xuat() {
        cout <<endl << "Dien tich: " ;
        cout << dien_tich();
        cout << endl << "Chu vi: ";
        cout << chu_vi();
    }

    // 1. Tịnh tiến theo vector (dx, dy)
    void tinh_tien(double dx, double dy) {
        A.tinh_tien(dx, dy);
        B.tinh_tien(dx, dy);
        C.tinh_tien(dx, dy);
    }

    // 2. Phóng to / Thu nhỏ theo hệ số k
    void phong_to_thu_nho(double k) {
        A.phong_to_thu_nho(k);
        B.phong_to_thu_nho(k);
        C.phong_to_thu_nho(k);
    }

    // 3. Quay tam giác quanh gốc O một góc (tính theo độ)
    void quay(double goc_do) {
        double rad = goc_do * M_PI / 180.0; // Đổi góc độ sang radian
        A.quay(rad);
        B.quay(rad);
        C.quay(rad);
    }
};

int main() {
    cTamGiac a;
    a.Nhap();

    cout << "\n=== THONG TIN BAN DAU ===";
    a.Xuat();
    cout << "Loai tam giac: ";
    a.check_loai();
    cout << endl;

    // Kiểm thử phép Tịnh Tiến
    cout << "\n=== THUC HIEN TINH TIEN VECTOR (2, 3) ===";
    a.tinh_tien(2, 3);
    a.Xuat();

    // Kiểm thử Phóng To
    cout << "\n=== THUC HIEN PHONG TO 2 LAN (k = 2) ===";
    a.phong_to_thu_nho(2);
    a.Xuat();

    // Kiểm thử Quay
    cout << "\n=== THUC HIEN QUAY 90 DO QUANH GOC O ===";
    a.quay(90);
    a.Xuat();
    return 0;
}
