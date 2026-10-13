#include "lab5_b3_SinhVien.h"
#define EPS 1e-9;

void SinhVien::nhap() {
    cout << "Nhap MSSV: ";
    cin >> mssv;

    cout << "Nhap ho ten: ";
    getline(cin >> ws, name);

    cout << "Nhap dia chi: ";
    getline(cin , dc);

    cout << "Tong so tin chi: ";
    cin >> tin;
    cout << "Diem GPA: ";
    cin >> gpa;

    while (gpa <= 0) {
        cout << "Nhap lai mssv ; gpa: ";
        cin >> gpa;
    }
}

void SinhVien::xuat() {
    cout << "MSSV: " << mssv << '\n';
    cout << "Ten: " << name << '\n';
    cout << "Dia chi: "<< dc << '\n';
    cout << "Tong so tin chi: " << tin << '\n';
    cout << "Diem GPA: " << gpa << '\n';
    
}

float SinhVien::get_gpa() {
    return gpa;
}
int SinhVien::get_tin() {
    return tin;
}