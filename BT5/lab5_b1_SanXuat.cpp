#include "lab5_b1_NhanVienSX.h"
#include <iostream>

void NhanVienSX::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so san pham: ";
    cin >> san_pham;
    cout << "Nhap luong co ban: ";
    cin >> luong_base;
    luong = luong_base + san_pham * 5;
}

void NhanVienSX::Xuat() {
    NhanVien::Xuat();
    cout << "So San Pham: " << san_pham << '\n';
    cout << "Luong co ban: " << luong_base << '\n';
}