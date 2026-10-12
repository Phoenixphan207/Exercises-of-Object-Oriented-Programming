#include "lab5_b3_SinhVien.h"
#include "lab5_b3_CaoDang.h"
#include "lab5_b3_DaiHoc.h" 
#include <vector>

class Truong {
private: 
    vector<SinhVien*> danhSach;

public: 
    void nhap_danh_sach();
    void xuat_danh_sach();

    void sinh_vien_tn();
    void sinh_vien_ko_tn();

    SinhVien dai_hoc_diem_max();
    SinhVien cao_dang_diem_max();

    void sinh_vien_ko_tn_moi_loai();
};