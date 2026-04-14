#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int TONG_SINH_VIEN_TOI_DA = 100;
const int DO_DAI_TEN_TOI_DA = 50;
const int DO_DAI_KHOA_HOC_TOI_DA = 50;

struct SinhVien {
    int maSo;
    char hoTen[DO_DAI_TEN_TOI_DA];
    int tuoi;
    char khoaHoc[DO_DAI_KHOA_HOC_TOI_DA];
};

SinhVien danhSachSinhVien[TONG_SINH_VIEN_TOI_DA];
int soLuongHienTai = 0;

void inCanGiua(const string &vanBan, int doRong) {
    int khoangTrong = (doRong - vanBan.length()) / 2;
    for (int i = 0; i < khoangTrong; ++i) {
        cout << " ";
    }
    cout << vanBan << endl;
}

bool laMaSoDuyNhat(int maSo) {
    for (int i = 0; i < soLuongHienTai; i++) {
        if (danhSachSinhVien[i].maSo == maSo) {
            return false;
        }
    }
    return true;
}

void themSinhVien() {
    if (soLuongHienTai >= TONG_SINH_VIEN_TOI_DA) {
        ("Danh sach sinh vien da day.", 100);
        return;
    }
    int maSo;
    ("Nhap Ma SV: ", 100);
    cin >> maSo;
    while (!laMaSoDuyNhat(maSo)) {
        ("Ma SV da ton tai. Vui long nhap lai: ", 100);
        cin >> maSo;
    }
    danhSachSinhVien[soLuongHienTai].maSo = maSo;

    cin.ignore();
    ("Nhap Ho Ten: ", 100);
    cin.getline(danhSachSinhVien[soLuongHienTai].hoTen, DO_DAI_TEN_TOI_DA);

    ("Nhap Tuoi: ", 100);
    cin >> danhSachSinhVien[soLuongHienTai].tuoi;

    while (cin.fail() || danhSachSinhVien[soLuongHienTai].tuoi <= 0 || danhSachSinhVien[soLuongHienTai].tuoi > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        ("Tuoi khong hop le. Vui long nhap lai (1-100): ", 100);
        cin >> danhSachSinhVien[soLuongHienTai].tuoi;
    }
    cin.ignore();

    ("Nhap Khoa hoc: ", 100);
    cin.getline(danhSachSinhVien[soLuongHienTai].khoaHoc, DO_DAI_KHOA_HOC_TOI_DA);

    soLuongHienTai++;
    ("Them sinh vien thanh cong!", 100);
}

void xemTatCaSinhVien() {
    if (soLuongHienTai == 0) {
        ("Chua co du lieu sinh vien.", 100);
        return;
    }
    ("MSV\tHo Ten\t\tTuoi\tKhoa Hoc", 100);
    ("-------------------------------------------", 100);
    for (int i = 0; i < soLuongHienTai; i++) {
        cout << setw(25) << setfill(' ') << danhSachSinhVien[i].maSo << "\t"
             << setw(25) << setfill(' ') << danhSachSinhVien[i].hoTen << "\t\t"
             << setw(25) << setfill(' ') << danhSachSinhVien[i].tuoi << "\t"
             << setw(25) << setfill(' ') << danhSachSinhVien[i].khoaHoc << endl;
    }
}

void timKiemTheoMaSo() {
    int maSo;
    ("Nhap MSV can tim: ", 100);
    cin >> maSo;
    for (int i = 0; i < soLuongHienTai; i++) {
        if (danhSachSinhVien[i].maSo == maSo) {
            cout << "Tim thay: MSV: " << danhSachSinhVien[i].maSo << ", Ten: " << danhSachSinhVien[i].hoTen
                 << ", Tuoi: " << danhSachSinhVien[i].tuoi << ", Khoa hoc: " << danhSachSinhVien[i].khoaHoc << endl;
            return;
        }
    }
    ("Khong tim thay sinh vien.", 100);
}

void timKiemTheoTen() {
    char tenCanTim[DO_DAI_TEN_TOI_DA];
    ("Nhap Ten can tim: ", 50);
    cin.ignore();
    cin.getline(tenCanTim, DO_DAI_TEN_TOI_DA);
    for (int i = 0; i < soLuongHienTai; i++) {
        if (strcmp(danhSachSinhVien[i].hoTen, tenCanTim) == 0) {
            cout << "Tim thay: MSV: " << danhSachSinhVien[i].maSo << ", Ten: " << danhSachSinhVien[i].hoTen
                 << ", Tuoi: " << danhSachSinhVien[i].tuoi << ", Khoa hoc: " << danhSachSinhVien[i].khoaHoc << endl;
            return;
        }
    }
    ("Khong tim thay sinh vien.", 100);
}

void xoaSinhVien() {
    int maSo;
    ("Nhap MSV can xoa: ", 100);
    cin >> maSo;
    for (int i = 0; i < soLuongHienTai; i++) {
        if (danhSachSinhVien[i].maSo == maSo) {
            ("Ban co chac muon xoa? (y/n): ", 100);
            char xacNhan;
            cin >> xacNhan;
            if (xacNhan == 'y' || xacNhan == 'Y') {
                for (int j = i; j < soLuongHienTai - 1; j++) {
                    danhSachSinhVien[j] = danhSachSinhVien[j + 1];
                }
                soLuongHienTai--;
                ("Xoa thanh cong.", 100);
            } else {
                ("Da huy xoa.", 100);
            }
            return;
        }
    }
    ("Khong tim thay MSV.", 100);
}

void capNhatSinhVien() {
    int maSo;
    ("Nhap MSV can cap nhat: ", 100);
    cin >> maSo;
    for (int i = 0; i < soLuongHienTai; i++) {
        if (danhSachSinhVien[i].maSo == maSo) {
            cin.ignore();
            ("Nhap Ten moi: ", 100);
            cin.getline(danhSachSinhVien[i].hoTen, DO_DAI_TEN_TOI_DA);
            ("Nhap Tuoi moi: ", 100);
            cin >> danhSachSinhVien[i].tuoi;
            cin.ignore();
            ("Nhap Khoa hoc moi: ", 100);
            cin.getline(danhSachSinhVien[i].khoaHoc, DO_DAI_KHOA_HOC_TOI_DA);
            ("Cap nhat thanh cong!", 100);
            return;
        }
    }
    ("Khong tim thay MSV.", 100);
}

void sapXepTheoTen() {
    for (int i = 0; i < soLuongHienTai - 1; i++) {
        for (int j = 0; j < soLuongHienTai - i - 1; j++) {
            if (strcmp(danhSachSinhVien[j].hoTen, danhSachSinhVien[j + 1].hoTen) > 0) {
                SinhVien tam = danhSachSinhVien[j];
                danhSachSinhVien[j] = danhSachSinhVien[j + 1];
                danhSachSinhVien[j + 1] = tam;
            }
        }
    }
    ("Da sap xep danh sach theo ten.", 100);
}

void thongKe() {
    if (soLuongHienTai == 0) {
        ("Khong co du lieu de thong ke.", 100);
        return;
    }
    int tongTuoi = 0;
    for (int i = 0; i < soLuongHienTai; i++) {
        tongTuoi += danhSachSinhVien[i].tuoi;
    }
    cout << "Tong so sinh vien: " << soLuongHienTai << endl;
    cout << "Tuoi trung binh: " << (float)tongTuoi / soLuongHienTai << endl;
}

int main() {
    int luaChon;
    do {
        ("-------- HE THONG QUAN LY SINH VIEN --------", 100);
        ("1. Them sinh vien", 100);
        ("2. Xem tat ca sinh vien", 100);
        ("3. Tim kiem theo MSV", 100);
        ("4. Tim kiem theo Ten", 100);
        ("5. Xoa sinh vien", 100);
        ("6. Cap nhat sinh vien", 100);
        ("7. Sap xep theo ten", 100);
        ("8. Thong ke", 100);
        ("9. Thoat", 100);
        ("--------------------------------------------", 100);
        ("Chon chuc nang: ", 100);
        cin >> luaChon;

        switch (luaChon) {
            case 1: themSinhVien(); break;
            case 2: xemTatCaSinhVien(); break;
            case 3: timKiemTheoMaSo(); break;
            case 4: timKiemTheoTen(); break;
            case 5: xoaSinhVien(); break;
            case 6: capNhatSinhVien(); break;
            case 7: sapXepTheoTen(); break;
            case 8: thongKe(); break;
            case 9: ("Tam biet!", 50); break;
            default: ("Lua chon khong hop le!", 50);
        }
    } while (luaChon != 9);
    return 0;
}
