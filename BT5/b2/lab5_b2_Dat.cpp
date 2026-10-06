#include "lab5_b2_Dat.h"

void Dat::nhap_gd() {
    GiaoDich::nhap_gd();
    cout << "Nhap loai dat: (A,B,C) ";
    cin >> loai_dat;
    cout << "Nhap dien tich dat: ";
    cin >> s;
}

double Dat::thanh_tien_gd() {
    double tien = 0.0;

    if (loai_dat == 'B' || loai_dat == 'C' ) {
        tien = s * gia;
    }
    else tien = s * gia * 1.5;

    return tien;
}

void Dat::xuat_gd(){
    GiaoDich::xuat_gd();
    cout << "Loai dat: " << loai_dat << "'\n";
    cout << "Thanh tien: " << Dat::thanh_tien_gd();
}