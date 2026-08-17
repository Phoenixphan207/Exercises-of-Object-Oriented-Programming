#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class cArray {
private: 
    vector<int> a;

    bool so_ngto(const int k) {
        if (k <= 1) return false;
        if (k == 2) return true;

        for (int i = 1 ; i < sqrt(k); i++) {
            if (k % i == 0) return false;
        }
        return true;
    }

    int partition(const int left , const int right) {
        int i = left - 1;
        int j = right;
        int v = a[left];

        while (1) {
            while (a[++i] < v);
            while (a[--j] > v);

            if (i >= j) return j;
            swap(a[i] , a[j]);
        }
    }

public:
    cArray() {
        vector<int> tmp ;
        a = tmp;
    }

    int get_size() {
        return a.size();
    }

    void tao_mang(const int &n) {
        vector<int> res;
        for (int i = 0 ; i < n ; i++)
            res.push_back(rand() % 100);

        a = res;            
    }

    void xuat_mang(const int &n) {
        for (int i = 0; i < n ; i++) {
            cout << a[i] << " ";
        }
    }

    int so_lan_xuat_hien(const int n , const int x ) {
        int d = 0;
        for (int i = 0 ; i < n ; i++) {
            if (a[i] == x) 
                d ++;
        }

        return d;
    }

    bool tang_dan(const int n ) {
        for (int i = 1; i < n ; i++) {
            if (a[i-1] < a[i]) 
                return false;
        }
        return true;
    }

    int le_min(const int n) {
        vector<int> le;
        for (int i = 0 ; i < n ; i++) {
            if (a[i] % 2 != 0) {
                le.push_back(a[i]);
            }
        }
        if (le.empty()) return -1;

        int ans = le[0];
        for (int i = 0 ; i < le.size() ; i++) {
            if (ans > le[i])
                ans = le[i];
        }
        return ans;
    }

    int so_ngto_max(const int n) {
        vector<int> res;
        for (int i = 0 ; i < n ; i++) {
            if (so_ngto(a[i])) 
                res.push_back(a[i]);
        }
        
        if (res.empty()) return -1;
        
        int ans = res[0];
        for (int i : res) {
            if (i > ans) {
                ans = i;
            }
        }
        return ans;
    }

    void quicksort(const int left , const int right) {
        if (left >= right) return;
        int j = partition(left , right);
        quicksort(left , j);
        quicksort(j + 1 , right);
    }

};

int main() {
    

    cArray arr;

    int n;
    cout << "Nhap so phan tu n: ";
    cin >> n;

    // Tạo và xuất mảng
    cout << "\n===== Mang random " << n << " phan tu =====\n";
    arr.tao_mang(n);
    arr.xuat_mang(n);
    cout << "\n";

    // Đếm số lần xuất hiện của x
    int x;
    cout << "\nNhap gia tri x can tim: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " la: "
         << arr.so_lan_xuat_hien(n, x) << "\n";

    // Kiểm tra tăng dần
    cout << "\n===== Kiem tra mang =====\n";
    if (arr.tang_dan(n))
        cout << "Mang dang tang dan.\n";
    else
        cout << "Mang KHONG tang dan.\n";

    // Phần tử lẻ nhỏ nhất
    cout << "Phan tu le nho nhat: " << arr.le_min(n) << "\n";

    // Số nguyên tố lớn nhất
    cout << "So nguyen to lon nhat: " << arr.so_ngto_max(n) << "\n";

    // Sắp xếp quicksort
    arr.quicksort(0, n - 1);
    cout << "\n===== Mang sau khi sap xep quicksort =====\n";
    arr.xuat_mang(n);
    cout << "\n";

    return 0;
}