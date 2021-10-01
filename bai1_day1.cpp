#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

// cau a
void so_lon_nhat(vector<int> cac_so, string tenfile)
{
    ofstream dapan;
    dapan.open(tenfile);
    vector<int> cac_vi_tri;
    cac_vi_tri.push_back(1);
    int so_lon_nhat;
    so_lon_nhat = cac_so[0];
    for (int i = 0; i < cac_so.size(); i++)
    {
        if (so_lon_nhat < cac_so[i])
        {
            cac_vi_tri.clear();
            so_lon_nhat = cac_so[i];
            cac_vi_tri.push_back(i + 1);
        }
        else if (so_lon_nhat == cac_so[i])
        {
            cac_vi_tri.push_back(i + 1);
        }
    }
    dapan << "Bai 1" <<endl;
    dapan << "a: so lon nhat la : " << so_lon_nhat << endl;
    dapan << "   cac vi tri co so lon nhat la: ";
    for (int i = 0; i < cac_vi_tri.size(); i++)
    {
        dapan << cac_vi_tri[i] << " ";
        if (i == cac_vi_tri.size() - 1)
        {
            dapan << endl;
            dapan.close();
        }
    }
    return;
}

//cau b
void tim_so_nguyen_to_lon_nhat(vector<int> cac_so, string tenfile)
{
    //mo file dap an
    ofstream file_dap_an;
    file_dap_an.open(tenfile, ios_base::app);

    //flag
    bool isPrime;
    int so_nguyen_to_lon_nhat = -1;
    vector<int> vi_tri_so_nguyen_to_lon_nhat;
    for (int i = 0; i < cac_so.size(); i++)
    {
        //set gia tri prime true ban dau
        isPrime = true;
        for (int k = 2; k <= sqrt(cac_so[i]); k++)
        {
            if (cac_so[i] % k == 0)
            {
                //neu chia het thi kph so nguyen to, thoat for
                isPrime = false;
                break;
            }
        }
        //kiem tra xem co phai so nguyen to lon nhat
        if (isPrime)
        {
            if (so_nguyen_to_lon_nhat < cac_so[i])
            {
                vi_tri_so_nguyen_to_lon_nhat.clear();
                so_nguyen_to_lon_nhat = cac_so[i];
                vi_tri_so_nguyen_to_lon_nhat.push_back(i + 1);
            }
            else if (so_nguyen_to_lon_nhat == cac_so[i])
            {
                vi_tri_so_nguyen_to_lon_nhat.push_back(i + 1);
            }
        }
    }
    if (so_nguyen_to_lon_nhat != -1)
    {
        file_dap_an << "b. so nguyen to lon nhat la : " << so_nguyen_to_lon_nhat << endl;
        file_dap_an << "   so nguyen to lon nhat nam o vi tri : ";
        for (int i = 0; i < vi_tri_so_nguyen_to_lon_nhat.size(); i++)
        {
            file_dap_an << vi_tri_so_nguyen_to_lon_nhat[i] << " ";
            if (i == vi_tri_so_nguyen_to_lon_nhat.size() - 1)
            {
                file_dap_an << endl;
                file_dap_an.close();
            }
        }
    }
    else
    {
        file_dap_an << "cau b khong co dap an" << endl;
        file_dap_an.close();
    }
}

//cau c 
void tim_so_chinh_phuong_max(vector<int> cac_so, string tenfile){
    //mo file dap an
    ofstream file_dap_an;
    file_dap_an.open(tenfile, ios_base::app);
    //khai bao bien 
    int can_bac_hai ;
    int so_chinh_phuong_lon_nhat = -1 ;
    vector<int> tat_ca_vi_tri ;
    //kiem tra so chinh phuong 
    for(int i = 0; i < cac_so.size(); i++){
        if(cac_so[i]>=0){
            can_bac_hai = sqrt(cac_so[i]);
            if(can_bac_hai*can_bac_hai == cac_so[i]){
                if(cac_so[i]>so_chinh_phuong_lon_nhat){
                    tat_ca_vi_tri.clear();
                    so_chinh_phuong_lon_nhat = cac_so[i];
                    tat_ca_vi_tri.push_back(i+1);
                }else if(cac_so[i] == so_chinh_phuong_lon_nhat){
                    tat_ca_vi_tri.push_back(i+1);
                }
            }
        }
    }
    if(so_chinh_phuong_lon_nhat > -1){
        file_dap_an << "c. so chinh phuong lon nhat la : " << so_chinh_phuong_lon_nhat << endl;
        file_dap_an << "   so chinh phuong lon nhat nam o vi tri : ";
        for (int i = 0; i < tat_ca_vi_tri.size(); i++)
        {
            file_dap_an << tat_ca_vi_tri[i] << " ";
            if (i == tat_ca_vi_tri.size() - 1)
            {
                file_dap_an << endl;
                file_dap_an.close();
            }
        }
    }else{
        file_dap_an << "c. khong co so chinh phuong nao" ;
        file_dap_an.close();
    }

}

//cau d
// tinh trung binh cac so le trong day
void tinh_trung_binh_so_le(vector<int> cac_so, string tenfile)
{
    //mo file dap an
    ofstream file_dap_an;
    file_dap_an.open(tenfile, ios_base::app);
    //khai bao bien
    int tong_cac_so_le ;
    int so_cac_so_le =0 ;
    for(int i = 0; i < cac_so.size(); i++){
        if(cac_so[i] % 2 == 1 ){
            tong_cac_so_le += cac_so[i];
            so_cac_so_le ++ ;
        }
    }
    if(so_cac_so_le != 0 ){
        file_dap_an << "d. trung binh cac so le la : ";
        file_dap_an << ((float)tong_cac_so_le/(float)so_cac_so_le) << endl;
        file_dap_an.close();
    }else{
        file_dap_an << "d. khong co so le nao";
        file_dap_an.close();
    }
}

int main()
{
    string tenfile;
    ifstream input_file;
    string ten_file_dap_an = "dap_an.txt";
    int so;
    vector<int> cac_so;
    cout << "ten file : ";
    cin >> tenfile;
    input_file.open(tenfile);

    while (input_file >> so)
    {
        cac_so.push_back(so);
    }
    //dong file cau hoi
    input_file.close();

    if (cac_so.size() > 0)
    {
        //lam cau a
        so_lon_nhat(cac_so, ten_file_dap_an);
        //lam cau b
        tim_so_nguyen_to_lon_nhat(cac_so, ten_file_dap_an);
        //lam cau c
        tim_so_chinh_phuong_max(cac_so, ten_file_dap_an);
        //lam cau d
        tinh_trung_binh_so_le(cac_so,ten_file_dap_an);
    }
    else
    {
        cout << "khong co du lieu";
    }

    return 0;
}