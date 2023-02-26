#include<bits/stdc++.h>
#include<string>
using namespace std;
struct thongtin_KH{
    char hoten[25];
    string MSKH;
    
};

void nhap_Du_Lieu(thongtin_KH KH[], int &biendem){
    cout << "nhap ho va ten khach hang: ";
    cin >> KH[biendem].hoten;
    cout << "nhap MSKH: ";
    cin >> KH[biendem].MSKH;
    cout << "\nThem thanh cong\n";
    biendem++;
}
void xuat_Du_Lieu(thongtin_KH KH[], int biendem){
    for(int i = 0; i <= biendem; i++){
    cout << "\nten khach hang: "<<KH[i].hoten;
    cout << "\nMSKH: "<<KH[i].MSKH << "\n";
    }
}
menu1(int &n){
    cout << "1. them khach hang";
    cout << "\n2.Xuat danh sach";
    cout << "\nnhap lua chon: ";
    cin >> n;
}

int main(){
thongtin_KH KH[100];
int m;
int biendem = 0;
    menu1(m);
    if(m == 1){
        nhap_Du_Lieu(KH,biendem);
    
    }else{
        if(m == 2){
            xuat_Du_Lieu(KH,biendem);
        }
    }
    main();
}
