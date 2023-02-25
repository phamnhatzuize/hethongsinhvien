#include <bits/stdc++.h>
#include<windows.h>
struct du_Lieu_Sinh_Vien{
    float diembt, diemgk, diemck, diemtong ;
    int sotin, giatin;
    int sotien;
};

void menu1(){
    std :: cout << "\n\t\t\t\t";
    std :: cout << "---- CHAO MUNG BAN DEN VOI PHAN MEM HO TRO SINH VIEN 22DT4 ----";
    std :: cout << "\n\t\t\t\t\t   -----------------*********----------------";
    std :: cout << "\n\t\t\t\t\t1. Ho tro tinh diem hoc phan";
    std :: cout << "\n\t\t\t\t\t2. Ho tro tinh so tien hoc";
}

void menu2(){
    std :: cout << "\n\t\t\t\t\t****** HO TRO TINH DIEM HOC PHAN ******";
    std :: cout << "\n\t\t\t\t\t=======================================";
    std :: cout << "\n\n\t\t\t\t\t -----Moi ban lua chon hoc phan------";
    std :: cout << "\n\t\t\t\t\t\t1. Nhap mon nganh";
    std :: cout << "\n\t\t\t\t\t\t2. Ky thuat lap trinh";
    std :: cout << "\n\t\t\t\t\t\t3. Giai Tich";
}

void lua_Chon1( int &n);
void lua_Chon2( int &m);
float tinh_Diem(int m,float a,float b,float c); 
void nhap_Du_Lieu(int m,float &a,float &b,float &c);
void check_pass_or_fail(int m,float a, float b,float c);
void display1(float d);
void display2(float d);
void loading();
void vong_Lap();
void nhap_So_tin(int &sotin, int &giatin);
int tinh_Tien(int sotien, int sotin, int giatin);

class DocTien{
    public: 
    const char mau[10][8] = { "khong ","mot ","hai ","ba ","bon ","nam ","sau ", "bay ", "tam ","chin " };
int arr[10];
// hàm xét các vị trí dặc biệt 
// về trăm, nghin
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
// hàm chyen so thanh mang
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
    for( i = 1; i <= 8; i++){
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
        std :: cout << arr[i];
        if(i == 2 || i == 5){
            phan_donvi(i);
        }
    }
}
};

int main(){
    int n, m;
    du_Lieu_Sinh_Vien sv;
    DocTien dt;
    Phan_don_vi pdv;
    menu1();
    lua_Chon1(n);
    if(n == 1){ 
        loading();
        system("cls");
        menu2();
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
        
        vong_Lap();
        
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
            vong_Lap();
        }
    }
    return 0;
}

void lua_Chon1(int &n){
   do{
     std :: cout << "\n\t\t\t\t\tMoi ban lua chon: ";
     std :: cin >> n;
   }while((n >= 3 || n <= 0) && std :: cout << "\t\t\t\t\tKhong co lua chon cua ban !!!"<< "\n\tnhap lai !!!");
}

void lua_Chon2(int &m){
   do{
     std :: cout << "\n\t\t\t\t\t\tMoi ban lua chon: ";
     std :: cin >> m;
   }while((m >= 4 || m <= 0) && std :: cout << "\t\t\t\t\tKhong co lua chon cua ban !!!"<< "\n\tnhap lai !!!");
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
    if( d >= 4.0){
        std :: cout << "\n\n\t\t\t\t=> CHUC MUNG BAN DA QUA MON (^ :3 ^)";
    }else{
        std :: cout << "\n\n\t\t\t\t=> CHIA BUON BAN TACH MON ROI. CHUC HOC LAI VUI VE =))";
    }
}

void nhap_So_tin(int &sotin,int &giatin){
    do{
     std :: cout << "\n\t\t\t\t\tMoi ban nhap so tin: ";
     std :: cin >> sotin;
   }while((sotin >= 100 || sotin < 0) && std :: cout << "\t\t\t\t\tKhong co lua chon cua ban !!!"<< "\n\tnhap lai !!!");
    do{
     std :: cout << "\n\t\t\t\t\tMoi ban nhap so tien 1 tin: ";
     std :: cin >> giatin;
   }while((giatin < 0) && std :: cout << "\t\t\t\t\tKhong co lua chon cua ban !!!"<< "\n\tnhap lai !!!");
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
    Sleep(250);
    if(i > 10 && i < 20)
    Sleep(150);
    if(i >20 && i < 25 )
    Sleep(100);
    }  
}

void vong_Lap(){
    char a ;
    do{
        std :: cout << "\n\n\t\t\t\tBan co muon quay lai trang chu. Neu CO bam 'c' neu KHONG bam 'k': ";
        std :: cin >> a;
    }while((a != 'c' && a != 'k') && std :: cout << "\t\t\t\tnhap sai. Vui long nhap lai !!!");
    if(a == 'c'){
    	std :: cout << "\n";
        loading();
    	system("cls");
        main();
    }
    else{
    
    }
}