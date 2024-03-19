#include <iostream>
#include <string>

using namespace std;

string data_hewan[100] = {"singa", "gajah"};
int jumlah_hewan = 2;

void login() {
    cout << "login" << endl;
    cout << "1. masuk" << endl;
    cout << "2. keluar" << endl;
}

void menu() {
    cout << "=== MENU ===" << endl;
    cout << "1. tambah LIST" << endl;
    cout << "2. hapus LIST" << endl;
    cout << "3. edit list" << endl;
    cout << "4. lihat list" << endl;
    cout << "5. luas kandang dibutuhkan" << endl;
    cout << "6. keluar" << endl;
}

int jumlahDataHewan() {
    return jumlah_hewan;
}

int luasKandang(const int& jumlahHewan) {
    int luasSatuHewan = 4; 
    return jumlahHewan * luasSatuHewan;
}

int main() {
    while (true) {
        login();
        cout << "masukan pilihan anda: ";
        int log; 
        cin >> log;
        if (log == 1) {
            cout << "LIST DATA HEWAN DI KEBUN BINATANG" << endl;
            string nama_ = "zidan";
            string nama;
            cout << "masukan nama anda: ";
            cin >> nama;
            string nim = "084";
            string pass_ = nim.substr(nim.length() - 3);
            int percobaan = 0;
            while (percobaan < 3) {
                string passs;
                cout << "masukan password anda (password menggunakan 3 nomor akhir NIM): ";
                cin >> passs;
                if (passs == pass_ && nama == nama_) {
                    menu();
                    cout << "selamat datang " << nama << endl;
                    int pilih2;
                    cout << "masukan pilihan anda: ";
                    cin >> pilih2;
                    if (pilih2 == 1) {
                        cout << "tambah list" << endl;
                        string lanjut1 = "ya";
                        while (lanjut1 == "ya") {
                            string hewan_baru;
                            cout << "masukan nama hewan: ";
                            cin >> hewan_baru;
                            data_hewan[jumlah_hewan] = hewan_baru;
                            jumlah_hewan++;
                            cout << "apakah ingin lanjut?[ya/tidak]: ";
                            cin >> lanjut1;
                        }
                    } else if (pilih2 == 2) {
                        cout << "hapus list" << endl;
                        for (int i = 0; i < jumlah_hewan; i++) {
                            cout << i + 1 << "." << data_hewan[i] << endl;
                        }
                        string lanjut2 = "ya";
                        while (lanjut2 == "ya") {
                            string hewan_hapus;
                            cout << "masukan nama hewan yang akan dihapus: ";
                            cin >> hewan_hapus;
                            int index_hapus = -1;
                            for (int i = 0; i < jumlah_hewan; i++) {
                                if (data_hewan[i] == hewan_hapus) {
                                    index_hapus = i;
                                    break;
                                }
                            }
                            if (index_hapus != -1) {
                                for (int i = index_hapus; i < jumlah_hewan - 1; i++) {
                                    data_hewan[i] = data_hewan[i + 1];
                                }
                                jumlah_hewan--;
                                cout << "Data berhasil dihapus." << endl;
                            } else {
                                cout << "Data tidak ditemukan." << endl;
                            }
                            cout << "apakah ingin lanjut?[ya/tidak]: ";
                            cin >> lanjut2;
                        }
                    } else if (pilih2 == 3) {
                        cout << "edit list" << endl;
                        for (int i = 0; i < jumlah_hewan; i++) {
                            cout << i + 1 << "." << data_hewan[i] << endl;
                        }
                        string lanjut3 = "ya";
                        while (lanjut3 == "ya") {
                            string hewan_edit;
                            cout << "masukan nama hewan yang diganti: ";
                            cin >> hewan_edit;
                            int index_edit = -1;
                            for (int i = 0; i < jumlah_hewan; i++) {
                                if (data_hewan[i] == hewan_edit) {
                                    index_edit = i;
                                    break;
                                }
                            }
                            if (index_edit != -1) {
                                string hewan_baru;
                                cout << "masukan nama hewan baru: ";
                                cin >> hewan_baru;
                                data_hewan[index_edit] = hewan_baru;
                                cout << "Data berhasil diubah." << endl;
                            } else {
                                cout << "Data tidak ditemukan." << endl;
                            }
                            cout << "apakah ingin lanjut?[ya/tidak]: ";
                            cin >> lanjut3;
                        }
                    } else if (pilih2 == 4) {
                        cout << "Jumlah data hewan: " << jumlahDataHewan() << endl;
                        cout << "lihat list" << endl;
                        for (int i = 0; i < jumlah_hewan; i++) {
                            cout << i + 1 << "." << data_hewan[i] << endl;
                        }
                    } else if (pilih2 == 5) {
                        cout << "Masukkan jumlah hewan: ";
                        int jumlahHewan;
                        cin >> jumlahHewan;
                        cout << "Total luas kandang yang dibutuhkan untuk " << jumlahHewan << " hewan adalah " << luasKandang(jumlahHewan) << "m^2" << endl;
                    } else if (pilih2 == 6) {
                        cout << "anda keluar program" << endl;
                        break;
                    }
                } else {
                    cout << "sandi salah" << endl;
                    percobaan++;
                }
            }
        } else if (log == 2) {
            cout << "anda keluar program" << endl;
            break;
        } else {
            cout << "pilihan tidak ada" << endl;
        }
    }

    return 0;
}
