#include "lab5_b3_Truong.h"

int main() {
    Truong us;
    us.nhap_danh_sach();

    cout << "___________Danh sach cac sinh vien___________________:" << '\n';
    us.xuat_danh_sach();

    cout << endl;
    cout << "___________Du dk tot nghiep__________________________:" << '\n';
    us.sinh_vien_tn();
    
    cout << endl;
    cout << "___________Ko dc Tot nghiep__________________________:" << '\n';
    us.sinh_vien_ko_tn();

    cout << endl;
    cout << "___________Sinh vien Dai hoc co diem GPA MAX_________:" << '\n';
    SinhVien* tmp1 = us.dai_hoc_diem_max();
    tmp1->xuat();

    cout << endl;
    cout << "___________Sinh vien Cao Dang co diem GPA MAX________:" << '\n';
    SinhVien* tmp = us.cao_dang_diem_max();
    tmp->xuat();

    cout << endl;
    cout << "___________So sinh vien khong tot nghiep______________:" << '\n';
    us.sinh_vien_ko_tn_moi_loai();


}