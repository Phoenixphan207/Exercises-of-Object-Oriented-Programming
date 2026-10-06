#include "lab5_b2_ChungCu.h"

void ChungCu::nhap_gd() {
    GiaoDich::nhap_gd();
    cout << "Nhap ma can chung cu: " << '\n';
    cin >> ma_can;
    cout << "Nhap tang: " << '\n';
    cin >> tang;
    cout << "Nhap dien tich can cc: " << '\n';
    cin >> s;
}

double ChungCu::thanh_tien_gd() {
    double tien = 0.0;
    if (tang == 1) {    
        tien = s * gia * 2;
    }
    else if (tang >= 1 && tang < 15) {
            tien = s * gia;
        }
    else tien = s * gia * 1.2;

    return tien;
}


void ChungCu::xuat_gd() {
    GiaoDich::xuat_gd();
    cout << "Ma can chung cu: " << ma_can << '\n';
    cout << "Tang: " << tang << '\n';
    cout << "Dien tich chung cu: " << s;
    cout << '\n' << "Thanh tien: " << ChungCu::thanh_tien_gd();
}
