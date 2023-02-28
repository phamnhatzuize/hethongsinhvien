# hethongsinhvien
#include<bits/stdc++.h>
#include<string>
using namespace std;


struct thongtin_KH{
    char hoten[25];
    string MSKH;

};

void nhap1(thongtin_KH &KH, int &biendem){
    cout << "nhap ho va ten khach hang: ";
    cin >> KH.hoten;
    cout << "nhap MSKH: ";
    cin >> KH.MSKH;
    cout << "\nThem thanh cong\n";
    ++biendem;
    cout << "So luong KH la: " << biendem << endl;
}

void nhap_Du_Lieu(thongtin_KH KH[], int &biendem){
	nhap1(KH[biendem], biendem);
}

void xuat_Du_Lieu(thongtin_KH KH[], int biendem){
    for(int i = 0; i < biendem; i++){
   	 cout << "\nten khach hang: "<< KH[i].hoten;
    	cout << "\nMSKH: "<<KH[i].MSKH << "\n";
    }
}


// xoa du lieu khach hang
int check_MSKH(int biendem, thongtin_KH KH[],string checkMS){
    int bienxuat = -1;
    for(int i = 0; i < biendem && bienxuat == -1; i++){
        // Khi bienxuat gán bằng i phải kèm điều kiện để out vòng lặp
        // Có thể sử dụng lệnh break;
        if(checkMS == KH[i].MSKH) {
		bienxuat = i; 
	}else{
		 bienxuat = -1;
	}
    }
    return bienxuat;
}
void xoa_Du_Lieu(int &biendem, thongtin_KH KH[],string checkMS){
	int index = check_MSKH(biendem,KH,checkMS); 
        // Khi index ở vị trí cuối
	if(index == (biendem - 1)){
		KH[index].hoten == "";
        	KH[index].MSKH == "";
	}else{   //khi index ở đầu hoặc giữa
		for(int i = index; i < biendem - 1 ; i++){
    	    		KH[i] = KH[i + 1];
    		}
	}
        biendem -= 1;
}
void xoa_KH(int &biendem, thongtin_KH KH[]){
    string MSKH1;
    int bienxuat ;
    do{
        cout << "\nNhap MSKH: ";
        cin >> MSKH1;
        if(check_MSKH(biendem,KH,MSKH1) != -1 ){
            bienxuat = check_MSKH(biendem,KH,MSKH1);
            cout << "\nten khach hang: "<< KH[bienxuat].hoten;
            cout << "\nMSKH: "<<KH[bienxuat].MSKH << "\n";
            xoa_Du_Lieu(biendem,KH,MSKH1);
            cout << "\nDa xoa du lieu !!!\n";
        }else if(check_MSKH(biendem,KH,MSKH1) == -1){
            cout << "\nKhong tim thay khach hang !!!\n";
        }
    }while(check_MSKH(biendem,KH,MSKH1) == -2);
}

// menu lua chon
void menu1(int &n){
    cout << "1. Them khach hang";
    cout << "\n2.Xoa khach hang";
    cout << "\n3. Xuat danh sach";
    cout << "\n4. Thoat he thong";
    cout << "\nnhap lua chon: ";
    cin >> n;
}

int main(){
thongtin_KH KH[100];
int m = 0;
int biendem = 0;

    while( m != 4){
    menu1(m);
    if(m == 1) nhap_Du_Lieu(KH,biendem);
    else if( m == 2) xoa_KH(biendem,KH);
    else if (m == 3) xuat_Du_Lieu(KH,biendem);
	}
 return 0;
}
