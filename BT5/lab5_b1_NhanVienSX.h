#pragma once 
#include "lab5_b1_NhanVien.h"

using namespace std;

class NhanVienSX : public NhanVien {
private: 
    int san_pham;
    double luong_base;

public:
    void Nhap() override;
    void Xuat() override;
    
};