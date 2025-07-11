#ifndef MANDIBOLA_H
#define MANDIBOLA_H

#include <stdio.h>

/**
 * @brief Menyapa pengguna dan menampilkan harga tiket serta memproses jumlah pengunjung dari input.
 *
 * @param input Angka tiga digit yang menyatakan jumlah pengunjung (ratusan: lansia, puluhan: dewasa, satuan: anak).
 *
 * @note Setiap digit bernilai 0–9.
 *
 * @example
 * * Format output:
 * *   ----------------------------------------
 * *   Selamat datang di Wahana Mandi Bola!
 * *   
 * *   Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.
 * *   
 * *   Harga tiket:
 * *   - Anak-anak (usia 0-12 tahun): Rp 10000
 * *   - Dewasa (usia 13-64 tahun): Rp 20000
 * *   - Lansia (usia 65 tahun ke atas): Rp 15000
 * *   
 * *   Jumlah anak: <jumlah_anak>
 * *   Jumlah dewasa: <jumlah_dewasa>
 * *   Jumlah lansia: <jumlah_lansia>
 */
void welcome(int input);

/**
 * @brief Menghitung total biaya tiket berdasarkan jumlah anak, dewasa, dan lansia.
 *
 * @param childCount Jumlah anak-anak (0-9).
 * @param adultCount Jumlah dewasa (0-9).
 * @param seniorCount Jumlah lansia (0-9).
 * 
 * @return Total biaya tiket untuk semua pengunjung.
 */
int countTicketCost(int childCount, int adultCount, int seniorCount);

/**
 * @brief Menampilkan detail tiket yang telah dibeli.
 *
 * @param childCount Jumlah anak-anak.
 * @param adultCount Jumlah dewasa.
 * @param seniorCount Jumlah lansia.
 *
 * @example
 * * Format output:
 * *   ----------------------------------------
 * *   Tiket berhasil dibeli!
 * *   Rincian:
 * *   - Jumlah anak-anak: <jumlah_anak>
 * *   - Jumlah dewasa: <jumlah_dewasa>
 * *   - Jumlah lansia: <jumlah_lansia>
 * *   - Total biaya: <total_biaya>
 */
void printTicket(int childCount, int adultCount, int seniorCount);

/**
 * @brief Mensimulasikan permainan Nimons dalam mencari harta dan menutup lubang berdasarkan input digit panjang.
 *
 * @param input Angka panjang yang mengkodekan seluruh aksi permainan.
 *
 * @note semua digit 0–9, kecuali `<harga>` bisa bernilai lebih besar.
 * 
 * @example
 * * Format input:
 * *   <harga><tutup_lubang><temukan_harta><langkah>...<tutup_lubang><temukan_harta><langkah><jumlah_harta><jumlah_lubang><jumlah_langkah>
 * *
 * * Format output:
 * *   ----------------------------------------
 * *   Selamat datang di Treasure Hunting Nimons!
 * *   Jumlah pergerakan Nimons di dalam kolam: <jumlah_pergerakan>
 * *   Jumlah lubang yang ada di kolam: <jumlah_lubang>
 * *   Jumlah harta karun yang ada di kolam: <jumlah_harta_karun>
 * *   Langkah ke-1
 * *   {jika input = 0} Nimons tidak bergerak
 * *   {jika input = 1} Nimons menemukan harta karun!
 * *   {jika input = 1} Nimons menutup lubang!
 * *   ...
 * *   Langkah ke-<n>
 * *   Nimons bergerak sejauh <langkah> langkah
 * *   Nimons menemukan harta karun!
 * *   Nimons menutup lubang!
 * *   
 * *   Total lubang yang ditutup: <jumlah_lubang_ditutup> dari <jumlah_lubang> lubang
 * *   Total harta karun yang ditemukan: <total_harta_karun>
 * *   Total harga harta karun yang ditemukan: <total_harta_karun * harga * 5>
 * *   Total langkah yang ditempuh: <total_langkah>
 * *   Total biaya ganti rugi Pak Gro: <harga * jumlah_lubang_ditutup>
 * *   Total keuntungan Nimons dan Pak Gro: <total_harga - biaya_rugi>
 */
void handleNimonsHunting(long long input);

#endif /* MANDIBOLA_H */