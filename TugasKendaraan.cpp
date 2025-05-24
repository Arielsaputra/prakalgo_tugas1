
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct kendaraan {
    string nomorPlat;
    string jenisKendaraan;
    string merkKendaraan;
    string modelKendaraan;
    string namaPemilik;
    int tahunProduksi;
};

kendaraan dataKendaraan[100]; 
int jumlahKendaraan = 0;


int tampilkanMenu() {
    int menu;
    
    cout << "\n=================================\n";
    cout << "|        MENU PILIHAN           |\n";
    cout << "=================================\n";
    cout << "1. Input Data Kendaraan\n";
    cout << "2. Tampilkan seluruh data kendaraan\n";
    cout << "3. Urutkan data kendaraan (Bubble Sort)\n";
    cout << "4. Cari data kendaraan (Sequential Search)\n";
    cout << "5. Exit\n";
    cout << "=================================\n";
    cout << "Pilihan Menu: "; 
    cin >> menu;
    cin.ignore(); 
    return menu;
}


void inputData() {
    int tambah;
    cout << "Masukkan jumlah kendaraan yang ingin ditambahkan: ";
    cin >> tambah;
    cin.ignore(); 

    if (jumlahKendaraan + tambah > 100) {
        cout << "Jumlah maksimal kendaraan adalah 100.\n";
        return;
    }

    for (int i = jumlahKendaraan; i < jumlahKendaraan + tambah; i++) {
        cout << "\nKendaraan ke-" << (i + 1) << ":\n";
        
        cout << "Masukkan Nomor Plat Kendaraan: ";
        getline(cin, dataKendaraan[i].nomorPlat);
        
        cout << "Jenis Kendaraan (Mobil/Motor): ";
        getline(cin, dataKendaraan[i].jenisKendaraan);
        
        cout << "Merk Kendaraan: ";
        getline(cin, dataKendaraan[i].merkKendaraan);
        
        cout << "Model Kendaraan: ";
        getline(cin, dataKendaraan[i].modelKendaraan);
        
        cout << "Nama Pemilik: ";
        getline(cin, dataKendaraan[i].namaPemilik);

        cout << "Tahun Produksi: ";
        cin >> dataKendaraan[i].tahunProduksi;
        cin.ignore();
    }
    
    jumlahKendaraan += tambah;
    cout << "Data telah ditambahkan.\n";
}


void tampilData() {
    if (jumlahKendaraan == 0) {
        cout << "Belum ada data kendaraan.\n";
        return;
    }

    cout << "\n=================================================================================================\n";
    cout << "| No | Nomor Plat      | Jenis        | Merk       | Model      | Pemilik    | Tahun Produksi |\n";
    cout << "==================================================================================================\n";
    
    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(15) << dataKendaraan[i].nomorPlat << " | "
             << setw(12) << dataKendaraan[i].jenisKendaraan << " | "
             << setw(10) << dataKendaraan[i].merkKendaraan << " | "
             << setw(10) << dataKendaraan[i].modelKendaraan << " | "
             << setw(10) << dataKendaraan[i].namaPemilik << " | "
             << setw(14) << dataKendaraan[i].tahunProduksi << " |\n";
    }

    cout << "=================================================================================================\n";
}

// Bubble Sort 
void bubbleSort() {
    if (jumlahKendaraan == 0) {
        cout << "Belum ada data kendaraan untuk diurutkan.\n";
        return;
    }

    for (int i = 0; i < jumlahKendaraan - 1; i++) {
        for (int j = 0; j < jumlahKendaraan - i - 1; j++) {
            if (dataKendaraan[j].tahunProduksi > dataKendaraan[j + 1].tahunProduksi) {
                swap(dataKendaraan[j], dataKendaraan[j + 1]);
            }
        }
    }
    
    cout << "Data kendaraan telah diurutkan berdasarkan tahun produksi.\n";
}

// sequensial
void cariKendaraan() {
    if (jumlahKendaraan == 0) {
        cout << "Belum ada data kendaraan untuk dicari.\n";
        return;
    }

    string cariPlat;
    cout << "Masukkan nomor plat kendaraan yang ingin dicari: ";
    getline(cin, cariPlat);

    bool ditemukan = false;
    for (int i = 0; i < jumlahKendaraan; i++) {
        if (dataKendaraan[i].nomorPlat == cariPlat) {
            cout << "Data Kendaraan Ditemukan!\n";
            cout << "Nomor Plat: " << dataKendaraan[i].nomorPlat << "\n";
            cout << "Jenis Kendaraan: " << dataKendaraan[i].jenisKendaraan << "\n";
            cout << "Merk Kendaraan: " << dataKendaraan[i].merkKendaraan << "\n";
            cout << "Model Kendaraan: " << dataKendaraan[i].modelKendaraan << "\n";
            cout << "Nama Pemilik: " << dataKendaraan[i].namaPemilik << "\n";
            cout << "Tahun Produksi: " << dataKendaraan[i].tahunProduksi << "\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Kendaraan dengan nomor plat " << cariPlat << " tidak ditemukan.\n";
    }
}


int main() {
    int pilihan;
    do {
        pilihan = tampilkanMenu();

        switch (pilihan) {
            case 1:
                inputData();
                break;
            case 2:
                tampilData();
                break;
            case 3:
                bubbleSort();
                break;
            case 4:
                cariKendaraan();
                break;
            case 5:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
