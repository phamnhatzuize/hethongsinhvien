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

// ham tim vi tri can tim
int check_MSKH(int biendem, thongtin_KH KH[],string checkMS){
    int bienxuat = -1;
    for(int i = 0; i < biendem && bienxuat == -1; i++){
        // Khi bienxuat gan bang i can phai co dieu kien de out vong lap
        // Co the su dung lenh break;
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
        // Khi index o vi tri cuoi
	if(index == (biendem - 1)){
		KH[index].hoten == "";
        KH[index].MSKH == "";
	}else{   //khi index o dau hoac giua
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

// chinh sua du lieu khach hang
void update_Du_lieu(int &biendem, thongtin_KH KH[]){
    int n;
    int index;
    string MSKH1;
    do{
        cout << "\nNhap MSKH: ";
        cin >> MSKH1;
        if(check_MSKH(biendem,KH,MSKH1) != -1 ){
            index = check_MSKH(biendem,KH,MSKH1);
            cout << "\nten khach hang: "<< KH[index].hoten;
            cout << "\nMSKH: "<<KH[index].MSKH << "\n";
            cout << "Sua doi thong tin:";
            cout << "\n1. Ho ten";
            cout << "\n2. MSKH";
            do{
                cout << "\nnhap thong tin can sua: ";
                cin >> n;
                if(n == 1){
                    cout << "nhap ho va ten khach hang: ";
                    cin >> KH[index].hoten;
                }else if(n == 2){
                    cout << "nhap MSKH: ";
                    cin >> KH[index].MSKH;
                }
            }while((n > 2 || n < 1) && cout << "\n khong co lua chon. Nhap lai!!!\n");
            cout << "\nCap nhat thanh cong\n";
        }else if(check_MSKH(biendem,KH,MSKH1) == -1){
            cout << "\nKhong tim thay khach hang !!!\n";
        }
    }while(check_MSKH(biendem,KH,MSKH1) == -2);

}

// menu lua chon
void menu1(int &n){
    cout << "1. Them khach hang";
    cout << "\n2. Xoa khach hang";
    cout << "\n3. Xuat danh sach";
    cout << "\n4. Cap nhat du lieu";
    cout << "\n5. Thoat he thong";
    cout << "\nnhap lua chon: ";
    cin >> n;
}

int main(){
thongtin_KH KH[100];
int m = 0;
int biendem = 0;

    while( m != 5){
    menu1(m);
    switch(m){
        case 1: nhap_Du_Lieu(KH,biendem); break;
        case 2: xoa_KH(biendem,KH); break;
        case 3: xuat_Du_Lieu(KH,biendem); break; 
        case 4: update_Du_lieu(biendem,KH); break;
        default: ;
    }
	}
 return 0;
}
