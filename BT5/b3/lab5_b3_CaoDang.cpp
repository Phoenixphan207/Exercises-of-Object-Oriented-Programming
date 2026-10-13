#include "lab5_b3_CaoDang.h"
#define EPS 1e-9

void CaoDang::nhap() {
    SinhVien::nhap();
    cout << "Nhap diem thi TN: ";
    cin >> diem;
    while (diem < 0) {
        cout << "Nhap lai diem thi: ";
        cin >> diem;
    }
}

void CaoDang::xuat() {
    SinhVien::xuat();
    cout << "Diem thi TN: " << diem << endl;
}

bool CaoDang::tot_nghiep() {
    if (((this->get_gpa() - 5) > EPS) && (this->get_tin() > 120) && (this->get_diem() - 5) > EPS) {
        return true;
    }
    return false;
}