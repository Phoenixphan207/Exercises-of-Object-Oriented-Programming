#pragma once 
#include "lab5_b1_NhanVien.h"

using namespace std;

class NhanVienVP: public NhanVien {
private: 
    int so_ngay_lam;
public: 
    void Nhap() override;
    void Xuat() override;
};