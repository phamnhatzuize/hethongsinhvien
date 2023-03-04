#include<bits/stdc++.h>
#include<string>
#include<windows.h>
#include<conio.h>

using namespace std;


struct thongtin_KH{
    string MSKH,hoten;
    int timkiem;
 //   int tiendien = rand() % 100;
};

void gotoxy(short x, short y)
{
 HANDLE hConsoleOutput;
 COORD Cursor_an_Pos = { x, y };
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// ham bat su kien tu ban phim de quay lai 
int return_p(int  &m ){
    char c;
    while(1){
        if(kbhit()){
            c = getch();
            switch(c){
                case 75:m = 1 ;return m;break; // phim <-

                case 27: m = 0;return m;break; // phim Esc
            }
        }
    }
} 

void TextColor(int x)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
void nhap1(thongtin_KH &KH, int &biendem){
    gotoxy(50,15);
    cout << "nhap ho va ten khach hang: ";
    gotoxy(50,16);
    cout << "nhap MSKH: ";
    gotoxy(77,15);
    cin.ignore(0);
    getline(cin,KH.hoten);
    gotoxy(61,16);
    cin >> KH.MSKH;
    gotoxy(60, 18);
    cout << "Them thanh cong";
}

void nhap_Du_Lieu(thongtin_KH KH[], int &biendem){
	nhap1(KH[biendem], biendem);
	++biendem;
    gotoxy(60,19);
	cout << "So luong KH la: " << biendem;
}

void xuat_Du_Lieu(thongtin_KH KH[], int &biendem){
    int a = 10;
    gotoxy(30,a);
	cout << "-------------------------------------------------------";
    gotoxy(30,a+1);
   	cout << "| Ho va ten                        |       MSKH       |";
    gotoxy(30,a+2);
    cout << "-------------------------------------------------------";
    for(int i = 0; i < biendem; i++){
        int kc = 13;
        if(i > 0) kc = kc + 1;
        gotoxy(30,i + kc);
        cout << "|"<<KH[i].hoten; cout << "|"; cout << KH[i].MSKH << "|";
        gotoxy(30,i+ kc + 1);

    //	cout << "\nTien dien: " <<KH[i].tiendien * 3200 <<" VND\n";
    }
}



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

// xoa du lieu khach hang
void delname(int &biendem, thongtin_KH KH[],int index){
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
            delname(biendem,KH,bienxuat);
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


string tachten(string &KH){
	int cnt;
	for (int i = KH.length(); i > 0 ; i--){
		if (KH[i] == ' '){
            cnt = i; 
            break;   
        } 
	}
	return KH.substr((cnt + 1),KH.length());  // tra ve chuoi da duoc cat
}

void SearchName(thongtin_KH KH[], int &biendem){
	string KHx,ten;
	int m,n;
    int cnt = 0;
    cin.ignore();
	cout << "Nhap ten tim kiem: ";
    getline(cin,ten);
	for(int i = 0; i < biendem; i++){
		KHx = tachten(KH[i].hoten) ;
		if (ten.compare(KHx) == 0){
			cnt ++; 
            KH[i].timkiem = cnt;
			cout << KH[i].timkiem <<". Ten khach hang: " << KH[i].hoten << " - MSKH: " << KH[i].MSKH<< "\n";
		}
	}
	cout << "Lua chon khach hang: "; cin >> m;
	for (int i = 0; i < biendem; i++){
		if (KH[i].timkiem == m){
			cout << "\n1. Chinh sua thong tin\n";
			cout <<"2. Xoa khach hang\n";
			cout <<"Vui long chon lenh: ";
			cin >> n;cout << endl;
			switch(n){
		        case 1: nhap1(KH[i],biendem); break;
		        case 2:	delname(biendem,KH,i); break;
		        default: ;
			}
		}
	}
}

// menu lua chon
int menu1(int &dk){
    
    string s[1000];
    s[11]= "| 1. Them khach hang  |";
    s[13]= "| 2. Xoa khach hang   |";
    s[15]= "| 3. Xuat danh sach   |";
    s[17]= "| 4. Cap nhat du lieu |";
    s[19]= "| 5. Tim theo ten     |";
    s[21]= "| 6. Thoat            |";

    // ve bang menu
    TextColor(3);
    gotoxy(50,10);
    cout << "+---------------------+";
   
        for(int i = 11; i < 23; i += 2){
            gotoxy(50,i);
            cout << s[i];
            gotoxy(50,i+1);
            cout << "+---------------------+";
        }
    // thay mau cho s[0]; s[0] mau 15 đang đè len s[0] mau 3
    TextColor(15);
    gotoxy(50,11);
    cout << s[11];
    // bat su kien tu ban phim 
    gotoxy(70,11);
    char c;
    while (1) {
        if (kbhit()) {
            c = getch();
            switch (c) {
                case 13: { // phim enter
                    system("cls");
                    if(dk == 21)
                        return 0;
                    return dk;
                }
                case 72: { // len
                    if(dk == 11){
                        dk = 23;
                    }   
                    gotoxy(70,dk-2);   
                    dk -= 2;
                    break;
                }
                case 80: { // xuong
                    if (dk == 21){
                    	dk = 9;
					}
                    gotoxy(70,dk+2);
                    dk += 2;
                    break;
                }
            }
            // SAU KHI DIEU KHIEN PHIM VE LAI BANG MENU
            TextColor(3);
            gotoxy(50,10);
            cout << "+---------------------+";
            for(int i = 11; i < 23; i += 2){
                gotoxy(50,i);
                cout << s[i];
                gotoxy(50,i+1);
                cout << "+---------------------+";
            }
            // CHO CAC PHAN TU MA ON TRO DANG CHI DOI MAU
                TextColor(15);
                gotoxy(50,dk);
                cout << s[dk];
    

        }
    }
}

int main(){
    thongtin_KH KH[100];
    int m = 11;
    int biendem = 0;
    int check = 0;
   do{      
            if(check == 1) system("cls");m = 11;
            menu1(m);
            system("cls");
            switch(m){
                case 11: nhap_Du_Lieu(KH, biendem);break;
                case 13: xoa_KH(biendem,KH) ;break;
                case 15: xuat_Du_Lieu(KH,biendem) ;break;
                case 17: update_Du_lieu(biendem, KH);break;
                case 19: SearchName(KH,biendem);break;
                default: ;
            } 
            gotoxy(50,25);cout << "nhan <- de quay lai\n"; 
            return_p(check);  
    }while((check == 1));

    return 0;
}


