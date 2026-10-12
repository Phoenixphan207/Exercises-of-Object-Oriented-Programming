#include "lab5_b3_DaiHoc.h"
#define EPS 1e-9
void DaiHoc::nhap() {
    SinhVien:nhap();
    cout << "Nhap ten luan van: ";
    getline(cin , luan_van);

    cout << "Nhap diem luan van: ";
    cin >> lv;
    while (lv < 0) {
        cout << "Nhap lai diem luan van: ";
        cin >> lv;
    }
}

void DaiHoc::xuat() {
    SinhVien:xuat();
    cout << "Ten luan van: " << luan_van << '\n';
    cout << "Diem luan van: " << lv << '\n';
}

bool DaiHoc::tot_nghiep() {
    if ((this->get_gpa() - 5) > EPS &&  (this->get_tin() > 170) && (this->get_lv() - 5) > EPS) {
        return true;
    }
    return false;
}