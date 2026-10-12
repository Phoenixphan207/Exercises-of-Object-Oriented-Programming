#pragma once

#include "lab5_b3_SinhVien.h"

class CaoDang : public SinhVien {
private: 
    float diem;
public: 
    void nhap() override;
    void xuat() override;
    float get_diem() {
        return diem;
    }
    int loai_sinh_vien() override {
        return 1;
    }
    bool tot_nghiep() override;
};