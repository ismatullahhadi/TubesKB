#include <iostream>
#include <stdio.h>

using namespace std;

class Fuzzy{
float memberPenghasilanKecil = 0;
float memberPenghasilanSedang = 0;
float memberPenghasilanBesar = 0;
float memberSaldoSedikit = 0;
float memberSaldoCukup = 0;
float memberSaldoBanyak = 0;
float memberKeaktifanJarang = 0;
float memberKeaktifanNormal = 0;
float memberKeaktifanSering = 0;

public:
    //Keanggotaan Penghasilan
    void anggotaPenghasilan(float inputPenghasilan){

    //Penghasilan Kecil
    if(inputPenghasilan <= 1){
       memberPenghasilanKecil=1;
    }else{
        if(inputPenghasilan < 3.0){
            memberPenghasilanKecil = (float)((-inputPenghasilan+3.00)/2);
        }else memberPenghasilanKecil = 0;
    }

    //Penghasilan Sedang
    if(inputPenghasilan >= 3 && inputPenghasilan <= 5){
        memberPenghasilanSedang = 1;
    }else{
        if(inputPenghasilan > 1 && inputPenghasilan < 3){
            memberPenghasilanSedang = (float)((inputPenghasilan-1)/2);
        }else{
            if(inputPenghasilan > 5 && inputPenghasilan < 7){
                memberPenghasilanSedang = (float)((-inputPenghasilan+7)/2);
            } else memberPenghasilanSedang = 0;
        }
    }

    //Penghasilan Besar
    if(inputPenghasilan <= 5){
        memberPenghasilanBesar = 0;
    }else{
        if(inputPenghasilan > 5 && inputPenghasilan < 7){
            memberPenghasilanBesar = (float)((inputPenghasilan-5)/2);
        }
        else memberPenghasilanBesar=1;
    }
};

//Keanggotaan Saldo
    void anggotaSaldo(float inputSaldo){

    //Saldo Sedikit
    if(inputSaldo <= 0.5){
       memberSaldoSedikit = 1;
    }else{
        if(inputSaldo < 1){
            memberSaldoSedikit = (float)((-inputSaldo+1)/0.5);
        }else memberSaldoSedikit = 0;
    }

    //Saldo Cukup
    if(inputSaldo >= 1 && inputSaldo <= 4){
        memberSaldoCukup = 1;
    }else{
        if(inputSaldo > 0.5 && inputSaldo < 1){
            memberSaldoCukup = (float)((inputSaldo-0.5)/0.5);
        }else{
            if(inputSaldo > 4 && inputSaldo < 5){
                memberSaldoCukup= (float)((-inputSaldo+5)/1);
            } else memberSaldoCukup= 0;
        }
    }

    //Saldo Banyak
    if(inputSaldo <= 4){
        memberSaldoBanyak = 0;
    }else{
        if(inputSaldo > 4 && inputSaldo < 5){
            memberSaldoBanyak = (float)((inputSaldo-4)/1);
        }
        else memberSaldoBanyak=1;
    }
};

//Keanggotaan Keaktifan Transaksi
    void anggotaKeaktifan(float inputKeaktifan){

    //Keaktifan Transaksi Jarang
    if(inputKeaktifan <= 5){
       memberKeaktifanJarang =1;
    }else{
        if(inputKeaktifan < 6){
            memberKeaktifanJarang = (float)((-inputKeaktifan+6)/1);
        }else memberKeaktifanJarang = 0;
    }

    //Keaktifan Transaksi Normal
    if(inputKeaktifan >= 6 && inputKeaktifan<= 15){
        memberKeaktifanNormal = 1;
    }else{
        if(inputKeaktifan > 5 && inputKeaktifan < 6){
            memberKeaktifanNormal = (float)((inputKeaktifan-5)/1);
        }else{
            if(inputKeaktifan > 15 && inputKeaktifan< 16){
                memberKeaktifanNormal = (float)((-inputKeaktifan+16)/1);
            } else memberKeaktifanNormal = 0;
        }
    }

    //Keaktifan Transaksi Sering
    if(inputKeaktifan <= 15){
        memberKeaktifanSering = 0;
    }else{
        if(inputKeaktifan > 15 && inputKeaktifan < 16){
            memberKeaktifanSering= (float)((inputKeaktifan-15)/1);
        }
        else memberKeaktifanSering=1;
    }
};

        void cetakMember(){
        cout << " \n\n----------PROSES FUZZIFIKASI----------\n" << endl;
        cout << " Nilai Fuzzy Penghasilan" << endl;
        cout << "Kecil \n" << memberPenghasilanKecil << endl;
        cout << "Sedang \n" << memberPenghasilanSedang << endl;
        cout << "Besar \n" << memberPenghasilanBesar << endl;
        cout << " Nilai Fuzzy Saldo" << endl;
        cout << "Sedikit \n" << memberSaldoSedikit<< endl;
        cout << "Cukup \n" << memberSaldoCukup<< endl;
        cout << "Banyak \n" << memberSaldoBanyak<< endl;
        cout << " Nilai Fuzzy Keaktifan Transaksi" << endl;
        cout << "Jarang \n" << memberKeaktifanJarang << endl;
        cout << "Normal \n" << memberKeaktifanNormal << endl;
        cout << "Sering \n" << memberKeaktifanSering << endl;
    }
};

int main(){
    float penghasilan;
    float saldo;
    float kt;
    Fuzzy test;

    cout << "Masukkan Penghasilan (Juta): ";
    cin >> penghasilan;
    test.anggotaPenghasilan(penghasilan);
    cout << "Masukkan Saldo (Juta): ";
    cin >> saldo;
    test.anggotaSaldo(saldo);
    cout << "Masukkan Keaktifan transaksi per bulan (kali): ";
    cin >> kt;
    test.anggotaKeaktifan(kt);
    test.cetakMember();

    return 0;
}
