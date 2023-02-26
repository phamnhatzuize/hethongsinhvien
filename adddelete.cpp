#include<bits/stdc++.h>
#include<string.h>
using namespace std;


struct thongtin_KH{
    char hoten[25];
    string MSKH;
    
};

void nhap1(thongtin_KH &KH, int &biendem){
    cout << "nhap ho va ten khach hang: ";
    cin.getline (KH.hoten,25);
    cout << "nhap MSKH: ";
    cin >> KH.MSKH;
    cout << "\nThem thanh cong\n";
    
    cout << "So luong KH la: " << biendem + 1 << endl;
}

void nhap_Du_Lieu(thongtin_KH KH[], int &biendem){
	biendem++;
	nhap1(KH[biendem], biendem);
}

void xuat_Du_Lieu(thongtin_KH KH[], int biendem){
    for(int i = 0; i <= biendem; i++){
    cout << "\nten khach hang: "<< KH[i].hoten;
    cout << "\nMSKH: "<<KH[i].MSKH << "\n";
    }
    
}

void menu1(int &n){
    cout << "1. Them khach hang";
    cout << "\n2. Xuat danh sach";
    cout << "\n3. Thoat he thong";
    cout << "\nnhap lua chon: ";
    cin >> n;
    cin.ignore();
}

int main(){
thongtin_KH KH[100];
int m = 0;
int biendem = -1;

    while (m != 3){
    menu1(m);
    if(m == 1) nhap_Du_Lieu(KH,biendem);
    else if (m == 2) xuat_Du_Lieu(KH,biendem);
	}
 return 0;
}
