#include <iostream>
using namespace std;

#define MAX 100
struct ArrayList{
    int a[MAX];
    int soLuong;
};

//Khai bao rong
void init(ArrayList& l){
    l.soLuong = 0;
}

//Nhap danh sach
void inputList(ArrayList& l){
    cout << "Nhap so luong phan tu:";
    cin >> l.soLuong;
    for(int i = 0; i < l.soLuong; i++){
        cout << "a[" << i << "]= ";
        cin >> l.a[i];
    }
}

//Xuat danh sach
void outputList(const ArrayList l){
    for(int i = 0; i < l.soLuong; i++){
        cout << l.a[i] << "\t";
    }
    cout << endl;
}

//Tim mot phan tu trong danh sach
int find(const ArrayList l,const int key){
    for(int i = 0; i < l.soLuong; i++){
        if(l.a[i] == key)
            return i; // tim thay thi tra ve index cua no
    }
    return -1; //khong tim thay
}

//Bonus: Xuat ket qua tim kiem
void printRes(const ArrayList l,const int key){
    if(find(l, key) == -1)
        cout << "Khong tim thay phan tu!\n";
    else
        cout << "Da tim thay! Phan tu nam o vi tri: " << find(l, key) + 1 << endl;  
}

//Them phan tu vao cuoi danh sach
void insertLast(ArrayList& l,const int x){
    if(l.soLuong == MAX){
        cout << "Mang da day, khong the them.\n";
        return;
    }
    l.a[l.soLuong] = x;
    l.soLuong++;
}

//Xoa phan tu cuoi danh sach
void delLast(ArrayList& l){
    if(l.soLuong == 0){
        cout << "Danh sach rong, khong the xoa\n";
        return;
    }
    l.soLuong--;
}

//Xoa phan tu tai vi tri bat ky
void delElement(ArrayList& l,const int index){
    if(index >= 0 && index < l.soLuong){
        if(index < l.soLuong - 1)
            for(int i = index; i < l.soLuong; i++)
                l.a[i] = l.a[i + 1];
        l.soLuong--;
    }
}

//Them mot phan tu tai vi tri bat ky
void insertAt(ArrayList& l, const int index, const int y){
    if(index >= 0 && index < l.soLuong){
        for(int i = index; i < l.soLuong; i++)
            l.a[i + 1] = l.a[i];
        l.a[index] = y;
        l.soLuong++;
    }
}

//Tim va xoa mot phan tu trong danh sach
void findAndDel(ArrayList& l, const int z) {
    if (l.soLuong == 0) {
        cout << "Danh sach rong!\n";
        return;
    }
    int index = find(l, z);
    if (index == -1) {
        cout << "Khong tim thay phan tu do!\n";
        return;
    }
    delElement(l, index);
}
int main(){
    ArrayList l;
    init(l);
    
    inputList(l);
    outputList(l);
    
    cout << "===TIM KIEM===\n";
    int key;
    cout << "Nhap phan tu muon tim trong danh sach: ";
    cin >> key;
    printRes(l, key);
    
    cout << "===THEM PHAN TU VAO CUOI===\n";
    int x;
    cout << "Nhap phan tu muon them: ";
    cin >> x;
    insertLast(l,x);
    outputList(l);
    
    cout << "===XOA PHAN TU CUOI DANH SACH===\n";
    delLast(l);
    outputList(l);
    
    cout << "===Xoa phan tu o vi tri i===\n";
    int index;
    cout << "Nhap vi tri muon xoa: ";
    cin >> index;
    delElement(l, index);
    outputList(l);
    
    cout << "===Them phan tu vao vi tri i===\n";
    int y;
    cout << "Nhap phan tu muon them: "; //cho nay neu muon cho vi tri khac thi cho, tui xai cai index o tren
    cin >> y;
    insertAt(l, index, y);
    outputList(l);
    
    cout << "===Tim va xoa phan tu bat ky===\n";
    int z;
    cout << "Nhap phan tu: ";
    cin >> z;
    findAndDel(l, z);
    outputList(l);
    
    
    return 0;
}