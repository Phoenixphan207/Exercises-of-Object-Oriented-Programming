#pragma once

#include <iostream>
using namespace std;

class SinhVien {
private:
    int mssv;
    string name;
    string dc;
    int tin;
    float gpa;
public:
    virtual ~SinhVien() = default;
    SinhVien() : mssv(0) , name("") , dc("") , tin(0) ,gpa(0.0) {};
    float get_gpa();
    int get_tin();

    virtual void nhap();
    virtual void xuat();

    virtual bool tot_nghiep() = 0;
    virtual int loai_sinh_vien() = 0; //1: CaoDang ; 2: DaiHoc
};