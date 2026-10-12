#include "lab5_b3_SinhVien.h"
#define EPS 1e-9;

void SinhVien::nhap() {
    cout << "Nhap MSSV: ";
    cin >> mssv;

    cin.ignore();
    cin.clear();
    cout << "Nhap ho ten: ";
    getline(cin , name);

    cout << "Nhap dia chi: ";
    getline(cin , dc);

    cout << "Tong so tin chi: ";
    cin >> tin;
    cout << "Diem GPA: ";
    cin >> gpa;

    while (mssv * gpa <= 0) {
        cout << "Nhap lai mssv ; gpa: ";
        cin >> mssv >> gpa;
    }
}

void SinhVien::xuat() {
    cout << "MSSV: " << mssv << '\n';
    cout << "Ten: " << name << '\n';
    cout << "Dia chi: "<< dc << '\n';
    cout << "Tong so tin chi: " << '\n';
    cout << "Diem GPA: " << gpa;
    cout << "Tot nghiep: ";
    
    if (SinhVien::tot_nghiep()) cout << "SINH VIEN DUOC TOT NGHIEP !";
    else cout << "SINH VIEN KHONG DC TOT NGHIEP !!!!!";
}

float SinhVien::get_gpa() {
    return gpa;
}
int SinhVien::get_tin() {
    return tin;
}