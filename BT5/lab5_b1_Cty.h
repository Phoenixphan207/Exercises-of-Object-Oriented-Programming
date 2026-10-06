#pragma once 
#include <vector>
#include "lab5_b1_NhanVien.h"
using namespace std;

class Cty {
private:    
    int so_nhan_vien;
    vector<NhanVien> danhSach;

public: 
    void nhap();
    void xuat();
    double tong_luong();
    NhanVien* luong_min();
    NhanVien* tuoi_max();
    void in_nv_tuoi_max();
    void in_nv_luong_min();

};