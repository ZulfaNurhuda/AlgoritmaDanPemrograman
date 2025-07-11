/**
 * --------------------------------------------------------------
 * | @file PalindromLagi.c                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk mengecek apakah sebuah string atau salah     |
 * | satu hasil rotasinya merupakan palindrom.                  |
 * --------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h> // Untuk strlen
#include <stdbool.h> // Untuk tipe data bool

/**
 * @brief Memeriksa apakah sebuah string merupakan palindrom.
 * @param str Pointer ke string yang akan diperiksa.
 * @param length Panjang dari string.
 * @return bool Mengembalikan true jika string adalah palindrom, false jika bukan.
 * @note I.S. : str terdefinisi, length adalah panjang aktual dari str.
 * @note F.S. : Mengembalikan status palindrom dari str.
 *              String kosong atau string dengan satu karakter dianggap palindrom.
 */
bool isPalindrome(const char *str, int length) // Menggunakan const char* karena fungsi tidak mengubah string
{
    // String dengan panjang 0 atau 1 adalah palindrom.
    if (length < 2)
    {
        return true;
    }

    // Membandingkan karakter dari kedua ujung string bergerak ke tengah.
    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            return false; // Ditemukan karakter yang tidak cocok.
        }
    }

    return true; // Semua karakter cocok.
}

/**
 * @brief Melakukan rotasi kanan pada sebuah string sebanyak satu kali.
 * @details Karakter terakhir string dipindahkan ke posisi pertama,
 *          dan semua karakter lain digeser satu posisi ke kanan.
 * @param str Pointer ke string yang akan dirotasi (modifikasi in-place).
 * @param length Panjang dari string.
 * @note I.S. : str terdefinisi dan dapat dimodifikasi, length adalah panjang str.
 *              Diasumsikan length > 0. Jika length <= 0, fungsi tidak melakukan apa-apa.
 * @note F.S. : String str telah dirotasi ke kanan sebanyak satu posisi.
 */
void rotateStringRight(char *str, int length)
{
    if (length <= 1) // Tidak ada rotasi yang berarti untuk string kosong atau 1 karakter.
    {
        return;
    }

    // Simpan karakter terakhir.
    char tempLastChar = str[length - 1];

    // Geser semua karakter ke kanan.
    for (int i = length - 1; i > 0; i--)
    {
        str[i] = str[i - 1];
    }

    // Tempatkan karakter terakhir yang disimpan ke posisi pertama.
    str[0] = tempLastChar;
}

/**
 * @brief Fungsi utama program.
 * @details Membaca sebuah string, lalu mengecek apakah string asli atau salah satu
 *          hasil rotasinya merupakan palindrom. Mencetak "YES" atau "NO".
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Buffer untuk menyimpan string input, dengan ukuran 1001 untuk menampung hingga 1000 karakter + null terminator.
    char inputString[1001];

    // Membaca string dari pengguna. scanf "%s" akan berhenti pada whitespace pertama.
    scanf("%s", inputString);

    // Mendapatkan panjang string yang dibaca.
    int stringLength = strlen(inputString);

    // Cek apakah string asli adalah palindrom.
    if (isPalindrome(inputString, stringLength))
    {
        printf("YES\n");
        return 0; // Program selesai jika sudah ditemukan palindrom.
    }

    // Lakukan rotasi sebanyak (panjang string - 1) kali dan cek palindrom setiap kali.
    // Total N rotasi akan mengembalikan string ke bentuk semula, jadi cukup N-1 rotasi berbeda.
    // Loop i dari 0 hingga n-1 berarti n kali rotasi.
    // Setelah n rotasi, string kembali ke awal. Cukup n-1 rotasi untuk semua kemungkinan unik.
    for (int i = 0; i < stringLength -1; i++) // Melakukan stringLength-1 rotasi
    {
        rotateStringRight(inputString, stringLength);
        if (isPalindrome(inputString, stringLength))
        {
            printf("YES\n");
            return 0; // Program selesai jika palindrom ditemukan setelah rotasi.
        }
    }

    // Jika setelah semua rotasi tidak ditemukan palindrom.
    printf("NO\n");

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}