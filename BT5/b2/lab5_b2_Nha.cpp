#include "lab5_b2_Nha.h"

void Nha::nhap_gd() {
    GiaoDich::nhap_gd(); // Bên trong hàm này kết thúc bằng `cin >> gia;`
    
    cout << "nhap loai nha: (Cao cap , Thuong) ";
    getline(cin >> ws, loai_nha); // cin >> ws tự động dọn phím Enter thừa từ cin >> gia

    cout << "nhap dia chi: ";
    getline(cin, address); // KHÔNG dùng cin.ignore() ở đây!

    cout << "nhap dien tich: ";
    cin >> s;
}
void Nha::xuat_gd() {
    GiaoDich::xuat_gd();
    cout << "Loai nha: " << loai_nha << '\n';
    cout << "Dia chi: " << address << '\n';
    cout << "Dien tich: " << s << '\n';
    cout << "Thanh tien nha o: " << Nha::thanh_tien_gd();

}

double Nha::thanh_tien_gd(){
    double tien = 0.0;
    if (loai_nha == "Cao cap") {
        tien = s * gia;    
    }
    else tien = s * gia* 0.9;

    return tien;
}