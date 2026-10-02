#include "lab5_b1_NhanVien.h"

using namespace std;

NhanVien::NhanVien() {
    name = "";
    ntn = CDate();
    luong = 0;
}

void NhanVien::Nhap() {
    cout << "Nhap ten: ";
    getline(cin , name);
    cout << "Nhap ngay thang nam sinh: ";
    ntn.nhap_ngay_thang_nam();
}

void NhanVien::Xuat() {
    cout << "Ho ten: " << name;
    cout << "Ngay thang nam sinh: ";
    ntn.xuat_ngay_thang_nam();
    cout << "Luong: " << luong;
}

double NhanVien::luong_chinh() {
    return luong;
}

long NhanVien::so_ngay_tu1900() {
    return ntn.tong_so_ngay_tu_1900();
}