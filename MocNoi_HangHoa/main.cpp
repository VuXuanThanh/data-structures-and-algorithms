#include <bits/stdc++.h>

using namespace std;
struct HangHoa{
    int maHang;
    char tenHang[22];
    char dvTinh[10];
    int donGia;
    int soLuong;
    int thanhTien;
};
struct Node{
    HangHoa infor;
    Node *next;
};
typedef Node *TRO;// Kieu con tro Node


void creat(TRO &H){
    H=NULL;
}
int Empty(TRO H){
    return H==NULL;
}
void add(TRO &H ,HangHoa x){
    TRO P=new Node;
    P->infor=x;
    P->next=NULL;
    if(H==NULL){
        H=P;
    }
    else{
        TRO Q=H;
        while(Q->next!=NULL){
            Q=Q->next;
        }
        Q->next=P;
    }
}
HangHoa taoHh(int maHang, const char *tenHang, const char* dvTinh,int donGia, int soLuong){
    HangHoa h;
    h.maHang=maHang;
    strcpy(h.tenHang,tenHang);
    strcpy(h.dvTinh,dvTinh);
    h.donGia=donGia;
    h.soLuong=soLuong;
    h.thanhTien=h.soLuong*h.donGia;
    return h;
}
void taoDS(TRO &H){
    creat(H);
    add(H,taoHh(2001,"Vo", "Quyen",5000,20));
    add(H,taoHh(2002,"But chi", "Cai",8000,20));
    add(H,taoHh(2003,"Hop but", "Chiec",30000,20));
    add(H,taoHh(2004,"Tay", "Cai",10000,20));
    add(H,taoHh(2005,"Muc", "Lo",5000,20));
}
void tieude(){
    cout<<setw(4)<<left<<"STT";
    cout<<setw(8)<<"Ma Hang";
    cout<<setw(16)<<"  Ten Hang";
    cout<<setw(12)<<"DV tinh";
    cout<<setw(8)<<"Don gia";
    cout<<setw(8)<<"So luong";
    cout<<setw(8)<<"  Thanh tien"<<endl;

}
void hthh(HangHoa h, int stt){
        cout<<setw(3)<<right<<stt<<" ";
        cout<<setw(6)<<h.maHang<<"  ";
         cout<<setw(16)<<left<<h.tenHang<<"  ";
          cout<<setw(6)<<h.dvTinh<<"  ";
           cout<<setw(8)<<right<<h.donGia<<"  ";
            cout<<setw(7)<<h.soLuong<<"  ";
             cout<<setw(10)<<h.thanhTien<<endl;
}
void htds(TRO H){
    tieude();
    TRO Q=H;
    int stt=1;
    while(Q!=NULL){
        hthh(Q->infor,stt);
        stt++;
        Q=Q->next;
    }
    cout<<"-------------------------------"<<endl;
}
void xoaPTThu3(TRO &H){
    if(Empty(H)){
        cout<<"\nDanh sach rong, ko xoa dc";
        return;
    }
   TRO M=H;
   int d=1;
   while(M->next!=NULL &&d<2){
        M=M->next;
        d++;
   }
   if(M->next==NULL){
    cout<<"\nDanh sach ko co phan tu thu 3, xoa dc";
    return;
   }
   TRO Q=M->next;
   M->next=Q->next;
   delete Q;
}
void chen_vt_DauTien(TRO &H, HangHoa x){
    TRO P = new Node;
    P->infor=x;
    P->next=H;
    H=P;
}
void sapXep(TRO &H){
    if(Empty(H)||H->next==NULL){
        return;
    }
    TRO P=H,Q,M=NULL;
    while(P->next!=M){
        Q=P->next;
        if(P->infor.thanhTien>Q->infor.thanhTien){
            HangHoa tg=P->infor;
            P->infor=Q->infor;
            Q->infor=tg;
        }
        P=P->next;
        Q=Q->next;

    }
      M=P;
        P=H;
}
int main()
{
    cout<<"Bai tap ds moc noi don\n";
    TRO H;
    taoDS(H);
    cout<<"\n========DANH SACH HANG HOA ========\n";
    htds(H);
    xoaPTThu3(H);
    cout<<"\nSau khi xoa phan tu thu 3"<<endl;
    cout<<"\n========DANH SACH HANG HOA ========\n";
    htds(H);
   chen_vt_DauTien(H,taoHh(2007,"Phan", "Hop",2000,15));
    cout<<"\n========DANH SACH HANG HOA Sau Khi chen dau tin========\n";
    htds(H);
    sapXep(H);
     cout<<"\n========DANH SACH HANG HOA sau khi sap xep=======\n";
    htds(H);
    return 0;

}
