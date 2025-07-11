# PraPraktikum 5 - ADT List

Repositori ini berisi solusi untuk soal-soal Praktikum 5 Algoritma dan Pemrograman, yang berfokus pada implementasi Abstract Data Type (ADT) List.

## Problem 1: Implementasi ADT List (`ListStatik.c`)

Untuk Problem 1, terdapat ambiguitas teknis antara nama ADT yang diminta ("List Statik") dengan definisi struktur data yang disediakan dalam file header (`ListStatik.h`). Nama "List Statik" secara konseptual mengacu pada list dengan alokasi memori statik (array berukuran tetap), namun file header yang diberikan justru mendefinisikan struktur data menggunakan pointer (`int *data`), yang merupakan ciri khas dari list dengan alokasi memori dinamis.

Untuk mendemonstrasikan pemahaman kedua konsep tersebut, solusi untuk masalah ini disajikan dalam dua pendekatan yang berbeda, masing-masing disimpan dalam folder `Alt` dan `Brief`.

### 1. Folder `Alt` - Implementasi List Statik Sebenarnya

Folder ini berisi implementasi yang sesuai dengan **konsep ADT List Statik yang sesungguhnya**. Pendekatan ini mengasumsikan bahwa tujuan utama dari soal adalah untuk mengimplementasikan list dengan alokasi memori statik, sehingga file header pun disesuaikan untuk mencerminkan hal ini.

**Karakteristik Utama:**
* **Alokasi Memori**: Memori untuk menyimpan elemen list dialokasikan saat kompilasi (*compile-time*) dan memiliki ukuran yang tetap.
* **Struktur Data**: `struct listStatik ListStatik` didefinisikan agar berisi array dengan ukuran tetap, bukan pointer.
    ```c
    #define CAPACITY 100
    
    typedef struct listStatik {
        int data[CAPACITY];     // Array statik, bukan pointer
        int ukuran;
    } ListStatik;
    ```
* **Manajemen Memori**: Tidak memerlukan `malloc()` dan `free()`. Oleh karena itu, library `stdlib.h` tidak digunakan.
* **Kelebihan**: Lebih cepat dan aman dari *memory leak* karena tidak ada manajemen memori dinamis.
* **Kekurangan**: Kapasitas list tidak fleksibel dan harus ditentukan saat kompilasi.

> **Kesimpulan**: Pendekatan `Alt` adalah implementasi yang secara teknis benar untuk sebuah **"List Statik"**.

### 2. Folder `Brief` - Implementasi Sesuai Spesifikasi Awal (List Dinamis)

Folder ini berisi implementasi yang **secara harfiah mengikuti file header (`ListStatik.h`) yang diberikan dalam brief soal**. Meskipun nama ADT-nya "List Statik", implementasinya adalah sebuah **List Dinamis berbasis Array**.

**Karakteristik Utama:**
* **Alokasi Memori**: Memori untuk menyimpan elemen list dialokasikan saat program berjalan (*run-time*).
* **Struktur Data**: `struct listStatik ListStatik` menggunakan pointer untuk menunjuk ke blok memori yang dialokasikan secara dinamis.
    ```c
    typedef struct listStatik {
        int *data;     // Pointer ke blok memori
        int ukuran;
        int kapasitas;
    } ListStatik;
    ```
* **Manajemen Memori**: **Wajib** menggunakan `malloc()` untuk mengalokasikan memori dan `free()` untuk melepaskannya setelah selesai digunakan. Membutuhkan library `stdlib.h`.
* **Kelebihan**: Kapasitas list lebih fleksibel dan dapat ditentukan saat runtime.
* **Kekurangan**: Memiliki overhead manajemen memori dan rentan terhadap *memory leak* jika `free()` tidak dipanggil.

> **Kesimpulan**: Pendekatan `Brief` adalah implementasi yang patuh pada spesifikasi awal, namun secara konsep merupakan **"List Dinamis"**.

### Tabel Perbandingan Teknis

| Fitur                 | Implementasi `Alt` (List Statik)   | Implementasi `Brief` (List Dinamis)  |
| :-------------------- | :--------------------------------- | :----------------------------------- |
| **Alokasi Memori**    | Compile-time (Statik)              | Run-time (Dinamis)                   |
| **Struktur Data Inti**| `int data[CAPACITY];`              | `int *data;`                         |
| **Kapasitas**         | Tetap, ditentukan di kode          | Fleksibel, ditentukan saat runtime   |
| **Library Tambahan**  | Tidak ada                          | `stdlib.h` (untuk `malloc` & `free`) |
| **Konsep ADT**        | **List Statik Sebenarnya**         | **List Dinamis (berbasis Array)**    |