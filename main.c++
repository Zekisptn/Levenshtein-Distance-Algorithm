#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Struktur data untuk buku
struct Buku {
    string judul;
    string pengarang;
    string penerbit;
    int tahun;
};

// Fungsi untuk membaca buku dari file
vector<Buku> bacaBukuDariFile(const string& namaFile) {
    vector<Buku> daftarBuku;
    ifstream file(namaFile);

    if (!file.is_open()) {
        cerr << "Gagal membuka file: " << namaFile << endl;
        return daftarBuku;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string judul, pengarang, penerbit, tahunStr;
        int tahun;

        getline(ss, judul, '|');
        getline(ss, pengarang, '|');
        getline(ss, penerbit, '|');
        getline(ss, tahunStr);
        tahun = stoi(tahunStr);

        daftarBuku.push_back({judul, pengarang, penerbit, tahun});
    }

    file.close();
    return daftarBuku;
}

// Fungsi untuk menghitung Levenshtein Distance
int hitungLevenshtein(const string& str1, const string& str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dp[i][j] = min({dp[i - 1][j] + 1,       // Deletion
                            dp[i][j - 1] + 1,       // Insertion
                            dp[i - 1][j - 1] + cost // Substitution
                          });
        }
    }
    return dp[m][n];
}

// Fungsi untuk mencari buku berdasarkan substring dari judul
bool containsSubstring(const string& str, const string& kataKunci) {
    string strLower = str;
    string kataKunciLower = kataKunci;

    transform(strLower.begin(), strLower.end(), strLower.begin(), ::tolower);
    transform(kataKunciLower.begin(), kataKunciLower.end(), kataKunciLower.begin(), ::tolower);

    return strLower.find(kataKunciLower) != string::npos;
}

// Fungsi utama untuk mencari buku
bool cariBuku(const vector<Buku>& daftarBuku) {
    while (true) {
        cout << "\nMasukkan kata kunci untuk mencari buku: ";
        string kataKunci;
        cin.ignore(); // Membersihkan buffer
        getline(cin, kataKunci);

        vector<int> hasilIndeks;
        vector<pair<int, int>> hasilLevenshtein;

        // Mencari buku yang judulnya mengandung kata kunci
        for (size_t i = 0; i < daftarBuku.size(); ++i) {
            if (containsSubstring(daftarBuku[i].judul, kataKunci)) {
                hasilIndeks.push_back(i);
            } else {
                // Hitung jarak Levenshtein jika substring tidak ditemukan
                int jarak = hitungLevenshtein(daftarBuku[i].judul, kataKunci);
                if (jarak <= 10) { // Ambang batas typo
                    hasilLevenshtein.push_back({i, jarak});
                }
            }
        }

        // Menampilkan hasil pencarian
        if (!hasilIndeks.empty() || !hasilLevenshtein.empty()) {
            int nomorList = 1; // Penomoran untuk list hasil pencarian
            cout << "\nHasil pencarian buku:\n";

            if (!hasilIndeks.empty()) {
                cout << "\nJudul buku yang cocok:" << endl;
                for (int idx : hasilIndeks) {
                    cout << nomorList++ << ". " << daftarBuku[idx].judul << endl;
                }
            }

            if (!hasilLevenshtein.empty()) {
                cout << "\nJudul buku yang mungkin cocok:" << endl;
                for (auto& [idx, jarak] : hasilLevenshtein) {
                    cout << nomorList++ << ". " << daftarBuku[idx].judul << endl;
                }
            }

            cout << "\nPilih nomor buku untuk melihat detail atau ketik 0 untuk mencari kembali: ";
            int pilihan;
            cin >> pilihan;

            if (pilihan > 0 && pilihan < nomorList) {
                // Menentukan indeks database berdasarkan pilihan
                int idx;
                if (pilihan <= hasilIndeks.size()) {
                    idx = hasilIndeks[pilihan - 1];
                } else {
                    idx = hasilLevenshtein[pilihan - hasilIndeks.size() - 1].first;
                }

                // Menampilkan detail buku dengan nomor dari database
                cout << "\nDetail Buku yang Dipilih:" << endl;
                cout << "Nomor Buku: " << (idx + 1) << endl; // Menampilkan nomor sesuai urutan data
                cout << "Judul: " << daftarBuku[idx].judul << endl;
                cout << "Pengarang: " << daftarBuku[idx].pengarang << endl;
                cout << "Penerbit: " << daftarBuku[idx].penerbit << endl;
                cout << "Tahun: " << daftarBuku[idx].tahun << endl;

                // Menanyakan apakah ingin mencari buku lagi
                cout << "\nApakah Anda ingin mencari buku lagi? (y/n): ";
                char konfirmasi;
                cin >> konfirmasi;
                if (konfirmasi == 'n' || konfirmasi == 'N') {
                    return false; // Keluar dari program
                } else if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    break; // Kembali ke awal pencarian
                } else {
                    cout << "Input tidak valid. Kembali ke menu pencarian.\n";
                }
            } else if (pilihan == 0) {
                // Langsung kembali ke menu pencarian
                break;
            } else {
                cout << "Pilihan tidak valid.\n";
            }
        } else {
            cout << "Tidak ada buku yang ditemukan dengan kata kunci \"" << kataKunci << "\"." << endl;
        }
    }
    return true;
}

int main() {
    // Nama file tempat menyimpan daftar buku
    string namaFile = "C:\\Users\\DM-ZackySeptian\\Documents\\zaki-project\\kuliah\\tugas-pak-hudi\\daftar_buku.txt";

    // Membaca daftar buku dari file
    vector<Buku> daftarBuku = bacaBukuDariFile(namaFile);

    if (daftarBuku.empty()) {
        cerr << "Tidak ada buku dalam file." << endl;
        return 1;
    }

    // Memulai pencarian buku
    while (cariBuku(daftarBuku)) {}

    cout << "Terima kasih telah menggunakan program pencarian buku." << endl;
    return 0;
}
