#include "lab5_b2_GiaoDich.h"

GiaoDich::GiaoDich() {
    ma_gd = "";
    gia = 0;
    ngay_gd = Date();
}

void GiaoDich::nhap_gd() {
    cin.ignore(1000, '\n'); 

    cout << "Nhap ma gd: ";
    cin >> ma_gd;

    cout << "nhap ngay gd: (dd mm yyyy) ";
    ngay_gd.nhap_ntn();

    cout << "nhap gia giao dich: ";
    cin >> gia;
}

void GiaoDich::xuat_gd() {
    cout << "Ma giao dich: " << ma_gd << '\n';
    cout << "Ngay giao dich: ";
    ngay_gd.xuat_ntn();
    cout << "Gia giao dich: " << gia << '\n';
    
}

int GiaoDich::get_month() const {
    return ngay_gd.get_thang();
}

int GiaoDich::get_year() const {
    return ngay_gd.get_nam();
}