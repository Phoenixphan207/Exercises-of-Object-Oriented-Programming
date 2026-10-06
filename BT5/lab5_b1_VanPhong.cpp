#include "lab5_b1_NhanVienVP.h"
#include <iostream>

using namespace std;

void NhanVienVP::Nhap() {
    NhanVien::Nhap();
    cout << "So ngay lam: " ;
    cin >> so_ngay_lam;
    luong = so_ngay_lam * 100;
}

void NhanVienVP::Xuat() {
    NhanVien::Xuat();
    cout << "So ngay lam viec: " << so_ngay_lam;
}

