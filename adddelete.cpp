#include<bits/stdc++.h>
#include<string>
using namespace std;
struct thongtin_KH{
    char hoten[25];
    string MSKH;
    
};

void nhap_Du_Lieu(struct thongtin_KH KH[], int &biendem){
    cout << "nhap ho va ten khach hang: ";
    cin >> KH[biendem].hoten;
    cout << "nhap MSKH: ";
    cin >> KH[biendem].MSKH;
    biendem++;
}
void xuat_Du_Lieu(struct thongtin_KH KH[], int biendem){
    for(int i = 0; i <= biendem; i++){
    cout << "\nten khach hang: "<<KH[i].hoten;
    cout << "\nMSKH: "<<KH[i].MSKH;
    }
}
menu1(int &n){
    cout << "1. them khach hang";
    cout << "\n2.Xuat danh sach";
    cout << "\nnhap lua chon: ";
    cin >> n;
}
void Loop4(int m);
void loop_1(int m){
    thongtin_KH KH[100];
    int biendem = 0;
    menu1(m);
    if(m == 1){
        nhap_Du_Lieu(KH,biendem);
    
    }else{
        if(m == 2){
            xuat_Du_Lieu(KH,biendem);
        }
    }
    Loop4(m);
}
int main(){
 thongtin_KH KH[100];
int m;
loop_1(m);


}
void Loop4(int m){
    char a ;
    do{
        std :: cout << "\n\n\t\t\t\tBan co muon quay lai trang chu. Neu CO bam 'c' neu KHONG bam 'k': ";
        std :: cin >> a;
    }while((a != 'c' && a != 'k') && std :: cout << "\t\t\t\tnhap sai. Vui long nhap lai !!!");
    if(a == 'c'){
    	std :: cout << "\n";
        //loading();
    	//system("cls");
        loop_1(m);
    }
    else{  }
}