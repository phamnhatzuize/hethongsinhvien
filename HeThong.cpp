#include <bits/stdc++.h>
#include<windows.h>
#include <string>
#include <cstring>
using namespace std;
struct du_Lieu{
	string USERNAME;
	string USERNAME2;
	string PASSWORD1;
	string PASSWORD2;
	string PASSWORD3; 
};

struct du_Lieu_Sinh_Vien{
    float diembt, diemgk, diemck, diemtong ;
    int sotin, giatin;
    int sotien;
};

void gotoxy(short x, short y)
{
 HANDLE hConsoleOutput;
 COORD Cursor_an_Pos = { x, y };
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void menu1(){
    std :: cout << "\n\t\t\t\t";
    std :: cout << "---- CHAO MUNG BAN DEN VOI PHAN MEM HO TRO SINH VIEN 22DT4 ----";
    std :: cout << "\n\t\t\t\t\t   -----------------*********----------------";
    std :: cout << "\n\t\t\t\t\t1. Ho tro tinh diem hoc phan";
    std :: cout << "\n\t\t\t\t\t2. Ho tro tinh so tien hoc";
}

void display3(){
	gotoxy(55,7);
   	std :: cout <<"DANG KY TAI KHOAN";
   	gotoxy(30,9);
   	std :: cout << "Ten dang nhap thuoc dang A-Z,a-z,0-9 (Khong chua ky tu dac biet).";
   	gotoxy(30,10);
   	std :: cout << "Mat khau thuoc dang A-Z,a-z,0-9 va gom 6 ky tu (khong chua ky tu dac biet).";
}

bool check_Length(string x){
	int length;
	length = x.size();
	if(length != 6) return false;
	return true;
}

void login_in(string USERNAME,string &USERNAME2,string PASSWORD1,string &PASSWORD3);
void sign_in(string &USERNAME,string &PASSWORD1,string PASSWORD2);
void sing_inlogin_in(string USERNAME,string USERNAME2,string PASSWORD1,string PASSWORD2,string PASSWORD3);
void lua_Chon1( int &n);
void lua_Chon2( int &m);
void lua_Chon3(int &l);
float tinh_Diem(int m,float a,float b,float c); 
void nhap_Du_Lieu(int m,float &a,float &b,float &c);
void check_pass_or_fail(int m,float a, float b,float c);
void display1(float d);
void display2(float d);
void loading();
void Loop1(int l,int n, int m);
void Loop4(int n,int m);
void nhap_So_tin(int &sotin, int &giatin);
int tinh_Tien(int sotien, int sotin, int giatin);

class DocTien{
    public: 
    const char mau[10][8] = { "khong ","mot ","hai ","ba ","bon ","nam ","sau ", "bay ", "tam ","chin "};
int arr[10];
// ham xet cac vi tri dac biet 
// tram, nghin,trieu
void them_Ky_Tu(int vt){
    if(vt == 8){
        return;
    }
    switch (vt)
    {
    case 1:
        std :: cout << "muoi ";
        break;
    case 2:
        std :: cout << "trieu ";
        break;
    case 3:
        if((arr[vt + 1] != 0 || arr[vt + 2] != 0) || (arr[vt] != 0)){
            std :: cout << "tram ";
        }
        break;
    case 5:
        if((arr[vt -2] != 0 || arr[vt -1] != 0) || (arr[vt] != 0)){
            std :: cout << "nghin ";
        }
        break;
    case 6:
        if((arr[vt] != 0) || (arr[vt + 1] != 0 || arr[vt + 2] != 0)){
            std :: cout << "tram ";
        }
        break;
    case 4: case 7:
        if(arr[vt] != 0){
            std :: cout << "muoi ";
        }else{
            if(arr[vt+1] != 0)
            std :: cout << "le ";
        }
        break;
    }
}

// ham chyen so thanh mang
// vidu 1.098.097 ==> arr[6] = 7; arr[5] = 9; ... arr[0] = 1;
void chuyenSo_Thanh_Mang( int &c){
	int i;
	for(i = 1; i <= 8; i++){
		arr[i] = 0;
	}
	i = 8;
	while(c != 0){
		arr[i] = c % 10;
		c = c / 10;
		i--;
	}
}

void doc_So(int b){
    chuyenSo_Thanh_Mang(b);
    int vtd = 9;
    for( int i = 1; i <= 8; i++)
        if(arr[i] != 0){
            vtd = i;
            break ;
        }
    if(vtd == 9){
        std :: cout << "khong ";
        return ;
    }
    for(int i = vtd; i <= 8; i++){
        switch (arr[i])
        {
        case 1: case 2: case 3: case 4: case 6: case 7: case 8: case 9:
            if((arr[i] != 1) || ((i != 7) && (i != 4) && (i != 1)))
            std :: cout << mau[arr[i]];
            them_Ky_Tu(i);
            break;
        case 5:
            if(i == 8){
                if(arr[i - 1] == 0){
                  std :: cout << "nam ";
                }else{
                    std :: cout << "lam ";
                   }
            }else{ 
                if( i == 5){
                    if(arr[i - 1] == 0){
                        std :: cout << "nam ";
                    }else{
                        std :: cout << "lam ";
                    }
                }else{
                    if( i == 2){
                        std :: cout << "lam ";
                    }else{
                        std :: cout << mau[arr[i]];
                        them_Ky_Tu(i);
                        break;
                    }
                }
            }
        case 0:
            if( (i == 6 || i == 3) && ((arr[i + 2] != 0) || arr[i + 1] != 0))
            std :: cout << mau[arr[i]];
            them_Ky_Tu(i);
            break;
            }
        }
    }
};

class Phan_don_vi{
    public:
    int arr[10];
void chuyen_so_thanh_mang(int c){
	int i;
	for( i = 1; i <= 8 ; i++){
		arr[i] = 0;
	}
    i = 8;
    while(c != 0){
        arr[i] = c % 10;
        c /= 10;
        i--;
    }
}
void phan_donvi(int vt){
    switch (vt)
    {
    case 2:
        std :: cout << ".";
        break; 
    case 5:
        std :: cout << ".";
        break;
    }
}
void xuat_so(int a){
    chuyen_so_thanh_mang(a);
     int vtd = 9;
    for( int i = 1; i <= 8; i++){
        if(arr[i] != 0){
            vtd = i;
            break ;
        }
	}
    if(vtd == 9){
        std :: cout << "khong ";
        return ;
    }
    for(int i = vtd; i <= 8; i++){
        std :: cout << arr[i];
        if(i == 2 || i == 5){
            phan_donvi(i);
        }
    }
}
};

void Loop2(int &n, int &m){
    du_Lieu_Sinh_Vien sv;
    DocTien dt;
    Phan_don_vi pdv;
    menu1();
    lua_Chon1(n);
    if(n == 1){
        loading();
        system("cls");
        std :: cout << "\n\t\t\t\t\t****** HO TRO TINH DIEM HOC PHAN ******";
        std :: cout << "\n\t\t\t\t\t=======================================";
        std :: cout << "\n\n\t\t\t\t\t -----Moi ban lua chon hoc phan------";
        std :: cout << "\n\t\t\t\t\t\t1. Nhap mon nganh";
        std :: cout << "\n\t\t\t\t\t\t2. Ky thuat lap trinh";
        std :: cout << "\n\t\t\t\t\t\t3. Giai Tich";
        lua_Chon2(m);
        if( m == 1 || m == 2){
        	std:: cout << "\n\t\t\t\t\t----------------------------------\n";
            nhap_Du_Lieu(m,sv.diembt,sv.diemgk,sv.diemck);
            sv.diemtong = tinh_Diem(m,sv.diembt,sv.diemgk,sv.diemck);
            display1(sv.diemtong);
            check_pass_or_fail(m,sv.diembt,sv.diemgk,sv.diemck);
        }else if(m == 3){
        	std:: cout << "\n\t\t\t\t\t----------------------------------\n";
            nhap_Du_Lieu(m,sv.diembt,sv.diemgk,sv.diemck);
            sv.diemtong = tinh_Diem(m,sv.diembt,sv.diemgk,sv.diemck);
            display2(sv.diemtong);
            check_pass_or_fail(m,sv.diembt,sv.diemgk,sv.diemck);
    }
        
        Loop4(n,m);
        
    }else{
        if(n == 2){
            loading();
            system("cls");
            std :: cout << "\n\t\t\t\t\t****** HO TRO TINH TIEN HOC PHAN ******";
            std :: cout << "\n\t\t\t\t\t=======================================";
            nhap_So_tin(sv.sotin,sv.giatin);
            std :: cout << "\n\t\t\t\t\tSo tien can dong la: ";
            pdv.xuat_so(tinh_Tien(sv.sotien,sv.sotin,sv.giatin));
            std :: cout <<" VND\n";
            std :: cout << "\n\t\t\t\tGhi bang chu: "; 
            dt.doc_So(tinh_Tien(sv.sotien,sv.sotin,sv.giatin));
            std :: cout << "dong";
            Loop4(n,m);
        }
    }
}

void Loop3(int &l, int &n, int &m){
//    du_Lieu dl;
//    std :: cout << "\n\t\t\t\t";
//    std :: cout << "---- CHAO MUNG BAN DEN VOI PHAN MEM HO TRO SINH VIEN 22DT4 ----";
//    std :: cout << "\n\t\t\t\t\t   -----------------*********----------------";
//    std :: cout << "\n\t\t\t\t\t1. Dang ki.";
//    std :: cout << "\n\t\t\t\t\t2. Dang nhap.";
//    lua_Chon3(l);
//    if(l == 1){
//        loading();
//        system("cls");
//        sign_in(dl.USERNAME,dl.PASSWORD1,dl.PASSWORD2);
//        system("cls");
//        gotoxy(50,10);
//        std :: cout << "--> DANG KI THANH CONG !!!";
//        gotoxy(50,12);
//        std :: cout << "--> DANG QUAY VE TRANG CHU";
//        Sleep(3500);
//        system("cls");
//        std :: cout << "\n\t\t\t\t";
//        std :: cout << "---- CHAO MUNG BAN DEN VOI PHAN MEM HO TRO SINH VIEN 22DT4 ----";
//        std :: cout << "\n\t\t\t\t\t   -----------------*********----------------";
//        std :: cout << "\n\t\t\t\t\t1. Dang ki.";
//        std :: cout << "\n\t\t\t\t\t2. Dang nhap.";
//        lua_Chon3(l);
//        if(l==1){
//            Loop3(l,n,m);
//        }else if( l == 2){
//            loading();
//            system("cls");
//            login_in(dl.USERNAME,dl.USERNAME2,dl.PASSWORD1,dl.PASSWORD1);
//        }
//        system("cls");
        Loop2(n,m);
//    }else if(l == 2) {
//        loading();
//        system("cls");
//        gotoxy(50,8);
//        std :: cout << "--> BAN PHAI DANG KI TRUOC";
//        Loop1(l,n,m);
//    }
}
int main(){
    int n, m, l;
    du_Lieu_Sinh_Vien sv;
    DocTien dt;
    Phan_don_vi pdv;
    du_Lieu dl;
    Loop3(l,n,m);
	system("cls" );
    return 0;
}

void login_in(string USERNAME,string &USERNAME2,string PASSWORD1,string &PASSWORD3){
    int a = 15;
	gotoxy(55,7);
   	std :: cout <<"DANG NHAP TAI KHOAN";
	gotoxy(39,a-1);
	std :: cout << "________________________________________________";
	gotoxy(39,a);
   	std :: cout << "|       Username       |                       |" ;
   	gotoxy(39,a+1);
   	std :: cout << "------------------------------------------------";
    gotoxy(39,a+2);
	std :: cout << "|       Password       |                       |"; 
	gotoxy(39,a+3);
	std :: cout << "------------------------------------------------";  
    gotoxy(70,a);
	cin.ignore();
   	getline(std :: cin,USERNAME2);
   	gotoxy(70,a+2);
   	std :: cin >> PASSWORD3;
	gotoxy(45,a+6);
   	loading();
    if((PASSWORD1.compare(PASSWORD3) != 0 )|| USERNAME.compare(USERNAME2) != 0){
 	    system("cls");
 	    a = a+1;
 		gotoxy(55,7);
   	    std :: cout <<"DANG NHAP TAI KHOAN";
    	gotoxy(30,13);
    	std :: cout << "--> Mat khau hoac ten dang nhap khong dung !!!.\n";
    	login_in(USERNAME,USERNAME2,PASSWORD1,PASSWORD3);
	}
}
void sign_in(string &USERNAME,string &PASSWORD1,string PASSWORD2){
	display3();
	int a = 15;
	gotoxy(39,a-1);
	std :: cout << "________________________________________________";
	gotoxy(39,a);
   	std :: cout << "|       Username       |                       |" ;
   	gotoxy(39,a+1);
   	std :: cout << "------------------------------------------------";
    gotoxy(39,a+2);
	std :: cout << "|       Password       |                       |"; 
	gotoxy(39,a+3);
	std :: cout << "------------------------------------------------";   	
	gotoxy(39,a+4);
	std :: cout << "|   Confirm Password   |                       |";
	gotoxy(39,a+5);
	std :: cout << "------------------------------------------------";
   	gotoxy(70,a);
   	std :: cin >> USERNAME;
   	gotoxy(70,a+2);
   	std :: cin >> PASSWORD1;
   	gotoxy(70,a+4);
   	cin.ignore();
   	std :: cin >> PASSWORD2;
   	gotoxy(45,a+6);
   	loading();
    if(PASSWORD1.compare(PASSWORD2) != 0 && (check_Length(PASSWORD1) == true || check_Length(PASSWORD2) == true)){
    	system("cls");
		a = a+1;
 		display3();
    	gotoxy(30,13);
    	std :: cout << "--> Mat khau khong khop. Nhap lai!!!\n";
    	sign_in(USERNAME,PASSWORD1,PASSWORD2);
	}else{
		if((PASSWORD1.compare(PASSWORD2) == 0) && (check_Length(PASSWORD1) == false || check_Length(PASSWORD2) == false) ){
			system("cls");
 			a = a+1;
 			display3();
 			gotoxy(30,13);
 			std :: cout << "--> Mat khau khong dung quy dinh. Nhap lai!!!\n";
    		sign_in(USERNAME,PASSWORD1,PASSWORD2);
		}else{
			if((PASSWORD1.compare(PASSWORD2) != 0 ) && (check_Length(PASSWORD1) == false || check_Length(PASSWORD2) == false) ){
				system("cls");
 				a = a+1;
 	    		display3();
 	    		gotoxy(30,12);
 	    		std :: cout << "--> Mat khau khong dung quy dinh. Nhap lai!!!\n";
 	    		gotoxy(30,13);
 	    		std :: cout << "--> Mat khau khong khop. Nhap lai!!!\n";
        		sign_in(USERNAME,PASSWORD1,PASSWORD2);
			}
		}
	}
}

void lua_Chon1(int &n){
   do{
     std :: cout << "\n\t\t\t\t\tMoi ban lua chon: ";
     std :: cin >> n;
   }while((n >= 3 || n <= 0) && std :: cout << "\t\t\t\t\tKhong co lua chon cua ban !!!"<< "\n\t\t\t\t\tnhap lai !!!\n");
}

void lua_Chon2(int &m){
   do{
     std :: cout << "\n\t\t\t\t\t\tMoi ban lua chon: ";
     std :: cin >> m;
   }while((m >= 4 || m <= 0) && std :: cout << "\t\t\t\t\tKhong co lua chon cua ban !!!"<< "\n\t\t\t\t\tnhap lai !!!\n");
}

void lua_Chon3(int &l){
   do{
     std :: cout << "\n\t\t\t\t\tMoi ban lua chon: ";
     std :: cin >> l;
   }while((l >= 3 || l <= 0) && std :: cout << "\t\t\t\t\tKhong co lua chon cua ban !!!"<< "\n\t\t\t\t\tnhap lai !!!\n");
}

void nhap_Du_Lieu(int m,float &a, float &b, float &c){
	if(m == 1){
		std :: cout << "\t\t\t\t\tNhap mon nganh\n";
	}else{
		if(m == 2){
			std :: cout << "\t\t\t\t\tKy thuat lap trinh\n";
		}else{
			if(m == 3){
				std :: cout << "\t\t\t\t\tGiai tich\n";
			}
		}
	}
	do{
    std :: cout << "\n";
    std :: cout << "\t\t\t\t\tMoi nhap diem bai tap: ";
    std :: cin >> a;
    std :: cout << "\t\t\t\t\tMoi nhap diem giua ki: ";
    std :: cin >> b;
    std :: cout << "\t\t\t\t\tMoi nhap diem cuoi ki: ";
    std :: cin >> c;
    std :: cout << "\n";
	}while((a > 10 || b > 10 || c > 10 ) && std :: cout << "\t\t\t\t\tHay nhap theo thang diem 10 !!!\n");
}

float tinh_Diem(int m, float a, float b, float c){
    float d = 0;
    if(m == 1 || m == 2){
        d = (a*0.2) + (b*0.3) + (c*0.5);
        return d;
    }else if(m == 3){
        d = (a*0.3) + (b*0.2) + (c*0.5);
        return d;
    }
}

void display1( float d){
    std ::cout << "\t\t\t\t-------------------------------------------------------\n";
    std :: cout << "\t\t\t\t| Cong thuc tinh diem: [BT]*0.2 + [GK]*0.3 + [CK]*0.5 |\n";
    std :: cout << "\t\t\t\t|-----------------------------------------------------|\n";
    std :: cout << "\t\t\t\t| Tong diem hoc phan cua ban la: \t"<<d<<"\t      |\n";
    std :: cout << "\t\t\t\t|-----------------------------------------------------|\n";
}

void display2( float d){
    std ::cout << "\t\t\t\t-------------------------------------------------------\n";
    std :: cout << "\t\t\t\t| Cong thuc tinh diem: [BT]*0.3 + [GK]*0.2 + [CK]*0.5 |\n";
    std :: cout << "\t\t\t\t|-----------------------------------------------------|\n";
    std :: cout << "\t\t\t\t| Tong diem hoc phan cua ban la: \t"<<d<<"\t      |\n";
    std :: cout << "\t\t\t\t|-----------------------------------------------------|\n";
}

void check_pass_or_fail(int m,float a,float b,float c){
    int d = tinh_Diem(m,a,b,c);
    if( d >= 4.0 && d <= 5.5){
    	std :: cout << "\n\t\t\t\t=> BAN CAN CAI THIEN DIEM MON HOC !!! ";
        std :: cout << "\n\n\t\t\t\t=> CHUC MUNG BAN DA QUA MON (^ :3 ^)";
    }else{
        std :: cout << "\n\n\t\t\t\t=> CHIA BUON BAN TACH MON ROI. CHUC HOC LAI VUI VE =))";
    }
}

void nhap_So_tin(int &sotin,int &giatin){
    do{
     std :: cout << "\n\t\t\t\t\tMoi ban nhap so tin: ";
     std :: cin >> sotin;
   }while((sotin >= 100 || sotin < 0) && std :: cout << "\t\t\t\t\tKhong co lua chon cua ban !!!"<< "\n\t\t\t\t\tnhap lai !!!\n");
    do{
     std :: cout << "\n\t\t\t\t\tMoi ban nhap so tien 1 tin: ";
     std :: cin >> giatin;
   }while((giatin < 0) && std :: cout << "\t\t\t\t\tKhong co lua chon cua ban !!!"<< "\n\t\t\t\t\tnhap lai !!!\n");
}

int tinh_Tien(int sotien, int sotin,int giatin){
    sotien = sotin * giatin;
    return sotien;
}

void loading(){
    std :: cout << "\n\t\t\t\t\tLoading... ";
    char a = 219;
    for(int i = 0; i < 25; i++){
    std :: cout << a;
    if( i  < 10)
    Sleep(150);
    if(i > 10 && i < 20)
    Sleep(100);
    if(i >20 && i < 25 )
    Sleep(50);
    }  
}

void Loop1(int l,int n,int m){
    char a ;
    do{
        std :: cout << "\n\n\t\t\t\tBan co muon quay lai trang chu. Neu CO bam 'c' neu KHONG bam 'k': ";
        std :: cin >> a;
    }while((a != 'c' && a != 'k') && std :: cout << "\t\t\t\tnhap sai. Vui long nhap lai !!!");
    if(a == 'c'){
    	std :: cout << "\n";
        loading();
    	system("cls");
        Loop3(l,n,m);
    }
    else{  }
}

void Loop4(int n,int m){
    char a ;
    do{
        std :: cout << "\n\n\t\t\t\tBan co muon quay lai trang chu. Neu CO bam 'c' neu KHONG bam 'k': ";
        std :: cin >> a;
    }while((a != 'c' && a != 'k') && std :: cout << "\t\t\t\tnhap sai. Vui long nhap lai !!!");
    if(a == 'c'){
    	std :: cout << "\n";
        loading();
    	system("cls");
        Loop2(n,m);
    }
    else{  }
}
