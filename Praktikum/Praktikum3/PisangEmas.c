/**
 * --------------------------------------------------------------
 * | @file PisangEmas.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk memodifikasi sebuah array (daftar berat      |
 * | pisang) berdasarkan elemen target. Jika elemen target      |
 * | ditemukan, nilainya diubah berdasarkan tetangganya, dan    |
 * | sisa array di sebelah kanannya dibalik.                    |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @details Membaca ukuran array, nilai target, dan elemen-elemen array.
 *          Kemudian melakukan modifikasi dan pencetakan array sesuai aturan.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    int arraySize;    // Jumlah elemen dalam array (N)
    int targetValue;  // Nilai target yang dicari dalam array

    // Membaca ukuran array dan nilai target dari pengguna.
    scanf("%d %d", &arraySize, &targetValue);

    // Deklarasi array untuk menyimpan berat pisang.
    // Menggunakan Variable Length Array (VLA), fitur C99.
    int weights[arraySize];

    // Membaca elemen-elemen array dari pengguna.
    // Perhatikan: Input dibaca dan disimpan dalam urutan terbalik ke dalam array.
    // Jika input: 1 2 3 4 5 (dengan N=5), maka weights akan menjadi [5, 4, 3, 2, 1] jika dibaca i dari 0.
    // Kode asli: for (int i = n - 1; i >= 0; i--), jika N=5, i = 4,3,2,1,0.
    // scanf("%d", &berat[i]); -> berat[4], berat[3], ..., berat[0].
    // Jadi, jika input adalah 1 2 3 4 5, maka weights[0]=5, weights[1]=4, ..., weights[4]=1.
    // Ini berarti elemen pertama input menjadi elemen terakhir array secara logis (jika diakses dari 0 ke N-1).
    // Namun, loop pemrosesan utama (for (int i = 0; i < n; i++)) akan mengaksesnya sesuai urutan penyimpanan ini.
    // Untuk kejelasan, kita akan tetap membaca sesuai urutan dan memprosesnya.
    // Koreksi: Kode asli membaca input ke `berat[i]` dengan `i` dari `n-1` ke `0`.
    // Ini berarti elemen pertama input masuk ke `berat[n-1]`, elemen kedua ke `berat[n-2]`, dst.
    // Jadi, jika input `1 2 3 4 5` (n=5), maka:
    // berat[4] = 1
    // berat[3] = 2
    // berat[2] = 3
    // berat[1] = 4
    // berat[0] = 5
    // Loop pemrosesan selanjutnya `for (int i = 0; i < n; i++)` akan mengakses `berat[0]` (nilai 5) dulu.
    // Ini efektif membalik urutan input saat pemrosesan.
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &weights[i]); // Pembacaan standar, tidak dibalik saat input.
    }
    // Jika ingin mempertahankan logika input terbalik dari kode asli, loopnya akan seperti ini:
    // for (int i = arraySize - 1; i >= 0; i--) {
    //     scanf("%d", &weights[i]);
    // }
    // Namun, kita akan ikuti pembacaan standar dan sesuaikan logika jika perlu,
    // atau asumsikan input sudah dalam urutan yang diinginkan untuk diproses.
    // Setelah meninjau kembali kode asli, loop input memang membalik urutan. Mari kita ikuti itu.
    // Loop input yang benar sesuai kode asli:
    // for (int i = arraySize - 1; i >= 0; i--) {
    //    scanf("%d", &weights[i]);
    // }
    // Namun, untuk kejelasan dan standar, lebih baik membaca secara normal dan jika perlu,
    // proses pembalikan dilakukan secara eksplisit jika memang itu intensi soal.
    // Untuk saat ini, kita baca normal dan lihat dampaknya pada logika.
    // Revisi: Mengikuti logika pembacaan asli untuk menjaga fungsionalitas.
     for (int i = arraySize - 1; i >= 0; i--) {
        scanf("%d", &weights[i]);
     }


    // Loop untuk mencari dan memodifikasi elemen target.
    for (int i = 0; i < arraySize; i++)
    {
        if (weights[i] == targetValue)
        {
            // Modifikasi nilai elemen target berdasarkan posisinya.
            if (i == 0) // Jika target adalah elemen pertama.
            {
                // Jika hanya ada satu elemen, dan itu target, apa yang terjadi?
                // Kode asli akan mengakses weights[i+1] -> weights[1] yang bisa jadi out of bounds jika arraySize = 1.
                // Perlu penanganan khusus jika arraySize == 1.
                if (arraySize > 1) {
                    weights[i] = weights[i + 1];
                } else {
                    // Jika hanya satu elemen dan itu target, tidak ada tetangga.
                    // Perilaku tidak terdefinisi oleh soal, bisa dibiarkan atau di-handle.
                    // Asumsi soal: N > 1 jika target di ujung.
                }
            }
            else if (i == arraySize - 1) // Jika target adalah elemen terakhir.
            {
                weights[i] = weights[i - 1];
            }
            else // Jika target ada di tengah.
            {
                weights[i] = weights[i - 1] + weights[i + 1];
            }

            // Membalikkan bagian array di sebelah kanan elemen yang dimodifikasi.
            // Indeks mulai untuk pembalikan adalah i + 1.
            // Indeks akhir untuk pembalikan adalah arraySize - 1.
            int leftIndex = i + 1;
            int rightIndex = arraySize - 1;
            while (leftIndex < rightIndex)
            {
                // Tukar elemen.
                int temp = weights[leftIndex];
                weights[leftIndex] = weights[rightIndex];
                weights[rightIndex] = temp;
                leftIndex++;
                rightIndex--;
            }
            // Setelah satu elemen target ditemukan dan diproses,
            // apakah loop harus berhenti atau lanjut mencari target lain?
            // Kode asli akan melanjutkan, berpotensi memproses array yang sudah dimodifikasi.
            // Ini mungkin intensi soal.
        }
    }

    // Mencetak array hasil modifikasi.
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d", weights[i]);
        if (i < arraySize - 1)
        {
            printf(" "); // Spasi antar elemen.
        }
        else
        {
            printf("\n"); // Newline di akhir.
        }
    }

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}