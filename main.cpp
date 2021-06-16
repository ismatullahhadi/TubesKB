#include <iostream>
#include <stdio.h>

using namespace std;

class Fuzzy{
float memberPenghasilanKecil = 0, memberPenghasilanSedang = 0, memberPenghasilanBesar = 0;
float memberSaldoSedikit = 0, memberSaldoCukup = 0, memberSaldoBanyak = 0;
float memberKeaktifanJarang = 0, memberKeaktifanNormal = 0, memberKeaktifanSering = 0;
float terbesarX = 0, terbesarY = 0;

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

    void Inferensi(){
        int l=0;
        float nilaiKelayakan[8];
        string kelayakan[8];
        float nilaiPenghasilan[3] = {memberPenghasilanKecil, memberPenghasilanSedang, memberPenghasilanBesar};
        float nilaiSaldo[3] = {memberSaldoSedikit, memberSaldoCukup, memberSaldoBanyak};
        float nilaiKeaktifan[3] = {memberKeaktifanJarang, memberKeaktifanNormal, memberKeaktifanSering};

        //Menentukan rules dan nilai minimum
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if((nilaiPenghasilan[i] > 0) && (nilaiSaldo[j] > 0) && (nilaiKeaktifan[k] > 0)){
                        if(nilaiSaldo[j] < nilaiKeaktifan[k])
                            nilaiKelayakan[l] = nilaiSaldo[j];
                        else if(nilaiPenghasilan[i] < nilaiSaldo[j])
                            nilaiKelayakan[l] = nilaiPenghasilan[i];
                        else
                            nilaiKelayakan[l] = nilaiKeaktifan[k];
                        if((i == 0) && (j == 0) && (k >= 0))
                            kelayakan[l] = "TINGGI";
                        else if((i == 0) && (j == 1) && (k > 0))
                            kelayakan[l] = "TINGGI";
                        else if((i == 0) && (j == 2) && (k > 1))
                            kelayakan[l] = "TINGGI";
                        else if((i == 1) && (j == 0) && (k > 0))
                            kelayakan[l] = "TINGGI";
                        else if((i == 1) && (j == 1) && (k > 0))
                            kelayakan[l] = "TINGGI";
                        else if((i == 2) && (j == 0) && (k > 0))
                            kelayakan[l] = "TINGGI";
                        else if((i == 2) && (j == 1) && (k > 1))
                            kelayakan[l] = "TINGGI";
                        else
                            kelayakan[l] = "RENDAH";

                        cout << "Ketika Penghasilan "<<nilaiPenghasilan[i]<<", Saldo "<<nilaiSaldo[j]<<" dan Keaktifan Transaksi "<<nilaiKeaktifan[k]<<" maka Nasabah "<<kelayakan[l]<<" dengan nilai = "<<nilaiKelayakan[l] << endl;
                        l++;
                    }
                }
            }
        }
        //menentukan nilai max
        for (int i = 0; i < l; i++){
            if(kelayakan[i] == "RENDAH"){
                if(i == 0)
                    terbesarX = nilaiKelayakan[i];
                else{
                    if(nilaiKelayakan[i] > terbesarX)
                        terbesarX = nilaiKelayakan[i];
                }
            }else{
                if(i == 0)
                    terbesarY = nilaiKelayakan[i];
                else{
                    if(nilaiKelayakan[i] > terbesarY)
                        terbesarY = nilaiKelayakan[i];
                }
            }
        }
        if(terbesarX > 0)
            cout << endl << "======Nilai tidak mendapatkan emas====== \t= " << terbesarX << endl;
        if(terbesarY > 0)
            cout << endl << "=========Nilai mendapatkan emas========= \t= " << terbesarY << endl;
    }

    float defuzzifikasi(int sampel){
        float pengaliX, pengaliY;
        float hasilPembilang = 0;
        float hasilPenyebut = 0;
        float hasilDefuzzifikasi;
        int titik_sampel = 0;
        float jumlah_sampelX = 0;
        float jumlah_sampelY = 0;
        float pengaliZ[100], titik_sampelZ[100];
        int delta = 0; int k =0; pengaliX = terbesarX; pengaliY = terbesarY;
        delta = 100 / sampel;
        titik_sampel += delta;
        for(int i = 1; i <= sampel; i++){
            if(titik_sampel <= 50){
                hasilPembilang += titik_sampel * pengaliX;
                jumlah_sampelX += 1;
            }else if(titik_sampel >= 80){
                hasilPembilang += titik_sampel * pengaliY;
                jumlah_sampelY += 1;
            }else if((titik_sampel > 50) && (titik_sampel < 80)){
                if(pengaliX > pengaliY){
                    titik_sampelZ[k] = titik_sampel;
                    pengaliZ[k] = (int)(((80 - titik_sampelZ[k])/30)*1000);
                    pengaliZ[k] = (float)(pengaliZ[k]/1000);
                    hasilPembilang += titik_sampelZ[k] * pengaliZ[k];
                }else{
                    titik_sampelZ[k] = titik_sampel;
                    pengaliZ[k] = (int)(((titik_sampelZ[k] - 50)/30)*1000);
                    pengaliZ[k] = (float)(pengaliZ[k]/1000);
                    hasilPembilang += titik_sampelZ[k] * pengaliZ[k];
                }
                k += 1;
            }
            titik_sampel += delta;
        }
        hasilPenyebut = (jumlah_sampelX * pengaliX) + (jumlah_sampelY * pengaliY);
        for(int i = 0; i < k; i++){
            hasilPenyebut += pengaliZ[i];
        }
        cout << "\nHasil Pembilang\t\t= " << hasilPembilang << endl;
        cout << "Hasil Penyebut\t\t= " << hasilPenyebut << endl;
        hasilDefuzzifikasi = hasilPembilang / hasilPenyebut;
        return hasilDefuzzifikasi;
    }

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
    int sampel;
    float penghasilan;
    float saldo;
    float kt;
    float na;
    Fuzzy test;
    cout << "====================================================================="<< endl;
    cout << "||                       APLIKASI FUZZY                            ||"<< endl;
    cout << "======== PENGAMBILAN KEPUTUSAN PEMENANG UNTUK UNDIAN BANK============"<<endl<<endl;
    cout << "||Masukkan Penghasilan (Juta)||: ";
    cin >> penghasilan;
    test.anggotaPenghasilan(penghasilan);
    cout << "||Masukkan Saldo (Juta)||: ";
    cin >> saldo;
    test.anggotaSaldo(saldo);
    cout << "||Masukkan Keaktifan transaksi per bulan (kali)||: ";
    cin >> kt;
    test.anggotaKeaktifan(kt);
    test.cetakMember();

    cout << "\n||INFERENSI||\n";
    test.Inferensi();

    cout << "\n||DEFUZZIFIKASI||\n";
    cout << "\nMasukkan jumlah sampel\t= "; cin >> sampel;
    cout << endl;
    na = test.defuzzifikasi(sampel);
    cout << "=====Nilai Akhir===== \t\t= " << na;
    return 0;
}
