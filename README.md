# 📚 Program Pencarian Buku
Program ini dirancang untuk membantu pengguna mencari buku berdasarkan judul, termasuk mendeteksi kesalahan ejaan (typo) menggunakan algoritma **Levenshtein Distance**. Program ini mendukung pencarian ulang dan memberikan detail lengkap buku yang dipilih.
## 🛠️ Fitur
1. Pencarian buku berdasarkan kata kunci.
2. Deteksi kesalahan ejaan (typo) hingga batas toleransi tertentu.
3. Menampilkan daftar hasil pencarian dengan opsi untuk memilih detail buku.
4. Memungkinkan pengguna untuk melakukan pencarian ulang setelah melihat detail buku.
---
## 📝 Langkah-langkah Penggunaan
1. **Clone atau Unduh Repository**
   - Clone repository ke komputer Anda dengan perintah:
     ```bash
     git clone https://github.com/Zekisptn/Levenshtein-Distance-Algorithm
     ```
   - Atau unduh file `.zip` dari GitHub dan ekstrak ke direktori pilihan Anda.
2. **Persiapkan**
   - Pastikan Anda memiliki compiler **C++** seperti **g++** (bagian dari GCC).
   - Untuk pengguna **Windows**, gunakan IDE seperti **Code::Blocks**, **Dev-C++**, atau **Visual Studio**.
   - Untuk pengguna **Linux** atau **Mac**, gunakan terminal.

4. **Jalankan Program**
   - Jalankan program dengan mengklik tombol run
   - Program akan menampilkan pesan **"Masukkan kata kunci untuk mencari buku:"**.
5. **Masukkan Kata Kunci**
   - Ketik kata kunci yang sesuai dengan judul buku yang ingin Anda cari, lalu tekan **Enter**.
   - Program akan mencari buku yang cocok dengan kata kunci Anda, termasuk memperbaiki kesalahan ejaan.
6. **Pilih Nomor Buku**
   - Setelah hasil pencarian ditampilkan:
     - Pilih nomor buku dari daftar untuk melihat detail.
     - Ketik **0** untuk mencari buku kembali.
7. **Lihat Detail Buku**
   - Jika Anda memilih buku, program akan menampilkan detail lengkap, termasuk:
     - Judul
     - Pengarang
     - Penerbit
     - Tahun
   - Setelah itu, Anda akan diminta untuk menjawab:
     - Ketik **y** untuk mencari buku lain.
     - Ketik **n** untuk keluar dari program.
8. **Ulangi atau Keluar**
   - Program akan terus berjalan hingga Anda memilih untuk keluar dengan mengetik **n**.
---
## Contoh Penggunaan
1. Masukkan kata kunci: 
Data Science
2. Pilih hasil pencarian:
Data Science for All
Data Scire for All Pilih nomor buku untuk melihat detail atau ketik 0 untuk mencari kembali: 1
3. Lihat detail buku:
Detail Buku yang Dipilih: Judul: Data Science for All Pengarang: John Doe Penerbit: Tech Press Tahun: 2020
4. Jawab pertanyaan:
Apakah Anda ingin mencari buku lagi? (y/n): y
---
## 📂 Struktur File
|-- main.cpp |-- README.md
---
## 🔗 Lisensi
Program ini dilisensikan di bawah lisensi [MIT](https://opensource.org/licenses/MIT). Silakan gunakan, modifikasi, dan distribusikan.
---
Dengan mengikuti panduan ini, Anda dapat menjalankan program pencarian buku dengan mudah! 🚀
Salin dan tempelkan teks ini ke file README.md di repository GitHub Anda.
 
