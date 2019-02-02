# Engi's Kitchen Game

Sebuah game sederhana dibuat untuk memenuhi ketentuan sebuah mata kuliah

## Compiling

Untuk menjalankan, dapat menggunakan shell script yang sudah disediakan
```
./run.sh main
```
Pastikan library ncursesw sudah terinstall pada sistem

## Bermain
### Tujuan
Pemain berujuan mengumpulkan sebanyak mungkin uang. Uang didapat dengan menaruh pelanggan ke kursi dan membuatkan makanan untuk meja tersebut. Pemain dapat kalah jika terlalu lama melayani pelanggan.

### Command
- **ORDER** - Mengambil order dari meja yang bersebelahan dengan pemain
- **PUT** - Menaruh makanan di hand ke nampan
- **TAKE** - Mengambil bahan yang bersebelahan dengan
- **CH** - Membuang seluruh bahan makanan yang
- **CT** - Membuang seluruh makanan yang berada di dalam tray
- **PLACE** - Menaruh pelanggan di meja dan kosong.
- **GIVE** - Memberikan makanan yang berada di paling atas tumpukan ke pengunjung yang bertetanggaan
- **RECIPE** - Menampilkan pohon makanan.
- **SAVE** - Menyimpan state permainan saat ini
- **LOAD** - Melanjutkan permainan yang telah disimpan
- **EXIT** - Keluar dari program.
