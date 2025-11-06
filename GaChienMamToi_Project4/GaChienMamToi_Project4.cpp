#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class NguoiDung {
protected:
	string strTenDangNhap;
	string strMatKhau;
public:
	NguoiDung() : strTenDangNhap(""), strMatKhau("") {}
	NguoiDung(string ten, string mk) : strTenDangNhap(ten), strMatKhau(mk) {}
	NguoiDung(const NguoiDung& other) : strTenDangNhap(other.strTenDangNhap), strMatKhau(other.strMatKhau) {}
	string getTenDangNhap() const {
		return this->strMatKhau;
	}
	bool ktMatKhau(string strMatKhau, string strTenDangNhap);
	virtual void hienThiMenu() = 0;
	virtual ~NguoiDung() {}
};
class QuanLy : public NguoiDung {
public:
	QuanLy() : NguoiDung() {}
	QuanLy(string ten, string mk) : NguoiDung(ten, mk) {}
	virtual void hienThiMenu() override {
		cout << "\n--- MENU QUAN LY (" << strTenDangNhap << ") ---\n";
		cout << "1. Quan Ly San Pham\n";
		cout << "2. Xu Ly Don Hang\n";
		cout << "3. Quan Ly Nhan Vien\n";
		cout << "ESC. Dang xuat\n";
	}
	void themNhanVien() {}
	void xoaNhanVien() {}
	void xuLyDon() {}
};
class NhanVien : public NguoiDung {
public:
	NhanVien() : NguoiDung() {}
	NhanVien(string ten, string mk) : NguoiDung(ten, mk) {}
	NhanVien(const NhanVien& other) : NguoiDung(other) {}
	void hienThiMenu() override {
		cout << "\n--- MENU NHAN VIEN (" << strTenDangNhap << ") ---\n";
		cout << "1. Xu Ly Don Hang\n";
		cout << "2. Cap Nhat Kho Hang\n";
		cout << "ESC. Dang xuat\n";
	}
	void xuLyDon() { cout << "Dang xu ly don hang...\n"; }
};
class KhachHang : public NguoiDung {
private:
	string strDiaChi;
	string strSDT;

public:
	KhachHang() : NguoiDung(), strDiaChi(""), strSDT("") {}
	KhachHang(string ten, string mk, string dc, string sdt)
		: NguoiDung(ten, mk), strDiaChi(dc), strSDT(sdt) {
	}
	KhachHang(const KhachHang& other)
		: NguoiDung(other), strDiaChi(other.strDiaChi), strSDT(other.strSDT) {
	}
	void hienThiMenu() override {
		cout << "\n--- MENU KHACH HANG (" << strTenDangNhap << ") ---\n";
		cout << "1. Xem San Pham\n";
		cout << "2. Dat Hang\n";
		cout << "3. Xem Don Hang Cua Toi\n";
		cout << "ESC. Dang xuat\n";
	}
	string getDiaChi() const { return strDiaChi; }
	string getSDT() const { return strSDT; }
};

int main() {


	return 0;
}